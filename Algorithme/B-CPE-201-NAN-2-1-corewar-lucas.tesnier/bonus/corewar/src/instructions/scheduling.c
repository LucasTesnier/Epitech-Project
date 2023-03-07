/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** scheduling
*/

#include "op.h"
#include "vm.h"

bool scheduling_check(vm_t *machine, champ_t *champ, int nb_cycle)
{
    if (champ->scheduling == -1)
        champ->scheduling = machine->max_cycle;
    if (champ->scheduling + nb_cycle -1 > machine->max_cycle)
        return (false);
    champ->scheduling = -1;
    return (true);
}