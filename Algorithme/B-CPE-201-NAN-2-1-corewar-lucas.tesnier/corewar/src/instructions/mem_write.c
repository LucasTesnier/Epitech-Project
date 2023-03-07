/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-lucas.tesnier
** File description:
** write_reg_in_mem
*/

#include "vm.h"
#include "op.h"

void write_reg_in_mem(vm_t *machine, unsigned char *str, int start, \
champ_t *champ)
{
    int count = 0;

    while (start < 0)
        start += MEM_SIZE;
    for (int i = start; i < REG_SIZE + start; i++) {
        machine->mem[i % MEM_SIZE] = str[count];
        count++;
    }
}

void write_a_reg(vm_t *machine, int val, unsigned char *reg)
{
    if (reg == 0)
        return;
    reg[0] = (val >> (8 * 3));
    reg[1] = (val >> (8 * 2)) - (reg[0] << 8);
    reg[2] = (val >> 8) - (reg[0] << (8 * 2)) - (reg[1] << 8);
    reg[3] = (val) - (reg[0] << (8 * 3)) - (reg[1] << (8 * 2)) - (reg[2] << 8);
}