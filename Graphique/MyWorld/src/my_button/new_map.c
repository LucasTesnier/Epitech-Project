/*
** EPITECH PROJECT, 2021
** new_map
** File description:
** desc
*/

#include "my_world.h"

void new_map_generation(my_game_t *my_game, textzone_t \
*textzones, my_window_t my_window)
{
    sfRenderWindow_close(my_window.window);
    my_game->my_map.size.x = my_getnbr\
    (textzones[0].box.text.buffer);
    my_game->my_map.size.y = my_getnbr\
    (textzones[1].box.text.buffer);
    my_game->my_window.tile_selected = (sfVector2i){0, 0};
    my_game->construction_number = 0;
    my_game->my_map = my_map_init\
    (my_game->my_window.mode, my_game->my_map.size);
    my_game->gold = 100;
    my_game->gold_generation = 0;
    my_game->sprite = my_init_sprite(my_game->my_map, my_game);
}

void new_map_action(my_game_t *my_game, textzone_t \
*textzones, my_window_t my_window)
{
    my_game->new_map_confirm = 0;
    if (my_str_isnum(textzones[0].box.text.buffer) == 1 && \
    my_str_isnum(textzones[1].box.text.buffer) == 1 && my_strlen\
    (textzones[0].box.text.buffer) > 1 && my_strlen\
    (textzones[1].box.text.buffer) > 1) {
        if (my_getnbr(textzones[0].box.text.buffer) > 9 && \
        my_getnbr(textzones[1].box.text.buffer) > 9 && my_getnbr\
        (textzones[0].box.text.buffer) < 501 && my_getnbr\
        (textzones[1].box.text.buffer) < 501) {
            new_map_generation(my_game, textzones, my_window);
        }
    }
}

void new_map(my_game_t *my_game)
{
    my_window_t my_window = new_window_setup(my_game);
    my_sprite_t *sprites = new_sprite_setup(my_game);
    textzone_t *textzones = new_textzone_setup(my_game);
    button_t *buttons = new_button_setup(my_game);

    my_game->was_pressed = 0;
    while (sfRenderWindow_isOpen(my_window.window)) {
        sfRenderWindow_clear(my_window.window, (sfColor){150, 150, 150, 255});
        new_event(my_game, buttons, textzones, my_window);
        if (sfRenderWindow_hasFocus(my_window.window) == sfFalse)
            sfRenderWindow_close(my_window.window);
        sfRenderWindow_drawSprite(my_window.window, sprites[0].sprite, NULL);
        sfRenderWindow_drawSprite(my_window.window, sprites[1].sprite, NULL);
        new_draw(my_game, buttons, textzones, my_window);
        if (my_game->new_map_confirm == 1) {
            new_map_action(my_game, textzones, my_window);
            return;
        }
        sfRenderWindow_display(my_window.window);
    }
}