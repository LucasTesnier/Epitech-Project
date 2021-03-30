/*
** EPITECH PROJECT, 2021
** loop.c
** File description:
** loop function
*/

#include "proto.h"

bool verif_win_two(game_t *game, int i)
{
    for (int j = 0; j < (game->lines - 1) * 2 + 1; j++)
        if (game->map[i][j] == 1)
            return (false);
    return (true);
}

bool verif_win(game_t *game)
{
    for (int i = 0; i < game->lines; i++) {
        if (verif_win_two(game, i) == false)
            return (false);
    }
    return (true);
}

int loop_match_ia(game_t *game, int *action)
{
    my_putstr("\nAI's turn...\n");
    action = get_ai(game);
    remove_stick(action, game);
    display_map(game);
}

int loop_match(game_t *game)
{
    int *action;

    display_map(game);
    while (game->is_winning == false) {
        if (verif_win(game) == true) {
            my_putstr("I lost... snif... but I'll get you next time!!\n");
            return (1);
        }
        my_putchar('\n');
        my_putstr("Your turn:\n");
        action = get_user(game);
        if (action == NULL)
            return (0);
        remove_stick(action, game);
        display_map(game);
        if (verif_win(game) == true) {
            my_putstr("You lost, too bad...\n");
            return (2);
        }
        loop_match_ia(game, action);
    }
}
