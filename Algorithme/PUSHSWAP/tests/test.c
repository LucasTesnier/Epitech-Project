/*
** EPITECH PROJECT, 2020
** test.c
** File description:
** all TU
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/proto.h"

int push_swap(int ac, char *argv[]);

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    int size = 0;
    char **result;

    result = malloc(sizeof(char *) * (nb_rows + 1));
    for (int i = 0; i < nb_rows; i++)
        result[i] = malloc(sizeof(char) * (nb_cols + 1));
    return (result);
}

Test(test_error, impossible_read)
{
    char **number = mem_alloc_2d_array(10, 10);

    for (int i = 0; i < 10; i++) {
        number[i] = 10 - i;
    }
    push_swap(10, number);
}
