/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** Reproduce the behavior of the strcmp function.
*/
#include "my.h"

int my_strcmp(char const *str, char const *cmp)
{
    int i = 0;
    int length_s;
    int length_c;

    if (!str || !cmp)
        return (-1);
    length_s = my_strlen(str);
    length_c = my_strlen(cmp);
    while (str[i] == cmp[i] && i < length_s && i < length_c) {
        i += 1;
    }
    return (str[i] - cmp[i]);
}
