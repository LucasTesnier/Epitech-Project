/*
** EPITECH PROJECT, 2021
** terra two
** File description:
** desc
*/

#include "my_world.h"

void terra_on_off_sprite(my_game_t *my_game, my_sprite_t *sprites)
{
    sprites[0] = new_sprite(1, "assets/pictures/window_back.png", NULL);
    sprites[1] = new_sprite(2, "assets/pictures/texture_window.png", NULL);
    sfSprite_setScale(sprites[0].sprite, (sfVector2f){10, 7});
    sfSprite_setScale(sprites[1].sprite, (sfVector2f){3, 3});
    sfSprite_setPosition(sprites[1].sprite, (sfVector2f){300, 50});
}

void terra_on_off_button_zero(my_game_t *my_game, button_t *buttons)
{
    buttons[0] = button_create((sfVector2f){125, 200}, \
    (sfVector2f){100, 100}, true, true);
    button_change_texture(&(buttons[0]), "assets/pictures/new_grass.png", 1);
    button_change_texture(&(buttons[0]), "assets/pictures/new_grass.png", 2);
    button_change_texture(&(buttons[0]), "assets/pictures/new_grass.png", 3);
    button_add_text("Play", sfFont_createFromFile("assets/fonts/arial.ttf"), \
    sfGreen, &(buttons[0]));
    button_add_info(&(buttons[0]), (sfVector2f){400, 50}, true, \
    "Select the moving cursor");
    button_add_action(&(buttons[0]), &(choose_grass), &(choose_grass));
    buttons[0].have_textbox = false;
    buttons[0].text.is_display = false;
}

void terra_on_off_button_one(my_game_t *my_game, button_t *buttons)
{
    buttons[1] = button_create((sfVector2f){300, 200}, \
    (sfVector2f){100, 100}, true, true);
    button_change_texture(&(buttons[1]), "assets/pictures/new_stone.png", 1);
    button_change_texture(&(buttons[1]), "assets/pictures/new_stone.png", 2);
    button_change_texture(&(buttons[1]), "assets/pictures/new_stone.png", 3);
    button_add_text("Play", sfFont_createFromFile("assets/fonts/arial.ttf"), \
    sfGreen, &(buttons[1]));
    button_add_info(&(buttons[1]), (sfVector2f){400, 50}, true, \
    "Select the moving cursor");
    button_add_action(&(buttons[1]), &(choose_water), &(choose_water));
    buttons[1].have_textbox = false;
    buttons[1].text.is_display = false;
}

void terra_on_off_button_two(my_game_t *my_game, button_t *buttons)
{
    buttons[2] = button_create((sfVector2f){475, 200}, \
    (sfVector2f){100, 100}, true, true);
    button_change_texture(&(buttons[2]), "assets/pictures/new_sand.png", 1);
    button_change_texture(&(buttons[2]), "assets/pictures/new_sand.png", 2);
    button_change_texture(&(buttons[2]), "assets/pictures/new_sand.png", 3);
    button_add_text("Play", sfFont_createFromFile("assets/fonts/arial.ttf"), \
    sfGreen, &(buttons[2]));
    button_add_info(&(buttons[2]), (sfVector2f){400, 50}, true, \
    "Select the moving cursor");
    button_add_action(&(buttons[2]), &(choose_sand), &(choose_sand));
    buttons[2].have_textbox = false;
    buttons[2].text.is_display = false;
}

void terra_on_off_button_three(my_game_t *my_game, button_t *buttons)
{
    buttons[3] = button_create((sfVector2f){650, 200}, \
    (sfVector2f){100, 100}, true, true);
    button_change_texture(&(buttons[3]), "assets/pictures/new_snow.png", 1);
    button_change_texture(&(buttons[3]), "assets/pictures/new_snow.png", 2);
    button_change_texture(&(buttons[3]), "assets/pictures/new_snow.png", 3);
    button_add_text("Play", sfFont_createFromFile("assets/fonts/arial.ttf"), \
    sfGreen, &(buttons[3]));
    button_add_info(&(buttons[3]), (sfVector2f){400, 50}, true, \
    "Select the moving cursor");
    button_add_action(&(buttons[3]), &(choose_snow), &(choose_snow));
    buttons[3].have_textbox = false;
    buttons[3].text.is_display = false;
}