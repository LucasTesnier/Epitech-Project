/*
** EPITECH PROJECT, 2021
** B-PSU-210-NAN-2-1-42sh-lucas.tesnier
** File description:
** alias_bultin_two
*/

#include "struct.h"
#include "my.h"
#include "shell_loop.h"
#include <stdlib.h>
#include <unistd.h>

void display_alias(alias_list_t *alias_list)
{
    for (int i = 0; i < alias_list->nbr; i++) {
        my_putstr(alias_list->alias[i].name);
        my_putstr("\t");
        my_putstr(alias_list->alias[i].command);
        my_putstr("\n");
    }
}

int return_alias_pos(alias_list_t *alias_list, char *name)
{
    int alias_pos = -1;

    for (int i = 0; i < alias_list->nbr; i++) {
        if (my_strcmp(name, alias_list->alias[i].name) == 0)
            alias_pos = i;
    }
    return (alias_pos);
}

char *alias_replace(char *command, alias_list_t *alias_list)
{
    char **args = my_strtok(command, " ");

    if (!args)
        return (command);
    int alias_pos = return_alias_pos(alias_list, args[0]);
    if (alias_pos == -1)
        return (command);
    char *str = malloc(sizeof(char) * 10000);
    str[0] = '\0';
    my_strcat(str, alias_list->alias[alias_pos].command);
    for (int i = 1; args[i]; i++) {
        my_strcat(str, " ");
        my_strcat(str, args[i]);
    }
    return (str);
}

void copy_alias_without_pos(alias_list_t *alias_list, int alias_pos)
{
    for (int i = alias_pos + 1; i < alias_list->nbr; i++) {
        alias_list->alias[i - 1].command = my_strdup\
        (alias_list->alias[i].command);
        alias_list->alias[i - 1].name = my_strdup(alias_list->alias[i].name);
    }
    alias_list->nbr -= 1;
}

void execute_unalias(char **args, my_shell_t *shell)
{
    int alias_pos = 0;

    if (!args[1]) {
        my_puterror("unalias: Too few arguments.\n");
        shell->return_value = 1;
        return;
    }
    for (int i = 1; args[i]; i++) {
        alias_pos = return_alias_pos(shell->alias_list, args[i]);
        if (alias_pos != -1) {
            copy_alias_without_pos(shell->alias_list, alias_pos);
        }
    }
}