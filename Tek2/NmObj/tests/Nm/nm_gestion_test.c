/*
** EPITECH PROJECT, 2022
** NmObj
** File description:
** nm_gestion_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "nm_gestion.h"

/// TESTS FONCTIONNELS

Test(functionalTesting, nm_start_unknown_path) {
    char *av[1] = {
        "./my_nm"
    };

    cr_assert_eq(nm_start(1, av), 1);
}

Test(functionalTesting, nm_start_dir) {
    char *av[2] = {
        "./my_nm",
        "tests"
    };

    cr_assert_eq(nm_start(2, av), 1);
}

Test(functionalTesting, nm_start_invalid_file) {
    char *av[2] = {
        "./my_nm",
        "Makefile"
    };

    cr_assert_eq(nm_start(2, av), 1);
}

Test(functionalTesting, nm_start_valid, .init = cr_redirect_stdout) {
    char *av[2] = {
        "./my_nm",
        "tests/a.out"
    };

    cr_assert_eq(nm_start(2, av), 0);
}

Test(functionalTesting, nm_start_multiple, .init = cr_redirect_stdout) {
    char *av[3] = {
        "./my_nm",
        "tests/a.out",
        "tests/a.out"
    };

    cr_assert_eq(nm_start(3, av), 0);
}

Test(functionalTesting, nm_start_multiple_error, .init = cr_redirect_stdout) {
    char *av[3] = {
        "./my_nm",
        "a.out",
        "a.out"
    };

    cr_assert_eq(nm_start(3, av), 1);
}

Test(functionalTesting, nm_start_o, .init = cr_redirect_stdout) {
    char *av[2] = {
        "./my_nm",
        "tests/test.main.o"
    };

    cr_assert_eq(nm_start(2, av), 0);
}

Test(functionalTesting, nm_start_no_symbole_error, .init = cr_redirect_stdout) {
    char *av[2] = {
        "./my_nm",
        "/bin/ls"
    };

    cr_assert_eq(nm_start(2, av), 0);
}