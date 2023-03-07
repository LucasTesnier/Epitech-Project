/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** my_lineroy_list_tools
*/

#include "my.h"
#include "struct.h"
#include "shell_loop.h"
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>

char *my_line_list_transform_to_line(my_line_list_t *list)
{
    char *new_line;
    int line_ptr = 0;
    my_line_noad_t *ptr;

    if (!list)
        return NULL;
    new_line = my_calloc_char(sizeof(char), list->length, 0);
    if (!new_line)
        return NULL;
    ptr = list->first;
    while (ptr) {
        if (ptr->c != -1 || \
        (ptr->c == '\n' && ptr->prev && ptr->prev->c == -1)) {
            new_line[line_ptr] = ptr->c;
            line_ptr++;
        }
        ptr = ptr->next;
    }
    return (new_line);
}

void my_line_list_delete_before_cursor(my_line_list_t *line)
{
    my_line_noad_t *ptr;

    if (!line)
        return;
    ptr = line->last;
    while (ptr && ptr->c != -1)
        ptr = ptr->prev;
    if (!ptr || !ptr->prev)
        return;
    my_line_noad_destroy(line, ptr->prev);
}

void erase_line(my_shell_t *shell)
{
    my_line_noad_t *ptr;

    if (!shell->line)
        return;
    if (shell->prompt)
        for (int i = 0; shell->prompt[i]; i++)
            write(1, "\b \b", 3);
    ptr = shell->line->first;
    while (ptr) {
        if (ptr->c != -1)
            write(1, "\b \b", 3);
        ptr = ptr->next;
    }
}

void write_line(my_shell_t *shell)
{
    my_line_noad_t *ptr;

    if (!shell->line)
        return;
    shell->prompt = get_prompt(shell);
    if (shell->prompt)
        my_putstr(shell->prompt);
    ptr = shell->line->first;
    while (ptr) {
        if (ptr->c != -1)
            write(1, &ptr->c, 1);
        ptr = ptr->next;
    }
}

char *my_line_list_get_auto_completion_line(my_line_list_t *line)
{
    my_line_noad_t *ptr;
    char *line_auto = my_calloc_char(sizeof(char), 1000, 0);

    if (!line_auto) {
        my_puterror("Error Malloc.\n");
        exit(84);
    }
    if (!line)
        return 0;
    ptr = line->last;
    while (ptr && ptr->c != -1)
        ptr = ptr->prev;
    if (!ptr || !ptr->prev)
        return 0;
    ptr = ptr->prev;
    for (int i = 0; ptr && ptr->c != ' '; i++) {
        line_auto[i] = ptr->c;
        ptr = ptr->prev;
    }
    my_revstr(line_auto);
    return (line_auto);
}