/*
** EPITECH PROJECT, 2021
** moove.c
** File description:
** mooving players and box
*/

#include "proto.h"

bool moove_box(game_t *game, int x, int y, pos_t pos)
{
    pos.x -= x;
    pos.y -= y;
    if (game->map.cases[pos.y - y][pos.x - x].empty == true) {
        game->map.cases[pos.y - y][pos.x - x].box = true;
        game->map.cases[pos.y - y][pos.x - x].empty = false;
        game->map.cases[pos.y][pos.x].box = false;
        game->map.cases[pos.y][pos.x].empty = true;
        return (true);
    }
    return (false);
}

void moove_player_to_empty(game_t *game, int x, int y, pos_t pos)
{
    game->map.cases[pos.y - y][pos.x - x].player = true;
    game->map.cases[pos.y - y][pos.x - x].empty = false;
    game->map.cases[pos.y][pos.x].player = false;
    game->map.cases[pos.y][pos.x].empty = true;
}

pos_t setup_pos(game_t *game)
{
    pos_t pos = {0, 0};

    while (1) {
        if (game->map.cases[pos.y][pos.x].player == true)
            break;
        pos.x += 1;
        if (game->map.cases[pos.y][pos.x].end == true) {
            pos.x = 0;
            pos.y += 1;
        }
    }
    return (pos);
}

void moove_player(game_t *game, int x, int y)
{
    pos_t pos = setup_pos(game);

    if (pos.y - y >= 0 && pos.x - x >= 0 && \
    game->map.cases[pos.y - y][pos.x - x].empty == true) {
        moove_player_to_empty(game, x, y, pos);
        return;
    }
    if (pos.y - y >= 0 && pos.x - x >= 0 && \
    game->map.cases[pos.y - y][pos.x - x].box == true) {
        if (moove_box(game, x, y, pos) == true) {
            moove_player(game, x, y);
            return;
        }
    }
}

int action_gestion(int action, game_t *game, char *buffer)
{
    if (action == ' ') {
        *game = setup_struct(buffer);
    }
    if (action == KEY_UP)
        moove_player(game, 0, 1);
    if (action == KEY_DOWN)
        moove_player(game, 0, -1);
    if (action == KEY_RIGHT)
        moove_player(game, -1, 0);
    if (action == KEY_LEFT)
        moove_player(game, 1, 0);
}
