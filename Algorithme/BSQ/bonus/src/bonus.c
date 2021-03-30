/*
** EPITECH PROJECT, 2020
** bonus.c
** File description:
** all bonus fonctions
*/

#include "../include/proto.h"

int verification_params(char *argv[])
{
    if (argv[2][0] == argv[3][0] || argv[2][0] == argv[4][0] || argv[3][0] == \
    argv[4][0]) {
        my_putstr("Error, params equal");
        return (84);
    }
    for (int i = 2; i < 5; i++) {
        if (argv[i][0] < 32 || argv[i][0] == 127) {
            my_putstr("Error, non printable char");
            return (84);
        }
    }
    return (0);
}
