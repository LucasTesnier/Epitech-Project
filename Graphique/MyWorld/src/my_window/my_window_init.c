/*
** EPITECH PROJECT, 2021
** my_window
** File description:
** desc
*/

#include "my_world.h"

my_window_t my_window_init(void)
{
    my_window_t my_window;

    my_window.mode = (sfVideoMode){1920, 1080, 32};
    my_window.window = sfRenderWindow_create(my_window.mode, "My World",    \
    sfDefaultStyle, NULL);
    my_window.mouse_status = 0;
    my_window.tile_selected = (sfVector2i){0, 0};
    return (my_window);
}