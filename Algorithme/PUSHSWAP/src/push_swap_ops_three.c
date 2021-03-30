/*
** EPITECH PROJECT, 2020
** push_swpa_ops_three.c
** File description:
** all function for ops
*/

#include "../include/proto.h"

int rr(linked_list_t **lista, int *sizea, linked_list_t **listb, int *sizeb)
{
    if (ra(lista, sizea) == 84)
        return (0);
    if (rb(listb, sizeb) == 84)
        return (0);
    return (0);
}

int ra(linked_list_t **lista, int *sizea)
{
    *lista = (*lista)->next;
}

int rb(linked_list_t **listb, int *sizeb)
{
    *listb = (*listb)->next;
}
