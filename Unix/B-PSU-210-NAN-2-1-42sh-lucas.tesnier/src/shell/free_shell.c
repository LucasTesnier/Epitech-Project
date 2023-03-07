/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** prototypes of all the function on the lib
*/

#include "struct.h"
#include "my.h"
#include "shell_loop.h"
#include <stdlib.h>

void free_command_stack(my_command_t *command_stack)
{
    for (int i = 0; i < command_stack->stack_length; i++) {
        free(command_stack->command[i]);
    }
    free(command_stack->command_type);
    free(command_stack->command);
}

void free_env(char **env)
{
    for (; *env != NULL; env++) {
        free(*env);
    }
}

void free_shell(my_shell_t *shell)
{
    my_line_list_destroy(shell->line);
    my_hist_list_destroy(shell->hist);
    if (shell->temp_line)
        free(shell->temp_line);
    free_command_stack(shell->command_stack);
    free(shell->command_stack);
    free_env(shell->env);
    free(shell->env);
}