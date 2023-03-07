/*
** EPITECH PROJECT, 2021
** history-prompt
** File description:
** my_line_list_new_line_check
*/

#include "struct.h"
#include "my.h"
#include <stdbool.h>

bool new_line_mandatory_exec(my_shell_t *shell, char *line)
{
    if (!shell || !line || !line[0])
        return false;
    for (int i = 0; line[i]; i++)
        if (line[i] < 32 || line[i] >= 127)
            return false;
    return true;
}

bool new_line_mandatory_hist(my_shell_t *shell, char *line)
{
    if (!shell || !line || !line[0])
        return false;
    for (int i = 0; line[i]; i++)
        if (line[i] < 32 || line[i] >= 127)
            return false;
    if (shell->hist && shell->hist->first)
        if (my_strcmp(line, shell->hist->first->line) == 0)
            return false;
    return true;
}