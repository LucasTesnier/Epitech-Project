/*
** EPITECH PROJECT, 2020
** my_strncmp
** File description:
** reproduce the behavior of the strncmp function
*/

#include "my.h"

int my_strncmp(char const *str, char const *cmp, int n)
{
    int i = 0;

    while (i != n - 1 && str[i] == cmp[i] && str[i] != '\0' && cmp[i] != '\0')
        i += 1;
    return (str[i] - cmp[i]);
}