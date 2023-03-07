/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main function
*/

#include "proto.h"

void game_verif_malloc(game_t *game)
{
    if (game->actual_line.value == NULL || game->actual_line.hwall == NULL || \
    game->actual_line.vwall == NULL || game->prev_line.value == NULL || \
    game->prev_line.hwall == NULL || game->prev_line.vwall == NULL) {
        write(2, "Error Malloc.\n", 14);
        exit(0);
    }
}

game_t setup_game(int size_x, int size_y, bool is_perfect)
{
    game_t game;

    srand(time(NULL));
    game.original_y = size_y;
    game.original_x = size_x;
    size_x /= 2;
    size_y /= 2;
    game.size_x = size_x;
    game.size_y = size_y;
    game.is_perfect = is_perfect;
    game.actual_line.value = malloc(sizeof(int) * game.size_x);
    game.actual_line.hwall = malloc(sizeof(bool) * (game.size_x + 1));
    game.actual_line.vwall = malloc(sizeof(bool) * game.size_x);
    game.prev_line.value = malloc(sizeof(int) * game.size_x);
    game.prev_line.hwall = malloc(sizeof(bool) * (game.size_x + 1));
    game.prev_line.vwall = malloc(sizeof(bool) * game.size_x);
    game_verif_malloc(&game);
    return (game);
}

void loop_lab(game_t *game)
{
    for (int i = 0; i < game->size_y; i++) {
        if (i + 1 < game->size_y)
            modification_line(game, false);
        else
            modification_line(game, true);
        if (i == 0)
            game->actual_line.hwall[0] = false;
        if (i + 1 < game->size_y)
            draw_line(game, false);
        else
            draw_line(game, true);
        fill_line_with_previous(game, i + 1);
    }
}

void lab_free(game_t *game)
{
    free(game->actual_line.value);
    free(game->actual_line.hwall);
    free(game->actual_line.vwall);
    free(game->prev_line.vwall);
    free(game->prev_line.value);
    free(game->prev_line.hwall);
}

int setup_lab(int size_x, int size_y, bool is_perfect)
{
    game_t game = setup_game(size_x, size_y, is_perfect);
    int count = 0;

    fill_line(&game, 0);
    if (game.original_y % 2 != 0) {
        write(1, "*X", 2);
        for (int i = 1; i < game.size_x; i++)
            write(1, "XX", 2);
        if (game.original_x % 2 != 0)
            write(1, "X", 1);
        write(1, "\n", 1);
    }
    loop_lab(&game);
    lab_free(&game);
    return (0);
}