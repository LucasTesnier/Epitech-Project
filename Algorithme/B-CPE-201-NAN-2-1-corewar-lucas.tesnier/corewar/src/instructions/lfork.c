/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-lucas.tesnier
** File description:
** lfork
*/

#include "op.h"
#include "vm.h"
#include "my.h"
#include <stdlib.h>

void link_child_lfork(champ_t *champ, champ_t *child)
{
    champ_t *tmp;

    if (!champ->child) {
        child->child = NULL;
        champ->child = child;
    } else {
        tmp = champ->child;
        champ->child = child;
        child->child = tmp;
    }
}

void do_lfork_inst(vm_t *machine, champ_t *champ)
{
    champ_t *child = malloc(sizeof(champ_t));

    if (!child)
        exit(my_error("Error Malloc.\n", 84));
    child->champ_nbr = champ->champ_nbr;
    child->filepath = champ->filepath;
    child->load_address = champ->load_address;
    child->scheduling = champ->scheduling;
    child->living = champ->living;
    child->last_live_cycle = champ->last_live_cycle;
    child->live_counter = champ->live_counter;
    child->carry = champ->carry;
    child->child = NULL;
    child->deep_child = champ->deep_child + 1;
    child->header = champ->header;
    champ_regs_init(child);
    for (int i = 0; i < REG_NUMBER; i++)
        unsigned_ncopy(child->reg[i], champ->reg[i], REG_SIZE);
    child->prog_count = champ->prog_count + (hex_to_short(machine, \
    (champ->prog_count + 1) % MEM_SIZE));
    link_child_lfork(champ, child);
}

bool inst_lfork(vm_t *machine, champ_t *champ)
{
    op_t op = op_tab[14];

    if (!scheduling_check(machine, champ, op.nbr_cycles))
        return (true);
    do_lfork_inst(machine, champ);
    champ->prog_count += 3;
    return (true);
}