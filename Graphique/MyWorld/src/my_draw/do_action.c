/*
** EPITECH PROJECT, 2021
** do action
** File description:
** desc
*/

#include "my_world.h"

void do_action2(my_game_t *my_game, sfVector2i mouse_pos)
{
    build(my_game, mouse_pos);
    if (my_game->mod == 3)
        change_tile_texture(my_game, mouse_pos);
    if (my_game->mod == 4)
        reset_altitude(my_game, mouse_pos);
    if (my_game->mod == 5)
        place_sprite(my_game, mouse_pos);
    if (my_game->mod == 6)
        destroy_sprite(my_game, mouse_pos);
}

void do_action(my_game_t *my_game, sfVector2i mouse_pos)
{
    sfVector2u window_size =    \
    sfRenderWindow_getSize(my_game->my_window.window);

    if (mouse_pos.x > my_game->progress_bar->back_pos.x &&  \
        mouse_pos.x < my_game->progress_bar->back_pos.x +   \
        my_game->progress_bar->back_size.x && mouse_pos.y < \
        my_game->progress_bar->back_pos.y + \
        my_game->progress_bar->back_size.y)
        return;
    window_size.y -= (my_game->toolsbar_on == true) ?   \
sfRectangleShape_getSize(my_game->shapes[0]).y : 0;
    if (mouse_pos.y > window_size.y)
        return;
    if (mouse_pos.x > 50 && mouse_pos.x < 150 && mouse_pos.y > 20 &&    \
        mouse_pos.y < 120)
        return;
    move_map_position(my_game, mouse_pos, window_size);
    do_action2(my_game, mouse_pos);
}