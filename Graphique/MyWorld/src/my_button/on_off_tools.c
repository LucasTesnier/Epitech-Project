/*
** EPITECH PROJECT, 2021
** on off tools
** File description:
** desc
*/

#include "my_world.h"

void on_off_toolsbar(my_game_t *my_game)
{
    if (my_game->toolsbar_on == true)
        my_game->toolsbar_on = false;
    else
        my_game->toolsbar_on = true;
}

void hand_on_off(my_game_t *my_game)
{
    my_game->mod = 1;
}

void pointer_on_off(my_game_t *my_game)
{
    my_game->mod = 2;
}

void gomme_on_off(my_game_t *my_game)
{
    my_game->mod = 4;
}

void backhoe_on_off(my_game_t *my_game)
{
    my_game->mod = 6;
}