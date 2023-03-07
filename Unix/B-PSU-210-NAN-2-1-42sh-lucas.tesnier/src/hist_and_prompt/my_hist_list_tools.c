/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** my_histroy_list_tools
*/

#include "my.h"
#include "struct.h"
#include "shell_loop.h"
#include <stdbool.h>

bool my_hist_list_add_at_beginning(my_hist_list_t *list, char *line)
{
    my_hist_noad_t *new_noad;

    if (!list)
        return false;
    new_noad = my_hist_noad_create(line);
    if (!new_noad)
        return false;
    new_noad->next = list->first;
    list->first = new_noad;
    if (new_noad->next)
        new_noad->next->prev = new_noad;
    else
        list->last = new_noad;
    new_noad->id = list->next_id;
    list->next_id++;
    list->length++;
    return true;
}