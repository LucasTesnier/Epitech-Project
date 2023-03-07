/*
** EPITECH PROJECT, 2021
** B-PSU-210-NAN-2-1-42sh-lucas.tesnier
** File description:
** set_builtin
*/
#include "struct.h"
#include "my.h"
#include "shell_loop.h"
#include <stdlib.h>

st_local_var *sort_local_var(st_local_var *local_var,
int *change, my_shell_t *shell)
{
    st_local_var *tmp = local_var;
    char *tmp_two = NULL;

    *change = 0;
    while (tmp->next != NULL) {
        if (my_strcmp(tmp->next->name, tmp->name) < 0) {
            tmp_two = my_strdup(tmp->name);
            tmp->name = my_strdup(tmp->next->name);
            tmp->next->name = my_strdup(tmp_two);
            tmp_two = my_strdup(tmp->data);
            tmp->data = my_strdup(tmp->next->data);
            tmp->next->data = my_strdup(tmp_two);
            free(tmp_two);
            *change = 1;
        }
        tmp = tmp->next;
    }
    shell->return_value = 0;
    return (local_var);
}

st_local_var *create_new_local_var(st_local_var *local_var, char **args)
{
    st_local_var *tmp = malloc(sizeof(st_local_var));

    if (tmp == NULL)
        return (NULL);
    tmp->name = my_strdup(args[0]);
    if (args[1] && args[2] && my_strcmp(args[1], "=") == 0)
        tmp->data = my_strdup(args[2]);
    else
        tmp->data = NULL;
    tmp->next = local_var;
    if (tmp->name == NULL)
        return (NULL);
    return (tmp);
}

st_local_var *change_local_var(st_local_var *local_var, char *data,
st_local_var *tmp)
{
    if (data == NULL) {
        free(tmp->data);
        tmp->data = NULL;
    } else {
        free(tmp->data);
        tmp->data = my_strdup(data);
    }
    return (local_var);
}

st_local_var *empty_local_var_data(st_local_var *local_var, char **args,
my_shell_t *shell, int *change)
{
    st_local_var *tmp = local_var;

    tmp = check_local_var_name(tmp, args[0]);
    if (tmp == NULL)
        tmp = create_new_local_var(local_var, args);
    else
        tmp = change_local_var(local_var, NULL, tmp);
    shell->return_value = 0;
    while (*change == 1)
        tmp = sort_local_var(tmp, change, shell);
    return (tmp);
}

st_local_var *execute_set(char **args, my_shell_t *shell,
st_local_var *local_var)
{
    int change = 1;
    st_local_var *tmp = local_var;

    if (!args[0])
        display_local_var(tmp, shell, &change);
    else if (!args[1] || my_strcmp(args[1], "=") != 0) {
        tmp = empty_local_var_data(tmp, args, shell, &change);
        if (arr_len(args) > 1)
            tmp = execute_set(args + 1, shell, tmp);
    } else {
        tmp = check_local_var_name(tmp, args[0]);
        if (tmp == NULL)
            tmp = create_new_local_var(local_var, args);
        else
            tmp = change_local_var(local_var, args[2], tmp);
        while (change == 1)
            tmp = sort_local_var(tmp, &change, shell);
        if (arr_len(args) > 3)
            tmp = execute_set(args + 3, shell, tmp);
    }
    return (tmp);
}