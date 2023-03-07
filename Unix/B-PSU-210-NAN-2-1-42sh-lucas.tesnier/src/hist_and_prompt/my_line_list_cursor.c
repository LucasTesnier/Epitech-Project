/*
** EPITECH PROJECT, 2021
** history-prompt
** File description:
** my_line_list_cursor
*/

#include "my.h"
#include "struct.h"
#include "shell_loop.h"

my_line_noad_t *get_cursor(my_line_list_t *line)
{
    my_line_noad_t *cursor;

    if (!line)
        return NULL;
    cursor = line->last;
    while (cursor && cursor->c != -1)
        cursor = cursor->prev;
    if (!cursor)
        return NULL;
    return cursor;
}

bool my_line_list_move_cursor_to_left(my_line_list_t *list)
{
    my_line_noad_t *cursor = get_cursor(list);
    my_line_noad_t *tmp;

    if (!list || !cursor || !cursor->prev)
        return false;
    tmp = cursor->next;
    cursor->next = cursor->prev;
    cursor->prev = cursor->prev->prev;
    if (cursor->prev)
        cursor->prev->next = cursor;
    cursor->next->prev = cursor;
    cursor->next->next = tmp;
    if (tmp)
        tmp->prev = cursor->next;
    if (!cursor->next->next)
        list->last = cursor->next;
    if (!cursor->prev)
        list->first = cursor;
    return true;
}

bool my_line_list_move_cursor_to_right(my_line_list_t *list)
{
    my_line_noad_t *cursor = get_cursor(list);
    my_line_noad_t *tmp;

    if (!list || !cursor || !cursor->next)
        return false;
    tmp = cursor->next;
    cursor->next->prev = cursor->prev;
    cursor->prev = tmp;
    cursor->next = tmp->next;
    tmp->next = cursor;
    if (!cursor->next)
        list->last = cursor;
    else
        cursor->next->prev = cursor;
    if (!tmp->prev)
        list->first = tmp;
    else
        tmp->prev->next = tmp;
    return true;
}