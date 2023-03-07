/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-lucas.tesnier
** File description:
** insert_size
*/

#include "asm.h"
#include "op.h"
#include "my.h"

/**
* @brief insert entry size to write for .cor files in byte
*
* @param op_code
* @param entry
* @param arg
* @param arg_idx
*/
int insert_size(int op_code, int *entry, char *arg, int arg_idx)
{
    if (arg_idx == 0) {
        *entry = 1;
        return (1);
    }
    if (*arg == 'r') {
        *entry = 1;
        return (2);
    }
    if (*arg == DIRECT_CHAR && arg[1] != LABEL_CHAR) {
        *entry = 4;
        if (op_code == 9 || op_code == 10 || op_code == 11 || op_code == 12 \
            || op_code == 14 || op_code == 15)
            *entry = 2;
        return (3);
    }
    *entry = 2;
    return (4);
}