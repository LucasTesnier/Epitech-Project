/*
** EPITECH PROJECT, 2021
** setup_cases.c
** File description:
** setup cases functions
*/

#include "proto.h"

void set_false_case(pos_t pos, game_t *game)
{
    game->map.cases[pos.y][pos.x].end = false;
    game->map.cases[pos.y][pos.x].pos = pos;
    game->map.cases[pos.y][pos.x].empty = false;
    game->map.cases[pos.y][pos.x].box = false;
    game->map.cases[pos.y][pos.x].player = false;
    game->map.cases[pos.y][pos.x].wall = false;
    game->map.cases[pos.y][pos.x].is_storage = false;
}

void set_true_case(pos_t pos, game_t *game, char *buffer, int i)
{
    if (buffer[i] == ' ')
        game->map.cases[pos.y][pos.x].empty = true;
    if (buffer[i] == 'X')
        game->map.cases[pos.y][pos.x].box = true;
    if (buffer[i] == 'P')
        game->map.cases[pos.y][pos.x].player = true;
    if (buffer[i] == '#')
        game->map.cases[pos.y][pos.x].wall = true;
    if (buffer[i] == 'O') {
        game->map.cases[pos.y][pos.x].is_storage = true;
        game->map.cases[pos.y][pos.x].empty = true;
    }
}

void filling_cases(game_t *game, char *buffer)
{
    pos_t pos = {0, 0};

    for (int i = 0; buffer[i]; i++) {
        if (buffer[i] == '\n') {
            set_false_case(pos, game);
            game->map.cases[pos.y][pos.x].end = true;
            pos.x = 0;
            pos.y += 1;
        } else {
            set_false_case(pos, game);
            set_true_case(pos, game, buffer, i);
            pos.x += 1;
        }
    }
    game->map.cases[pos.y][pos.x].end = true;
}
