/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** fill_stack_separators
*/

#include "struct.h"
#include "my.h"
#include "shell_loop.h"
#include <stdlib.h>

void fill_stack_separators(my_command_t *command_stack, char *command)
{
    char **command_parse = my_strtok(command, ";");

    command_stack->command[0] = my_strdup("A");
    command_stack->stack_length += 1;
    command_stack->command_type[0] = SEPARATORS;
    for (int i = 0; command_parse[i]; i++) {
        fill_stack_and(command_stack, command_parse[i]);
        if (command_parse[i + 1]) {
            command_stack->command_type[command_stack->stack_length] = \
            SEPARATORS;
            command_stack->command[command_stack->stack_length] = \
            my_strdup("A");
            command_stack->stack_length += 1;
        }
        free(command_parse[i]);
    }
    free(command_parse);
}