/*
** EPITECH PROJECT, 2021
** up and down
** File description:
** desc
*/

#include "my_world.h"

void up_and_down_tile2(my_game_t *my_game, int k, sfVector2i pos1)
{
    my_game->my_map.map_height[pos1.x][pos1.y] += \
    (my_game->my_map.map_height[pos1.x][pos1.y] + k < 120 &&  \
    my_game->my_map.map_height[pos1.x][pos1.y] + k > -120) ? k : 0;
    my_game->my_map.map_height[pos1.x + 1][pos1.y] += \
    (my_game->my_map.map_height[pos1.x + 1][pos1.y] + k < 120 &&  \
    my_game->my_map.map_height[pos1.x + 1][pos1.y] + k > -120) ? k : 0;
    my_game->my_map.map_height[pos1.x][pos1.y + 1] += \
    (my_game->my_map.map_height[pos1.x][pos1.y + 1] + k < 120 &&  \
    my_game->my_map.map_height[pos1.x][pos1.y + 1] + k > -120) ? k : 0;
    my_game->my_map.map_height[pos1.x + 1][pos1.y + 1] += \
    (my_game->my_map.map_height[pos1.x + 1][pos1.y + 1] + k < 120 &&  \
    my_game->my_map.map_height[pos1.x + 1][pos1.y + 1] + k > -120) ?  \
k : 0;
}

void up_and_down_tile(my_game_t *my_game, int k, sfVector2i mouse_pos)
{
    int i = 0;
    int j = 0;

    for (int a = 0; a < my_game->my_map.size.x - 1; a++) {
        for (int b = 0; b < my_game->my_map.size.y - 1; b++) {
            in_tiles(my_game, a, b, mouse_pos);
        }
    }
    i = my_game->my_window.tile_selected.x - my_game->radius + 1;
    for (; i < 0; i++);
    j = my_game->my_window.tile_selected.y - my_game->radius + 1;
    for (; j < 0; j++);
    for (int a = 0; a < 2 * my_game->radius - 1 && a + i + 1 <  \
    my_game->my_map.size.x; a++) {
        for (int b = 0; b < 2 * my_game->radius - 1 && b + j + 1 <  \
        my_game->my_map.size.y; b++) {
            up_and_down_tile2(my_game, k, (sfVector2i){i + a, j + b});
        }
    }
    my_game->my_map.vector = my_vector_init(my_game->my_map);
}

void build(my_game_t *my_game, sfVector2i mouse_pos)
{
    if (my_game->mod == 2) {
        if (my_game->my_window.mouse_status == 1)
            up_and_down_tile(my_game, 1, mouse_pos);
        else if (my_game->my_window.mouse_status == 2)
            up_and_down_tile(my_game, -1, mouse_pos);
    }
}
