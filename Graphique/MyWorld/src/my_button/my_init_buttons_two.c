/*
** EPITECH PROJECT, 2021
** my_init_button
** File description:
** desc
*/

#include "my_world.h"
#include "proto.h"

button_t init_button_one(my_game_t *my_game, button_t *buttons)
{
    buttons[0] = button_create((sfVector2f){760, 300}, \
    (sfVector2f){400, 250}, true, true);
    button_change_texture(&(buttons[0]), "assets/buttons/play1.png", 1);
    button_change_texture(&(buttons[0]), "assets/buttons/play1.png", 2);
    button_change_texture(&(buttons[0]), "assets/buttons/play3.png", 3);
    button_add_text("Play", \
    sfFont_createFromFile("assets/fonts/arial.ttf"), sfGreen, &(buttons[0]));
    button_add_info(&(buttons[0]), (sfVector2f){0, 0}, false, NULL);
    button_add_action(&(buttons[0]), &(play), &(play));
    buttons[0].have_textbox = false;
    buttons[0].text.is_display = false;
}

button_t init_button_two(my_game_t *my_game, button_t *buttons)
{
    buttons[1] = button_create((sfVector2f){0, 900}, \
    (sfVector2f){100, 100}, true, false);
    button_change_texture(&(buttons[1]), "assets/buttons/toolsbar_on1.png", 1);
    button_change_texture(&(buttons[1]), "assets/buttons/toolsbar_on2.png", 2);
    button_change_texture(&(buttons[1]), "assets/buttons/toolsbar_on3.png", 3);
    button_add_text("Play", \
    sfFont_createFromFile("assets/fonts/arial.ttf"), sfGreen, &(buttons[1]));
    button_add_info(&(buttons[1]), (sfVector2f){0, 0}, false, NULL);
    button_add_action(&(buttons[1]), &(on_off_toolsbar), &(on_off_toolsbar));
    buttons[1].have_textbox = false;
    buttons[1].text.is_display = false;
}

button_t init_button_three(my_game_t *my_game, button_t *buttons)
{
    buttons[2] = button_create((sfVector2f){50, 900}, \
    (sfVector2f){100, 100}, true, false);
    button_change_texture(&(buttons[2]), "assets/buttons/hand1.png", 1);
    button_change_texture(&(buttons[2]), "assets/buttons/hand2.png", 2);
    button_change_texture(&(buttons[2]), "assets/buttons/hand3.png", 3);
    button_add_text("Play", \
    sfFont_createFromFile("assets/fonts/arial.ttf"), sfGreen, &(buttons[2]));
    button_add_info(&(buttons[2]), (sfVector2f){400, 50}, true, \
    "Select the moving cursor");
    button_info_add_text(&(buttons[2]), "Select the moving cursor", \
    sfFont_createFromFile("assets/fonts/arial.ttf"), 25);
    text_change_fill_color(&(buttons[2].info.text), sfBlack);
    text_change_pos(&(buttons[2].info.text), \
    (sfVector2f){50 + 100 + 65, 900 - 50});
    button_info_set_texture(&(buttons[2]), "assets/pictures/window_back.png");
    button_add_action(&(buttons[2]), &(hand_on_off), &(hand_on_off));
    buttons[2].have_textbox = true;
    buttons[2].text.is_display = false;
}

button_t init_button_four(my_game_t *my_game, button_t *buttons)
{
    buttons[3] = button_create((sfVector2f){250, 900}, \
    (sfVector2f){100, 100}, true, false);
    button_change_texture(&(buttons[3]), "assets/buttons/pointer1.png", 1);
    button_change_texture(&(buttons[3]), "assets/buttons/pointer2.png", 2);
    button_change_texture(&(buttons[3]), "assets/buttons/pointer3.png", 3);
    button_add_text("Play", \
    sfFont_createFromFile("assets/fonts/arial.ttf"), sfGreen, &(buttons[3]));
    button_add_info(&(buttons[3]), (sfVector2f){460, 50}, true, \
    "Select the terraforming cursor");
    button_info_add_text(&(buttons[3]), "Select the terraforming cursor", \
    sfFont_createFromFile("assets/fonts/arial.ttf"), 25);
    text_change_fill_color(&(buttons[3].info.text), sfBlack);
    text_change_pos(&(buttons[3].info.text), \
    (sfVector2f){250 + 100 + 65, 900 - 50});
    button_info_set_texture(&(buttons[3]), "assets/pictures/window_back.png");
    button_add_action(&(buttons[3]), &(pointer_on_off), &(pointer_on_off));
    buttons[3].have_textbox = true;
    buttons[3].text.is_display = false;
}

button_t init_button_five(my_game_t *my_game, button_t *buttons)
{
    buttons[4] = button_create((sfVector2f){450, 900}, \
    (sfVector2f){100, 100}, true, false);
    button_change_texture(&(buttons[4]), "assets/buttons/terra1.png", 1);
    button_change_texture(&(buttons[4]), "assets/buttons/terra2.png", 2);
    button_change_texture(&(buttons[4]), "assets/buttons/terra3.png", 3);
    button_add_text("Play", \
    sfFont_createFromFile("assets/fonts/arial.ttf"), sfGreen, &(buttons[4]));
    button_add_info(&(buttons[4]), (sfVector2f){370, 50}, true, \
    "Select the texture cursor");
    button_info_add_text(&(buttons[4]), "Select the texture cursor", \
    sfFont_createFromFile("assets/fonts/arial.ttf"), 25);
    text_change_fill_color(&(buttons[4].info.text), sfBlack);
    text_change_pos(&(buttons[4].info.text), \
    (sfVector2f){450 + 100 + 50, 900 - 50});
    button_info_set_texture(&(buttons[4]), "assets/pictures/window_back.png");
    button_add_action(&(buttons[4]), &(terra_on_off), &(terra_on_off));
    buttons[4].have_textbox = true;
    buttons[4].text.is_display = false;
}