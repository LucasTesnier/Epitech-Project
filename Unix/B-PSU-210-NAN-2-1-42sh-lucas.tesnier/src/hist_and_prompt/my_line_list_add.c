/*
** EPITECH PROJECT, 2021
** history-prompt
** File description:
** my_line_list_add
*/

#include "struct.h"
#include "shell_loop.h"
#include <stdbool.h>
#include <stdlib.h>

bool my_line_list_add_at_beginning(my_line_list_t *list, char c)
{
    my_line_noad_t *new_noad;

    if (!list)
        return false;
    new_noad = my_line_noad_create(c);
    if (!new_noad)
        return false;
    new_noad->next = list->first;
    if (new_noad->next)
        new_noad->prev = new_noad->next->prev;
    else
        new_noad->prev = NULL;
    list->first = new_noad;
    if (!list->last)
        list->last = new_noad;
    new_noad->id = list->next_id;
    list->next_id++;
    list->length++;
    return true;
}

bool my_line_list_add_before_cursor(my_line_list_t *list, char c)
{
    my_line_noad_t *new_noad;
    my_line_noad_t *ptr;

    if (!list || (new_noad = my_line_noad_create(c)) == NULL)
        return false;
    ptr = list->last;
    while (ptr && ptr->c != -1)
        ptr = ptr->prev;
    if (!ptr)
        return false;
    new_noad->next = ptr;
    new_noad->prev = ptr->prev;
    if (new_noad->prev)
        new_noad->prev->next = new_noad;
    else
        list->first = new_noad;
    ptr->prev = new_noad;
    new_noad->id = list->next_id;
    list->next_id++;
    list->length++;
    return true;
}

bool my_line_list_add_after_cursor(my_line_list_t *list, char c)
{
    my_line_noad_t *new_noad;
    my_line_noad_t *ptr;

    if (!list || (new_noad = my_line_noad_create(c)) == NULL)
        return false;
    ptr = list->last;
    while (ptr && ptr->c != -1)
        ptr = ptr->prev;
    if (!ptr)
        return false;
    new_noad->next = ptr->next;
    new_noad->prev = ptr;
    if (!new_noad->next)
        list->last = new_noad;
    else
        new_noad->next->prev = new_noad;
    ptr->next = new_noad;
    new_noad->id = list->next_id;
    list->next_id++;
    list->length++;
    return true;
}

bool my_line_list_add_at_end(my_line_list_t *list, char c)
{
    my_line_noad_t *new_noad;

    if (!list)
        return false;
    new_noad = my_line_noad_create(c);
    if (!new_noad)
        return false;
    new_noad->prev = list->last;
    if (new_noad->prev)
        new_noad->prev = new_noad->prev->next;
    else
        new_noad->next = NULL;
    list->last = new_noad;
    if (!list->first)
        list->first = new_noad;
    new_noad->id = list->next_id;
    list->next_id++;
    list->length++;
    return true;
}