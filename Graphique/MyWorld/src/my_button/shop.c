/*
** EPITECH PROJECT, 2021
** shop
** File description:
** desc
*/

#include "my_world.h"

my_sprite_t *shop_sprite_setup(my_game_t *my_game)
{
    my_sprite_t *sprites = malloc(sizeof(my_sprite_t) * 3);

    sprites[0] = new_sprite(1, "assets/pictures/window_back.png", NULL);
    sprites[1] = new_sprite(2, "assets/pictures/store_title.png", NULL);
    sfSprite_setPosition(sprites[1].sprite, (sfVector2f){280, 110});
    sfSprite_setScale(sprites[1].sprite, (sfVector2f){3, 3});
    sfSprite_setScale(sprites[0].sprite, (sfVector2f){10, 15});
    return (sprites);
}

my_window_t shop_window_setup(my_game_t *my_game)
{
    my_window_t my_window;

    my_window.mode = (sfVideoMode){900, 900, 32};
    my_window.window = sfRenderWindow_create(my_window.mode, \
    "Buy Your Building", sfTitlebar, NULL);
    sfRenderWindow_setPosition(my_window.window, (sfVector2i){510, 90});
    return (my_window);
}

void shop_event(my_game_t *my_game, button_t *buttons, my_window_t my_window)
{
    while (sfRenderWindow_pollEvent(my_window.window, &my_window.event)) {
        if (my_window.event.type == sfEvtClosed)
            sfRenderWindow_close(my_window.window);
        if (my_window.event.type == sfEvtMouseButtonPressed) {
            button_is_up(&(buttons[0]), my_window.window, true, my_game);
            button_is_up(&(buttons[1]), my_window.window, true, my_game);
            button_is_up(&(buttons[2]), my_window.window, true, my_game);
            button_is_up(&(buttons[3]), my_window.window, true, my_game);
            button_is_up(&(buttons[4]), my_window.window, true, my_game);
            button_is_up(&(buttons[5]), my_window.window, true, my_game);
        }
    }
}

void shop_display(my_game_t *my_game, button_t *buttons, \
my_sprite_t *sprites, my_window_t my_window)
{
    sfRenderWindow_drawSprite(my_window.window, sprites[0].sprite, NULL);
    sfRenderWindow_drawSprite(my_window.window, sprites[1].sprite, NULL);
    button_display(&(buttons[0]), my_window.window);
    button_display(&(buttons[1]), my_window.window);
    button_display(&(buttons[2]), my_window.window);
    button_display(&(buttons[3]), my_window.window);
    button_display(&(buttons[4]), my_window.window);
    button_display(&(buttons[5]), my_window.window);
    sfRenderWindow_display(my_window.window);
}

void shop_on_off(my_game_t *my_game)
{
    my_window_t my_window = shop_window_setup(my_game);
    my_sprite_t *sprites = shop_sprite_setup(my_game);
    button_t *buttons =shop_button_setup(my_game);

    my_game->mod = 5;
    my_game->window_choose = &my_window;
    while (sfRenderWindow_isOpen(my_window.window)) {
        sfRenderWindow_clear(my_window.window, (sfColor){150, 150, 150, 255});
        shop_event(my_game, buttons, my_window);
        if (sfRenderWindow_hasFocus(my_window.window) == sfFalse)
            sfRenderWindow_close(my_window.window);
        shop_display(my_game, buttons, sprites, my_window);
    }
}