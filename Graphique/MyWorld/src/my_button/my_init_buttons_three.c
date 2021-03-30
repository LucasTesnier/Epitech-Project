/*
** EPITECH PROJECT, 2021
** my_init_button
** File description:
** desc
*/

#include "my_world.h"
#include "proto.h"

button_t init_button_six(my_game_t *my_game, button_t *buttons)
{
    buttons[5] = button_create((sfVector2f){1250, 900}, \
    (sfVector2f){100, 100}, true, false);
    button_change_texture(&(buttons[5]), "assets/buttons/new1.png", 1);
    button_change_texture(&(buttons[5]), "assets/buttons/new2.png", 2);
    button_change_texture(&(buttons[5]), "assets/buttons/new3.png", 3);
    button_add_text("Play", \
    sfFont_createFromFile("assets/fonts/arial.ttf"), sfGreen, &(buttons[5]));
    button_add_info(&(buttons[5]), \
    (sfVector2f){350, 50}, true, "Generate a new map");
    button_info_add_text(&(buttons[5]), \
    "Generate a new map", sfFont_createFromFile("assets/fonts/arial.ttf"), 25);
    text_change_fill_color(&(buttons[5].info.text), sfBlack);
    text_change_pos(&(buttons[5].info.text), \
    (sfVector2f){1250 + 100 + 65, 900 - 50});
    button_info_set_texture(&(buttons[5]), \
    "assets/pictures/window_back.png");
    button_add_action(&(buttons[5]), &(new_map), &(new_map));
    buttons[5].have_textbox = true;
    buttons[5].text.is_display = false;
}

button_t init_button_seven(my_game_t *my_game, button_t *buttons)
{
    buttons[6] = button_create((sfVector2f){1450, 900}, \
    (sfVector2f){100, 100}, true, false);
    button_change_texture(&(buttons[6]), "assets/buttons/save1.png", 1);
    button_change_texture(&(buttons[6]), "assets/buttons/save2.png", 2);
    button_change_texture(&(buttons[6]), "assets/buttons/save3.png", 3);
    button_add_text("Play", \
    sfFont_createFromFile("assets/fonts/arial.ttf"), sfGreen, &(buttons[6]));
    button_add_info(&(buttons[6]), (sfVector2f){350, 50}, true, \
    "Save the current map");
    button_info_add_text(&(buttons[6]), "Save the current map", \
    sfFont_createFromFile("assets/fonts/arial.ttf"), 25);
    text_change_fill_color(&(buttons[6].info.text), sfBlack);
    text_change_pos(&(buttons[6].info.text), \
    (sfVector2f){1450 + 100 + 59, 900 - 50});
    button_info_set_texture(&(buttons[6]), "assets/pictures/window_back.png");
    button_add_action(&(buttons[6]), &(save_map), &(save_map));
    buttons[6].have_textbox = true;
    buttons[6].text.is_display = false;
}

button_t init_button_eight(my_game_t *my_game, button_t *buttons)
{
    buttons[7] = button_create((sfVector2f){1650, 900}, \
    (sfVector2f){100, 100}, true, false);
    button_change_texture(&(buttons[7]), "assets/buttons/load1.png", 1);
    button_change_texture(&(buttons[7]), "assets/buttons/load2.png", 2);
    button_change_texture(&(buttons[7]), "assets/buttons/load3.png", 3);
    button_add_text("Play", \
    sfFont_createFromFile("assets/fonts/arial.ttf"), sfGreen, &(buttons[7]));
    button_add_info(&(buttons[7]), (sfVector2f){250, 50}, true, "Load a map");
    button_info_add_text(&(buttons[7]), "Load a map", \
    sfFont_createFromFile("assets/fonts/arial.ttf"), 25);
    text_change_fill_color(&(buttons[7].info.text), sfBlack);
    text_change_pos(&(buttons[7].info.text), \
    (sfVector2f){1450 + 100 + 65, 900 - 50});
    sfRectangleShape_setPosition(buttons[7].info.background, \
    (sfVector2f){1560, 840});
    button_info_set_texture(&(buttons[7]), "assets/pictures/window_back.png");
    button_add_action(&(buttons[7]), &(load_map), &(load_map));
    buttons[7].have_textbox = true;
    buttons[7].text.is_display = false;
}

button_t init_button_nine(my_game_t *my_game, button_t *buttons)
{
    buttons[8] = button_create((sfVector2f){650, 900}, \
    (sfVector2f){100, 100}, true, false);
    button_change_texture(&(buttons[8]), "assets/buttons/cleaner1.png", 1);
    button_change_texture(&(buttons[8]), "assets/buttons/cleaner2.png", 2);
    button_change_texture(&(buttons[8]), "assets/buttons/cleaner3.png", 3);
    button_add_text("Play", \
    sfFont_createFromFile("assets/fonts/arial.ttf"), sfGreen, &(buttons[8]));
    button_add_info(&(buttons[8]), (sfVector2f){370, 50}, true, \
    "Select the cleaner cursor");
    button_info_add_text(&(buttons[8]), "Select the cleaner cursor", \
    sfFont_createFromFile("assets/fonts/arial.ttf"), 25);
    text_change_fill_color(&(buttons[8].info.text), sfBlack);
    text_change_pos(&(buttons[8].info.text), \
    (sfVector2f){650 + 100 + 50, 900 - 50});
    button_info_set_texture(&(buttons[8]), "assets/pictures/window_back.png");
    button_add_action(&(buttons[8]), &(gomme_on_off), &(gomme_on_off));
    buttons[8].have_textbox = true;
    buttons[8].text.is_display = false;
}

button_t init_button_ten(my_game_t *my_game, button_t *buttons)
{
    buttons[9] = button_create((sfVector2f){50, 20}, \
    (sfVector2f){100, 100}, true, false);
    button_change_texture(&(buttons[9]), "assets/buttons/size1.png", 1);
    button_change_texture(&(buttons[9]), "assets/buttons/size1.png", 2);
    button_change_texture(&(buttons[9]), "assets/buttons/size3.png", 3);
    button_add_text("1 px", \
    sfFont_createFromFile("assets/fonts/arial.ttf"), sfBlack, &(buttons[9]));
    text_change_pos(&(buttons[9].text), (sfVector2f){150, 50});
    button_add_info(&(buttons[9]), \
    (sfVector2f){400, 75}, true, "Change the range of tools");
    button_info_add_text(&(buttons[9]), "1 px", \
    sfFont_createFromFile("assets/fonts/arial.ttf"), 25);
    text_change_fill_color(&(buttons[9].info.text), sfBlack);
    text_change_pos(&(buttons[9].info.text), \
    (sfVector2f){360 + 100 + 50, 75 - 50});
    button_info_set_texture(&(buttons[9]), "assets/pictures/window_back.png");
    button_add_action(&(buttons[9]), &(update_radius), &(update_radius));
    buttons[9].have_textbox = false;
    buttons[9].text.is_display = true;
}
