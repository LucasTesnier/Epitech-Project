/*
** EPITECH PROJECT, 2021
** bultins.c
** File description:
** all function for bultins
*/

#include "proto.h"

bool is_alpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (true);
    return (false);
}

void execute_setenv(char **envp, char **argv)
{
    int pos = 0;
    char *str;

    if (setenv_error_message(argv, envp) == true)
        return;
    if (get_in_env(envp, argv[1], &pos) != NULL) {
        if (argv[2])
            replace_var(envp, argv[1], argv[2], 1);
        else
            envp[pos][my_strlen(argv[1]) + 1] = '\0';
        return;
    }
    setenv_new(envp, argv);
}

void execute_unsetenv(char **envp, char **argv)
{
    int pos = 0;

    if (!argv[1]) {
        my_puterror("unsetenv: Too few arguments.\n");
        return;
    }
    if (get_in_env(envp, argv[1], &pos) != NULL) {
        dup_env(envp, pos);
    }

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
