/*
** EPITECH PROJECT, 2021
** my_init_button
** File description:
** desc
*/

#include "my_world.h"
#include "proto.h"

button_t init_button_eleven(my_game_t *my_game, button_t *buttons)
{
    buttons[10] = button_create((sfVector2f){850, 900}, \
    (sfVector2f){100, 100}, true, false);
    button_change_texture(&(buttons[10]), "assets/buttons/shop1.png", 1);
    button_change_texture(&(buttons[10]), "assets/buttons/shop2.png", 2);
    button_change_texture(&(buttons[10]), "assets/buttons/shop3.png", 3);
    button_add_text("Play", \
    sfFont_createFromFile("assets/fonts/arial.ttf"), sfGreen, &(buttons[10]));
    button_add_info(&(buttons[10]), \
    (sfVector2f){380, 50}, true, "Purchase some buildings !");
    button_info_add_text(&(buttons[10]), \
    "Purchase some buildings !", \
    sfFont_createFromFile("assets/fonts/arial.ttf"), 25);
    text_change_fill_color(&(buttons[10].info.text), sfBlack);
    text_change_pos(&(buttons[10].info.text), \
    (sfVector2f){850 + 100 + 50, 900 - 50});
    button_info_set_texture(&(buttons[10]), \
    "assets/pictures/window_back.png");
    button_add_action(&(buttons[10]), &(shop_on_off), &(shop_on_off));
    buttons[10].have_textbox = true;
    buttons[10].text.is_display = false;
}

button_t init_button_twelve(my_game_t *my_game, button_t *buttons)
{
    buttons[11] = button_create((sfVector2f){1050, 900}, \
    (sfVector2f){100, 100}, true, false);
    button_change_texture(&(buttons[11]), "assets/buttons/backhoe1.png", 1);
    button_change_texture(&(buttons[11]), "assets/buttons/backhoe2.png", 2);
    button_change_texture(&(buttons[11]), "assets/buttons/backhoe3.png", 3);
    button_add_text("Play", sfFont_createFromFile("assets/fonts/arial.ttf"), \
    sfGreen, &(buttons[11]));
    button_add_info(&(buttons[11]), (sfVector2f){380, 50}, true, \
    "Destroys some buildings !");
    button_info_add_text(&(buttons[11]), "Destroys some buildings !", \
    sfFont_createFromFile("assets/fonts/arial.ttf"), 25);
    text_change_fill_color(&(buttons[11].info.text), sfBlack);
    text_change_pos(&(buttons[11].info.text), \
    (sfVector2f){1050 + 100 + 50, 900 - 50});
    button_info_set_texture(&(buttons[11]), "assets/pictures/window_back.png");
    button_add_action(&(buttons[11]), &(backhoe_on_off), &(backhoe_on_off));
    buttons[11].have_textbox = true;
    buttons[11].text.is_display = false;
}

button_t *init_button(my_game_t *my_game)
{
    button_t *buttons = malloc(sizeof(button_t) * 15);

    init_button_one(my_game, buttons);
    init_button_two(my_game, buttons);
    init_button_three(my_game, buttons);
    init_button_four(my_game, buttons);
    init_button_five(my_game, buttons);
    init_button_six(my_game, buttons);
    init_button_seven(my_game, buttons);
    init_button_eight(my_game, buttons);
    init_button_nine(my_game, buttons);
    init_button_ten(my_game, buttons);
    init_button_eleven(my_game, buttons);
    init_button_twelve(my_game, buttons);
    return (buttons);
}

void display_button(sfRenderWindow *window, button_t *buttons)
{
    for (int i = 0; i < 12; i++)
        button_display(&(buttons[i]), window);
}
