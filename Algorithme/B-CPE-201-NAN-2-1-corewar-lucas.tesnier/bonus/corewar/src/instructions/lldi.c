/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-lucas.tesnier
** File description:
** lldi
*/

#include "vm.h"
#include "op.h"
#include <stdlib.h>

int set_tmp_param_llid(vm_t *machine, champ_t *champ, int param, int *start)
{
    int res = 0;

    if (param == 1) {
        if (machine->mem[*start] < 1 || machine->mem[*start] > REG_NUMBER) {
            champ->carry = true;
            return (false);
        }
        res = reg_to_int(champ->reg[machine->mem[*start] - 1]);
        *start += 1;
    } else {
        res = (int)hex_to_short(machine, *start);
        *start += 2;
    }
    return (res);
}

void inst_lldi_reg_part(vm_t *machine, champ_t *champ, int tmp, int start)
{
    int start_two = (champ->prog_count + tmp) % MEM_SIZE;
    int tmp_two = champ->prog_count + tmp;

    if (machine->mem[start] < 1 | machine->mem[start] > REG_NUMBER)
        return;
    while (tmp_two < 0)
        tmp_two += MEM_SIZE;
    tmp_two %= MEM_SIZE;
    for (int i = start_two; start_two < REG_SIZE + i; \
        start_two = (start_two + 1) % MEM_SIZE)
        champ->reg[machine->mem[start] - 1][start_two - tmp_two] = \
        machine->mem[start_two];
    if (reg_to_int(champ->reg[machine->mem[start] - 1]) == 0) {
        if (champ->carry)
            champ->carry = false;
        else
            champ->carry = true;
    }
}

void do_lldi_inst(vm_t *machine, champ_t *champ, int *params)
{
    int start = (champ->prog_count + 2) % MEM_SIZE;
    int tmp = 0;

    champ->carry = false;
    tmp = set_tmp_param_llid(machine, champ, params[0], &start);
    while (start < 0)
        start += MEM_SIZE;
    start %= MEM_SIZE;
    tmp += set_tmp_param_llid(machine, champ, params[1], &start);
    while (start < 0)
        start += MEM_SIZE;
    start %= MEM_SIZE;
    inst_lldi_reg_part(machine, champ, tmp, start);
}

bool inst_lldi(vm_t *machine, champ_t *champ)
{
    op_t op = op_tab[13];
    int *params = 0;

    if (!scheduling_check(machine, champ, op.nbr_cycles))
        return (true);
    params = get_inst_parameters(machine, champ, op);
    if (!inst_parms_verif(op, params))
        return (false);
    do_lldi_inst(machine, champ, params);
    inst_change_pc(champ, params, op);
    free(params);
    return (true);
}