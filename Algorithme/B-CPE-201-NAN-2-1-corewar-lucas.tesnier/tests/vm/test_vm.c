/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-lucas.tesnier
** File description:
** test_asm
*/

#include "vm.h"
#include "op.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(fonctional_test_vm, vm, .init=cr_redirect_stdout)
{
    char *av[] = {"./corewar", "-dump", "10000", "tests/vm/mortel.cor", "tests/vm/42.cor", "tests/vm/champ.cor", "tests/vm/skynet.cor"};

    launch_virtual_machine(7, av);
}

Test(fonctional_test_vm, vm_two, .init=cr_redirect_stdout)
{
    char *av[] = {"./corewar", "-dump", "10000", "-n", "2", "tests/vm/mortel.cor", "-a", "300", "tests/vm/42.cor", "tests/vm/champ.cor", "tests/vm/skynet.cor"};

    launch_virtual_machine(11, av);
}

Test(unit_test_vm, vm_three, .init=cr_redirect_stdout)
{
    char *av[] = {"./corewar", "-dump", "10000", "-n", "2", "tests/vm/mortel.cor", "-a", "300", "tests/vm/42.cor", "tests/vm/champ.cor", "tests/vm/skynet.cor"};

    launch_virtual_machine(11, av);
}

Test(unit_test_vm, vm_four, .init=cr_redirect_stdout)
{
    char *av[] = {"./corewar", "-dump", "10000", "-n", "2", "tests/vm/mortel.cor", "-a", "300", "tests/vm/42.cor", "tests/vm/champ.cor", "tests/vm/skynet.cor"};

    launch_virtual_machine(11, av);
}