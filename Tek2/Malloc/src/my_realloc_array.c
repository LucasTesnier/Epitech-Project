/*
** EPITECH PROJECT, 2022
** Malloc
** File description:
** my_realloc_array
*/

#include "my_malloc.h"
#include "my_realloc.h"
#include "my_realloc_array.h"
#include "my_free.h"
#include <string.h>
#include <errno.h>

void *my_reallocarray(void *ptr, size_t nmemb, size_t size)
{
    size_t temp = nmemb * size;

    if (temp / nmemb != size) {
        errno = ENOENT;
        return NULL;
    }
    return my_realloc(ptr, temp);
}
