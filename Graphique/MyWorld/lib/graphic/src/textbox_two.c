/*
** EPITECH PROJECT, 2021
** textbox_two.c
** File description:
** textbox_two.c
*/

#include "proto.h"

void textbox_change_display(textbox_t *textbox, bool is_display)
{
    textbox->is_display = is_display;
    textbox->text.is_display = is_display;
}