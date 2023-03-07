/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** This function counts and returns the number of characters found in the
** string passed as parameter.
*/
#include "my.h"

int my_strlen(char const *str)
{
    int i;

    if (!str)
        return (-1);
    for (i = 0; str[i] != '\0'; i += 1);
    return (i);
}
