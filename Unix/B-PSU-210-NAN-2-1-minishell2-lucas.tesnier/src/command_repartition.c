/*
** EPITECH PROJECT, 2021
** bultins.c
** File description:
** all function for bultins
*/

#include "proto.h"

void shell_command_repartition_verification(char **envp, char *command)
{
    if (command == NULL) {
        shell_start(envp);
        exit(0);
    }
    command = check_integrity(command);
    if (command == NULL) {
        shell_start(envp);
        exit(0);
    }
}

void shell_command_repartition_execute_bultins(char **envp, \
char *command, bool fos)
{
    int bultins = 0;

    if (fos == true) {
        bultins = execute_bultin(command, envp);
        if (bultins == 0)
            shell_execute_command(envp, command);
    } else {
        if (is_a_bultin(command) == false)
            shell_execute_command(envp, command);
    }
}

void shell_command_repartition_execute_simple_command(char **envp, \
char *command, bool fos)
{
    int type = 0;
    int redirection_pos = 0;
    int bultins = 0;

    redirection_pos = get_redirection_pos(command, &type);
    if (redirection_pos != my_strlen(command)) {
        execute_redirection(envp, command, redirection_pos, type);
    } else {
        shell_command_repartition_execute_bultins(envp, command, fos);
    }
}

void shell_command_repartition_bultin(char **envp, char *command)
{
    char **a = segmentation_c(command, "|");

    for (; a[1] != NULL; a++);
    if (is_a_bultin(a[0]) == true)
        execute_bultin(a[0], envp);
}

void shell_command_repartition(char **envp, char *command, bool fos)
{
    int pos = 0;
    bool more_commands = multiple_command(command, &pos);
    int pipe_pos = 0;

    shell_command_repartition_verification(envp, command);
    for (; pipe_pos < my_strlen(command); pipe_pos++) {
        if (command[pipe_pos] == '|')
            break;
    }
    if (pipe_pos != my_strlen(command)) {
        execute_pipe(envp, command, pipe_pos);
        if (fos == true)
            shell_command_repartition_bultin(envp, command);
    } else {
        shell_command_repartition_execute_simple_command(envp, command, fos);
    }
    if (more_commands == true) {
        command += pos;
        shell_command_repartition(envp, command, fos);
    }
}