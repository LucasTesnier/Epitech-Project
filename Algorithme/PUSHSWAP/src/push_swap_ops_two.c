/*
** EPITECH PROJECT, 2020
** push_swap_ops_two.c
** File description:
** all function for ops
*/

#include "../include/proto.h"

int sb(linked_list_t **lista, int *sizea)
{
    int save = 0;
    int save2 = 0;

    if (*sizea < 2)
        return (84);
    save = (*lista)->data;
    save2 = (*lista)->next->data;
    (*lista)->data = save2;
    (*lista)->next->data = save;
    return (0);
}

int sa(linked_list_t **lista, int *sizea)
{
    int save = 0;
    int save2 = 0;

    if (*sizea < 2)
        return (84);
    save = (*lista)->data;
    save2 = (*lista)->next->data;
    (*lista)->data = save2;
    (*lista)->next->data = save;
    return (0);
}

int rrr(linked_list_t **lista, int *sizea, linked_list_t **listb, int *sizeb)
{
    if (rra(lista, sizea) == 84)
        return (0);
    if (rrb(listb, sizeb) == 84)
        return (0);
    return (0);
}

int rrb(linked_list_t **listb, int *sizeb)
{
    *listb = (*listb)->prev;
}

int rra(linked_list_t **lista, int *sizea)
{
    *lista = (*lista)->prev;
}
