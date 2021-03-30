/*
** EPITECH PROJECT, 2021
** my_game_init
** File description:
** desc
*/

#include "my_world.h"

sfKeyCode *init_shortcut(void)
{
    sfKeyCode *shortcut = malloc(sizeof(sfKeyCode) * 10);

    shortcut[0] = sfKeyV;
    shortcut[1] = sfKeyC;
    shortcut[2] = sfKeyT;
    shortcut[3] = sfKeyE;
    shortcut[4] = sfKeyB;
    shortcut[5] = sfKeyZ;
    shortcut[6] = sfKeyN;
    shortcut[7] = sfKeyS;
    shortcut[8] = sfKeyL;
    shortcut[9] = sfKeyR;
    return (shortcut);
}

void my_game_init2(my_game_t *my_game)
{
    my_game->construction_number = 0;
    my_game->gold_generation = 0;
    my_game->gold = 100;
    my_game->good_buy = 1;
    my_game->shortcut = init_shortcut();
}

my_game_t my_game_init(sfVector2i size)
{
    my_game_t my_game;

    my_game.my_window = my_window_init();
    my_game.my_sprite = my_sprite_init();
    my_game.my_map = my_map_init(my_game.my_window.mode, size);
    my_game.my_map.pos = (sfVector2f){my_game.my_window.mode.width / 2, \
        my_game.my_window.mode.height / 10};
    my_game.convexShape = sfConvexShape_create();
    my_game.clock = sfClock_create();
    my_game.fps = 0;
    my_game.ctrl = 0;
    my_game.progress_bar = init_progress_bar();
    my_game.shapes = init_shapes();
    my_game.mod = 1;
    my_game.actual = 2;
    my_game.toolsbar_on = true;
    my_game.texture_change = 1;
    my_game.radius = 1;
    my_game.sprite = my_init_sprite(my_game.my_map, &my_game);
    my_game_init2(&my_game);
    return (my_game);
}