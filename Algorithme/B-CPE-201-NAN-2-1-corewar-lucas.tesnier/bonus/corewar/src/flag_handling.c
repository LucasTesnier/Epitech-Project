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

void help_handling(int ac, char **av)
{
    for (int i = 1; i < ac; i++) {
        if (my_strcmp(av[i], "-h") == 0) {
            my_putstr(USAGE);
            exit(0);
        }
    }
}

void dump_gestion(int ac, char **av, vm_t *machine, int *i)
{
    if (!my_strcmp(av[1], "-dump")) {
        if (!av[2] || !my_str_isnum(av[2]) ||
            (machine->dump_time = my_getnbr(av[2])) < 0)
            exit(my_error("Please put a valid dump number.\n", 84));
        *i += 2;
    }
}

void flags_management(int ac, char **av, vm_t *machine)
{
    int i = 1;

    if (ac < 2)
        exit(my_error("Invalid number of argument.\n", 84));
    help_handling(ac, av);
    dump_gestion(ac, av, machine, &i);
    champion_list_handling(ac, av, machine, i);
}