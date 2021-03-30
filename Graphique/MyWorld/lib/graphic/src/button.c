/*
** EPITECH PROJECT, 2020
** button.c
** File description:
** function button
*/

#include "proto.h"

button_t button_create(sfVector2f pos, sfVector2f size, bool have_texture, \
bool is_display)
{
    button_t button;

    button.button = sfRectangleShape_create();
    button.pos = pos;
    sfRectangleShape_setPosition(button.button, pos);
    button.size = size;
    sfRectangleShape_setSize(button.button, size);
    button.area[0] = pos;
    button.area[1] = (sfVector2f){pos.x + size.x, pos.y};
    button.area[2] = (sfVector2f){pos.x, pos.y + size.y};
    button.area[3] = (sfVector2f){pos.x + size.x, pos.y + size.y};
    button.have_texture = have_texture;
    button.is_pressed = false;
    button.is_up = false;
    button.is_display = is_display;
    return (button);
}

void button_add_text(char *buffer, sfFont *font, sfColor color, \
button_t *button)
{
    button->text = text_create((sfVector2f){button->pos.x + \
        button->size.x / 2 - (my_stlen(buffer) * 5 / 2), button->pos.y + \
        button->size.y / 2 - 10}, buffer, font, button->is_display);
    text_change_fill_color(&(button->text), color);
    text_change_char_size(&(button->text), 30);
}

void button_change_texture(button_t *button, char *texture, int number)
{
    if (number == 1) {
        sfRectangleShape_setTexture(button->button, sfTexture_createFromFile(\
        texture, NULL), true);
        button->state_one = sfTexture_createFromFile(texture, NULL);
    }
    if (number == 2) {
        button->state_two = sfTexture_createFromFile(texture, NULL);
    }
    if (number == 3) {
        button->state_three = sfTexture_createFromFile(texture, NULL);
    }
}

void button_change_color(button_t *button, sfColor color, int number)
{
    if (number == 1) {
        sfRectangleShape_setFillColor(button->button, color);
        button->step_one = color;
    }
    if (number == 2) {
        button->step_two = color;
    }
    if (number == 3) {
        button->step_three = color;
    }
}

void button_display(button_t *button, sfRenderWindow *window)
{
    if (button->is_display == true) {
        sfRenderWindow_drawRectangleShape(window, button->button, NULL);
        if (button->text.is_display == true)
            sfRenderWindow_drawText(window, button->text.text, NULL);
        textbox_display(&(button->info), window);
    }
}