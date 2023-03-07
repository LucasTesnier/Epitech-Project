/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-lucas.tesnier
** File description:
** ld
*/

#include "my.h"
#include "vm.h"
#include "op.h"
#include <stdlib.h>

void ld_inst_dir(vm_t *machine, champ_t *champ)
{
    int start = (champ->prog_count + 2) % MEM_SIZE;

    if (machine->mem[(start + REG_SIZE) % MEM_SIZE] < 1 ||
        machine->mem[(start + REG_SIZE) % MEM_SIZE] > REG_NUMBER)
        return;
    for (int i = 0; i < REG_SIZE; i++) {
        champ->reg[machine->mem[(start + REG_SIZE - i) % MEM_SIZE] - 1][i] =
        machine->mem[start % MEM_SIZE];
        start++;
    }
    champ->carry = false;
    start %= MEM_SIZE;
    if (reg_to_int(champ->reg[machine->mem[start] - 1]) == 0)
        champ->carry = true;
}

void ld_inst_indir(vm_t *machine, champ_t *champ)
{
    int start = (champ->prog_count + 2) % MEM_SIZE;
    int val = (int)hex_to_short(machine, start);

    start = (start + 2) % MEM_SIZE;
    if (machine->mem[start] < 1 || machine->mem[start] > REG_NUMBER)
        return;
    val = (champ->prog_count + (val % IDX_MOD)) % MEM_SIZE;
    for (int i = 0; i < REG_SIZE; i++) {
        champ->reg[machine->mem[start] - 1][i] = machine->mem[val];
        val = (val + 1) % MEM_SIZE;
    }
    champ->carry = false;
    if (reg_to_int(champ->reg[machine->mem[start] - 1]) == 0)
        champ->carry = true;
}

void do_ld_inst(vm_t *machine, champ_t *champ, int param)
{
    if (param == 2)
        ld_inst_dir(machine, champ);
    else
        ld_inst_indir(machine, champ);
}

bool inst_ld(vm_t *machine, champ_t *champ)
{
    op_t op = op_tab[1];
    int *params = NULL;

    if (!scheduling_check(machine, champ, op.nbr_cycles))
        return (true);
    params = get_inst_parameters(machine, champ, op);
    if (!inst_parms_verif(op, params))
        return (false);
    do_ld_inst(machine, champ, params[0]);
    inst_change_pc(champ, params, op);
    free(params);
    return (true);
}