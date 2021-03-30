/*
** EPITECH PROJECT, 2021
** choose texture
** File description:
** desc
*/

#include "my_world.h"

void choose_grass(my_game_t *my_game)
{
    my_game->texture_change = GRASS;
    sfRenderWindow_close(my_game->window_choose->window);
}

void choose_sand(my_game_t *my_game)
{
    my_game->texture_change = SAND;
    sfRenderWindow_close(my_game->window_choose->window);
}

void choose_snow(my_game_t *my_game)
{
    my_game->texture_change = SNOW;
    sfRenderWindow_close(my_game->window_choose->window);
}

void choose_water(my_game_t *my_game)
{
    my_game->texture_change = STONE;
    sfRenderWindow_close(my_game->window_choose->window);
}