/*
** EPITECH PROJECT, 2022
** Malloc
** File description:
** my_malloc
*/

#ifndef MY_MALLOC_H_
    #define MY_MALLOC_H_

    #ifndef __x86_64__
        #define align_size(x) ((((x) - 1)>>4)<<4) + 8
    #else
        #define align_size(x) ((((x) - 1)>>2)<<2) + 4
    #endif

    #include <stddef.h>
    #include "my_block.h"

typedef struct data_s {
    void *data_block;
} data_t;

extern data_t data;

void *my_malloc(size_t size);

#endif /* !MY_MALLOC_H_ */
