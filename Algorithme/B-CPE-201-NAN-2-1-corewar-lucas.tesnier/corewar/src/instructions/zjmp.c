/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-lucas.tesnier
** File description:
** zjmp
*/

#include "vm.h"
#include "op.h"

bool inst_zjmp(vm_t *machine, champ_t *champ)
{
    op_t op = op_tab[8];

    if (!scheduling_check(machine, champ, op.nbr_cycles))
        return (true);
    if (!champ->carry) {
        champ->prog_count += hex_to_short(machine, champ->prog_count + 1);
        return (true);
    }
    champ->prog_count += hex_to_short(machine, champ->prog_count + 1) % \
    MEM_SIZE;
    return (true);
}