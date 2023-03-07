/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** return_position_stack
*/

#include "struct.h"
#include "my.h"
#include "shell_loop.h"

int stack_return_classic_pos(command_type_e *type, int pos, int size)
{
    for (int i = pos + 1; i < size; i++) {
        if (type[i] == CLASSIC)
            return (i);
        if (type[i] == SEPARATORS)
            return (-1);
    }
    return (-1);
}

int stack_return_separators_pos(command_type_e *type, int pos, int size)
{
    for (int i = pos + 1; i < size; i++) {
        if (type[i] == SEPARATORS)
            return (i);
    }
    return (size);
}