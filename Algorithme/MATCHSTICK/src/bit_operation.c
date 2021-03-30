/*
** EPITECH PROJECT, 2021
** ia.c
** File description:
** ia function
*/

#include "proto.h"

int define_bin_max(game_t *game)
{
    int nb = my_square_root((game->lines - 1) * 2 + 1);

    return (nb);
}

char *convert_nbr_in_bin(game_t *game, int size, int nbr)
{
    char *bin = malloc(sizeof(char) * (256));
    int power = 256;
    int count = 0;

    bin[0] = '\0';
    while (power >= 1) {
        if (nbr - power >= 0) {
            bin[count] = '1';
            nbr -= power;
        } else
            bin[count] = '0';
        power /= 2;
        count++;
    }
    bin[count] = '\0';
    return (bin);
}

char **convert_map_in_bin(game_t *game)
{
    char **bin_map = malloc(sizeof(char *) * (game->lines + 1));
    int size = define_bin_max(game);

    for (int i = 0; i < game->lines; i++) {
        bin_map[i] = convert_nbr_in_bin(game, size, get_nbr_stick(game, i));
    }
    return (bin_map);
}

int get_total_bit(char **bin_map, game_t *game)
{
    int bit = 0;

    for (int i = 0; i < game->lines; i++) {
        for (int j = 0; j < my_strlen(bin_map[i]); j++) {
            if (bin_map[i][j] == '1')
                bit += 1;
        }
    }
    return (bit);
}

bool verif_rand(int *action, game_t *game)
{
    char **bin_map;
    game_t games = setup_game(game->lines, game->max);

    games.map = game->map;
    if (get_nbr_stick(game, action[0] - 1) < action[1])
        return (false);
    if (true) {
        remove_stick(action, &games);
        bin_map = convert_map_in_bin(&games);
        add_stick(action, &games);
        if (get_total_bit(bin_map, &games) % 2 == 0) {
            return (false);
        }
    } else {
        action[1] = 1;
        return (true);
    }
    return (true);
}