/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** all function for main
*/

#include "../include/proto.h"

int main(int ac, char *argv[])
{
    if (ac < 2) {
        write(2, "To few arguments", 16);
        return (84);
    }
    if (verif_integer(ac, argv) == 84)
        return (84);
    if (push_swap(ac, argv) == 84)
        return (84);
    return (0);
}
