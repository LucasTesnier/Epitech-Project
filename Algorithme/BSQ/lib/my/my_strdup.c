/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** allocates memory and copies string
*/
#include <stdlib.h>
#include "../../include/my.h"

char *my_strdup(char const *src)
{
    char *str;
    int size = 0;
    int i = 0;

    size = my_strlen(src) + 1;
    str = malloc(sizeof(char) * (size + 1));
    my_strncpy(str, src, size);
    return (str);
}
