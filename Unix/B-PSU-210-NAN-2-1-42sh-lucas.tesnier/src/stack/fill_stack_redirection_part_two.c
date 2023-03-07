/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** fill_stack_redirection_part_two
*/

#include "struct.h"
#include "my.h"
#include <stdbool.h>

void fill_stack_redirection_write(my_command_t *command_stack, char *command, \
bool find, char **command_parse)
{
    if (find == true) {
        command_parse = my_strtok(command, "<>");
        command_stack->command_type[command_stack->stack_length] = CLASSIC;
        command_stack->command[command_stack->stack_length] = \
        my_strdup(command_parse[0]);
        command_stack->stack_length += 1;
    } else {
        command_stack->command_type[command_stack->stack_length] = CLASSIC;
        command_stack->command[command_stack->stack_length] = \
        my_strdup(command);
        command_stack->stack_length += 1;
    }
}