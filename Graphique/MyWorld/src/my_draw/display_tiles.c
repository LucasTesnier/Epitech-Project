/*
** EPITECH PROJECT, 2021
** display_tiles
** File description:
** desc
*/

#include "my_world.h"

void display_tiles2(my_game_t *my_game, int i, int j, int type)
{
    sfConvexShape_setPoint(my_game->convexShape, 0, \
    my_iso_projection(i * my_game->my_map.display_size, j * \
    my_game->my_map.display_size, my_game->my_map.map_height[i][j], \
    my_game->my_map.angles));
    sfConvexShape_setPoint(my_game->convexShape, 1, \
    my_iso_projection((i + 1) * my_game->my_map.display_size, j *   \
    my_game->my_map.display_size, my_game->my_map.map_height[i + 1][j], \
    my_game->my_map.angles));
    sfConvexShape_setPoint(my_game->convexShape, 2, \
    my_iso_projection((i + 1) * my_game->my_map.display_size, (j + 1) * \
    my_game->my_map.display_size,   \
    my_game->my_map.map_height[i + 1][j + 1], my_game->my_map.angles));
    sfConvexShape_setPoint(my_game->convexShape, 3, \
    my_iso_projection(i * my_game->my_map.display_size, (j + 1) *   \
    my_game->my_map.display_size, my_game->my_map.map_height[i][j + 1], \
    my_game->my_map.angles));
}

void display_tiles(my_game_t *my_game, int i, int j, int type)
{
    sfConvexShape_setPosition(my_game->convexShape, my_game->my_map.pos);
    sfConvexShape_setPointCount(my_game->convexShape, 4);
    if (type != WATER) {
        sfConvexShape_setPoint(my_game->convexShape, 0, \
        my_game->my_map.vector[i][j]);
        sfConvexShape_setPoint(my_game->convexShape, 1, \
        my_game->my_map.vector[i + 1][j]);
        sfConvexShape_setPoint(my_game->convexShape, 2, \
        my_game->my_map.vector[i + 1][j + 1]);
        sfConvexShape_setPoint(my_game->convexShape, 3, \
        my_game->my_map.vector[i][j + 1]);
    } else {
        display_tiles2(my_game, i, j, type);
    }
    sfRenderWindow_drawConvexShape(my_game->my_window.window,   \
    my_game->convexShape, NULL);
}