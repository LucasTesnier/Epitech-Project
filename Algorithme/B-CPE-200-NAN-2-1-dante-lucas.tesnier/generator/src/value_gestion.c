/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main function
*/

#include "proto.h"

void fill_line(game_t *game, int count_min)
{
    int count = count_min;

    for (int i = 0; i < game->size_x; i++) {
        game->actual_line.value[i] = count;
        game->actual_line.hwall[i] = true;
        game->actual_line.vwall[i] = true;
        count++;
    }
    game->actual_line.hwall[game->size_x] = true;
}

void change_case(game_t *game)
{
    int choose = rand() % (game->size_x - 1);

    if (game->actual_line.value[choose] != game->actual_line.value[choose + 1])
        game->actual_line.hwall[choose + 1] = false;
    else if (game->is_perfect == false) {
        game->actual_line.hwall[choose + 1] = false;
    }
}

void update_value(game_t *game)
{
    for (int i = 0; i < game->size_x - 1; i++) {
        if (game->actual_line.hwall[i + 1] == false)
            game->actual_line.value[i + 1] = game->actual_line.value[i];
    }
}

bool my_int_search(int *list, int nbr, int list_count)
{
    for (int i = 0; i < list_count; i++)
        if (list[i] == nbr)
            return (true);
    return (false);
}

int get_number_of_value(game_t *game, int nbr)
{
    int count = 0;

    for (int i = 0; i < game->size_x; i++) {
        if (game->actual_line.value[i] == nbr)
            count++;
    }
    return (count);
}