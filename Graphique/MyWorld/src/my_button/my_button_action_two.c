/*
** EPITECH PROJECT, 2021
** my_init_button
** File description:
** desc
*/

#include "my_world.h"
#include "proto.h"

void play(my_game_t *my_game)
{
    my_game->actual = 1;
}

void update_radius(my_game_t *my_game)
{
    my_game->radius += 1;
    if (my_game->radius > 5)
        my_game->radius = 1;
}

void one_buy(my_game_t *my_game)
{
    my_game->sprite_type = 1;
    sfRenderWindow_close(my_game->window_choose->window);
}

void two_buy(my_game_t *my_game)
{
    my_game->sprite_type = 2;
    sfRenderWindow_close(my_game->window_choose->window);
}

void three_buy(my_game_t *my_game)
{
    my_game->sprite_type = 3;
    sfRenderWindow_close(my_game->window_choose->window);
}