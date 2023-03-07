/*
** EPITECH PROJECT, 2022
** Project
** File description:
** strace_init
*/

#include "strace_init.h"
#include "strace_uniq_command.h"
#include "strace_flags.h"
#include "strace_prepare_command.h"
#include "syscall.h"
#include "strace_syscall.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <unistd.h>
#include <sys/reg.h>
#include <sys/wait.h>
#include <sys/user.h>

/**
*@brief parse the receive arguments
*
*@param strace_data data needed for strace
*@param ac number of arguments
*@param args arguments
*@return 0 if every arguments is valid, 84 otherwise
*/
static int parse_strace_args(strace_data_t *strace_data, int ac, char **av)
{
    if (ac == 2) {
        return handle_unique_command(strace_data, av[1]);
    } else if (ac == 3 || ac == 4) {
        return handle_flags(strace_data, av, ac);
    } else {
        return 84;
    }
}

/**
* @brief do the job of the parent system
*
* @param strace_data
*/
int strace_do_parent_job(strace_data_t *strace_data)
{
    struct user_regs_struct regs;
    syscall_t actual_signal;
    int status = 0;

    waitpid(strace_data->pid, &status, 0);
    while (true) {
        next_signal(&status, strace_data->pid, &regs);
        int temp = ptrace(PTRACE_PEEKTEXT, strace_data->pid, regs.rip, NULL);
        if ((temp & 0xffff) == 0x050F) {
            next_signal(&status, strace_data->pid, &regs);
            fill_actual_signal_with_regs_value(regs, &actual_signal);
            matching_actual_signal_with_signal_table(&actual_signal);
            display_actual_signal(actual_signal);
        }
        if (WIFEXITED(status) || WIFSIGNALED(status))
            break;
    }
    return WEXITSTATUS(status);
}

/**
* @brief start the child process
*
* @param strace_data
* @param envp
* @return int
*/
int strace_do_child_job(strace_data_t *strace_data, char **env)
{
    char **args = NULL;
    char *command = prepare_command(strace_data->command, env);

    if (!command)
        return COMMAND_ERROR;
    strace_data->pid = fork();
    if (strace_data->pid == -1) {
        return PID_ERROR;
    } else if (strace_data->pid == 0) {
        args = malloc(sizeof(char *) * 2);
        args[0] = strace_data->command;
        args[1] = NULL;
        ptrace(PTRACE_TRACEME, 0, NULL, NULL);
        kill(getpid(), SIGSTOP);
        execve(command, args, env);
        return 0;
    }
    free(command);
    return strace_data->pid;
}

/**
*@brief hold the pid flags
*
*@param strace_data
*@param envp
*@return int
*/
int strace_pid_gestion(strace_data_t *strace_data, char **envp)
{
    int ret = 0;

    if (!strace_data->p_option) {
        int res = strace_do_child_job(strace_data, envp);

        if (res == PID_ERROR || res == COMMAND_ERROR) {
            return 84;
        } else {
            strace_data->pid = res;
        }
    } else
        ptrace(PTRACE_ATTACH, strace_data->pid, NULL, NULL);
    ret = strace_do_parent_job(strace_data);
    fprintf(stderr, "+++ exited with %d +++\n", ret);
    return ret;
}

/**
*@brief start the strace process
*
*@param ac
*@param av
*@param envp
*@return int
*/
int strace_start(int ac, char **av, char **envp)
{
    strace_data_t *strace_data = init_strace_data();
    int ret = 0;

    (void)table;
    if (!strace_data)
        return 84;
    ret = parse_strace_args(strace_data, ac, av);
    if (ret) {
        if (ret == 1)
            return 0;
        else
            return ret;
    }
    ret = strace_pid_gestion(strace_data, envp);
    strace_data_destroy(strace_data);
    return ret;
}
