/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** function main
*/

#include "proto.h"

int main(int ac, char *argv[])
{
    if (ac != 2) {
        my_putstr("./my_screensaver: bad arguments: 0 ");
        my_putstr("given but 1 is required\nretry with -h");
        return (84);
    }
    if (screen_saver_start(argv[1]) == 84)
        return (84);
    return (0);
}
