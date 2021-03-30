/*
** EPITECH PROJECT, 2021
** my_game_destroy
** File description:
** desc
*/

#include "my_world.h"

void my_game_destroy(my_game_t *my_game)
{
    my_window_destroy(&my_game->my_window);
    my_map_destroy(&my_game->my_map);
    sfConvexShape_destroy(my_game->convexShape);
}