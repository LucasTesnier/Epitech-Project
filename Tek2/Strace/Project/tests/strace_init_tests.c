/*
** EPITECH PROJECT, 2022
** Project
** File description:
** strace_init_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "strace_init.h"

Test(handle_pid, functionnal_unknown_pid) {
    int ac = 4;
    char *args[4] = {
        "./strace",
        "-s",
        "-p",
        "10000"
    };

    cr_assert_eq(strace_start(ac, args, args), 0);
}

Test(handle_pid, functionnal_unknown_command) {
    int ac = 3;
    char *args[3] = {
        "./strace",
        "-s",
        "aaaa"
    };
    char *envp[2] = {
        "PATH=/bin",
        NULL
    };

    cr_assert_eq(strace_start(ac, args, envp), 84);
}

Test(handle_pid, functionnal_known_command) {
    int ac = 3;
    char *args[3] = {
        "./strace",
        "-s",
        "ls"
    };
    char *envp[2] = {
        "PATH=/bin/",
        NULL
    };

    cr_assert_eq(strace_start(ac, args, envp), 84);
}

Test(handle_pid, functionnal_known_command_two) {
    int ac = 2;
    char *args[2] = {
        "./strace",
        "ls"
    };
    char *envp[2] = {
        "PATH=/bin/",
        NULL
    };

    cr_assert_eq(strace_start(ac, args, envp), 84);
}