/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** my_history_noad_create
*/

#include "struct.h"
#include "shell_loop.h"
#include "my.h"
#include <stdlib.h>
#include <stdbool.h>

my_hist_noad_t *my_hist_noad_create(char *line)
{
    my_hist_noad_t *new_noad = malloc(sizeof(my_hist_noad_t));

    if (!new_noad) {
        my_puterror("Error Malloc.\n");
        return (NULL);
    }
    new_noad->line = my_strdup(line);
    if (!new_noad->line) {
        my_puterror("Error Malloc.\n");
        free(new_noad);
        return (NULL);
    }
    new_noad->id = -1;
    new_noad->next = NULL;
    new_noad->prev = NULL;
    return (new_noad);
}

void my_hist_noad_destroy(my_hist_noad_t *noad)
{
    my_hist_noad_t *prev;
    my_hist_noad_t *next;

    if (!noad)
        return;
    prev = noad->prev;
    next = noad->next;
    if (prev)
        prev->next = next;
    if (next)
        next->prev = prev;
    free(noad->line);
    free(noad);
}