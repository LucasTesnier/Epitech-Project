/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** function main
*/

#include "proto.h"

char **copy_env(char **envp)
{
    int envp_size = get_envp_size(envp);
    char **new_env = malloc(sizeof(char *) * (envp_size + 1000));
    int count = 0;

    for (int i = 0; i < envp_size; i++) {
        new_env[count] = my_strdup(envp[i]);
        count++;
    }
    new_env[count] = NULL;
    return (new_env);
}

int main(int ac, char **argv, char **envp)
{
    char **env = copy_env(envp);

    shell_start(env);
    return (0);
}
