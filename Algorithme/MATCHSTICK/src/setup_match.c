/*
** EPITECH PROJECT, 2021
** setup_match.c
** File description:
** setup function match
*/

#include "proto.h"

game_t setup_game(int lines, int max)
{
    game_t game;

    game.is_winning = false;
    game.lines = lines;
    game.max = max;
    game.map = malloc(sizeof(int *) * (lines + 2));
    for (int i = 0; i < lines; i++) {
        game.map[i] = malloc(sizeof(int) * ((lines - 1) * 2 + 10));
        for (int j = 0; j < (lines - 1) * 2 + 1; j++)
            game.map[i][j] = 0;
        game.map[i][(lines - 1) * 2 + 2] = -1;
    }
    return (game);
}

void fill_map(game_t *game)
{
    int actual = 0;

    for (int i = game->lines - 1; i >= 0; i--) {
        for (int j = actual; j < (game->lines - 1) * 2 + 1 - actual; j++)
            game->map[i][j] = 1;
        actual++;
    }
}

int setup_match(int lines, int max)
{
    game_t game;

    srandom(time(NULL));
    if (verification_match(lines, max) == -1)
        return (84);
    game = setup_game(lines, max);
    fill_map(&game);
    return (loop_match(&game));
}
