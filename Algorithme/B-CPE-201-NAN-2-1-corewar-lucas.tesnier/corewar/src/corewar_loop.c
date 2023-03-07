/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** corewar_loop
*/

#include "vm.h"
#include "op.h"
#include "my.h"
#include <stdlib.h>

int check_all_champs(vm_t *machine, int i)
{
    int count = 0;
    champ_t *ptr = machine->champs[i];

    while (ptr) {
        count++;
        if (ptr->last_live_cycle < \
            (machine->max_cycle - machine->actual_cycle))
            ptr->living = false;
        if (!ptr->living)
            count--;
        ptr = ptr->child;
    }
    return (count);
}

void reinit_cycles(vm_t *machine)
{
    int count = 0;

    if (machine->total_living_champ >= NBR_LIVE)
        machine->cycle_to_die -= CYCLE_DELTA;
    for (int i = 0; i < machine->champs_number; i++)
        count += check_all_champs(machine, i);
    machine->actual_cycle = 0;
    if (count <= 1)
        machine->cycle_to_die = -1;
}

void corewar_champ_exec(vm_t *machine, champ_t *champ)
{
    bool (*instructs[16])(vm_t *machine, champ_t *champ) = {inst_live, \
inst_ld, inst_st, inst_add, inst_sub, inst_and, inst_or, inst_xor, \
inst_zjmp, inst_ldi, inst_sti, inst_fork, inst_lld, inst_lldi, inst_lfork, \
inst_aff};

    while (champ->prog_count < 0)
        champ->prog_count += MEM_SIZE;
    champ->prog_count %= MEM_SIZE;
    if (machine->mem[champ->prog_count] < 1 || \
    machine->mem[champ->prog_count] > 16) {
        champ->prog_count += 1;
        return;
    }
    if ((*instructs[machine->mem[champ->prog_count] - 1])(machine, champ) == \
        false)
        champ->prog_count += 1;
}

void corewar_champion_fight(vm_t *machine)
{
    champ_t *ptr;

    for (int i = 0; i < machine->champs_number; i++) {
        ptr = machine->champs[i];
        while (ptr) {
            corewar_champ_exec(machine, ptr);
            ptr = ptr->child;
        }
    }
    machine->actual_cycle += 1;
    machine->max_cycle += 1;
    if (machine->actual_cycle >= machine->cycle_to_die)
        reinit_cycles(machine);
}

void corewar_loop(vm_t *machine)
{
    if (machine->dump_time == -1) {
        while (machine->cycle_to_die > 0)
            corewar_champion_fight(machine);
    } else {
        while (machine->cycle_to_die > 0 && \
            machine->max_cycle < machine->dump_time)
            corewar_champion_fight(machine);
    }
}