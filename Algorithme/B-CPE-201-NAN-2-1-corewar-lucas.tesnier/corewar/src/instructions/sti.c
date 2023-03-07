/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-lucas.tesnier
** File description:
** sti
*/

#include "op.h"
#include "vm.h"
#include <stdlib.h>

int sti_get_adress(vm_t *machine, champ_t *champ, int param, int *start)
{
    int res = 0;

    if (param != 1) {
        res += hex_to_short(machine, *start);
        *start += 2;
        return (res);
    }
    if (machine->mem[*start] < 1 || machine->mem[*start] > REG_NUMBER) {
        *start = -1;
        return (-1);
    }
    res += reg_to_int(champ->reg[machine->mem[*start] - 1]);
    *start += 1;
    return (res);
}

void do_sti_inst(vm_t *machine, champ_t *champ, int *params)
{
    int start = (champ->prog_count + 3) % MEM_SIZE;
    int tmp = 0;

    tmp += sti_get_adress(machine, champ, params[1], &start);
    if (start == -1)
        return;
    tmp += sti_get_adress(machine, champ, params[2], &start);
    if (start == -1)
        return;
    start = (champ->prog_count + 2) % MEM_SIZE;
    if (machine->mem[start] < 1 || machine->mem[start] > REG_NUMBER)
        return;
    write_reg_in_mem(machine, champ->reg[machine->mem[start] - 1], \
    champ->prog_count + (tmp % IDX_MOD), champ);
}

bool inst_sti(vm_t *machine, champ_t *champ)
{
    op_t op = op_tab[10];
    int *params = 0;

    if (!scheduling_check(machine, champ, op.nbr_cycles))
        return (true);
    params = get_inst_parameters(machine, champ, op);
    if (!inst_parms_verif(op, params))
        return (false);
    do_sti_inst(machine, champ, params);
    inst_change_pc(champ, params, op);
    free(params);
    return (true);
}