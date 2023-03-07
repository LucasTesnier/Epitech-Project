/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-lucas.tesnier
** File description:
** test_null_objects
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "asm.h"
#include "instructions.h"
#include "parsing.h"

Test(size, null_array)
{
    char **arg = NULL;
    char *str = NULL;
    char *not_null_str = "hello";

    cr_assert_eq(array_size(arg), 0);
    cr_assert_eq(check_champion_data(str, not_null_str), -1);
    cr_assert_eq(check_champion_data(not_null_str, str), -1);
    cr_assert_eq(check_champion_data(not_null_str, not_null_str), 0);
}

Test(size, null_node)
{
    node_t *node = NULL;

    cr_assert_eq(get_node_size(node), 0);
}

Test(size, null_list)
{
    list_t *list = NULL;

    cr_assert_eq(get_program_size(list), -1);
    cr_assert_eq(parse_labels(list), -1);
}