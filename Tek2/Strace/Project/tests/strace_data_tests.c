/*
** EPITECH PROJECT, 2022
** Project
** File description:
** tests_init
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "strace_data.h"

Test(strace_data_init, classic_init) {
    strace_data_t *strace_data = init_strace_data();

    cr_assert_eq(strace_data->s_option, false);
}

Test(strace_data_destroy, classic_destroy) {
    strace_data_t *strace_data = init_strace_data();

    strace_data_destroy(strace_data);
}