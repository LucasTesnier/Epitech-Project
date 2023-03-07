/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-lucas.tesnier
** File description:
** st
*/

#include "vm.h"
#include "op.h"
#include <stdlib.h>

void do_st_copy_inst(vm_t *machine, champ_t *champ, int start)
{
    start = (start + 1) % MEM_SIZE;
    if (machine->mem[start] < 1 || machine->mem[start] > REG_NUMBER)
        return;
    unsigned_ncopy(champ->reg[machine->mem[start] - 1], \
    champ->reg[machine->mem[(start - 1) % MEM_SIZE] - 1], REG_SIZE);
}

void do_st_write_inst(vm_t *machine, champ_t *champ, int start)
{
    write_reg_in_mem(machine, champ->reg[machine->mem[start] - 1], \
    (champ->prog_count + (hex_to_short(machine, start + 1) % IDX_MOD)) % \
    MEM_SIZE, champ);
}

void do_st_inst(vm_t *machine, champ_t *champ, int param)
{
    int start = (champ->prog_count + 2) % MEM_SIZE;

    if (machine->mem[start] < 1 || machine->mem[start] > REG_NUMBER)
        return;
    if (param == 1)
        do_st_copy_inst(machine, champ, start);
    else
        do_st_write_inst(machine, champ, start);
}

bool inst_st(vm_t *machine, champ_t *champ)
{
    op_t op = op_tab[2];
    int *params = 0;

    if (!scheduling_check(machine, champ, op.nbr_cycles))
        return (true);
    params = get_inst_parameters(machine, champ, op);
    if (!inst_parms_verif(op, params))
        return (false);
    do_st_inst(machine, champ, params[1]);
    inst_change_pc(champ, params, op);
    free(params);
    return (true);
}