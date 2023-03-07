/*
** EPITECH PROJECT, 2021
** bultins.c
** File description:
** all function for bultins
*/

#include "proto.h"

void execute_setenv(char **envp, char **argv)
{
    int pos = 0;
    char *str;

    if (argv[1] && argv[2] && argv[3]) {
        my_putstr("setenv: Too many arguments.\n");
        return;
    }
    if (!argv[1]) {
        display_env(envp);
        return;
    }
    if (get_in_env(envp, argv[1], &pos) != NULL) {
        replace_var(envp, argv[1], argv[2], 1);
        return;
    }
}

void execute_unsetenv(char **envp, char **argv)
{
    int pos = 0;

    if (!argv[1]) {
        my_putstr("unsetenv: Too few arguments.\n");
        return;
    }
    get_in_env(envp, argv[1], &pos);
}

int execute_bultin_env(char *command, char **envp, char **argv)
{
    if (my_strcmp(argv[0], "setenv") == 0) {
        execute_setenv(envp, argv);
        return (1);
    }
    if (my_strcmp(argv[0], "unsetenv") == 0) {
        execute_unsetenv(envp, argv);
        return (1);
    }
    return (0);
}
