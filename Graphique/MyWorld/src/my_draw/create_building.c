/*
** EPITECH PROJECT, 2021
** create building
** File description:
** desc
*/

#include "my_world.h"

void create_building2(my_game_t *my_game, int i, int j)
{
    if (my_game->sprite_type == 4) {
        my_game->sprite[i][j] = new_sprite(WATER,   \
        "assets/sprites/forge.png", NULL);
        my_game->my_map.construction[i][j] = 4;
    }
    if (my_game->sprite_type == 5) {
        my_game->sprite[i][j] = new_sprite(WATER,   \
        "assets/sprites/mansion.png", NULL);
        my_game->my_map.construction[i][j] = 5;
    }
    if (my_game->sprite_type == 6) {
        my_game->sprite[i][j] = new_sprite(WATER,   \
        "assets/sprites/tower.png", NULL);
        my_game->my_map.construction[i][j] = 6;
    }
}

void create_buildings(my_game_t *my_game, int i, int j)
{
    if (my_game->sprite_type == 3) {
        my_game->sprite[i][j] = new_sprite(WATER,   \
        "assets/sprites/test.png", NULL);
        my_game->my_map.construction[i][j] = 3;
    }
    if (my_game->sprite_type == 1) {
        my_game->sprite[i][j] = new_sprite(WATER,   \
        "assets/sprites/house.png", NULL);
        my_game->my_map.construction[i][j] = 1;
    }
    if (my_game->sprite_type == 2) {
        my_game->sprite[i][j] = new_sprite(WATER,   \
        "assets/sprites/farm.png", NULL);
        my_game->my_map.construction[i][j] = 2;
    }
    create_building2(my_game, i, j);
}