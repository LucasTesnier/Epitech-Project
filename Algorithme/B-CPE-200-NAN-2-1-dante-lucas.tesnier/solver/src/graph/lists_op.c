/*
** EPITECH PROJECT, 2021
** solver
** File description:
** lists_op
*/

#include "solver.h"

openlist_t *openlist_push(openlist_t *list, pair_t pair)
{
    openlist_t *tmp;

    if (!list) {
        list = create_open_list(create_pv(0.0, pair));
        return (list);
    }
    tmp = create_open_list(create_pv(0.0, pair));
    tmp->next = list;
    return (tmp);
}

void destroy_openlist(openlist_t *list)
{
    if (!list)
        return;
    if (!list->next)
        return (free(list));
    destroy_openlist(list->next);
}