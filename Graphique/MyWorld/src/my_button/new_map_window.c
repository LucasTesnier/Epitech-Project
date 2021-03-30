/*
** EPITECH PROJECT, 2021
** new_map
** File description:
** desc
*/

#include "my_world.h"

void valid_new_map(my_game_t *my_game)
{
    my_game->new_map_confirm = 1;
}

void new_button_one(my_game_t *my_game, button_t *buttons)
{
    buttons[0] = button_create((sfVector2f){310, 250}, \
    (sfVector2f){250, 90}, true, true);
    button_change_texture(&(buttons[0]), "assets/buttons/confirm.png", 1);
    button_change_texture(&(buttons[0]), "assets/buttons/confirm3.png", 2);
    button_change_texture(&(buttons[0]), "assets/buttons/confirm2.png", 3);
    button_add_text("Play", \
    sfFont_createFromFile("assets/fonts/arial.ttf"), sfGreen, &(buttons[0]));
    button_add_info(&(buttons[0]), (sfVector2f){400, 50}, true, \
    "Select the moving cursor");
    button_add_action(&(buttons[0]), &(valid_new_map), &(valid_new_map));
    buttons[0].have_textbox = false;
    buttons[0].text.is_display = false;
}

button_t *new_button_setup(my_game_t *my_game)
{
    button_t *buttons = malloc(sizeof(button_t) * 3);

    new_button_one(my_game, buttons);
    return (buttons);
}

void new_textzone_one(my_game_t *my_game, textzone_t *textzones)
{
    textzones[0].box = button_create((sfVector2f){125, 150}, \
    (sfVector2f){200, 75}, true, true);
    button_change_texture(&(textzones[0].box), "assets/textzones/box.png", 1);
    button_change_texture(&(textzones[0].box), "assets/textzones/box2.png", 2);
    button_change_texture(&(textzones[0].box), "assets/textzones/box.png", 3);
    button_add_text("X Size", sfFont_createFromFile("assets/fonts/arial.ttf")\
    , sfBlack, &(textzones[0].box));
    text_change_char_size(&(textzones[0].box.text), 20);
    text_change_pos(&(textzones[0].box.text), \
    (sfVector2f){textzones[0].box.pos.x + 30, textzones[0].box.pos.y + 25});
    textzones[0].text_size = 4;
    button_add_info(&(textzones[0].box), \
    (sfVector2f){400, 50}, true, "Change the X size");
    button_add_action(&(textzones[0].box), &(textzone), &(textzone));
    textzones[0].box.have_textbox = false;
    textzones[0].box.text.is_display = true;
}

void new_textzone_two(my_game_t *my_game, textzone_t *textzones)
{
    textzones[1].box = button_create((sfVector2f){550, 150}, \
    (sfVector2f){200, 75}, true, true);
    button_change_texture(&(textzones[1].box), "assets/textzones/box.png", 1);
    button_change_texture(&(textzones[1].box), "assets/textzones/box2.png", 2);
    button_change_texture(&(textzones[1].box), "assets/textzones/box.png", 3);
    button_add_text("Y Size", \
    sfFont_createFromFile("assets/fonts/arial.ttf"), sfBlack, \
    &(textzones[1].box));
    text_change_char_size(&(textzones[1].box.text), 20);
    text_change_pos(&(textzones[1].box.text), \
    (sfVector2f){textzones[1].box.pos.x + 30, textzones[1].box.pos.y + 25});
    textzones[1].text_size = 4;
    button_add_info(&(textzones[1].box), \
    (sfVector2f){400, 50}, true, "Change the X size");
    button_add_action(&(textzones[1].box), &(textzone), &(textzone));
    textzones[1].box.have_textbox = false;
    textzones[1].box.text.is_display = true;
}
