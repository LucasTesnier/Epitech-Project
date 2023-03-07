/*
** EPITECH PROJECT, 2021
** bultins.c
** File description:
** all function for bultins
*/

#include "proto.h"

bool setenv_error_message(char **argv, char **envp)
{
    if (argv[1] && argv[2] && argv[3]) {
        my_puterror("setenv: Too many arguments.\n");
        return (true);
    }
    if (!argv[1]) {
        display_env(envp);
        return (true);
    }
    if (is_alpha(argv[1][0]) == false) {
        my_puterror("setenv: Variable name must begin with a letter.\n");
        return (true);
    }
    if (my_str_search(argv[1], '=') == 1) {
        my_puterror("setenv: Variable name must ");
        my_puterror("contain alphanumeric characters.\n");
        return (true);
    }
    return (false);
}

void setenv_new(char **envp, char **argv)
{
    int envp_size = get_envp_size(envp);

    envp[envp_size] = malloc(sizeof(char) * my_strlen(argv[1]) + 2);
    if (argv[2])
        envp[envp_size] = malloc(sizeof(char) * \
        my_strlen(argv[1]) + 2 + my_strlen(argv[2]));
    envp[envp_size][0] = '\0';
    my_strcat(envp[envp_size], argv[1]);
    my_strcat(envp[envp_size], "=");
    if (argv[2])
        my_strcat(envp[envp_size], argv[2]);
}

int get_envp_size(char **envp)
{
    int count = 0;

    for (char **env = envp; *env != NULL; env++) {
        count++;
    }
    return (count);
}

char **dup_env(char **envp, int pos)
{
    int envp_size = get_envp_size(envp);
    char **new_env = malloc(sizeof(char *) * (envp_size - 1));
    int count = 0;

    for (int i = 0; i < envp_size; i++) {
        if (pos != i) {
            new_env[count] = my_strdup(envp[i]);
            count++;
        }
    }
    new_env[count] = NULL;
    for (int i = 0; i < envp_size; i++) {
        envp[i] = new_env[i];
    }
}

void display_env(char **envp)
{
    for (char **env = envp; *env != NULL; env++) {
        my_putstr(*env);
        my_putchar('\n');
    }
}