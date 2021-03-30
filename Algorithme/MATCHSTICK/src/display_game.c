/*
** EPITECH PROJECT, 2021
** display_game.c
** File description:
** display game
*/

#include "proto.h"

void display_map_stick(game_t *game, int i)
{
    for (int j = 0; j < (game->lines - 1) * 2 + 1; j++) {
        if (game->map[i][j] == 0)
            my_putchar(' ');
        if (game->map[i][j] == 1)
            my_putchar('|');
    }
}

void display_map(game_t *game)
{
    for (int i = 0; i < (game->lines - 1) * 2 + 3; i++)
        my_putchar('*');
    my_putchar('\n');
    for (int i = 0; i < game->lines; i++) {
        my_putchar('*');
        display_map_stick(game, i);
        my_putchar('*');
        my_putchar('\n');
    }
    for (int i = 0; i < (game->lines - 1) * 2 + 3; i++)
        my_putchar('*');
    my_putchar('\n');
}
