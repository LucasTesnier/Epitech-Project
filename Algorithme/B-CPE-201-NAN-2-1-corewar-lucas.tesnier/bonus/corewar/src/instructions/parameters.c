/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** parameters
*/

#include "my.h"
#include "vm.h"
#include "op.h"

int *get_inst_parameters(vm_t *machine, champ_t *champ, op_t op)
{
    int actual_bit = machine->mem[(champ->prog_count + 1) % MEM_SIZE];
    int *params = my_calloc_int(sizeof(int), 4, 0);

    if (!params)
        exit(my_error("Error Malloc.\n", 84));
    params[0] = (actual_bit >> 6);
    params[1] = (actual_bit >> 4) - (params[0] << 2);
    params[2] = (actual_bit >> 2) - (params[0] << 4) - (params[1] << 2);
    return (params);
}

bool inst_parms_verif(op_t op, int *params)
{
    for (int i = 0; i < op.nbr_args; i++) {
        if (params[i] == 3 && (T_IND & op.type[i]) == 0)
            return (false);
        if ((params[i] & op.type[i]) == 0)
            return (false);
    }
    for (int i = op.nbr_args; i < 4; i++)
        if (params[i] != 0)
            return (false);
    return (true);
}