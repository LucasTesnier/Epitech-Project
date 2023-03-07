/*
** EPITECH PROJECT, 2021
** history-prompt
** File description:
** my_line_list_change_hist
*/

#include "struct.h"
#include "shell_loop.h"
#include <stdbool.h>
#include <stdlib.h>

bool my_line_list_change_older_hist(my_shell_t *shell)
{
    my_hist_noad_t *ptr;

    if (!shell->hist || !shell->hist->first)
        return true;
    if (shell->hist_id == 0)
        shell->temp_line = my_line_list_transform_to_line(shell->line);
    ptr = shell->hist->first;
    for (int i = 0; i < shell->hist_id && ptr; i++)
        ptr = ptr->next;
    if (!ptr)
        return true;
    erase_line(shell);
    free(shell->line);
    shell->line = my_line_list_create();
    for (int i = 0; ptr->line[i]; i++)
        my_line_list_add_before_cursor(shell->line, ptr->line[i]);
    write_line(shell);
    shell->hist_id++;
    return true;
}

bool my_line_list_change_newer_hist(my_shell_t *shell)
{
    my_hist_noad_t *ptr;

    if (!shell->hist || shell->hist_id <= 0)
        return true;
    free(shell->line);
    shell->line = my_line_list_create();
    if (shell->hist_id == 1) {
        for (int i = 0; shell->temp_line[i]; i++)
            my_line_list_add_before_cursor(shell->line, shell->temp_line[i]);
    } else {
        ptr = shell->hist->first;
        for (int i = 2; i < shell->hist_id && ptr; i++)
            ptr = ptr->next;
        if (!ptr)
            return true;
        for (int i = 0; ptr->line[i]; i++)
            my_line_list_add_before_cursor(shell->line, ptr->line[i]);
    }
    shell->hist_id--;
    return true;
}