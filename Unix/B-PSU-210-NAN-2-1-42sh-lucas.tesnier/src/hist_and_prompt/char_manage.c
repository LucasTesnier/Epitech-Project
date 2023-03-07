/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** char_manage
*/

#include "struct.h"
#include "shell_loop.h"
#include <stdlib.h>

char *c_manage_2(my_shell_t *shell, char c)
{
    char *cmd = 0;

    if ((cmd = check_new_line(shell, c)) != NULL)
        return cmd;
    if (check_backspace(shell, c))
        return NULL;
    if (check_ctrl_d(shell, c))
        return NULL;
    if (check_escape_sequence(shell, c))
        return NULL;
    if (check_auto_completion(shell, c))
        return NULL;
    return NULL;
}