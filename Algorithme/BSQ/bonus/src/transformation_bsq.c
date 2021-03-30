/*
** EPITECH PROJECT, 2020
** transformation_bsq.c
** File description:
** all function for transformation
*/

#include "../include/proto.h"

void transformation_first_cols(int nb_cols, char **map, int *size)
{
    for (int i = 0; i < nb_cols; i++) {
        if (map[0][i] == size[3])
            map[0][i] = 1;
        if (map[0][i] == size[4])
            map[0][i] = 0;
        if (map[0][i] > size[0]) {
            size[0] = map[0][i];
            size[1] = 0;
            size[2] = i;
        }
    }
}

void transformation_first_row(int nb_rove, char **map, int *size)
{
    for (int i = 0; i < nb_rove; i++) {
        if (map[i][0] == size[3])
            map[i][0] = 1;
        if (map[i][0] == size[4])
            map[i][0] = 0;
        if (map[i][0] > size[0]) {
            size[0] = map[i][0];
            size[1] = i;
            size[2] = 0;
        }
    }
}

void transformation_obstacle(int i, char **map, int nb_cols, int *size)
{
    for (int j = 0; j < nb_cols; j++) {
        if (map[i][j] == 0)
            map[i][j] = size[4];
        if (map[i][j] != size[4] && map[i][j] != size[5])
            map[i][j] = size[3];
    }
}

void transformation_square(int *size, char **map, int nb_rove, int nb_cols)
{
    for (int i = size[1]; i > size[1] - (size[0]); i--) {
        for (int j = size[2]; j > size[2] - (size[0]); j--) {
            map[i][j] = size[5];
        }
    }
    for (int i = 0; i < nb_rove; i++)
        transformation_obstacle(i, map, nb_cols, size);
    for (int i = 0; i < nb_rove; i++) {
        write(1, map[i], nb_cols);
        my_putchar('\n');
    }
}

void transformation_number(int i, int j, char **map, int *size)
{
    if (map[i][j] == size[4])
        map[i][j] = 0;
    else
        find_min_number(i, j, map, size);
}

