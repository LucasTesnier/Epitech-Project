/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-lucas.tesnier
** File description:
** sub
*/

#include "vm.h"
#include "op.h"
#include <stdlib.h>

void do_sub_inst(vm_t *machine, champ_t *champ)
{
    int start = (champ->prog_count + 2) % MEM_SIZE;
    int val_one = 0;
    int val_two = 0;

    if (machine->mem[start] < 1 || machine->mem[start] > REG_NUMBER)
        return;
    val_one = reg_to_int(champ->reg[machine->mem[start] - 1]);
    start = (start + 1) % MEM_SIZE;
    if (machine->mem[start] < 1 || machine->mem[start] > REG_NUMBER)
        return;
    val_two = reg_to_int(champ->reg[machine->mem[start] - 1]);
    start = (start + 1) % MEM_SIZE;
    if (machine->mem[start] < 1 || machine->mem[start] > REG_NUMBER)
        return;
    champ->carry = false;
    if ((val_one - val_two) == 0)
        champ->carry = true;
    write_a_reg(machine, val_two - val_one, \
    champ->reg[machine->mem[start] - 1]);
}

bool inst_sub(vm_t *machine, champ_t *champ)
{
    op_t op = op_tab[4];
    int *params = 0;

    if (!scheduling_check(machine, champ, op.nbr_cycles))
        return (true);
    params = get_inst_parameters(machine, champ, op);
    if (!inst_parms_verif(op, params))
        return (false);
    do_sub_inst(machine, champ);
    inst_change_pc(champ, params, op);
    free(params);
    return (true);
}