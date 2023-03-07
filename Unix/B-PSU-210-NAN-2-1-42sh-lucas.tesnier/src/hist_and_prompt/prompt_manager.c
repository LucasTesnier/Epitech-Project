/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** prompt_manager
*/

#include "struct.h"
#include "shell_loop.h"
#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *check_new_line(my_shell_t *shell, char c)
{
    char *new_line;

    if (c != '\n')
        return NULL;
    write(1, &c, 1);
    new_line = my_line_list_transform_to_line(shell->line);
    if (new_line_mandatory_hist(shell, new_line))
        my_hist_list_add_at_beginning(shell->hist, new_line);
    free(shell->line);
    shell->line = my_line_list_create();
    shell->hist_id = 0;
    if (shell->temp_line) {
        free(shell->temp_line);
        shell->temp_line = 0;
    }
    if (new_line_mandatory_exec(shell, new_line))
        return new_line;
    write_line(shell);
    return NULL;
}

bool check_backspace(my_shell_t *shell, char c)
{
    if (c != 127 && c != 8)
        return false;
    if (shell->line && shell->line->length > 1) {
        write(1, "\b \b", 3);
        my_line_list_delete_before_cursor(shell->line);
    }
    return true;
}

bool check_ctrl_d(my_shell_t *shell, char c)
{
    if (c != 4)
        return false;
    write(STDIN_FILENO, "\b\n", 2);
    my_putstr("exit\n");
    tcsetattr(0, TCSANOW, &shell->old);
    exit(0);
    return true;
}

bool check_escape_sequence(my_shell_t *shell, char c)
{
    char c_a;
    char c_b;

    if (c != 27)
        return false;
    read(0, &c_a, 1);
    read(0, &c_b, 1);
    if (c_a == 91 && c_b == 65) {
        my_line_list_change_older_hist(shell);
    }
    if (c_a == 91 && c_b == 66) {
        erase_line(shell);
        my_line_list_change_newer_hist(shell);
        write_line(shell);
    }
    return true;
}

bool check_auto_completion(my_shell_t *shell, char c)
{
    if (c != 9)
        return false;
    write(1, "\n", 1);
    auto_completion(my_line_list_get_auto_completion_line(shell->line), \
    shell->env);
    write_line(shell);
    return (true);
}