/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** execute_stack
*/

#include "struct.h"
#include "my.h"
#include "shell_loop.h"
#include <sys/wait.h>
#include <sys/types.h>


bool redirection_type_stack(int size, my_shell_t *shell, \
my_command_t *command_stack, int *pos)
{
    if (command_stack->command_type[*pos] == REDIRECTION_ONE) {
        execute_redirection_one(size, shell, command_stack, pos);
        return (true);
    }
    if (command_stack->command_type[*pos] == REDIRECTION_TWO) {
        execute_redirection_two(size, shell, command_stack, pos);
        return (true);
    }
    if (command_stack->command_type[*pos] == REDIRECTION_THREE) {
        execute_redirection_three(size, shell, command_stack, pos);
        return (true);
    }
    if (command_stack->command_type[*pos] == REDIRECTION_FOUR) {
        execute_redirection_four(size, shell, command_stack, pos);
        return (true);
    }
    return (false);
}

bool and_or_type_stack(int size, my_shell_t *shell, \
my_command_t *command_stack, int *pos)
{
    command_type_e *command_type = command_stack->command_type;

    if (command_type[*pos] == AND) {
        execute_and_or_stack(size, shell, command_stack, pos);
        *pos = stack_return_classic_pos(command_type, *pos, size);
        if (shell->return_value == 0)
            execute_and_or_stack(size, shell, command_stack, pos);
        *pos = stack_return_classic_pos(command_type, *pos, size);
        return (true);
    }
    if (command_type[*pos] == OR) {
        execute_and_or_stack(size, shell, command_stack, pos);
        *pos = stack_return_classic_pos(command_type, *pos, size);
        if (shell->return_value != 0)
            execute_and_or_stack(size, shell, command_stack, pos);
        *pos = stack_return_classic_pos(command_type, *pos, size);
        return (true);
    }
    return (false);
}

void all_type_stack(int size, my_shell_t *shell, \
my_command_t *command_stack, int *pos)
{
    if (command_stack->command_type[*pos] == PIPE) {
        execute_pipe(size, shell, command_stack, pos);
        return;
    }
    if (and_or_type_stack(size, shell, command_stack, pos))
        return;
    if (redirection_type_stack(size, shell, command_stack, pos))
        return;
    if (command_stack->command_type[*pos] == CLASSIC) {
        execute_classic(size, shell, command_stack, pos);
    }
}

void execute_loop_stack(int size, my_shell_t *shell, my_command_t \
*command_stack, int pos)
{
    int separators_pos = stack_return_separators_pos\
    (command_stack->command_type, pos, size);
    int i = pos + 1;

    if (command_stack->command_type[i] == NONE ||
        i >= command_stack->stack_length)
        return;
    all_type_stack(size, shell, command_stack, &i);
}

void execute_stack(my_shell_t *shell)
{
    int size = shell->command_stack->stack_length;

    for (int i = 0; i < size;) {
        execute_loop_stack(size, shell, shell->command_stack, i);
        i = stack_return_separators_pos(shell->command_stack->command_type, \
        i, size);
    }
}