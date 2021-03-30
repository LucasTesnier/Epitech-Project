/*
** EPITECH PROJECT, 2021
** stick_operations.c
** File description:
** stick operations function
*/

#include "proto.h"

int get_nbr_stick(game_t *game, int lines)
{
    int count = 0;

    for (int i = 0; i < (game->lines - 1) * 2 + 1; i++) {
        if (game->map[lines][i] == 1)
            count++;
    }
    return (count);
}

void add_stick(int *act, game_t *game)
{
    int pos = 0;
    int action[] = {act[0], act[1]};
    int save = 0;

    action[0] -= 1;
    for (; game->map[action[0]]\
    [pos] != 1 && pos < (game->lines - 1) * 2; pos++);
    for (int i = 0; i < save; i++) {
        game->map[action[0]][pos + i] = 1;
    }
}

void remove_stick(int *act, game_t *game)
{
    int pos = 0;
    int action[] = {act[0], act[1]};

    action[0] -= 1;
    for (; pos < (game->lines - 1) * 2; pos++);
    for (int i = pos; i >= 0; i--) {
        if (game->map[action[0]][i] == 1) {
            game->map[action[0]][i] = 0;
            action[1] -= 1;
        }
        if (action[1] == 0)
            break;
    }
}
