/*
** EPITECH PROJECT, 2021
** shop
** File description:
** desc
*/

#include "my_world.h"

void shop_button_six(my_game_t *my_game, button_t *buttons)
{
    buttons[5] = button_create((sfVector2f){440, 650}, \
    (sfVector2f){100, 100}, true, true);
    button_change_texture(&(buttons[5]), "assets/sprites/tower.png", 1);
    button_change_texture(&(buttons[5]), "assets/sprites/tower.png", 2);
    button_change_texture(&(buttons[5]), "assets/sprites/tower.png", 3);
    button_add_text("Tower :\nPrice : 31250 Coins\nRent : 6 / S", \
    sfFont_createFromFile("assets/fonts/arial.ttf"), sfBlack, &(buttons[5]));
    text_change_pos(&(buttons[5].text), (sfVector2f){440 + 120, 650 + 20});
    button_add_info(&(buttons[5]), (sfVector2f){400, 50}, true, \
    "Select the moving cursor");
    text_change_char_size(&(buttons[5].text), 20);
    button_add_action(&(buttons[5]), &(six_buy), &(six_buy));
    buttons[5].have_textbox = false;
    buttons[5].text.is_display = true;
}

button_t *shop_button_setup(my_game_t *my_game)
{
    button_t *buttons = malloc(sizeof(button_t) * 7);

    shop_button_one(my_game, buttons);
    shop_button_two(my_game, buttons);
    shop_button_three(my_game, buttons);
    shop_button_four(my_game, buttons);
    shop_button_five(my_game, buttons);
    shop_button_six(my_game, buttons);
    return (buttons);
}