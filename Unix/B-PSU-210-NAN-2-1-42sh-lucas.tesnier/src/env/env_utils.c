/*
** EPITECH PROJECT, 2021
** bultins.c
** File description:
** all function for bultins
*/

#include "struct.h"
#include "my.h"
#include "shell_loop.h"
#include <stdlib.h>

void add_env_variable(char **envp, char **argv)
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

char **dup_env_without(char **envp, int pos)
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

char **copy_env(char **envp)
{
    int envp_size = get_envp_size(envp);
    char **new_env = malloc(sizeof(char *) * (envp_size + 1000));
    char *str = NULL;
    int count = 0;
    int pos = 0;

    for (int i = 0; i < envp_size; i++) {
        new_env[count] = my_strdup(envp[i]);
        count++;
    }
    new_env[count] = NULL;
    str = get_in_env(envp, "OLDPWD", &pos);
    if (str == NULL) {
        new_env[count] = my_strdup("OLDPWD=");
        new_env[count + 1] = NULL;
    } else
        free(str);
    return (new_env);
}