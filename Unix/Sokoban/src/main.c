/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main function
*/

#include "proto.h"

int main(int ac, char *argv[])
{
    if (ac != 2) {
        my_putstr("Invalid Argument\n");
        return (84);
    }
    if (my_strcmp(argv[1], "-h") == 0) {
        my_putstr("USAGE\n     ./my_sokoban map\nDESCRIPTION\n     map  file");
        my_putstr(" representing the warehouse map, containing '#' for walls");
        my_putstr(",\n          'P' for the player, 'X' for boxes and 'O'");
        my_putstr("for storage locations.\n");
        return (0);
    }
    return (sokoban_setup(argv[1]));
}
