/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main function
*/

#include "proto.h"

void draw_line_two(game_t *game, bool is_end, char *str)
{
    for (int i = 0; i < game->size_x; i++) {
        if (game->actual_line.vwall[i] == true)
            strcat(str, "XX");
        else
            strcat(str, "X*");
    }
    if (game->original_x % 2 != 0) {
        if (is_end == true)
            game->actual_line.hwall[game->size_x] = false;
        if (game->actual_line.hwall[game->size_x] == true)
            strcat(str, "X");
        else
            strcat(str, "*");
    }
    if (is_end == false)
        strcat(str, "\n");
    write(1, str, strlen(str));
    free(str);
}

void draw_line(game_t *game, bool is_end)
{
    char *str = malloc(sizeof(char) * (10000000));

    str[0] = '\0';
    for (int i = 0; i < game->size_x; i++) {
        if (game->actual_line.hwall[i] == true)
            strcat(str, "X*");
        else
            strcat(str, "**");
    }
    if (game->original_x % 2 != 0) {
        if (game->actual_line.hwall[game->size_x] == true)
            strcat(str, "X");
        else
            strcat(str, "*");
    }
    strcat(str, "\n");
    if (is_end == true)
        game->actual_line.vwall[game->size_x - 1] = false;
    draw_line_two(game, is_end, str);
}