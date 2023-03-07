/*
** EPITECH PROJECT, 2022
** Malloc
** File description:
** my_free
*/

#ifndef MY_FREE_H_
    #define MY_FREE_H_
    #include "my_block.h"

void my_free(void *ptr);

block_t *convert_ptr_to_block(void *ptr);

#endif /* !MY_FREE_H_ */
