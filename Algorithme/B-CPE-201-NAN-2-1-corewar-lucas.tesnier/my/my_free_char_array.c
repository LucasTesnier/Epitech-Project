/*
** EPITECH PROJECT, 2021
** my
** File description:
** my_free_char_array.c
*/

#include "my.h"

int my_free_char_array(char **array)
{
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}