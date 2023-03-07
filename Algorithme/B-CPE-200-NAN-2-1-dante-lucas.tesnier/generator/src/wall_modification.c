/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main function
*/

#include "proto.h"

void modification_vertical_two(game_t *game, int pos, int count, int i)
{
    if (pos == count)
        game->actual_line.vwall[i] = false;
}

void modification_vertical(game_t *game)
{
    int *list = malloc(sizeof(int) * game->size_x);
    int list_count = 0;
    int count = 0;
    int pos = 0;

    list[0] = -1;
    for (int i = 0; i < game->size_x; i++) {
        if (my_int_search(list, game->actual_line.value[i], list_count) \
        == false) {
            pos = 0;
            count = get_number_of_value(game, game->actual_line.value[i]);
            count = rand() % (count);
            list[list_count] = game->actual_line.value[i];
            list_count += 1;
        } else if (game->is_perfect == false && rand() % 3 == 1)
            game->actual_line.vwall[i] = false;
        else
            pos += 1;
        modification_vertical_two(game, pos, count, i);
    }
    free(list);
}

void modification_line(game_t *game, bool is_last)
{
    int change = rand() % (game->size_x / 5) + (game->size_x / 2);
    int actual_change = 0;

    if (is_last == true) {
        for (int i = 0; i < game->size_x -1; i++) {
            if (game->actual_line.value[i] != game->actual_line.value[i + 1])
                game->actual_line.hwall[i + 1] = false;
            update_value(game);
        }
        return;
    }
    for (int i = 0; i < change; i++) {
        change_case(game);
        update_value(game);
    }
    modification_vertical(game);
}

void fill_line_with_previous(game_t *game, int actual_y)
{
    for (int i = 0; i < game->size_x; i++) {
        game->prev_line.value[i] = game->actual_line.value[i];
        game->prev_line.vwall[i] = game->actual_line.vwall[i];
    }
    fill_line(game, actual_y * game->size_x - 1);
    for (int i = 0; i < game->size_x; i++) {
        if (game->prev_line.vwall[i] == false) {
            game->actual_line.value[i] = game->prev_line.value[i];
        }
    }
}