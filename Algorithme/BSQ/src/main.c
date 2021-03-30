/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main
*/

#include "../include/proto.h"

int main(int ac, char *av[])
{
    if (ac != 2)
        return (84);
    if (bsq(av[1]) == 84)
        return (84);
    return (0);
}
