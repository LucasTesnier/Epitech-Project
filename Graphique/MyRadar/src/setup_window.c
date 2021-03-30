/*
** EPITECH PROJECT, 2021
** setup_window.c
** File description:
** function setup
*/

#include "proto.h"

timer_clock_t setup_clock(void)
{
    timer_clock_t clock;

    clock.clock = sfClock_create();
    clock.time_lost = 0;
    return (clock);
}

sfRenderWindow *setup_window(plane_t *planes, tower_t *towers, \
game_t *game, user_t user)
{
    sfRenderWindow *window;
    sfVideoMode mode = {1920, 1080, 32};

    window = sfRenderWindow_create(mode, "my_radar", sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(window, 32);
    setup_sprite(towers, planes, user);
    for (int i = 0; planes[i].is_air != -1; i++)
        colision(&planes[i], i, planes, towers);
    game->planes = planes;
    game->towers = towers;
    return (window);
}

void display_info_paused(sfRenderWindow *window, text_opt_t opt)
{
    sfRenderWindow_drawText(window, opt.timer, NULL);
    sfRenderWindow_drawText(window, opt.sprite_opt, NULL);
    sfRenderWindow_drawText(window, opt.hitbox_opt, NULL);
    sfRenderWindow_display(window);
}

quari_t setup_quari(int top, int bottom, int right, int left)
{
    quari_t quari;

    quari.top = top;
    quari.bottom = bottom;
    quari.right = right;
    quari.left = left;
    quari.list = malloc(sizeof(int) * 10000);
    quari.count = 0;
    return (quari);
}

game_t setup_game(plane_t *planes, tower_t *towers, user_t user)
{
    game_t game;

    game.window = setup_window(planes, towers, &game, user);
    game.clock = setup_clock();
    game.opt = setup_opt();
    game.change = malloc(sizeof(int) * 4);
    game.change[0] = 0;
    game.change[1] = 0;
    game.change[2] = 0;
    game.change[3] = 0;
    game.quari = malloc(sizeof(quari_t) * 4);
    game.quari[0] = setup_quari(1, 539, 959, 1);
    game.quari[1] = setup_quari(539, 1078, 1918, 959);
    game.quari[2] = setup_quari(539, 1078, 959, 1);
    game.quari[3] = setup_quari(1, 539, 1918, 959);
    return (game);
}
