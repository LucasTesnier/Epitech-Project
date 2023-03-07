/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main function
*/

#include "proto.h"

int main(int ac, char *argv[])
{
    bool is_perfect = false;

    if (ac < 3 || ac > 4) {
        write(1, "Invalid Argument\n", 17);
        return (84);
    }
    if (ac == 4)
        is_perfect = true;
    return (setup_lab(atoi(argv[1]), atoi(argv[2]), is_perfect));
}
