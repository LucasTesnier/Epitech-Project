/*
** EPITECH PROJECT, 2021
** new_map
** File description:
** desc
*/

#include "my_world.h"

textzone_t *new_textzone_setup(my_game_t *my_game)
{
    textzone_t *textzones = malloc(sizeof(textzone_t) * 3);

    new_textzone_one(my_game, textzones);
    new_textzone_two(my_game, textzones);
    return (textzones);
}

my_sprite_t *new_sprite_setup(my_game_t *my_game)
{
    my_sprite_t *sprites = malloc(sizeof(my_sprite_t) * 3);

    sprites[0] = new_sprite(1, "assets/pictures/window_back.png", NULL);
    sprites[1] = new_sprite(2, "assets/pictures/new_title.png", NULL);
    sfSprite_setPosition(sprites[1].sprite, (sfVector2f){280, 50});
    sfSprite_setScale(sprites[1].sprite, (sfVector2f){3, 3});
    sfSprite_setScale(sprites[0].sprite, (sfVector2f){10, 7});
    return (sprites);
}

my_window_t new_window_setup(my_game_t *my_game)
{
    my_window_t my_window;

    my_window.mode = (sfVideoMode){900, 420, 32};
    my_window.window = sfRenderWindow_create(my_window.mode, \
    "New Map", sfTitlebar, NULL);
    sfRenderWindow_setPosition(my_window.window, (sfVector2i){510, 330});
    return (my_window);
}

void new_event(my_game_t *my_game, button_t *buttons, \
textzone_t *textzones, my_window_t my_window)
{
    while (sfRenderWindow_pollEvent(my_window.window, &my_window.event)) {
        if (my_window.event.type == sfEvtClosed)
            sfRenderWindow_close(my_window.window);
        if (my_window.event.type == sfEvtMouseButtonPressed) {
            textzones_is_pressed(my_game, my_window, textzones, 2);
            button_is_up(&(buttons[0]), my_window.window, true, my_game);
        }
        if (my_window.event.type == sfEvtKeyPressed) {
            textzones_write(my_game, my_window, textzones, 2);
        }
    }
}

void new_draw(my_game_t *my_game, button_t *buttons, textzone_t \
*textzones, my_window_t my_window)
{
    for (int i = 0; i < 2; i++) {
        button_is_up(&(textzones[i].box), my_window.window, \
        false, my_game);
        button_display(&(textzones[i].box), my_window.window);
    }
    button_is_up(&(buttons[0]), my_window.window, false, my_game);
    button_display(&(buttons[0]), my_window.window);
}