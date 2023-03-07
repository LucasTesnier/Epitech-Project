/*
** EPITECH PROJECT, 2022
** Malloc
** File description:
** my_malloc
*/

#include "my_malloc.h"
#include <assert.h>
#include <unistd.h>

data_t data = {
    .data_block = NULL
};

block_t *get_free_block(block_t **last, size_t request_size)
{
    block_t *temp = data.data_block;

    while (temp != NULL && (temp->isFree == false ||
    temp->size < request_size)) {
        *last = temp;
        temp = temp->next;
    }
    return temp;
}

size_t align_page(int size)
{
    int pageSize = getpagesize() * 2;
    int rest = size % pageSize;

    return rest? (size + (pageSize - rest)) : size;
}

block_t *get_new_block(block_t *last, size_t request_size)
{
    block_t *new = sbrk(0);
    size_t newSize = align_page(request_size + BLOCK_SIZE);

    if (sbrk(newSize) == (void *) -1)
        return NULL;
    if (last)
        last->next = new;
    new->size = newSize - BLOCK_SIZE;
    new->next = NULL;
    new->isFree = false;
    return new;
}

void *create_new_block(block_t *new, size_t size)
{
    block_t *front = data.data_block;

    new = get_free_block(&front, size);
    if (new == NULL) {
        new = get_new_block(front, size);
        if (new == NULL)
            return NULL;
    } else {
        new->isFree = false;
    }
    return new;
}

void *my_malloc(size_t size)
{
    block_t *new;

    if (size <= 0)
        return NULL;
    size = align_size(size);
    if (data.data_block == NULL) {
        new = get_new_block(NULL, size);
        if (new == NULL)
            return NULL;
        data.data_block = new;
    } else {
        if ((new = create_new_block(new, size)) == NULL)
            return NULL;
    }
    return new + 1;
}
