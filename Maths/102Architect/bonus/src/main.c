/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** all function for main
*/

#include "../include/proto.h"

int main(int ac, char *argv[])
{
    if (ac < 4) {
        printf("To few arguments");
        return (84);
    }
    window(ac, argv);
    return (0);
}
