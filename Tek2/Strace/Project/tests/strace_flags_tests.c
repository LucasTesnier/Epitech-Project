/*
** EPITECH PROJECT, 2022
** Project
** File description:
** strace_flags_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "strace_flags.h"

Test(handle_flags, s_option) {
    strace_data_t *strace_data = init_strace_data();
    int ac = 3;
    char *args[3] = {
        "./strace",
        "-s",
        "ls"
    };

    cr_assert_eq(handle_flags(strace_data, args, ac), 0);
}

Test(handle_flags, multiple_command) {
    strace_data_t *strace_data = init_strace_data();
    int ac = 3;
    char *args[3] = {
        "./strace",
        "ls",
        "ls"
    };

    cr_assert_eq(handle_flags(strace_data, args, ac), 0);
}

Test(handle_flags, multiple_s) {
    strace_data_t *strace_data = init_strace_data();
    int ac = 3;
    char *args[3] = {
        "./strace",
        "-s",
        "-s"
    };

    cr_assert_eq(handle_flags(strace_data, args, ac), 0);
}

Test(handle_flags, p_option) {
    strace_data_t *strace_data = init_strace_data();
    int ac = 3;
    char *args[3] = {
        "./strace",
        "-p",
        "1000"
    };

    cr_assert_eq(handle_flags(strace_data, args, ac), 0);
}

Test(handle_flags, multiple_p) {
    strace_data_t *strace_data = init_strace_data();
    int ac = 3;
    char *args[3] = {
        "./strace",
        "-p",
        "-p"
    };

    cr_assert_eq(handle_flags(strace_data, args, ac), 84);
}

Test(handle_flags, complex_one) {
    strace_data_t *strace_data = init_strace_data();
    int ac = 4;
    char *args[4] = {
        "./strace",
        "-p",
        "1000",
        "-s"
    };

    cr_assert_eq(handle_flags(strace_data, args, ac), 0);
}

Test(handle_flags, complex_two) {
    strace_data_t *strace_data = init_strace_data();
    int ac = 4;
    char *args[4] = {
        "./strace",
        "-s",
        "-p",
        "10000"
    };

    cr_assert_eq(handle_flags(strace_data, args, ac), 0);
}