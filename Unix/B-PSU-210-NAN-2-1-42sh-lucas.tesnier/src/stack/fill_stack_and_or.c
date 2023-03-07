/*
** EPITECH PROJECT, 2021
** fill_stack_and_or.c
** File description:
** 42sh
*/

#include "struct.h"
#include "my.h"
#include "shell_loop.h"
#include <stdlib.h>

void fill_stack_and(my_command_t *command_stack, char *command)
{
    char **command_parse;
    int i;

    transform_command(&command, "&&");
    command_parse = my_strtok(command, "\t\t");
    for (i = 0; command_parse[i]; i++) {
        if (command_parse[i + 1]) {
            command_stack->command[command_stack->stack_length] = \
            my_strdup("A");
            command_stack->command_type[command_stack->stack_length] = AND;
            command_stack->stack_length += 1;
        }
        fill_stack_or(command_stack, command_parse[i]);
        free(command_parse[i]);
    }
    free(command_parse);
}

void fill_stack_or(my_command_t *command_stack, char *command)
{
    char **command_parse;
    int i;

    transform_command(&command, "||");
    command_parse = my_strtok(command, "\t\t");
    for (i = 0; command_parse[i]; i++) {
        if (command_parse[i + 1]) {
            command_stack->command[command_stack->stack_length] = \
            my_strdup("A");
            command_stack->command_type[command_stack->stack_length] = OR;
            command_stack->stack_length += 1;
        }
        fill_stack_pipe(command_stack, command_parse[i]);
        free(command_parse[i]);
    }
    free(command_parse);
}