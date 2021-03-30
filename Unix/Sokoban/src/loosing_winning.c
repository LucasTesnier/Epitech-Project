/*
** EPITECH PROJECT, 2021
** loosing_winning.c
** File description:
** loosing and winning detections
*/

#include "proto.h"

void verif_win(game_t *game)
{
    pos_t pos = {0, 0};

    game->is_winning = 1;
    while (1) {
        if (game->map.cases[pos.y][pos.x].is_storage == true && \
        game->map.cases[pos.y][pos.x].box == false) {
            game->is_winning = 0;
            break;
        }
        pos.x += 1;
        if (game->map.cases[pos.y][pos.x].end == true) {
            pos.x = 0;
            pos.y += 1;
        }
        if (game->map.cases[pos.y][0].end == true)
            break;
    }
}

bool box_is_stuck_down(game_t *game, pos_t pos)
{
    if (game->map.cases[pos.y + 1][pos.x].wall == true && game->map.cases\
    [pos.y][pos.x + 1].box == true) {
        return (true);
    }
    if (game->map.cases[pos.y + 1][pos.x].wall == true && game->map.cases\
    [pos.y][pos.x - 1].box == true) {
        return (true);
    }
    if (game->map.cases[pos.y - 1][pos.x].wall == true && game->map.cases\
    [pos.y][pos.x + 1].box == true) {
        return (true);
    }
    if (game->map.cases[pos.y - 1][pos.x].wall == true && game->map.cases\
    [pos.y][pos.x - 1].box == true) {
        return (true);
    }
    return (false);
}

bool box_is_stuck_up(game_t *game, pos_t pos)
{
    if (game->map.cases[pos.y + 1][pos.x].box == true && game->map.cases\
    [pos.y][pos.x + 1].wall == true) {
        return (true);
    }
    if (game->map.cases[pos.y + 1][pos.x].box == true && game->map.cases\
    [pos.y][pos.x - 1].wall == true) {
        return (true);
    }
    if (game->map.cases[pos.y - 1][pos.x].box == true && game->map.cases\
    [pos.y][pos.x + 1].wall == true) {
        return (true);
    }
    if (game->map.cases[pos.y - 1][pos.x].box == true && game->map.cases\
    [pos.y][pos.x - 1].wall == true) {
        return (true);
    }
    return (box_is_stuck_down(game, pos));
}

bool box_is_stuck(game_t *game, pos_t pos)
{
    if (game->map.cases[pos.y + 1][pos.x].wall == true && game->map.cases\
    [pos.y][pos.x + 1].wall == true) {
        return (true);
    }
    if (game->map.cases[pos.y + 1][pos.x].wall == true && game->map.cases\
    [pos.y][pos.x - 1].wall == true) {
        return (true);
    }
    if (game->map.cases[pos.y - 1][pos.x].wall == true && game->map.cases\
    [pos.y][pos.x + 1].wall == true) {
        return (true);
    }
    if (game->map.cases[pos.y - 1][pos.x].wall == true && game->map.cases\
    [pos.y][pos.x - 1].wall == true) {
        return (true);
    }
    return (box_is_stuck_up(game, pos));
}

void verif_loose(game_t *game)
{
    pos_t pos = {0, 0};

    game->is_winning = 2;
    while (1) {
        if (game->map.cases[pos.y][pos.x].box == true && \
        box_is_stuck(game, pos) == false) {
            game->is_winning = 0;
            break;
        }
        pos.x += 1;
        if (game->map.cases[pos.y][pos.x].end == true) {
            pos.x = 0;
            pos.y += 1;
        }
        if (game->map.cases[pos.y][0].end == true)
            break;
    }
}
