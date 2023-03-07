/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** fill_stack_classic
*/

#include "struct.h"
#include "my.h"
#include "shell_loop.h"
#include <stdlib.h>
#include <stdbool.h>

int fill_stack(my_shell_t *shell, my_command_t *command_stack, char *command)
{
    char *clean_command = stack_clean_command(command);

    if (clean_command[0] == '\0' \
    || verif_and_or_stack(shell, clean_command) == false) {
        free(clean_command);
        return (-1);
    }
    fill_stack_separators(command_stack, clean_command);
    return (0);
}