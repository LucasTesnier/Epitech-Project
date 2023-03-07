/*
** EPITECH PROJECT, 2021
** B-PSU-210-NAN-2-1-42sh-lucas.tesnier
** File description:
** unset_builtin
*/
#include "struct.h"
#include "my.h"
#include "shell_loop.h"
#include <stdlib.h>

st_local_var *remove_var(st_local_var *local_var,
my_shell_t *shell, char **args)
{
    st_local_var *tmp = local_var;
    st_local_var *node_to_free = local_var;

    while (tmp->next != NULL && tmp != NULL) {
        node_to_free = tmp->next;
        if (my_strcmp(node_to_free->name, args[0]) == 0) {
            tmp->next = tmp->next->next;
            tmp = tmp->next;
            free(node_to_free->name);
            free(node_to_free->data);
            free(node_to_free);
        } else
            tmp = tmp->next;
    }
    shell->return_value = 0;
    return (local_var);
}

st_local_var *remove_first_var(st_local_var *tmp, my_shell_t *shell)
{
    st_local_var *node_to_free = tmp;

    tmp = tmp->next;
    free(node_to_free->name);
    free(node_to_free->data);
    free(node_to_free);
    shell->return_value = 0;
    return (tmp);
}

st_local_var *execute_unset(char **args, my_shell_t *shell,
st_local_var *local_var)
{
    st_local_var *tmp = local_var;

    if (!args[0])
        return (local_var);
    if (arr_len(args) > 1)
        local_var = execute_unset(args + 1, shell, local_var);
    tmp = local_var;
    if (my_strcmp(tmp->name, args[0]) == 0)
        return (remove_first_var(tmp, shell));
    else
        return (remove_var(tmp, shell, args));
}