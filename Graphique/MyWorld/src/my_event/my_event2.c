/*
** EPITECH PROJECT, 2021
** my_event2
** File description:
** desc
*/

#include "my_world.h"

void key_shortcut2(my_game_t *my_game, my_window_t *my_window)
{
    if (my_window->event.key.code == my_game->shortcut[4])
        my_game->mod = 5;
    if (my_window->event.key.code == my_game->shortcut[5])
        my_game->mod = 6;
    if (my_window->event.key.code == my_game->shortcut[6])
        my_game->mod = 7;
    if (my_window->event.key.code == my_game->shortcut[7])
        my_game->mod = 8;
    if (my_window->event.key.code == my_game->shortcut[8])
        my_game->mod = 9;
    if (my_window->event.key.code == my_game->shortcut[9])
        my_game->radius += (my_game->radius < 5) ? 1 : -4;
    if (my_window->event.key.code == sfKeyX)
        my_game->my_map.pos = (sfVector2f){1920 / 2, 100};
}

void key_shortcut(my_game_t *my_game, my_window_t *my_window)
{
    if (my_window->event.type == sfEvtKeyPressed && \
        my_window->event.key.code == sfKeyLControl)
        my_game->ctrl = 1;
    else if (my_window->event.type == sfEvtKeyReleased &&   \
        my_window->event.key.code == sfKeyLControl)
        my_game->ctrl = 0;
    if (my_game->ctrl == 1 && my_window->event.type == sfEvtKeyPressed) {
        if (my_window->event.key.code == my_game->shortcut[0])
            my_game->mod = 1;
        if (my_window->event.key.code == my_game->shortcut[1])
            my_game->mod = 2;
        if (my_window->event.key.code == my_game->shortcut[2])
            my_game->mod = 3;
        if (my_window->event.key.code == my_game->shortcut[3])
            my_game->mod = 4;
        key_shortcut2(my_game, my_window);
    }
}

void zoom2(my_game_t *my_game, sfVector2i mouse_pos)
{
    my_game->my_map.display_size += \
    my_game->my_window.event.mouseWheelScroll.delta;
    if (my_game->my_map.display_size > 150 ||   \
    my_game->my_map.display_size < 20) {
        my_game->my_map.display_size -= \
        my_game->my_window.event.mouseWheelScroll.delta;
    }
    my_game->my_map.height_size = (float)my_game->my_map.display_size / 10;
    free(my_game->my_map.vector);
    my_game->my_map.vector = my_vector_init(my_game->my_map);
}

void zoom(my_game_t *my_game)
{
    sfVector2i mouse_pos =  \
    sfMouse_getPositionRenderWindow(my_game->my_window.window);

    for (int i = 0; i < my_game->my_map.size.x - 1; i++) {
        for (int j = 0; j < my_game->my_map.size.x - 1; j++) {
            in_tiles(my_game, i, j, mouse_pos);
        }
    }
    if (my_game->my_map.display_size < 150 && my_game->my_map.display_size  \
    > 20) {
        if (my_game->my_window.event.mouseWheelScroll.delta > 0) {
            my_game->my_map.pos.y -=    \
            sqrt(pow(my_game->my_window.event.mouseWheelScroll.delta, 2)    \
            * 2) * ((my_game->my_window.tile_selected.y) / 2);
        } else {
            my_game->my_map.pos.y +=    \
            sqrt(pow(my_game->my_window.event.mouseWheelScroll.delta, 2)    \
            * 2) * ((my_game->my_window.tile_selected.y) / 2);
        }
    }
    zoom2(my_game, mouse_pos);
}
