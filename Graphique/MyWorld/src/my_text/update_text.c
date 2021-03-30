/*
** EPITECH PROJECT, 2021
** update_text
** File description:
** desc
*/

#include "my_world.h"

void update_pixel(button_t *buttons, my_game_t *my_game)
{
    char *str = malloc(sizeof(char) * 5);

    str[0] = my_game->radius + '0';
    str[1] = '\0';
    my_strncat(str, " px", 3);
    str[4] = '\0';
    text_change_buffer(&(buttons[9].text), str);
}

void update_gold_text(my_game_t *my_game, text_t *texts)
{
    char *gold = text_convert_int_to_char(my_game->gold);
    char *gold_txt = "You have ";
    char *gold_end = " coins !";
    char *gold_str = malloc(sizeof(char) * (my_strlen(gold) + \
    my_strlen(gold_txt) + my_strlen(gold_end) + 1));

    gold_str[0] = '\0';
    my_strncat(gold_str, gold_txt, my_strlen(gold_txt));
    my_strncat(gold_str, gold, my_strlen(gold));
    my_strncat(gold_str, gold_end, my_strlen(gold_end));
    text_change_buffer(&(texts[2]), gold_str);
    if (my_game->good_buy == 0)
        text_change_fill_color(&(texts[2]), sfRed);
    if (my_game->good_buy == 1)
        text_change_fill_color(&(texts[2]), sfBlack);
}

void update_generation_text(my_game_t *my_game, text_t *texts)
{
    char *generation = text_convert_int_to_char(my_game->gold_generation);
    char *generation_txt = "Actual Generation : ";
    char *generation_end = " / Sec";
    char *generation_str = malloc(sizeof(char) * (my_strlen(generation) +   \
    my_strlen(generation_txt) + my_strlen(generation_end) + 1));

    generation_str[0] = '\0';
    my_strncat(generation_str, generation_txt, my_strlen(generation_txt));
    my_strncat(generation_str, generation, my_strlen(generation));
    my_strncat(generation_str, generation_end, my_strlen(generation_end));
    text_change_buffer(&(texts[1]), generation_str);
}

void update_fps_text(my_game_t *my_game, text_t *texts)
{
    char *fps = text_convert_int_to_char(my_game->fps);
    char *fps_str = malloc(sizeof(char) * (my_strlen(fps) + 5));
    char *fps_txt = "";
    char *fps_end = " FPS";

    fps_str[0] = '\0';
    my_strncat(fps_str, fps, my_strlen(fps));
    my_strncat(fps_str, fps_end, my_strlen(fps_end));
    if (sfTime_asSeconds(sfClock_getElapsedTime(my_game->clock)) >= 1)
        text_change_buffer(&(texts[3]), fps_str);
}

void update_text(my_game_t *my_game, text_t *texts)
{
    update_gold_text(my_game, texts);
    update_generation_text(my_game, texts);
    update_fps_text(my_game, texts);
}