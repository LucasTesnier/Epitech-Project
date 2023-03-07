/*
** EPITECH PROJECT, 2022
** NmObj
** File description:
** objdump_gestion_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "objdump_gestion.h"

/// TESTS FONCTIONNELS

Test(functionalTesting, objdump_start_unknown_path) {
    char *av[1] = {
        "./my_objdump"
    };

    cr_assert_eq(objdump_start(1, av), 1);
}

Test(functionalTesting, objdump_start_dir) {
    char *av[2] = {
        "./my_objdump",
        "tests"
    };

    cr_assert_eq(objdump_start(2, av), 1);
}

Test(functionalTesting, objdump_start_invalid_file) {
    char *av[2] = {
        "./my_objdump",
        "Makefile"
    };

    cr_assert_eq(objdump_start(2, av), 1);
}

Test(functionalTesting, objdump_start_valid, .init = cr_redirect_stdout) {
    char *av[2] = {
        "./my_objdump",
        "tests/a.out"
    };

    cr_assert_eq(objdump_start(2, av), 0);
}

Test(functionalTesting, objdump_start_multiple, .init = cr_redirect_stdout) {
    char *av[3] = {
        "./my_objdump",
        "tests/a.out",
        "tests/a.out"
    };

    cr_assert_eq(objdump_start(3, av), 0);
}

Test(functionalTesting, objdump_start_multiple_error, .init = cr_redirect_stdout) {
    char *av[3] = {
        "./my_objdump",
        "a.out",
        "a.out"
    };

    cr_assert_eq(objdump_start(3, av), 1);
}

Test(functionalTesting, objdump_start_32, .init = cr_redirect_stdout) {
    char *av[2] = {
        "./my_objdump",
        "tests/test.main.32"
    };

    cr_assert_eq(objdump_start(2, av), 0);
}