/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** fill_stack_pipe
*/

#include "struct.h"
#include "my.h"
#include "shell_loop.h"
#include <stdlib.h>

void fill_stack_pipe(my_command_t *command_stack, char *command)
{
    char **command_parse = my_strtok(command, "|");
    int i;

    for (i = 0; command_parse[i]; i++) {
        if (command_parse[i + 1]) {
            command_stack->command[command_stack->stack_length] = \
            my_strdup("A");
            command_stack->command_type[command_stack->stack_length] = PIPE;
            command_stack->stack_length += 1;
        }
        fill_stack_redirection_global(command_stack, command_parse[i]);
        free(command_parse[i]);
    }
    free(command_parse);
}