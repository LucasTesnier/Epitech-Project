/*
** EPITECH PROJECT, 2021
** save map
** File description:
** desc
*/

#include "my_world.h"

void save_event(my_game_t *my_game, button_t *buttons, textzone_t \
*textzones, my_window_t my_window)
{
    while (sfRenderWindow_pollEvent(my_window.window, &my_window.event)) {
        if (my_window.event.type == sfEvtClosed)
            sfRenderWindow_close(my_window.window);
        if (my_window.event.type == sfEvtMouseButtonPressed) {
            textzones_is_pressed(my_game, my_window, textzones, 1);
            button_is_up(&(buttons[0]), my_window.window, true, my_game);
        }
        if (my_window.event.type == sfEvtKeyPressed) {
            textzones_write(my_game, my_window, textzones, 1);
        }
    }
}

void save_draw(my_game_t *my_game, button_t *buttons, textzone_t \
*textzones, my_window_t my_window)
{
    button_is_up(&(textzones[0].box), my_window.window, false, my_game);
    button_display(&(textzones[0].box), my_window.window);
    button_is_up(&(buttons[0]), my_window.window, false, my_game);
    button_display(&(buttons[0]), my_window.window);
    sfRenderWindow_display(my_window.window);
}

void save_map_action(my_game_t *my_game, textzone_t *textzones, \
my_window_t my_window)
{
    if (my_strlen(textzones[0].box.text.buffer) != 0) {
        my_game->save_name = textzones[0].box.text.buffer;
        sfRenderWindow_close(my_window.window);
        saving_map(my_game);
    }
}

void save_map(my_game_t *my_game)
{
    my_window_t my_window = save_window_setup(my_game);
    my_sprite_t *sprites = save_sprite_setup(my_game);
    button_t *buttons = save_button_setup(my_game);
    textzone_t *textzones = save_textzone_setup(my_game);

    while (sfRenderWindow_isOpen(my_window.window)) {
        sfRenderWindow_clear(my_window.window, (sfColor){150, 150, 150, 255});
        save_event(my_game, buttons, textzones, my_window);
        if (sfRenderWindow_hasFocus(my_window.window) == sfFalse)
            sfRenderWindow_close(my_window.window);
        sfRenderWindow_drawSprite(my_window.window, sprites[0].sprite, NULL);
        sfRenderWindow_drawSprite(my_window.window, sprites[1].sprite, NULL);
        sfRenderWindow_drawSprite(my_window.window, sprites[2].sprite, NULL);
        save_draw(my_game, buttons, textzones, my_window);
        if (my_game->new_map_confirm == 1) {
            my_game->new_map_confirm = 0;
            save_map_action(my_game, textzones, my_window);
        }
    }
}