/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main function
*/

#include "proto.h"

int main(int ac, char *argv[])
{
    if (ac != 3) {
        my_putstr("Invalid Argument\n");
        return (84);
    }
    return (setup_match(my_getnbr(argv[1]), my_getnbr(argv[2])));
}
