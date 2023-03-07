/*
** EPITECH PROJECT, 2021
** B-PSU-210-NAN-2-1-42sh-lucas.tesnier
** File description:
** alias_bultin
*/

#include "struct.h"
#include "my.h"
#include "shell_loop.h"
#include <stdlib.h>
#include <unistd.h>

void display_alias_content(alias_list_t *alias_list, char *name)
{
    int alias_pos = return_alias_pos(alias_list, name);

    if (alias_pos == -1)
        return;
    my_putstr(alias_list->alias[alias_pos].command);
    my_putstr("\n");
}

void sort_alias_list(alias_list_t *alias_list, int *change)
{
    char *temp = NULL;
    char *temp_two = NULL;

    *change = 0;
    for (int i = 1; i < alias_list->nbr; i++) {
        if (my_strcmp(alias_list->alias[i].name, \
        alias_list->alias[i - 1].name) < 0) {
            temp = my_strdup(alias_list->alias[i].name);
            temp_two = my_strdup(alias_list->alias[i].command);
            alias_list->alias[i].name = \
            my_strdup(alias_list->alias[i - 1].name);
            alias_list->alias[i].command = \
            my_strdup(alias_list->alias[i - 1].command);
            alias_list->alias[i - 1].name = my_strdup(temp);
            alias_list->alias[i - 1].command = my_strdup(temp_two);
            free(temp);
            free(temp_two);
            *change = 1;
        }
    }
}

void create_new_alias(alias_list_t *alias_list, char *name, int *alias_pos)
{
    alias_list->alias[alias_list->nbr].name = my_strdup(name);
    alias_list->alias[alias_list->nbr].command = NULL;
    *alias_pos = alias_list->nbr;
    alias_list->nbr += 1;
}

void change_an_alias(alias_list_t *alias_list, char **content, int pos)
{
    alias_list->alias[pos].command = malloc(sizeof(char) * 10000);
    alias_list->alias[pos].command[0] = '\0';
    for (int i = 0; content[i]; i++) {
        my_strcat(alias_list->alias[pos].command, content[i]);
        if (content[i + 1])
            my_strcat(alias_list->alias[pos].command, " ");
    }
}

void execute_alias(char **args, my_shell_t *shell)
{
    int alias_pos = 0;
    int change = 1;

    if (!args[1]) {
        display_alias(shell->alias_list);
        shell->return_value = 0;
        return;
    }
    if (!args[2]) {
        display_alias_content(shell->alias_list, args[1]);
        shell->return_value = 0;
        return;
    }
    alias_pos = return_alias_pos(shell->alias_list, args[1]);
    if (alias_pos == -1)
        create_new_alias(shell->alias_list, args[1], &alias_pos);
    change_an_alias(shell->alias_list, args + 2, alias_pos);
    while (change == 1)
        sort_alias_list(shell->alias_list, &change);
    shell->return_value = 0;
}