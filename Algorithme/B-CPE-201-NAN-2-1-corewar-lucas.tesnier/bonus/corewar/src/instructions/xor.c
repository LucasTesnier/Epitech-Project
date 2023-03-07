/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-lucas.tesnier
** File description:
** xor
*/

#include "vm.h"
#include "op.h"
#include <stdlib.h>

bool xor_param_zero(vm_t *machine, champ_t *champ, \
int start, unsigned char *val_one)
{
    if (!val_one)
        return (false);
    if (machine->mem[start - 1] < 1 || machine->mem[start - 1] > REG_NUMBER)
        return (false);
    unsigned_ncopy(val_one, champ->reg[machine->mem[start] - 1], REG_SIZE);
    return (true);
}

bool xor_param_one(vm_t *machine, champ_t *champ, \
int start, unsigned char *val_two)
{
    if (!val_two)
        return (false);
    if (machine->mem[start + 1] < 1 || machine->mem[start + 1] > REG_NUMBER)
        return false;
    unsigned_ncopy(val_two, champ->reg[machine->mem[start + 1] - 1], REG_SIZE);
    return true;
}

void do_xor_inst(vm_t *machine, champ_t *champ, int *params)
{
    int start = (champ->prog_count + 2) % MEM_SIZE;
    unsigned char val_one[REG_SIZE + 1];
    unsigned char val_two[REG_SIZE + 1];

    if (params[0] == 1)
        if (!xor_param_zero(machine, champ, start, val_one))
            return;
    set_start_from_param(machine, params[0], val_one, &start);
    if (params[1] == 1)
        if (!xor_param_one(machine, champ, start, val_two))
            return;
    set_start_from_param(machine, params[0], val_one, &start);
    if (machine->mem[start] < 1 || machine->mem[start] > REG_NUMBER)
        return;
    for (int j = 0; j < REG_SIZE; j++)
        champ->reg[machine->mem[start] - 1][j] = (val_one[j] ^ val_two[j]);
    champ->carry = false;
    if (reg_to_int(champ->reg[machine->mem[start] - 1]) == 0)
        champ->carry = true;
}

bool inst_xor(vm_t *machine, champ_t *champ)
{
    op_t op = op_tab[7];
    int *params = 0;

    if (!scheduling_check(machine, champ, op.nbr_cycles))
        return (true);
    params = get_inst_parameters(machine, champ, op);
    if (!inst_parms_verif(op, params))
        return (false);
    do_xor_inst(machine, champ, params);
    inst_change_pc(champ, params, op);
    free(params);
    return (true);
}