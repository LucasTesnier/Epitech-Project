/*
** EPITECH PROJECT, 2021
** is_placable
** File description:
** desc
*/

#include "my_world.h"

int is_placable(my_game_t *my_game, int i, int j)
{
    if (!(my_game->my_map.map_height[i][j] >= 0))
        return (0);
    if (!(my_game->my_map.map_height[i][j] >=   \
        my_game->my_map.map_height[i + 1][j] - 5 && \
        my_game->my_map.map_height[i][j] <= \
        my_game->my_map.map_height[i + 1][j] + 5))
        return (0);
    if (!(my_game->my_map.map_height[i][j] >=   \
        my_game->my_map.map_height[i][j + 1] - 5 && \
        my_game->my_map.map_height[i][j] <= \
        my_game->my_map.map_height[i][j + 1] + 5))
        return (0);
    if (!(my_game->my_map.map_height[i][j] >=   \
        my_game->my_map.map_height[i + 1][j + 1] - 5 && \
        my_game->my_map.map_height[i][j] <= \
        my_game->my_map.map_height[i + 1][j + 1] + 5))
        return (0);
    return (1);
}