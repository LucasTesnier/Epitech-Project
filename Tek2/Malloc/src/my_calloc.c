/*
** EPITECH PROJECT, 2022
** Malloc
** File description:
** my_calloc
*/

#include "my_malloc.h"
#include <string.h>
#include <errno.h>

void *my_calloc(size_t nmemb, size_t size)
{
    size_t temp = nmemb * size;

    if (temp / nmemb != size) {
        errno = ENOENT;
        return NULL;
    }
    void *new = my_malloc(temp);
    memset(new, 0, temp);
    return new;
}
