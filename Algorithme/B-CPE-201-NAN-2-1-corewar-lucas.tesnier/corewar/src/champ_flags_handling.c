/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-lucas.tesnier
** File description:
** champ_flags_handling
*/

#include "my.h"
#include "vm.h"
#include "op.h"
#include <stdlib.h>

void check_address(vm_t *machine, int number, int j)
{
    if (machine->champs[j]->load_address == number)
        exit(my_error("Champion adress already used.\n", 84));
}

void check_champ_number(vm_t *machine, int number, int j)
{
    if (machine->champs[j]->champ_nbr == number)
        exit(my_error("Champion number already used.\n", 84));
}

bool champ_flag_handling_a(int *nb_champs, int *i, vm_t *machine, char **av)
{
    int number = -1;

    if (my_strcmp(av[*i], "-a") == 0) {
        if (av[*i + 1] == NULL || !my_str_isnum(av[*i + 1]))
            exit(my_error("You need to put a number after a -a.\n", 84));
        number = my_getnbr(av[*i + 1]);
        if (number < 0)
            exit(my_error("Please enter a valid number.\n", 84));
        for (int j = 0; j < MAX_CHAMPS; j++) {
            check_address(machine, number, j);
        }
        machine->champs[*nb_champs]->load_address = number;
        *i += 1;
        return (true);
    }
    return (false);
}

bool champ_flag_handling_n(int *nb_champs, int *i, vm_t *machine, char **av)
{
    int number = -1;

    if (my_strcmp(av[*i], "-n") == 0) {
        if (av[*i + 1] == NULL || !my_str_isnum(av[*i + 1]))
            exit(my_error("You need to put a number after a -n.\n", 84));
        number = my_getnbr(av[*i + 1]);
        if (number < 0 || number > MAX_CHAMPS)
            exit(my_error("Please enter a valid number.\n", 84));
        for (int j = 0; j < MAX_CHAMPS; j++) {
            check_champ_number(machine, number, j);
        }
        machine->champs[*nb_champs]->champ_nbr = number;
        *i += 1;
        return (true);
    }
    return (false);
}

void champ_flag_handling(int *number_champs, int *i, vm_t *machine, char **av)
{
    if (champ_flag_handling_n(number_champs, i, machine, av))
        return;
    if (champ_flag_handling_a(number_champs, i, machine, av))
        return;
    machine->champs[*number_champs]->filepath = my_strdup(av[*i]);
    *number_champs += 1;
}