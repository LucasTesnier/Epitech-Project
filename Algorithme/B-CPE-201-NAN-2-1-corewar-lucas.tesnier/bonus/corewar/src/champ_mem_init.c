/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-lucas.tesnier
** File description:
** champ_mem_init
*/

#include "vm.h"
#include "my.h"

void champs_set_adress(vm_t *machine)
{
    for (int i = 0; i < machine->champs_number; i++) {
        if (machine->champs[i]->load_address == -1) {
            machine->champs[i]->load_address = i * \
            (MEM_SIZE / machine->champs_number);
            machine->champs[i]->prog_count = machine->champs[i]->load_address;
        }
    }
}

void init_champ_register(vm_t *machine)
{
    for (int i = 0; i < machine->champs_number; i++) {
        machine->champs[i]->reg[0][REG_SIZE - 1] = \
        machine->champs[i]->champ_nbr;
    }
}