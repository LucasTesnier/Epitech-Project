/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** my_lineory_noad_create
*/

#include "struct.h"
#include "shell_loop.h"
#include "my.h"
#include <stdlib.h>
#include <stdbool.h>

my_line_noad_t *my_line_noad_create(char c)
{
    my_line_noad_t *new_noad = malloc(sizeof(my_line_noad_t));

    if (!new_noad) {
        my_puterror("Error Malloc.\n");
        return (NULL);
    }
    new_noad->c = c;
    new_noad->id = -1;
    new_noad->next = NULL;
    new_noad->prev = NULL;
    return (new_noad);
}

void my_line_noad_destroy(my_line_list_t *line, my_line_noad_t *noad)
{
    my_line_noad_t *prev;
    my_line_noad_t *next;

    if (!noad)
        return;
    prev = noad->prev;
    next = noad->next;
    if (prev)
        prev->next = next;
    else
        line->first = noad->next;
    if (next)
        next->prev = prev;
    else
        line->last = noad->prev;
    line->length--;
    free(noad);
    noad = NULL;
}