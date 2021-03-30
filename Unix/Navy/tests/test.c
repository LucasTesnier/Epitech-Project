/*
** EPITECH PROJECT, 2020
** B-PSU-101-NAN-1-1-navy-lucas.tesnier
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "navy.h"

Test(test_suite, display_game, .init=cr_redirect_stdout)
{
    game_info_t *test = malloc(sizeof(game_info_t));

    if (!test)
        cr_assert_fail();
    initialisation_map(test);
    test->player_map[0][0] = -1;
    getcheck_file("tests/assets/pos1", test);
    test->player_map[0][2] = -2;
    display_game(test);
}

Test(test_suite, check_pos)
{
    cr_assert(check_pos("C4\n", SHOOT));
    cr_assert_not(check_pos("C0\n", SHOOT));
    cr_assert_not(check_pos("CC\n", SHOOT));
    cr_assert_not(check_pos("33\n", SHOOT));
    cr_assert(check_pos("2:C1:C2\n", SET));
    cr_assert_not(check_pos("2:C1:C9\n", SET));
    cr_assert_not(check_pos("1:C1:C2\n", SET));
    cr_assert_not(check_pos("6:C1:C2\n", SET));
    cr_assert_not(check_pos("3:C1:C2\n", SET));
    cr_assert_not(check_pos("2:C1:D2\n", SET));
}

Test(test_suite, is_gameover)
{
    game_info_t *test = malloc(sizeof(game_info_t));

    if (!test)
        cr_assert_fail();
    initialisation_map(test);
    cr_assert(is_gameover(test));
    getcheck_file("tests/assets/pos1", test);
    cr_assert_not(is_gameover(test));
}

Test(test_suite, receive_attack_info, .init=cr_redirect_stdout)
{
    game_info_t *test = malloc(sizeof(game_info_t));

    if (!test)
        cr_assert_fail();
    initialisation_map(test);
    receive_attack_info("A1",  test, true);
    receive_attack_info("A2",  test, false);
    cr_assert_eq(test->opponent[0][0], -2);
    cr_assert_eq(test->opponent[1][0], -1);
}

Test(test_suite, get_attack_pos)
{
    game_info_t *test = malloc(sizeof(game_info_t));

    write(1, "C1\n", 3);
    char *res = get_attack_pos(test);
    cr_assert_str_eq(res, "C1");
    write(1, "C910\n", 6);
    res = get_attack_pos(test);
    cr_assert_null(res);
}