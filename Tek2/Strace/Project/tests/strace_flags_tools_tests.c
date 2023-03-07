/*
** EPITECH PROJECT, 2022
** Project
** File description:
** strace_flags_tools
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "strace_flags_tools.h"

Test(handle_pid, correct) {
    strace_data_t *strace_data = init_strace_data();

    cr_assert_eq(handle_pid(strace_data, "1000"), 0);
}

Test(handle_pid, invalid_number) {
    strace_data_t *strace_data = init_strace_data();

    cr_assert_eq(handle_pid(strace_data, "aa1010aaa"), 84);
}

Test(handle_pid, negatif_number) {
    strace_data_t *strace_data = init_strace_data();

    cr_assert_eq(handle_pid(strace_data, "-1000"), 84);
}