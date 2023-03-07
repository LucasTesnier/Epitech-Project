/*
** EPITECH PROJECT, 2021
** env_parsing.c
** File description:
** all function for parsing env
*/

#include "proto.h"

void display_env(char **envp)
{
    for (char **env = envp; *env != NULL; env++) {
        my_putstr(*env);
        my_putchar('\n');
    }
}

char *pick_env_info(char *envp_i)
{
    char *search;
    int i;
    int j;

    for (i = 0; envp_i[i] && envp_i[i] != '='; i++);
    i++;
    if ((search = malloc(sizeof(char) * (my_strlen(envp_i + i) + 2))) == NULL) {
        exit(0);
    }
    for (j = 0; envp_i[i]; j++) {
        search[j] = envp_i[i];
        i++;
    }
    search[j] = '\0';
    return (search);
}

int get_env_length(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '='; i++)
        count++;
    return (count);
}

char *get_in_env(char **envp, char *name, int *pos)
{
    char *search = NULL;
    int length = 0;

    *pos = 0;
    for (int i = 0; envp[i]; i++) {
        length = get_env_length(envp[i]);
        if (my_strncmp(envp[i], name, length) == 0) {
            search = pick_env_info(envp[i]);
            *pos = i;
        }
    }
    return (search);
}

void my_strccat(char **envp, int pos, char *replace, char *var)
{
    char *temp = malloc(sizeof(char) * (my_strlen(var) + 2 + \
    my_strlen(replace)));

    if (temp == NULL)
        exit(0);
    envp[pos] = temp;
    for (int i = 0; i < my_strlen(var); i++)
        envp[pos][i] = var[i];
    envp[pos][my_strlen(var)] = '=';
    for (int i = my_strlen(var) + 1; replace[i - my_strlen(var) - 1]; i++) {
        envp[pos][i] = replace[i - my_strlen(var) - 1];
    }
    envp[pos][my_strlen(var) + 1 + my_strlen(replace)] = '\0';
}

void replace_var(char **envp, char *var, char *valeur, int overwrite)
{
    int pos = 0;
    char *search = NULL;

    search = get_in_env(envp, var, &pos);
    if (overwrite != 0 && search) {
        my_strccat(envp, pos, valeur, var);
    }
}
