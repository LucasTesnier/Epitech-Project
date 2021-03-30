/*
** EPITECH PROJECT, 2020
** push_swap_verif.c
** File description:
** all verification funtctions
*/

#include "../include/proto.h"

int verif_integer(int ac, char *argv[])
{
    for (int i = 1; i < ac; i++) {
        for (int j = 0; j < my_strlen(argv[i]); j++) {
            if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '-') {
                write(2, "Invalid argument", 16);
                return (84);
            }
        }
    }
    return (0);
}

void test(int save, int *res, unsigned int sres)
{
    for (int i = 0; i < save; i++) {
        res[sres] = 4;
        sres++;
    }
    display_res(res, sres);
}

void add_ops(int *res, unsigned int *sres, int data)
{
    res[*sres] = data;
    *sres = *sres + 1;
}

void conc(linked_list_t **lista, int *sizea, int *res, int *sres)
{
    ra(lista, sizea);
    add_ops(res, sres, 9);
}
