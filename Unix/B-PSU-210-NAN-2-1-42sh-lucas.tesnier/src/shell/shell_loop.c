/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** prototypes of all the function on the lib
*/

#include "struct.h"
#include "my.h"
#include "shell_loop.h"

bool my_str_two_search(char *str, char **list)
{
    for (int i = 0; list[i]; i++)
        if (my_strcmp(str, list[i]) == 0)
            return (true);
    return (false);
}

int shell_loop(my_shell_t *shell)
{
    get_a_new_stack(shell->command_stack, shell);
    execute_stack(shell);
    if (shell->status == GO_STATUS)
        shell_loop(shell);
    return (shell->return_value);
}

int shell_loop_upgraded(my_shell_t *shell)
{
    get_a_new_stack_upgraded(shell->command_stack, shell);
    execute_stack(shell);
    if (shell->status == GO_STATUS)
        shell_loop_upgraded(shell);
    return (shell->return_value);
}