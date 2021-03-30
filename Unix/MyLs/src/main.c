/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** function main
*/

#include "proto.h"

int main(int ac, char *argv[])
{
    if (ac < 1) {
        my_putstr("Invalid number of argument");
        return (84);
    }
    if (my_ls_receiver(ac, argv) == 84)
        return (84);
    return (0);
}
