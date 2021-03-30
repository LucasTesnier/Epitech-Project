/*
** EPITECH PROJECT, 2021
** my_init_button
** File description:
** desc
*/

#include "my_world.h"
#include "proto.h"

void four_buy(my_game_t *my_game)
{
    my_game->sprite_type = 4;
    sfRenderWindow_close(my_game->window_choose->window);
}

void five_buy(my_game_t *my_game)
{
    my_game->sprite_type = 5;
    sfRenderWindow_close(my_game->window_choose->window);
}

void six_buy(my_game_t *my_game)
{
    my_game->sprite_type = 6;
    sfRenderWindow_close(my_game->window_choose->window);
}

void range_max(my_game_t *my_game)
{
    my_game->radius = 2;
}

void range_little(my_game_t *my_game)
{
    my_game->radius = 1;
}