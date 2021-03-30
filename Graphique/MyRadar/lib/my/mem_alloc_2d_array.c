/*
** EPITECH PROJECT, 2020
** mem_alloc_2d_array.c
** File description:
** all mem_alloc_2d_array functions
*/

#include <stdlib.h>

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    int size = 0;
    char **result;

    result = malloc(sizeof(char *) * (nb_rows + 1));
    for (int i = 0; i < nb_rows; i++)
        result[i] = malloc(sizeof(char) * (nb_cols + 1));
    return (result);
}
