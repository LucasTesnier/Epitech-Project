/*
** EPITECH PROJECT, 2021
** solver
** File description:
** create_lists
*/

#include "solver.h"

bool **create_closed_list(maze_t *maze)
{
    bool **closed_list = malloc(sizeof(bool *) * maze->width_height.b);

    if (!closed_list)
        exit(84);
    for (int i = 0; i < maze->width_height.b; ++i)
        if (!(closed_list[i] = calloc(maze->width_height.a, sizeof(bool))))
            exit(84);
    return (closed_list);
}

void destroy_closed_list(bool **cl, maze_t *maze)
{
    for (int i = 0; i < maze->width_height.b; ++i)
        free(cl[i]);
    free(cl);
}

openlist_t *open_list_insert(openlist_t *self, pair_value_t *pv)
{
    openlist_t *tmp = self;

    if (!self) {
        self = create_open_list(pv);
        return (self);
    }
    while (tmp->next)
        tmp = tmp->next;
    if (!(tmp->next = malloc(sizeof(openlist_t))))
        exit(84);
    tmp = tmp->next;
    tmp->next = NULL;
    tmp->pv = pv;
    tmp->pop = delete_top;
    tmp->insert = open_list_insert;
    return (self);
}

openlist_t * delete_top(openlist_t *self)
{
    openlist_t *tmp = self->next;

    free(self);
    return (tmp);
}

openlist_t *create_open_list(pair_value_t *pair_val)
{
    openlist_t *new = malloc(sizeof(openlist_t));

    if (!new)
        exit(84);
    new->pv = pair_val;
    new->insert = open_list_insert;
    new->pop = delete_top;
    new->next = NULL;
    return (new);
}