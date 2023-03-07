/*
** EPITECH PROJECT, 2022
** Malloc
** File description:
** my_block
*/

#ifndef MY_BLOCK_H_
    #define MY_BLOCK_H_
    #define BLOCK_SIZE sizeof(struct block_s)

    #include <stdbool.h>
    #include <stddef.h>

typedef struct block_s {
    size_t size;
    bool isFree;
    struct block_s *next;
} block_t;

#endif /* !MY_BLOCK_H_ */
