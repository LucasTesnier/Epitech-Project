/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** live
*/

#include "op.h"
#include "my.h"
#include "vm.h"

void do_live_inst(vm_t *machine, champ_t *champ, int champ_id)
{
    my_printf("The player %i", champ->champ_nbr);
    my_printf("(%s) is alive.\n", champ->header.prog_name);
    champ->prog_count += DIR_SIZE + 1;
    champ->last_live_cycle = machine->max_cycle;
    champ->live_counter += 1;
    machine->total_living_champ += 1;
    machine->winner = champ;
}

bool inst_live(vm_t *machine, champ_t *champ)
{
    op_t op = op_tab[0];
    int i;

    if (!scheduling_check(machine, champ, op.nbr_cycles))
        return (true);
    if (!champ->living)
        return (true);
    do_live_inst(machine, champ, i);
    return (true);
}