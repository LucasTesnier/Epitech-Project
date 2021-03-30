/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main
*/

#include "../include/proto.h"

int main(int ac, char *av[])
{
    if (ac < 2)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("BSQ manual utilisation :\n");
        my_putstr("\n./bsq ""path"" ""neutral"" ""obstacle"" ""square""\n");
        return (0);
    } else {
        if (ac != 5)
            return (84);
    }
    if (verification_params(av) == 84)
        return (84);
    if (bsq(av[1], av[2], av[3], av[4]) == 84)
        return (84);
    return (0);
}
