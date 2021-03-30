/*
** EPITECH PROJECT, 2021
** shop_initialisation.c
** File description:
** desc
*/

#include "my_world.h"

void shop_button_one(my_game_t *my_game, button_t *buttons)
{
    buttons[0] = button_create((sfVector2f){110, 250}, \
    (sfVector2f){100, 100}, true, true);
    button_change_texture(&(buttons[0]), "assets/sprites/house.png", 1);
    button_change_texture(&(buttons[0]), "assets/sprites/house.png", 2);
    button_change_texture(&(buttons[0]), "assets/sprites/house.png", 3);
    button_add_text("House :\nPrice : 10 Coins\nRent : 1 / S", \
    sfFont_createFromFile("assets/fonts/arial.ttf"), sfBlack, &(buttons[0]));
    text_change_pos(&(buttons[0].text), (sfVector2f){110 + 120, 250 + 20});
    text_change_char_size(&(buttons[0].text), 20);
    button_add_info(&(buttons[0]), (sfVector2f){400, 50}, true, \
    "Select the moving cursor");
    button_add_action(&(buttons[0]), &(one_buy), &(one_buy));
    buttons[0].have_textbox = false;
    buttons[0].text.is_display = true;
}

void shop_button_two(my_game_t *my_game, button_t *buttons)
{
    buttons[1] = button_create((sfVector2f){440, 250}, \
    (sfVector2f){100, 100}, true, true);
    button_change_texture(&(buttons[1]), "assets/sprites/farm.png", 1);
    button_change_texture(&(buttons[1]), "assets/sprites/farm.png", 2);
    button_change_texture(&(buttons[1]), "assets/sprites/farm.png", 3);
    button_add_text("Farm :\nPrice : 50 Coins\nRent : 2 / S", \
    sfFont_createFromFile("assets/fonts/arial.ttf"), sfBlack, &(buttons[1]));
    text_change_char_size(&(buttons[1].text), 20);
    text_change_pos(&(buttons[1].text), (sfVector2f){440 + 120, 250 + 20});
    button_add_info(&(buttons[1]), (sfVector2f){400, 50}, true, \
    "Select the moving cursor");
    button_add_action(&(buttons[1]), &(two_buy), &(two_buy));
    buttons[1].have_textbox = false;
    buttons[1].text.is_display = true;
}

void shop_button_three(my_game_t *my_game, button_t *buttons)
{
    buttons[2] = button_create((sfVector2f){110, 450}, \
    (sfVector2f){100, 100}, true, true);
    button_change_texture(&(buttons[2]), "assets/sprites/test.png", 1);
    button_change_texture(&(buttons[2]), "assets/sprites/test.png", 2);
    button_change_texture(&(buttons[2]), "assets/sprites/test.png", 3);
    button_add_text("Stable :\nPrice : 250 Coins\nRent : 3 / S", \
    sfFont_createFromFile("assets/fonts/arial.ttf"), sfBlack, &(buttons[2]));
    text_change_pos(&(buttons[2].text), (sfVector2f){110 + 120, 450 + 20});
    button_add_info(&(buttons[2]), (sfVector2f){400, 50}, true, \
    "Select the moving cursor");
    text_change_char_size(&(buttons[2].text), 20);
    button_add_action(&(buttons[2]), &(three_buy), &(three_buy));
    buttons[2].have_textbox = false;
    buttons[2].text.is_display = true;
}

void shop_button_four(my_game_t *my_game, button_t *buttons)
{
    buttons[3] = button_create((sfVector2f){440, 450}, \
    (sfVector2f){100, 100}, true, true);
    button_change_texture(&(buttons[3]), "assets/sprites/forge.png", 1);
    button_change_texture(&(buttons[3]), "assets/sprites/forge.png", 2);
    button_change_texture(&(buttons[3]), "assets/sprites/forge.png", 3);
    button_add_text("Forge :\nPrice : 1250 Coins\nRent : 4 / S", \
    sfFont_createFromFile("assets/fonts/arial.ttf"), sfBlack, &(buttons[3]));
    text_change_pos(&(buttons[3].text), (sfVector2f){440 + 120, 450 + 20});
    button_add_info(&(buttons[3]), (sfVector2f){400, 50}, true, \
    "Select the moving cursor");
    button_add_action(&(buttons[3]), &(four_buy), &(four_buy));
    buttons[3].have_textbox = false;
    text_change_char_size(&(buttons[3].text), 20);
    buttons[3].text.is_display = true;
}

void shop_button_five(my_game_t *my_game, button_t *buttons)
{
    buttons[4] = button_create((sfVector2f){110, 650}, \
    (sfVector2f){100, 100}, true, true);
    button_change_texture(&(buttons[4]), "assets/sprites/mansion.png", 1);
    button_change_texture(&(buttons[4]), "assets/sprites/mansion.png", 2);
    button_change_texture(&(buttons[4]), "assets/sprites/mansion.png", 3);
    button_add_text("Mansion :\nPrice : 6250 Coins\nRent : 5 / S", \
    sfFont_createFromFile("assets/fonts/arial.ttf"), sfBlack, &(buttons[4]));
    text_change_pos(&(buttons[4].text), (sfVector2f){110 + 120, 650 + 20});
    button_add_info(&(buttons[4]), (sfVector2f){400, 50}, true, \
    "Select the moving cursor");
    text_change_char_size(&(buttons[4].text), 20);
    button_add_action(&(buttons[4]), &(five_buy), &(five_buy));
    buttons[4].have_textbox = false;
    buttons[4].text.is_display = true;
}