/*
** EPITECH PROJECT, 2021
** main
** File description:
** desc
*/

#include "my_world.h"
#include "proto.h"

void init_text2(text_t *texts)
{
    texts[2] = text_create((sfVector2f){1400, 20}, "You have 0 coins",  \
    sfFont_createFromFile("assets/fonts/arial.ttf"), false);
    text_change_buffer(&(texts[2]), "You have 0 coins");
    text_change_char_size(&(texts[2]), 30);
    text_change_fill_color(&(texts[2]), sfBlack);
    texts[3] = text_create((sfVector2f){1800, 20}, "60 FPS",    \
    sfFont_createFromFile("assets/fonts/arial.ttf"), false);
    text_change_buffer(&(texts[3]), "60 FPS");
    text_change_char_size(&(texts[3]), 30);
    text_change_fill_color(&(texts[3]), sfBlack);
}

text_t *init_text(void)
{
    text_t *texts = malloc(sizeof(text_t) * 4);

    texts[0] = text_create((sfVector2f){1400, 950}, \
    "Made by Thomas and Lucas", \
    sfFont_createFromFile("assets/fonts/arial.ttf"), true);
    text_change_buffer(&(texts[0]), "Made by Thomas and Lucas");
    text_change_char_size(&(texts[0]), 40);
    text_change_fill_color(&(texts[0]), sfBlack);
    texts[1] = text_create((sfVector2f){1400, 50},  \
    "Actual Generation : 0 / S",    \
    sfFont_createFromFile("assets/fonts/arial.ttf"), false);
    text_change_buffer(&(texts[1]), "Actual Generation : 0 / S");
    text_change_char_size(&(texts[1]), 30);
    text_change_fill_color(&(texts[1]), sfBlack);
    init_text2(texts);
    return (texts);
}

void display_text(sfRenderWindow *window, text_t *texts)
{
    for (int i = 0; i < 4; i++) {
        text_display(&(texts[i]), window);
    }
}