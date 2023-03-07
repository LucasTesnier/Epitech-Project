/*
** EPITECH PROJECT, 2021
** tests.c
** File description:
** TU
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../generator/include/proto.h"
#include "../solver/include/moves.h"

Test(Generator, perfect, .init=cr_redirect_stdout)
{
    setup_lab(100, 100, true);
}

Test(Generator, imperfect, .init=cr_redirect_stdout)
{
    setup_lab(100, 100, false);
}

Test(Generator, perfect_impair, .init=cr_redirect_stdout)
{
    setup_lab(101, 101, true);
}

Test(Generator, imperfect_impair, .init=cr_redirect_stdout)
{
    setup_lab(101, 101, false);
}