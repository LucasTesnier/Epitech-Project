/*
** EPITECH PROJECT, 2020
** B-PSU-101-NAN-1-1-navy-lucas.tesnier
** File description:
** init_map
*/

#include "my.h"
#include "navy.h"

int **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    int size = 0;
    int **result;

    result = malloc(sizeof(int *) * (nb_rows + 1));
    for (int i = 0; i < nb_rows; i++)
        result[i] = malloc(sizeof(int) * (nb_cols + 1));
    return (result);
}

void initialisation_map(game_info_t *game_inf)
{
    game_inf->player_map = mem_alloc_2d_array(8, 8);
    game_inf->opponent = mem_alloc_2d_array(8, 8);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            game_inf->player_map[i][j] = 0;
            game_inf->opponent[i][j] = 0;
        }
    }
}
