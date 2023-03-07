/*
** EPITECH PROJECT, 2021
** B-PSU-210-NAN-2-1-42sh-lucas.tesnier
** File description:
** set_builtin_two
*/
#include "struct.h"
#include "my.h"
#include "shell_loop.h"
#include <stdlib.h>
#include <stdio.h>

void display_local_var(st_local_var *local_var, my_shell_t *shell, int *change)
{
    st_local_var *tmp = local_var;

    while (*change == 1)
        tmp = sort_local_var(tmp, change, shell);
    while (tmp != NULL && tmp->name != NULL) {
        if (tmp->name != NULL)
            my_putstr(tmp->name);
        my_putstr("\t");
        if (tmp->data != NULL)
            my_putstr(tmp->data);
        my_putstr("\n");
        tmp = tmp->next;
    }
    shell->return_value = 0;
}

st_local_var *check_local_var_name(st_local_var *local_var, char *name)
{
    st_local_var *tmp = local_var;

    while (tmp != NULL) {
        if (my_strcmp(tmp->name, name) == 0)
            break;
        tmp = tmp->next;
    }
    return (tmp);
}

st_local_var *check_local_var_names(st_local_var *local_var, char *name)
{
    st_local_var *tmp = local_var;

    if (name[0] == '$' && name[1])
        name += 1;
    else if ((name[0] == '$' && !name[1]) || name[0] != '$')
        return (NULL);
    while (tmp != NULL) {
        if (my_strcmp(tmp->name, name) == 0)
            break;
        tmp = tmp->next;
    }
    return (tmp);
}

void manage_undefined_var(char *args, my_shell_t *shell)
{
    args++;
    dprintf(2, "%s: Undefined variable.\n", args);
    shell->return_value = -1;
}

char *local_var_replace(char *command, my_shell_t *shell)
{
    char **args = my_strtok(command, " ");
    st_local_var *tmp = shell->local_var;
    char *str = malloc(sizeof(char) * 10000);

    if (!args) {
        free(str);
        return (command);
    }
    str[0] = '\0';
    for (int i = 0; args[i]; i++) {
        tmp = check_local_var_names(shell->local_var, args[i]);
        if (tmp != NULL && tmp->data != NULL)
            my_strcat(str, tmp->data);
        else if (tmp == NULL && args[i][0] == '$') {
            manage_undefined_var(args[i], shell);
            return (NULL);
        } else
            my_strcat(str, args[i]);
        my_strcat(str, " ");
    }
    return (str);
}