/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-lucas.tesnier
** File description:
** change_pc
*/

#include "op.h"
#include "vm.h"

void inst_change_pc(champ_t *champ, int *params, op_t op)
{
    champ->prog_count += 1;
    for (int i = 0; i < op.nbr_args; i++) {
        if (params[i] == 3)
            champ->prog_count += IND_SIZE;
        if (params[i] == 2)
            champ->prog_count += DIR_SIZE;
        if (params[i] != 3 && params[i] != 2)
            champ->prog_count += 1;
    }
    champ->prog_count += 1;
}