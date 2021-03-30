/*
** EPITECH PROJECT, 2021
** in_window
** File description:
** desc
*/

#include "my_world.h"

int in_window2(my_game_t *game, int i, int j)
{
    if (game->my_map.vector[i][j + 1].x + game->my_map.pos.x <  \
        sfRenderWindow_getSize(game->my_window.window).x && \
        game->my_map.vector[i][j + 1].y + game->my_map.pos.y <  \
        sfRenderWindow_getSize(game->my_window.window).y && \
        game->my_map.vector[i][j + 1].x + game->my_map.pos.x > 0 && \
        game->my_map.vector[i][j + 1].y + game->my_map.pos.y > 0)
        return (1);
    if (game->my_map.vector[i + 1][j + 1].x + game->my_map.pos.x <  \
        sfRenderWindow_getSize(game->my_window.window).x && \
        game->my_map.vector[i + 1][j + 1].y + game->my_map.pos.y <  \
        sfRenderWindow_getSize(game->my_window.window).y && \
        game->my_map.vector[i + 1][j + 1].x + game->my_map.pos.x > 0 && \
        game->my_map.vector[i + 1][j + 1].y + game->my_map.pos.y > 0)
        return (1);
    return (0);
}

int in_window(my_game_t *game, int i, int j)
{
    if (game->my_map.vector[i][j].x + game->my_map.pos.x <  \
        sfRenderWindow_getSize(game->my_window.window).x && \
        game->my_map.vector[i][j].y + game->my_map.pos.y <  \
        sfRenderWindow_getSize(game->my_window.window).y && \
        game->my_map.vector[i][j].x + game->my_map.pos.x > 0 && \
        game->my_map.vector[i][j].y + game->my_map.pos.y > 0)
        return (1);
    if (game->my_map.vector[i + 1][j].x + game->my_map.pos.x <  \
        sfRenderWindow_getSize(game->my_window.window).x && \
        game->my_map.vector[i + 1][j].y + game->my_map.pos.y <  \
        sfRenderWindow_getSize(game->my_window.window).y && \
        game->my_map.vector[i + 1][j].x + game->my_map.pos.x > 0 && \
        game->my_map.vector[i + 1][j].y + game->my_map.pos.y > 0)
        return (1);
    return (in_window2(game, i, j));
}