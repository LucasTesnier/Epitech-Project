/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-lucas.tesnier
** File description:
** aff
*/

#include "vm.h"
#include "op.h"
#include "my.h"
#include <stdlib.h>

void do_aff_inst(vm_t *machine, champ_t *champ, int *params)
{
    int start = (champ->prog_count + 2) % MEM_SIZE;

    if (machine->mem[start] < 1 || machine->mem[start] > REG_NUMBER)
        return;
    my_putchar(reg_to_int(champ->reg[machine->mem[start] - 1]) % 256);
}

bool inst_aff(vm_t *machine, champ_t *champ)
{
    op_t op = op_tab[15];
    int *params = 0;

    if (!scheduling_check(machine, champ, op.nbr_cycles))
        return (true);
    params = get_inst_parameters(machine, champ, op);
    if (!inst_parms_verif(op, params))
        return (false);
    do_aff_inst(machine, champ, params);
    inst_change_pc(champ, params, op);
    free(params);
    return (true);
}