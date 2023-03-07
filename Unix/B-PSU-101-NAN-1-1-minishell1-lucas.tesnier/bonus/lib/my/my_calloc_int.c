/*
** EPITECH PROJECT, 2020
** my_calloc.c
** File description:
** My calloc
*/
#include <stdlib.h>
#include "my.h"

int *my_calloc_int(size_t nmemb, size_t size, int default_int)
{
    int *t = malloc(nmemb * (size + 1));

    if (t == NULL)
        return (NULL);
    my_memset_int(t, default_int, size);
    return (t);
}
