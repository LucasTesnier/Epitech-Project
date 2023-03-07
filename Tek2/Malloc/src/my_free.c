/*
** EPITECH PROJECT, 2022
** Malloc
** File description:
** my_free
*/

#include <assert.h>
#include "my_free.h"
#include "my_malloc.h"

block_t *convert_ptr_to_block(void *ptr)
{
    return (block_t *) ptr - 1;
}

void my_free(void *ptr)
{
    if (ptr == NULL)
        return;
    block_t *block = convert_ptr_to_block(ptr);
    assert(block->isFree == false);
    block->isFree = true;
}
