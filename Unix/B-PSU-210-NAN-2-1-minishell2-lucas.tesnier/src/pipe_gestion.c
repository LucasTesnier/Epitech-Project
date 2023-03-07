/*
** EPITECH PROJECT, 2021
** bultins.c
** File description:
** all function for bultins
*/

#include "proto.h"

bool is_a_bultin(char *str)
{
    char *bultin[] = {"env", "exit", "setenv", "unsetenv", "cd"};
    char **args = segmentation_c(str, " \t");

    for (int i = 0; i < 5; i++) {
        if (my_strcmp(bultin[i], args[0]) == 0)
            return (true);
    }
    return (false);
}

void execute_pipe_first_child(char **envp, char *command, \
int pipe_pos, int *fd)
{
    int bultins = 0;

    command[pipe_pos] = '\0';
    dup2(fd[1], STDOUT_FILENO);
    close(fd[0]);
    close(fd[1]);
    int type = -1;
    int redirection_pos = get_redirection_pos(command, &type);
    if (type == 0 || type == 1) {
        my_puterror("Ambigous outpout Redirect.\n");
        exit(0);
    }
    if (redirection_pos != my_strlen(command))
        execute_redirection(envp, command, redirection_pos, type);
    if (is_a_bultin(command) == false) {
        bultins = execute_bultin(command, envp);
        if (bultins == 0)
            shell_execute_command(envp, command);
    }
    exit(0);
}

void execute_pipe_second_child(char **envp, char *command, \
int pipe_pos, int *fd)
{
    int type = -1;

    command += pipe_pos + 1;
    dup2(fd[0], STDIN_FILENO);
    close(fd[1]);
    close(fd[0]);
    command = check_integrity(command);
    if (command == NULL) {
        my_puterror("Invalid null command.\n");
    }
    get_redirection_pos(command, &type);
    if (type == 2 || type == 3) {
        my_puterror("Ambigous input Redirect.\n");
        exit(0);
    }
    shell_command_repartition(envp, command, false);
    exit(0);
}

void execute_pipe_first_parent(char **envp, char *command, \
int pipe_pos, int *fd)
{
    int pid = fork();

    if (pid == 0) {
        execute_pipe_second_child(envp, command, pipe_pos, fd);
    } else {
        int status;
        close(fd[0]);
        close(fd[1]);
        waitpid(pid, &status, 0);
    }
}

void execute_pipe(char **envp, char *command, int pipe_pos)
{
    int bultins = 0;
    int fd[2];
    pipe(fd);
    pid_t pid = fork();

    if (pid == 0) {
        execute_pipe_first_child(envp, command, pipe_pos, fd);
    } else {
        execute_pipe_first_parent(envp, command, pipe_pos, fd);
    }
}