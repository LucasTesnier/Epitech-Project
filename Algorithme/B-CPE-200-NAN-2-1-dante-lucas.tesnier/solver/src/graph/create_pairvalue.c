/*
** EPITECH PROJECT, 2021
** solver
** File description:
** create_pairvalue
*/

#include "solver.h"

pair_value_t *create_pv(double f, pair_t ij)
{
    pair_value_t *new = malloc(sizeof(pair_value_t));

    if (!new)
        exit(84);
    new->pair = ij;
    new->f = f;
    return (new);
}
