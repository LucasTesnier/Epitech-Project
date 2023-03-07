/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** my_history_list
*/

#include "my.h"
#include "struct.h"
#include "shell_loop.h"
#include <stdlib.h>

my_hist_list_t *my_hist_list_create(void)
{
    my_hist_list_t *list = malloc(sizeof(my_hist_list_t));

    if (!list) {
        my_puterror("Error Malloc.\n");
        return (NULL);
    }
    list->first = NULL;
    list->last = NULL;
    list->length = 0;
    list->next_id = 1;
    return (list);
}

void my_hist_list_destroy(my_hist_list_t *list)
{
    my_hist_noad_t *ptr;
    my_hist_noad_t *n_to_free;

    if (!list)
        return;
    ptr = list->first;
    while (ptr) {
        n_to_free = ptr;
        ptr = ptr->next;
        my_hist_noad_destroy(n_to_free);
    }
    free(list);
}