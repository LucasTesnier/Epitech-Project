/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** my_lineory_list
*/

#include "my.h"
#include "struct.h"
#include "shell_loop.h"
#include <stdlib.h>

my_line_list_t *my_line_list_create(void)
{
    my_line_list_t *list = malloc(sizeof(my_line_list_t));

    if (!list) {
        my_puterror("Error Malloc.\n");
        return (NULL);
    }
    list->first = NULL;
    list->last = NULL;
    list->length = 0;
    list->next_id = 1;
    my_line_list_add_at_beginning(list, -1);
    return (list);
}

void my_line_list_destroy(my_line_list_t *list)
{
    my_line_noad_t *ptr;
    my_line_noad_t *n_to_free;

    if (!list)
        return;
    ptr = list->first;
    while (ptr) {
        n_to_free = ptr;
        ptr = ptr->next;
        my_line_noad_destroy(list, n_to_free);
    }
    free(list);
    list = NULL;
}