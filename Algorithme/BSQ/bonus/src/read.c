/*
** EPITECH PROJECT, 2020
** read.c
** File description:
** reading files
*/

#include "../include/proto.h"

int fs_open_file(char const *filepath)
{
    int file_descriptor;

    file_descriptor = open(filepath, O_RDONLY);
    return (file_descriptor);
}

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    int size = 0;
    char **result;

    result = malloc(sizeof(char *) * (nb_rows + 1));
    for (int i = 0; i < nb_rows; i++)
        result[i] = malloc(sizeof(char) * (nb_cols + 1));
    return (result);
}
