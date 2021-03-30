/*
** EPITECH PROJECT, 2021
** load map
** File description:
** desc
*/

#include "my_world.h"

void load_button_one(my_game_t *my_game, button_t *buttons)
{
    buttons[0] = button_create((sfVector2f){310, 270}, \
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

button_t *load_button_setup(my_game_t *my_game)
{
    button_t *buttons = malloc(sizeof(button_t) * 3);

    load_button_one(my_game, buttons);
    return (buttons);
}

void load_textzone_one(my_game_t *my_game, textzone_t *textzones)
{
    textzones[0].box = button_create((sfVector2f){600, 180}, \
    (sfVector2f){200, 75}, true, true);
    button_change_texture(&(textzones[0].box), "assets/textzones/box.png", 1);
    button_change_texture(&(textzones[0].box), "assets/textzones/box2.png", 2);
    button_change_texture(&(textzones[0].box), "assets/textzones/box.png", 3);
    button_add_text("save", sfFont_createFromFile("assets/fonts/arial.ttf"), \
    sfBlack, &(textzones[0].box));
    text_change_char_size(&(textzones[0].box.text), 20);
    text_change_pos(&(textzones[0].box.text), (sfVector2f){textzones[0].\
        box.pos.x + 30, textzones[0].box.pos.y + 25});
    textzones[0].text_size = 12;
    button_add_info(&(textzones[0].box), (sfVector2f){400, 50}, true, \
    "Change the X size");
    button_add_action(&(textzones[0].box), &(textzone), &(textzone));
    textzones[0].box.have_textbox = false;
    textzones[0].box.text.is_display = true;
}

textzone_t *load_textzone_setup(my_game_t *my_game)
{
    textzone_t *textzones = malloc(sizeof(textzone_t) * 3);

    load_textzone_one(my_game, textzones);
    return (textzones);
}

my_sprite_t *load_sprite_setup(my_game_t *my_game)
{
    my_sprite_t *sprites = malloc(sizeof(my_sprite_t) * 4);

    sprites[0] = new_sprite(1, "assets/pictures/window_back.png", NULL);
    sprites[1] = new_sprite(2, "assets/pictures/load_title.png", NULL);
    sprites[2] = new_sprite(3, "assets/pictures/save_name.png", NULL);
    sfSprite_setPosition(sprites[1].sprite, (sfVector2f){280, 50});
    sfSprite_setScale(sprites[1].sprite, (sfVector2f){3, 3});
    sfSprite_setPosition(sprites[2].sprite, (sfVector2f){100, 170});
    sfSprite_setScale(sprites[2].sprite, (sfVector2f){2, 2});
    sfSprite_setScale(sprites[0].sprite, (sfVector2f){10, 7});
    return (sprites);
}