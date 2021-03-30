/*
** EPITECH PROJECT, 2021
** make_shape
** File description:
** desc
*/

#include "my_world.h"

int make_shape(my_game_t *my_game, int i, int j)
{
    if (in_window(my_game, i, j) != 1) {
        return (-1);
    }
    sfConvexShape_setTexture(my_game->convexShape,  \
    my_game->my_sprite[my_game->my_map.texture_name[i][j]].texture, sfTrue);
    sfConvexShape_setOutlineColor(my_game->convexShape, sfGreen);
    shadow(my_game, i, j);
    display_tiles(my_game, i, j, GRASS);
    if (my_game->my_map.map_height[i][j] < 0) {
        sfConvexShape_setTexture(my_game->convexShape,  \
        my_game->my_sprite[WATER].texture, sfTrue);
        sfConvexShape_setFillColor(my_game->convexShape,    \
        (sfColor){255, 255, 255, 150});
        sfConvexShape_setOutlineColor(my_game->convexShape, \
        (sfColor){0, 0, 0, 0});
        display_tiles(my_game, i, j, WATER);
    }
    return (0);
}