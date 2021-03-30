/*
** EPITECH PROJECT, 2020
** push_swap_ops.c
** File description:
** all operation a and b
*/

#include "../include/proto.h"

void delete_node(linked_list_t **from)
{
    if (*from == (*from)->next)
        *from = NULL;
    else {
        (*from)->prev->next = (*from)->next;
        (*from)->next->prev = (*from)->prev;
        (*from) = (*from)->next;
    }
}

int pb(linked_list_t **listb, int *sizeb, linked_list_t **lista, int *sizea)
{
    linked_list_t *save;
    linked_list_t *stock;

    if (*sizeb < 1)
        return (84);
    save = *listb;
    delete_node(listb);
    if (*lista) {
        stock = (*lista)->prev;
        (*lista) = (*lista)->prev;
    } else {
        *lista = save;
        (*lista)->next = *lista;
        (*lista)->prev = *lista;
    }
    *sizeb = *sizeb - 1;
    *sizea = *sizea + 1;
}

int pa(linked_list_t **lista, int *sizea, linked_list_t **listb, int *sizeb)
{
    linked_list_t *save;
    linked_list_t *stock;

    if (*sizeb < 1)
        return (84);
    save = *listb;
    delete_node(listb);
    if (*lista) {
        stock = (*lista)->prev;
        (*lista)->prev = save;
        (*lista)->prev->next = stock;
        (*lista)->prev->prev->next = save;
        (*lista) = (*lista)->prev;
    } else {
        *lista = save;
        (*lista)->next = *lista;
        (*lista)->prev = *lista;
    }
    *sizeb = *sizeb - 1;
    *sizea = *sizea + 1;
}

int sc(linked_list_t **lista, int *sizea, linked_list_t **listb, int *sizeb)
{
    if (sa(lista, sizea) == 84)
        return (0);
    if (sb(listb, sizeb) == 84)
        return (0);
}

void hope(linked_list_t *lista, int *b, int *pos)
{
    *b = lista->data;
    *pos = 0;
}
