/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-lucas.tesnier
** File description:
** and
*/

#include "vm.h"
#include "op.h"
#include <stdlib.h>

bool and_param_zero(vm_t *machine, champ_t *champ, \
int start, unsigned char *val_one)
{
    if (!val_one)
        return (false);
    if (machine->mem[start - 1] < 1 || machine->mem[start - 1] > REG_NUMBER)
        return (false);
    unsigned_ncopy(val_one, champ->reg[machine->mem[start] - 1], REG_SIZE);
    return (true);
}

bool and_param_one(vm_t *machine, champ_t *champ, \
int start, unsigned char *val_two)
{
    if (!val_two)
        return (false);
    if (machine->mem[start + 1] < 1 || machine->mem[start + 1] > REG_NUMBER)
        return false;
    unsigned_ncopy(val_two, champ->reg[machine->mem[start + 1] - 1], REG_SIZE);
    return true;
}

void set_start_from_param(vm_t *machine, int param, unsigned char *val, \
int *start)
{
    switch (param) {
    case 3:
        val[0] = 0;
        val[1] = 0;
        val[2] = machine->mem[*start];
        val[3] = machine->mem[(*start + 1) % MEM_SIZE];
        *start += 1;
        break;
    case 2:
        for (int i = 0; i < REG_SIZE; i++)
            val[i] = machine->mem[(i + *start) % MEM_SIZE];
        *start += 3;
        break;
    }
    *start += 1;
}

void do_and_inst(vm_t *machine, champ_t *champ, int *params)
{
    int start = (champ->prog_count + 2) % MEM_SIZE;
    unsigned char val_one[REG_SIZE + 1];
    unsigned char val_two[REG_SIZE + 1];

    if (params[0] == 1)
        if (!and_param_zero(machine, champ, start, val_one))
            return;
    set_start_from_param(machine, params[0], val_one, &start);
    if (params[1] == 1)
        if (!and_param_one(machine, champ, start, val_two))
            return;
    set_start_from_param(machine, params[0], val_one, &start);
    if (machine->mem[start] < 1 || machine->mem[start] > REG_NUMBER)
        return;
    for (int j = 0; j < REG_SIZE; j++)
        champ->reg[machine->mem[start] - 1][j] = (val_one[j] & val_two[j]);
    champ->carry = false;
    if (reg_to_int(champ->reg[machine->mem[start] - 1]) == 0)
        champ->carry = true;
}

bool inst_and(vm_t *machine, champ_t *champ)
{
    op_t op = op_tab[5];
    int *params = 0;

    if (!scheduling_check(machine, champ, op.nbr_cycles))
        return (true);
    params = get_inst_parameters(machine, champ, op);
    if (!inst_parms_verif(op, params))
        return (false);
    do_and_inst(machine, champ, params);
    inst_change_pc(champ, params, op);
    free(params);
    return (true);
}