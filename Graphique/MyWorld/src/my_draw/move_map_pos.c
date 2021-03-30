/*
** EPITECH PROJECT, 2021
** move_map_pos
** File description:
** desc
*/

#include "my_world.h"

void move_map_position(my_game_t *my_game, sfVector2i mouse_pos,    \
sfVector2u window_size)
{
    if (mouse_pos.x < 100 && mouse_pos.x > 0)
        my_game->my_map.pos.x += (100 - mouse_pos.x) / 5;
    else if (mouse_pos.x > window_size.x - 100 && mouse_pos.x < \
        window_size.x)
        my_game->my_map.pos.x -= (mouse_pos.x - (window_size.x - 100))  \
        / 5;
    if (mouse_pos.y < 100 && mouse_pos.y > 0)
        my_game->my_map.pos.y += (100 - mouse_pos.y) / 5;
    else if (mouse_pos.y > window_size.y - 100 && mouse_pos.y < \
        window_size.y)
        my_game->my_map.pos.y -= (mouse_pos.y - (window_size.y - 100))  \
        / 5;
    if (my_game->mod == 1 && my_game->my_window.mouse_status == 1) {
        my_game->my_map.pos.x += mouse_pos.x - my_game->mouse_pos.x;
        my_game->my_map.pos.y += mouse_pos.y - my_game->mouse_pos.y;
    }
}