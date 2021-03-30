/*
** EPITECH PROJECT, 2020
** button.c
** File description:
** function button
*/

#include "../../../include/proto.h"

void button_add_info(button_t *button, sfVector2f size, \
bool have_texture, char *buffer)
{
    button->info = textbox_create((sfVector2f){button->area[1].x + 10, \
        button->area[1].y - 10 - size.y}, size, have_texture);
}

void button_info_add_text(button_t *button, char *buffer, \
sfFont *font, int size)
{
    textbox_set_text(&(button->info), size, buffer, font);
}

void button_info_set_texture(button_t *button, char *path)
{
    textbox_set_texture(&(button->info), path);
}

void button_info_set_color(button_t *button, sfColor color)
{
    textbox_set_color(&(button->info), color);
}

void button_add_action(button_t *button, void (*action)(my_game_t *), \
void (*action_unclick)(my_game_t *))
{
    button->action = action;
    button->action_unclick = action_unclick;
}
