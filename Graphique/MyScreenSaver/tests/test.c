/*
** EPITECH PROJECT, 2020
** test.c
** File description:
** all function for test_units
*/

#include <criterion/criterion.h>
#include "proto.h"

Test(Invalid_number, Neg)
{
    cr_assert_eq(screen_saver_start("-1"), 84);
}

Test(Invalid_number, Up)
{
    cr_assert_eq(screen_saver_start("8"), 84);
}
