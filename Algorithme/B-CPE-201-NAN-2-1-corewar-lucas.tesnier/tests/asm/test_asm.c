/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-lucas.tesnier
** File description:
** test_asm
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "asm.h"
#include "instructions.h"
#include "parsing.h"

Test(check_argument_type, null_arg)
{
    char *arg = NULL;

    cr_assert_eq(check_label(arg), false);
    cr_assert_eq(check_indirect(arg), -1);
    cr_assert_eq(check_register(arg), -1);
    cr_assert_eq(check_direct(arg), -1);
    cr_assert_eq(check_arg_type(1, arg), -1);
}

Test(check_argument_type, null_first_char)
{
    char arg[1];

    arg[0] = '\0';
    cr_assert_eq(check_label(arg), false);
    cr_assert_eq(check_direct(arg), false);
    cr_assert_eq(check_register(arg), -1);
}

Test(functional_tests, run_prgm)
{
    char *av[2];

    av[0] = "./asm/asm";
    av[1] = "tests/asm/abel.s";
    cr_assert_eq(run_prgm(2, av), 0);
    av[1] = "tests/asm/bill.s";
    cr_assert_eq(run_prgm(2, av), 0);
    av[1] = "tests/asm/pdd.s";
    cr_assert_eq(run_prgm(2, av), 0);
    av[1] = "tests/asm/pdd_lfork.s";
    cr_assert_eq(run_prgm(2, av), 0);
    av[1] = "tests/asm/tyron.s";
    cr_assert_eq(run_prgm(2, av), 0);
    av[1] = "tests/asm/zork.s";
    cr_assert_eq(run_prgm(2, av), 0);
    av[1] = "tests/asm/zok.s";
    cr_assert_eq(run_prgm(2, av), 84);
    av[1] = "tests/asm/random_bullshit.s";
    cr_assert_eq(run_prgm(2, av), 84);
}

Test(error_handling, err)
{
    char *av[2];

    av[0] = "./asm/asm";
    av[1] = "tests/asm/abel.s";
    cr_assert_eq(error_handling(2, av), 0);
    cr_assert_eq(error_handling(1, av), 0);
    av[1] = "-h";
    cr_assert_eq(error_handling(2, av), 1);
    cr_assert_eq(error_handling(1, av), 0);
    cr_assert_eq(run_prgm(2, av), 0);
}