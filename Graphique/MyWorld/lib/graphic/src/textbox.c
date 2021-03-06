/*
** EPITECH PROJECT, 2020
** textbox.c
** File description:
** textbox
*/

#include "proto.h"

textbox_t textbox_create(sfVector2f pos, sfVector2f size, bool have_texture)
{
    textbox_t textbox;

    textbox.background = sfRectangleShape_create();
    textbox.pos = pos;
    sfRectangleShape_setPosition(textbox.background, pos);
    textbox.size = size;
    sfRectangleShape_setSize(textbox.background, size);
    textbox.have_texture = have_texture;
    textbox.is_display = false;
    return (textbox);
}

void textbox_set_text(textbox_t *textbox, int size, char *buffer, sfFont* font)
{
    textbox->text = text_create((sfVector2f){textbox->pos.x + 10, \
        textbox->pos.y + 10}, buffer, font, textbox->is_display);
    text_change_char_size(&(textbox->text), size);
}

void textbox_set_texture(textbox_t *textbox, char *texture)
{
    sfRectangleShape_setTexture(textbox->background, sfTexture_createFromFile(\
    texture, NULL), true);
    textbox->texture = sfTexture_createFromFile(texture, NULL);
}

void textbox_set_color(textbox_t *textbox, sfColor color)
{
    sfRectangleShape_setFillColor(textbox->background, color);
}

void textbox_display(textbox_t *textbox, sfRenderWindow *window)
{
    if (textbox->is_display == true) {
        sfRenderWindow_drawRectangleShape(window, textbox->background, NULL);
        text_display(&(textbox->text), window);
    }
}