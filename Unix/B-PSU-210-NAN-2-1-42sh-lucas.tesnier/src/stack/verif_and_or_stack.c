/*
** EPITECH PROJECT, 2021
** verif_and_or_stack.c
** File description:
** 42sh
*/

#include "shell_loop.h"
#include "my.h"
#include <stdbool.h>

bool verif_simple_and_or(char *cmd, int i)
{
    if (cmd[i + 2] == ';' && cmd[i + 3] == ' ')
        return (false);
    if (cmd[i + 2] == '<' && cmd[i + 3] == ' ')
        return (false);
    if (cmd[i + 2] == '>' && cmd[i + 3] == ' ')
        return (false);
    if (cmd[i + 2] == '|' && cmd[i + 3] == ' ')
        return (false);
    if (cmd[i + 2] == '&' && cmd[i + 3] == ' ')
        return (false);
    return (true);
}

bool verif_after_and_or(char *cmd, int i)
{
    if (cmd[i + 1] == 0)
        return (false);
    else if (cmd[i + 1] != ' ')
        return (true);
    if (my_strlen(cmd) > (i + 4)) {
        if (verif_simple_and_or(cmd, i) == false)
            return (false);
    } if (my_strlen(cmd) > (i + 5)) {
        if (cmd[i + 2] == '|' && cmd[i + 3] == '|' && cmd[i + 4] == ' ')
            return (false);
        if (cmd[i + 2] == '>' && cmd[i + 3] == '>' && cmd[i + 4] == ' ')
            return (false);
        if (cmd[i + 2] == '<' && cmd[i + 3] == '<' && cmd[i + 4] == ' ')
            return (false);
    }
    return (true);
}

bool verif_and_or_stack(my_shell_t *shell, char *cmd)
{
    bool result = true;

    for (int i = 1; cmd[i] != '\0'; i++) {
        if ((cmd[i - 1] == '&' && cmd[i] == '&') || \
            (cmd[i - 1] == '|' && cmd[i] == '|'))
            result = verif_after_and_or(cmd, i);
        if (result == false) {
            my_puterror("Invalid null command.\n");
            shell->return_value = -1;
            return (false);
        }
    }
    return (true);
}