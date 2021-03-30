/*
** EPITECH PROJECT, 2021
** ia.c
** File description:
** ia function
*/

#include "proto.h"

int	my_square_root(int nb)
{
    int i;

    i = 0;
    if (nb < 0)
        return (0);
    while ((i * i) != nb) {
        if ((i * i) > nb)
            return (i);
        i = i + 1;
    }
    return (i);
}

bool have_enough_stick(game_t *game)
{
    for (int i = 0; i < game->lines; i++) {
        if (get_nbr_stick(game, i) > 1) {
            return (false);
        }
    }
    return (true);
}

int *get_ai(game_t *game)
{
    int *action = malloc(sizeof(int) * 2);

    action[0] = random() % game->lines + 1;
    action[1] = random() % game->max + 1;
    if (get_nbr_stick(game, action[0] - 1) < action[1])
        return (get_ai(game));
    my_putstr("AI removed ");
    my_put_nbr(action[1]);
    my_putstr(" match(es) from line ");
    my_put_nbr(action[0]);
    my_putchar('\n');
    return (action);
}
