/*
** EPITECH PROJECT, 2021
** text.c
** File description:
** text.c
*/

#include "proto.h"

void text_change_thickness(text_t *text, float thick)
{
    text->thickness = thick;
    sfText_setOutlineThickness(text->text, thick);
}

void text_change_char_size(text_t *text, int size)
{
    text->char_size = size;
    sfText_setCharacterSize(text->text, size);
}

void text_change_is_display(text_t *text, bool is_display)
{
    text->is_display = is_display;
}