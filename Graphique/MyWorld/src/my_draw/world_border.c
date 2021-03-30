/*
** EPITECH PROJECT, 2021
** world border
** File description:
** desc
*/

#include "my_world.h"

void world_border2(my_game_t *my_game, sfConvexShape *convex)
{
    sfRenderWindow_drawConvexShape(my_game->my_window.window, convex, NULL);
    sfConvexShape_setPoint(convex, 1,   \
    my_iso_projection(my_game->my_map.size.x *  \
    my_game->my_map.display_size, 0, -200, my_game->my_map.angles));
    sfConvexShape_setPoint(convex, 0,   \
    my_iso_projection(my_game->my_map.size.x *  \
    my_game->my_map.display_size, my_game->my_map.size.y *  \
    my_game->my_map.display_size, -200, my_game->my_map.angles));
    for (int i = 0; i < my_game->my_map.size.y; i++) {
        sfConvexShape_setPoint(convex, i + 2,   \
        my_game->my_map.vector[my_game->my_map.size.x - 1][i]);
    }
}

void world_border(my_game_t *my_game)
{
    sfConvexShape *convex = sfConvexShape_create();

    sfConvexShape_setPosition(convex, my_game->my_map.pos);
    sfConvexShape_setPointCount(convex, my_game->my_map.size.x + 2);
    sfConvexShape_setFillColor(convex, (sfColor){103, 51, 0, 255});
    sfConvexShape_setPoint(convex, 1, my_iso_projection(0,  \
    my_game->my_map.size.y * my_game->my_map.display_size, -200,    \
    my_game->my_map.angles));
    sfConvexShape_setPoint(convex, 0,   \
    my_iso_projection(my_game->my_map.size.x *  \
    my_game->my_map.display_size, my_game->my_map.size.y *  \
    my_game->my_map.display_size, -200, my_game->my_map.angles));
    for (int i = 0; i < my_game->my_map.size.x; i++) {
        sfConvexShape_setPoint(convex, i + 2,   \
        my_game->my_map.vector[i][my_game->my_map.size.y - 1]);
    }
    world_border2(my_game, convex);
    sfRenderWindow_drawConvexShape(my_game->my_window.window,   \
    convex, NULL);
}