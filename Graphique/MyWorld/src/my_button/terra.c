/*
** EPITECH PROJECT, 2021
** terra
** File description:
** desc
*/

#include "my_world.h"

my_window_t terra_on_off_window(my_game_t *my_game)
{
    my_window_t my_window;

    my_window.mode = (sfVideoMode){900, 420, 32};
    my_window.window = sfRenderWindow_create(my_window.mode, \
    "Choose Your Magic Texture !", sfTitlebar, NULL);
    sfRenderWindow_setPosition(my_window.window, (sfVector2i){510, 330});
    return (my_window);
}

button_t *terra_on_off_button_setup(my_game_t *my_game)
{
    button_t *buttons = malloc(sizeof(button_t) * 5);

    terra_on_off_button_zero(my_game, buttons);
    terra_on_off_button_one(my_game, buttons);
    terra_on_off_button_two(my_game, buttons);
    terra_on_off_button_three(my_game, buttons);
    return (buttons);
}

void terra_on_off_event(my_game_t *my_game, my_window_t \
my_window, button_t *buttons)
{
    while (sfRenderWindow_pollEvent(my_window.window, &my_window.event)) {
        if (my_window.event.type == sfEvtClosed)
            sfRenderWindow_close(my_window.window);
        if (my_window.event.type == sfEvtMouseButtonPressed) {
            button_is_up(&(buttons[0]), my_window.window, true, my_game);
            button_is_up(&(buttons[1]), my_window.window, true, my_game);
            button_is_up(&(buttons[2]), my_window.window, true, my_game);
            button_is_up(&(buttons[3]), my_window.window, true, my_game);
        }
    }
}

void terra_on_off_display(my_game_t *my_game, button_t *buttons, \
my_sprite_t *sprites, my_window_t my_window)
{
    sfRenderWindow_drawSprite(my_window.window, sprites[0].sprite, NULL);
    sfRenderWindow_drawSprite(my_window.window, sprites[1].sprite, NULL);
    button_display(&(buttons[0]), my_window.window);
    button_display(&(buttons[1]), my_window.window);
    button_display(&(buttons[2]), my_window.window);
    button_display(&(buttons[3]), my_window.window);
    sfRenderWindow_display(my_window.window);
}

void terra_on_off(my_game_t *my_game)
{
    my_window_t my_window = terra_on_off_window(my_game);
    my_sprite_t *sprites = malloc(sizeof(my_sprite_t) * 3);
    button_t *buttons = terra_on_off_button_setup(my_game);

    my_game->mod = 3;
    my_game->window_choose = &my_window;
    terra_on_off_sprite(my_game, sprites);
    while (sfRenderWindow_isOpen(my_window.window)) {
        sfRenderWindow_clear(my_window.window, (sfColor){150, 150, 150, 255});
        terra_on_off_event(my_game, my_window, buttons);
        if (sfRenderWindow_hasFocus(my_window.window) == sfFalse)
            sfRenderWindow_close(my_window.window);
        terra_on_off_display(my_game, buttons, sprites, my_window);
    }
}