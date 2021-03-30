/*
** EPITECH PROJECT, 2021
** reset_altitude
** File description:
** desc
*/

#include "my_world.h"

void reset_altitude2(my_game_t *my_game, sfVector2i mouse_pos, int i, int j)
{
    for (int a = 0; a < 2 * my_game->radius - 1 && a + i + 1 <  \
    my_game->my_map.size.x; a++) {
        for (int b = 0; b < 2 * my_game->radius - 1 && b + j + 1 <  \
        my_game->my_map.size.y; b++) {
            my_game->my_map.map_height[i + a][j + b] = 0;
            my_game->my_map.map_height[i + a + 1][j + b] = 0;
            my_game->my_map.map_height[i + a][j + b + 1] = 0;
            my_game->my_map.map_height[i + a + 1][j + b + 1] = 0;
        }
    }
}

void reset_altitude(my_game_t *my_game, sfVector2i mouse_pos)
{
    int i = 0;
    int j = 0;

    for (int a = 0; a < my_game->my_map.size.x - 1; a++) {
        for (int b = 0; b < my_game->my_map.size.y - 1; b++) {
            in_tiles(my_game, a, b, mouse_pos);
        }
    }
    if (my_game->my_window.mouse_status != 0) {
        i = my_game->my_window.tile_selected.x - my_game->radius + 1;
        for (; i < 0; i++);
        j = my_game->my_window.tile_selected.y - my_game->radius + 1;
        for (; j < 0; j++);
        reset_altitude2(my_game, mouse_pos, i, j);
        my_game->my_map.vector = my_vector_init(my_game->my_map);
    }
}