/*
** EPITECH PROJECT, 2020
** test_unitaire
** File description:
** test unitaires
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"
#include "../include/bsprintf.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, simple_string, .init = redirect_all_std)
{
    my_printf("hello  world");
    cr_assert_stdout_eq_str("hello  world");
}

Test(my_printf, add_string, .init = redirect_all_std)
{
    my_printf("hello %s", "world");
    cr_assert_stdout_eq_str("hello world");
}

Test(my_printf, add_number, .init = redirect_all_std)
{
    my_printf("hello %d", 8);
    cr_assert_stdout_eq_str("hello 8");
}

Test(my_printf, add_char, .init = redirect_all_std)
{
    my_printf("hello %c", 'w');
    cr_assert_stdout_eq_str("hello w");
}

Test(my_printf, add_binary, .init = redirect_all_std)
{
    my_printf("hello %b", 3);
    cr_assert_stdout_eq_str("hello 11");
}

Test(my_printf, add_S, .init = redirect_all_std)
{
    my_printf("hello %S", "toto\t");
    cr_assert_stdout_eq_str("hello toto\\011");
}

Test(my_printf, add_i, .init = redirect_all_std)
{
    my_printf("hello %i", 3);
    cr_assert_stdout_eq_str("hello 3");
}

Test(my_printf, add_unsigned, .init = redirect_all_std)
{
    my_printf("hello %u", 2);
    cr_assert_stdout_eq_str("hello 2");
}

Test(my_printf, add_x, .init = redirect_all_std)
{
    my_printf("hello %x", 17);
    cr_assert_stdout_eq_str("hello 11");
}

Test(my_printf, add_X, .init = redirect_all_std)
{
    my_printf("hello %X", 17);
    cr_assert_stdout_eq_str("hello 11");
}

Test(my_printf, add_o, .init = redirect_all_std)
{
    my_printf("hello %o", 8);
    cr_assert_stdout_eq_str("hello 10");
}

Test(my_printf, add_p, .init = redirect_all_std)
{
    int a = 3;

    my_printf("hello %p", &a);
}

Test(my_printf, add_b_space, .init = redirect_all_std)
{
    my_printf("hello %4b", 3);
    cr_assert_stdout_eq_str("hello   11");
}

Test(my_printf, add_b_space_neg, .init = redirect_all_std)
{
    my_printf("hello %-4b", 3);
    cr_assert_stdout_eq_str("hello 11  ");
}

Test(my_printf, add_d_plus, .init = redirect_all_std)
{
    my_printf("hello %+d", 3);
    cr_assert_stdout_eq_str("hello +3");
}

Test(my_printf, add_x_hastag, .init = redirect_all_std)
{
    my_printf("hello %#x", 3);
    cr_assert_stdout_eq_str("hello 0x3");
}

Test(my_printf, add_d_space, .init = redirect_all_std)
{
    my_printf("hello % d", 3);
    cr_assert_stdout_eq_str("hello  3");
}

Test(my_printf, add_o_hastag, .init = redirect_all_std)
{
    my_printf("hello %#o", 3);
    cr_assert_stdout_eq_str("hello 03");
}

Test(my_printf, add_pourcent, .init = redirect_all_std)
{
    my_printf("hello %%", 3);
    cr_assert_stdout_eq_str("hello %");
}

Test(my_printf, add_b_hastag, .init = redirect_all_std)
{
    my_printf("hello %#b", 3);
    cr_assert_stdout_eq_str("hello 0b11");
}

Test(my_printf, add_X_hastag, .init = redirect_all_std)
{
    my_printf("hello %#X", 3);
    cr_assert_stdout_eq_str("hello 0X3");
}

Test(my_printf, add_d_big, .init = redirect_all_std)
{
    my_printf("hello %4d", 11);
    cr_assert_stdout_eq_str("hello   11");
}

Test(my_printf, add_d_big_neg, .init = redirect_all_std)
{
    my_printf("hello %-4d", 11);
    cr_assert_stdout_eq_str("hello 11  ");
}

Test(my_printf, add_d_big_two, .init = redirect_all_std)
{
    my_printf("hello %14d", 11);
    cr_assert_stdout_eq_str("hello             11");
}

Test(my_printf, invalid_flag, .init = redirect_all_std)
{
    my_printf("hello %j", 11);
    cr_assert_stdout_eq_str("hello %j");
}
