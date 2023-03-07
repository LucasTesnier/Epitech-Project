/*
** EPITECH PROJECT, 2022
** Malloc
** File description:
** prototype
*/

#include "my_malloc.h"
#include "my_free.h"
#include "my_realloc.h"
#include "my_calloc.h"
#include "my_realloc_array.h"

void *malloc(size_t size)
{
    return my_malloc(size);
}

void free(void *ptr)
{
    return my_free(ptr);
}

void *realloc(void *ptr, size_t size)
{
    return my_realloc(ptr, size);
}

void *calloc(size_t nmemb, size_t size)
{
    return my_calloc(nmemb, size);
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    return my_reallocarray(ptr, nmemb, size);
}
