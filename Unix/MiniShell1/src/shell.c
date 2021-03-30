/*
** EPITECH PROJECT, 2021
** shell.c
** File description:
** functions for shell
*/

#include "proto.h"

int execute_bultin(char *command, char **envp)
{
    char **argv = NULL;

    if (command == NULL)
        return (-1);
    if (my_strcmp(command, "env") == 0) {
        display_env(envp);
        return (1);
    }
    argv = segmentation(command);
    if (my_strcmp(argv[0], "exit") == 0) {
        my_putstr("exit\n");
        if (argv[1])
            exit(my_getnbr(argv[1]) % 256);
        return (-1);
    }
    if (my_strcmp(argv[0], "cd") == 0) {
        execute_cd(argv, envp);
        return (1);
    }
    if (execute_bultin_env(command, envp, argv) == 1)
        return (1);
}

int count_word(char *command)
{
    int nb = 0;

    for (int i = 0; i < my_strlen(command); i++) {
        if ((command[i] == ' ' || command[i] == '\t') && (command[i + 1] \
	    != ' ' && command[i + 1] != '\t' && command[i + 1] != '\0'))
	    nb++;
	if (command[i] != ' ' && command[i] != '\t' && i == 0)
            nb++;
    }
    return (nb);
}

char **segmentation_c(char *command, char *separators)
{
    char **args;
    int nb = count_word(command);
    int i = 0;
    char *s = command;
    char *t = NULL;

    if ((args = malloc(sizeof(char *) * nb)) == NULL)
        exit(0);
    t = strtok(s, separators);
    while (t != NULL) {
	if (i < nb) {
            if ((args[i] = malloc(sizeof(char) * (1 + my_strlen(t)))) == NULL)
                exit(0);
            my_strncpy(args[i], t, my_strlen(t));
            i++;
	} else
            break;
	t = strtok(NULL, separators);
    }
    args[i] = NULL;
    return (args);
}

int shell_execute_command(char **envp, char *command)
{
    char **argv = segmentation_c(command, " \t");
    char *path = get_path(envp, argv[0]);

    if (path == NULL) {
        my_putstr(argv[0]);
        my_putstr(": Command not found.\n");
    } else {
        if (my_strcmp(path, "a") != 0)
            shell(prepare_shell(argv[0], path), argv, envp);
        else
            shell(argv[0], argv, envp);
    }
    return (0);
}

void shell_start(char **envp)
{
    int bultins = 0;
    char *command = NULL;

    while (1) {
        put_prompt();
        command = get_str();
        if (command == NULL) {
            shell_start(envp);
            exit(0);
        }
        bultins = execute_bultin(command, envp);
        if (bultins == -1)
            return;
        if (bultins == 0)
            shell_execute_command(envp, command);
    }
}
