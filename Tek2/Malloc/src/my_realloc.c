/*
** EPITECH PROJECT, 2022
** Malloc
** File description:
** my_realloc
*/

#include "my_realloc.h"
#include "my_malloc.h"
#include "my_free.h"
#include <string.h>
#include <errno.h>

void *my_realloc(void *ptr, size_t size)
{
    if (ptr == NULL)
        return my_malloc(size);
    if (size <= 0)
        return NULL;
    size = align_size(size);
    block_t *block = convert_ptr_to_block(ptr);
    if (block->size >= size)
        return ptr;
    void *new = my_malloc(size);
    if (new == NULL) {
        errno = ENOENT;
        return NULL;
    }
    memcpy(new, ptr, block->size);
    my_free(ptr);
    return new;
}
