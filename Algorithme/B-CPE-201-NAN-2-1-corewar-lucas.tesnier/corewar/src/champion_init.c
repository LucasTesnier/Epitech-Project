/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** main
*/

#include "vm.h"
#include "op.h"
#include "my.h"
#include <stdlib.h>

int get_next_champ_nbr(vm_t *machine, int number)
{
    for (int i = 0; i < machine->champs_number; i++) {
        if (number == machine->champs[i]->champ_nbr)
            return (get_next_champ_nbr(machine, number + 1));
        else
            return (number);
    }
}

void finalize_champion_list_handling(vm_t *machine, int champs_number)
{
    int tmp = 1;

    if (champs_number < 2)
        exit(my_error("Not enough champs in the arena.\n", 84));
    machine->champs_number = champs_number;
    for (int i = 0; i < champs_number; i++) {
        if (machine->champs[i]->champ_nbr == -1) {
            tmp = get_next_champ_nbr(machine, tmp);
            machine->champs[i]->champ_nbr = tmp;
        }
    }
}

void champion_list_handling(int ac, char **av, vm_t *machine, int i)
{
    int number_champs = 0;

    for (i = i; i < ac; i++) {
        if (number_champs > MAX_CHAMPS -1)
            exit(my_error("Take a maximum of 4 Champs.\n", 84));
        champ_flag_handling(&number_champs, &i, machine, av);
    }
    finalize_champion_list_handling(machine, number_champs);
}