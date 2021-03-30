/*
** EPITECH PROJECT, 2020
** push_swap.c
** File description:
** all function for push_swap
*/

#include "../include/proto.h"

void concs(linked_list_t **lista, int *sizea, int *res, int *sres)
{
    rra(lista, sizea);
    add_ops(res, sres, 6);
}

void sort_three_next(linked_list_t **lista, int sizea, int *res, int *sres)
{
    if ((*lista)->data > (*lista)->next->data && (*lista)->next->data <= \
    (*lista)->next->next->data && (*lista)->next->next->data <= \
    (*lista)->data) {
        ra(lista, &sizea);
        res[*sres] = 6;
        *sres = *sres + 1;
    }
}

void sort_three_bis(linked_list_t **lista, int sizea, int *res, int *sres)
{
    if ((*lista)->data <= (*lista)->next->data && (*lista)->next->data > \
    (*lista)->next->next->data && (*lista)->next->next->data > \
    (*lista)->data) {
        sa(lista, &sizea);
        ra(lista, &sizea);
        res[*sres] = 1;
        *sres = *sres + 1;
        res[*sres] = 6;
        *sres = *sres + 1;
    }
    if ((*lista)->data <= (*lista)->next->data && (*lista)->next->data > \
    (*lista)->next->next->data && (*lista)->next->next->data <= \
    (*lista)->data) {
        rra(lista, &sizea);
        res[*sres] = 9;
        *sres = *sres + 1;
    }
}

void sort_three(linked_list_t **lista, int sizea, int *res, int *sres)
{
    if ((*lista)->data > (*lista)->next->data && (*lista)->next->data <= \
    (*lista)->next->next->data && (*lista)->next->next->data > \
    (*lista)->data) {
        sa(lista, &sizea);
        res[*sres] = 1;
        *sres = *sres + 1;
    }
    if ((*lista)->data > (*lista)->next->data && (*lista)->next->data > \
    (*lista)->next->next->data && (*lista)->next->next->data <= \
    (*lista)->data) {
        sa(lista, &sizea);
        rra(lista, &sizea);
        res[*sres] = 1;
        *sres = *sres + 1;
        res[*sres] = 9;
        *sres = *sres + 1;
    }
    sort_three_next(lista, sizea, res, sres);
    sort_three_bis(lista, sizea, res, sres);
}

int push_swap(int ac, char *argv[])
{
    linked_list_t *lista;
    linked_list_t *listb;
    int sizea = ac - 1;
    int sizeb = 0;
    int *res = malloc(sizeof(int) * (100000000));
    unsigned int sres = 0;
    int b = 0;
    int pos = 0;

    if (setup(ac, &lista, sizea, argv) == 0)
        return (0);
    while (sizea > 3) {
        linked_list_t *copy = lista;
        b = lista->data;
        pos = 0;
        for (int i = 0; i < sizea; i++, copy = copy->next)
            if (copy->data < b) {
                b = copy->data;
                pos = i;
            }
        if (pos == 0) {
            pb(&lista, &sizea, &listb, &sizeb);
            add_ops(res, &sres, 5);
        } else if (pos <= sizea / 2) {
            for (int i = 0; i < pos; i++)
                conc(&lista, &sizea, res, &sres);
        } else if (pos > sizea / 2)
            for (int i = sizea; i > pos; i--)
                concs(&lista, &sizea, res, &sres);
    }
    sort_three(&lista, sizea, res, &sres);
    int save = sizeb;
    test(save, res, sres);
}
