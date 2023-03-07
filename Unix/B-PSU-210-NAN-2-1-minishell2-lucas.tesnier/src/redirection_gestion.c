/*
** EPITECH PROJECT, 2021
** bultins.c
** File description:
** all function for bultins
*/

#include "proto.h"

void execute_redirection_type_one(char **envp, char *command, \
int pipe_pos, int type)
{
    int f = open_file(command + pipe_pos + 2, type);
    int bultins = 0;

    command[pipe_pos] = '\0';
    dup2(f, 1);
    close(f);
    bultins = execute_bultin(command, envp);
    if (bultins == 0)
        shell_execute_command(envp, command);
    exit(0);
}

void execute_redirection_type_two(char **envp, char *command, \
int pipe_pos, int type)
{
    int f = open_file(command + pipe_pos + 2, type);
    int bultins = 0;

    command[pipe_pos] = '\0';
    dup2(f, 0);
    close(f);
    bultins = execute_bultin(command, envp);
    if (bultins == 0)
        shell_execute_command(envp, command);
    exit(0);
}

void execute_redirection_type_three(char **envp, char *command, \
int pipe_pos, int type)
{
    int f = get_double_redir_input(command + pipe_pos + 3);
    int bultins = 0;

    command[pipe_pos] = '\0';
    dup2(f, 0);
    close(f);
    bultins = execute_bultin(command, envp);
    if (bultins == 0)
        shell_execute_command(envp, command);
    exit(0);
}

void execute_redirection(char **envp, char *command, int pipe_pos, int type)
{
    int bultins = 0;
    pid_t pid = fork();
    int status;

    if (pid == 0 && type < 2) {
        execute_redirection_type_one(envp, command, pipe_pos, type);
    } else if (pid == 0 && type == 2) {
        execute_redirection_type_two(envp, command, pipe_pos, type);
    } else if (pid == 0 && type == 3) {
        execute_redirection_type_three(envp, command, pipe_pos, type);
    } else {
        waitpid(pid, &status, 0);
    }
}

int get_redirection_pos(char *command, int *type)
{
    int redirection_pos = 0;

    for (; redirection_pos < my_strlen(command); redirection_pos++) {
        if (command[redirection_pos] == '>') {
            *type = 0;
            break;
        }
        if (command[redirection_pos] == '<') {
            *type = 2;
            break;
        }
    }
    if (command[redirection_pos + 1] == '>' && *type == 0) {
        *type = 1;
    }
    if (command[redirection_pos + 1] == '<' && *type == 2)
        *type = 3;
    return (redirection_pos);
}