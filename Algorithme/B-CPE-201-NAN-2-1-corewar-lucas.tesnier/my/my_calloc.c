/*
** EPITECH PROJECT, 2020
** my_calloc.c
** File description:
** My calloc
*/

#include <stdlib.h>
#include <stddef.h>
#include "my.h"

void *my_calloc(size_t nmemb, size_t size, char default_char)
{
    char *s = malloc(nmemb * size);

    if (s == NULL)
        return (NULL);
    my_memset_char(s, default_char, size);
    s[size - 1] = '\0';
    return (s);
}
