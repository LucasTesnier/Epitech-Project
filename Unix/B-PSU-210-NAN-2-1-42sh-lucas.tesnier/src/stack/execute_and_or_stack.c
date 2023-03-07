/*
** EPITECH PROJECT, 2021
** execute_and_stack
** File description:
** execute_and_stack
*/

#include "shell_loop.h"
#include "my.h"

void execute_and_or_stack(int size, my_shell_t *shell, my_command_t \
*command_stack, int *i)
{
    int pos = *i;
    int separators_pos = stack_return_classic_pos\
    (command_stack->command_type, pos, size);

    pos += 1;
    if (command_stack->command_type[pos] == NONE ||
        pos >= command_stack->stack_length)
        return;
    all_type_stack(size, shell, command_stack, &pos);
}