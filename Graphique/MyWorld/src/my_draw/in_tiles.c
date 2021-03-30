/*
** EPITECH PROJECT, 2021
** in tiles
** File description:
** desc
*/

#include "my_world.h"

int on_right(sfVector2f pos1, sfVector2f pos2, sfVector2i point,    \
sfVector2f pos)
{
    sfVector2f v1 = {(pos2.x + pos.x) - (pos1.x + pos.x), (pos2.y + pos.y)  \
        - (pos1.y + pos.y)};
    sfVector2f v2 = {point.x - (pos1.x + pos.x), point.y - (pos1.y + pos.y)};
    int res = v1.x * v2.y - v1.y * v2.x;

    if (res < 0)
        return (1);
    return (0);
}

int in_tiles(my_game_t *my_game, int i, int j, sfVector2i mouse_pos)
{
    int res = 0;

    if (in_window(my_game, i, j) != 1)
        return (0);
    res += on_right(my_game->my_map.vector[i][j],   \
    my_game->my_map.vector[i][j + 1], mouse_pos, my_game->my_map.pos);
    res += on_right(my_game->my_map.vector[i][j + 1],   \
    my_game->my_map.vector[i + 1][j + 1], mouse_pos, my_game->my_map.pos);
    res += on_right(my_game->my_map.vector[i + 1][j + 1],   \
    my_game->my_map.vector[i + 1][j], mouse_pos, my_game->my_map.pos);
    res += on_right(my_game->my_map.vector[i + 1][j],   \
    my_game->my_map.vector[i][j], mouse_pos, my_game->my_map.pos);
    if (res >= 4) {
        my_game->my_window.tile_selected = (sfVector2i){i, j};
        return (1);
    }
    return (0);
}