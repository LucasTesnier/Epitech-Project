/*
** EPITECH PROJECT, 2020
** test_units.c
** File description:
** all function for test_units
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/proto.h"

Test(test_suite, line, .init=cr_redirect_stdout)
{
    FILE *redir;
    FILE *solved = fopen("tests/maps/solved/map1", "r");

    bsq("tests/maps/map1");
    redir = cr_get_redirected_stdout();
    cr_expect_file_contents_eq(redir, solved);
    fclose(redir);
    fclose(solved);
}

Test(test_error, impossible_read)
{
    cr_assert_eq(bsq("tests/maps/map6"), 84);
}

Test(test_error, invalid_number)
{
    cr_assert_eq(bsq("tests/maps/map7"), 84);
}

Test(test_error, invalid_geometric)
{
    cr_assert_eq(bsq("tests/maps/map8"), 84);
}

Test(test_error, invalid_content)
{
    cr_assert_eq(bsq("tests/maps/map9"), 84);
}

Test(test_error, invalid_number_two)
{
    cr_assert_eq(bsq("tests/maps/map10"), 84);
}

Test(test_error, invalid_path)
{
    cr_assert_eq(bsq("tests/coucou"), 84);
}

Test(test_suite, easy_test, .init=cr_redirect_stdout)
{
    FILE *redir;
    FILE *solved = fopen("tests/maps/solved/map3", "r");

    bsq("tests/maps/map3");
    redir = cr_get_redirected_stdout();
    cr_expect_file_contents_eq(redir, solved);
    fclose(redir);
    fclose(solved);
}

Test(test_suite, easy_priority_test, .init=cr_redirect_stdout)
{
    FILE *redir;
    FILE *solved = fopen("tests/maps/solved/map4", "r");

    bsq("tests/maps/map4");
    redir = cr_get_redirected_stdout();
    cr_expect_file_contents_eq(redir, solved);
    fclose(redir);
    fclose(solved);
}

