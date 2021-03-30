/*
** EPITECH PROJECT, 2021
** test.c
** File description:
** all test units
*/

#include "proto.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(Game, TF)
{
    game_t outpout;
    int *action = malloc(sizeof(int) * 2);

    srandom(time(NULL));
    action[0] = 1;
    action[1] = 1;
    verification_match(4, 5);
    verification_match(-4, -5);
    outpout = setup_game(4, 5);
    fill_map(&outpout);
    display_map(&outpout);
    verif_win(&outpout);
    //cr_assert_stdout_eq_str("*********\n*   |   *\n*  |||  *\n* ||||| *\n*|||||||*\n*********\n");
    outpout = setup_game(10, 5);
    fill_map(&outpout);
    remove_stick(action, &outpout);
    verif_win(&outpout);
    get_ai(&outpout);
    //cr_assert_eq(outpout, -1);
}
