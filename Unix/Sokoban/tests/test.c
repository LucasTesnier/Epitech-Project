/*
** EPITECH PROJECT, 2021
** test.c
** File description:
** all test units
*/

#include "proto.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(Error, invalid_charactere, .init=cr_redirect_stdout)
{
    int outpout = 0;
    char *map = "###\n# #\n##R\n";

    outpout = verification_map(map);
    cr_assert_stdout_eq_str("Invalid Characteres !\n");
    cr_assert_eq(outpout, -1);
}

Test(Error, valid_charactere, .init=cr_redirect_stdout)
{
    int outpout = 0;
    char *map = "###\n#P#\n###\n";

    outpout = verification_map(map);
    cr_assert_eq(outpout, 0);
}

Test(Error, read_file, .init=cr_redirect_stdout)
{
    char *outpout;
    char *path = "tests/assets/map1";

    outpout = load_file_in_mem(path);
    cr_assert_str_eq(outpout, "###\n# #\n###\n");
}

Test(Setup, game)
{
    game_t game;
    char *map = "###\n#P#\n###\n";

    game = setup_struct(map);
    cr_assert_eq(game.is_winning, 0);
}


Test(Action, user)
{
    game_t game;
    char *map = "###\n#P#\n###\n";
    int action = KEY_UP;

    game = setup_struct(map);
    action_gestion(action, &game, map);
    cr_assert_eq(game.map.cases[1][1].player, 1); 
}

Test(Action, player_to_empty)
{
    game_t game;
    char *map = "####\n# P#\n####\n";
    int action = KEY_LEFT;

    game = setup_struct(map);
    action_gestion(action, &game, map);
    cr_assert_eq(game.map.cases[1][1].player, 1);
}

Test(Action, player_to_box)
{
    game_t game;
    char *map = "####\n#XP#\n####\n";
    int action = KEY_LEFT;

    game = setup_struct(map);
    action_gestion(action, &game, map);
    cr_assert_eq(game.map.cases[1][2].player, 1);
}

Test(Action, player_to_box_empty)
{
    game_t game;
    char *map = "#####\n# XP#\n#####\n";
    int action = KEY_LEFT;

    game = setup_struct(map);
    action_gestion(action, &game, map);
    cr_assert_eq(game.map.cases[1][2].player, 1);
}

Test(Winning, is_winning)
{
    game_t game;
    char *map = "#####\n#OXP#\n#####\n";

    game = setup_struct(map);
    verif_win(&game);
    cr_assert_eq(game.is_winning, 0);
}

Test(Winning, is_winnings)
{
    game_t game;
    char *map = "#####\n#OXP#\n#####\n";

    game = setup_struct(map);
    action_gestion(KEY_LEFT, &game, map);
    verif_win(&game);
    cr_assert_eq(game.is_winning, 1);
}

Test(Loose, is_loose)
{
    game_t game;
    char *map = "#####\n##XP#\n#####\n";

    game = setup_struct(map);
    action_gestion(KEY_LEFT, &game, map);
    verif_loose(&game);
    cr_assert_eq(game.is_winning, 1);
}

Test(Loose, is_looses)
{
    game_t game;
    char *map = "# ###\n# XP#\n# ###\n";

    game = setup_struct(map);
    verif_loose(&game);
    cr_assert_eq(game.is_winning, 0);
}

Test(Display, is_display)
{
    game_t game;
    char *map = "# ###\n#OXP#\n# ###\n";

    game = setup_struct(map);
    setup_screen();
    display_map(game);
    endwin();
}
