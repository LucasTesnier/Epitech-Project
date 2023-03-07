/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-lucas.tesnier
** File description:
** conver_values
*/

#include "vm.h"
#include "my.h"
#include "op.h"

short hex_to_short(vm_t *machine, int start)
{
    short res = 0;

    while (start < 0)
        start = MEM_SIZE - start;
    res = machine->mem[start % MEM_SIZE];
    res = (res << 8);
    res += machine->mem[(start + 1) % MEM_SIZE];
    return (res);
}

int reg_to_int(unsigned char *reg)
{
    int res = 0;

    if (!reg)
        return (0);
    res += reg[0];
    for (int i = 1; i < 4; i++) {
        res = (res << 8);
        res += reg[i];
    }
    return (res);
}