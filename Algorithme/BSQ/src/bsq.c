/*
** EPITECH PROJECT, 2020
** bsq.c
** File description:
** bsq files
*/

#include "../include/proto.h"

int bsq(char const *filepath)
{
    char *buffer = load_file_in_mem(filepath);
    int nb_rows = -1;
    int nb_cols = 0;
    int count = 0;
    char **map;

    if (buffer_modification(buffer, &nb_rows, &count) == 84)
        return (84);
    if (cols_setup(&count, buffer, &nb_cols) == 84)
        return (84);
    map = load_2d_arr_from_file(filepath, nb_rows, nb_cols, \
    my_strlen(buffer) + 1);
    for (int i = 0; i < nb_rows; i++) {
        if (verification_map(i, nb_cols, map) == 84)
            return (84);
    }
    find_biggest_square(map, nb_rows, nb_cols);
}

void find_min_number(int i, int j, char **map, int *size)
{
    int save1 = map[i - 1][j - 1];
    int save2 = map[i][j - 1];
    int save3 = map[i - 1][j];

    if (save1 <= save2 && save1 <= save3)
        map[i][j] = save1 + 1;
    if (save2 <= save1 && save2 <= save3)
        map[i][j] = save2 + 1;
    if (save3 <= save1 && save3 <= save2)
        map[i][j] = save3 + 1;
    if (map[i][j] > size[0]) {
        size[0] = map[i][j];
        size[1] = i;
        size[2] = j;
    }
}

int find_biggest_square(char **map, int nb_rove, int nb_cols)
{
    int coord[3] = {0};
    int size[3] = {0};

    transformation_first_cols(nb_cols, map, size);
    transformation_first_row(nb_rove, map, size);
    for (int i = 1; i < nb_rove; i++) {
        for (int j = 1; j < nb_cols; j++)
            transformation_number(i, j, map, size);
    }
    transformation_square(size, map, nb_rove, nb_cols);
}
