/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-lucas.tesnier
** File description:
** test_insert
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "asm.h"
#include "instructions.h"
#include "parsing.h"

Test(insert_towrite, candidate)
{
    char *null_candidate = NULL;
    char *candidate = "////";
    arg_entry_t entry;

    cr_assert_eq(check_valid_label(null_candidate), false);
    cr_assert_eq(check_valid_label(candidate), false);
    entry.arg = "hello";
    cr_assert_eq(insert_towrite_indirect(&entry), true);
    entry.arg = ":a";
    cr_assert_eq(insert_towrite_indirect(&entry), true);
    entry.arg = ":/";
    cr_assert_eq(insert_towrite_indirect(&entry), false);
    cr_assert_eq(insert_towrite(&entry), false);
    entry.arg = ":%//";
    cr_assert_eq(insert_towrite(&entry), false);
}

Test(insert_size, candidate)
{
    int entry = 0;
    char *arg = "r1";
    char *dir = "%0";

    cr_assert_eq(insert_size(0, &entry, arg, 0), 1);
    cr_assert_eq(insert_size(0, &entry, arg, 1), 2);
    cr_assert_eq(insert_size(0, &entry, dir, 1), 3);
    cr_assert_eq(entry, 4);
    cr_assert_eq(insert_size(9, &entry, dir, 1), 3);
    cr_assert_eq(entry, 2);
}
