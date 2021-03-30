/*
** EPITECH PROJECT, 2021
** place_sprite_two
** File description:
** desc
*/

#include "my_world.h"

void place_sprite_one(my_game_t *my_game, sfVector2i mouse_pos, int i, int j)
{
    if (my_game->sprite_type == 3) {
        if (my_game->gold >= 250) {
            my_game->construction_number += 1;
            my_game->good_buy = 1;
            my_game->sprite[i][j] = new_sprite(WATER,   \
            "assets/sprites/test.png", NULL);
            my_game->my_map.construction[i][j] = 3;
            my_game->gold -= 250;
        } else
            my_game->good_buy = 0;
    }
}

void place_sprite_two(my_game_t *my_game, sfVector2i mouse_pos, int i, int j)
{
    if (my_game->sprite_type == 1) {
        if (my_game->gold >= 10) {
            my_game->construction_number += 1;
            my_game->good_buy = 1;
            my_game->sprite[i][j] = new_sprite(WATER,   \
            "assets/sprites/house.png", NULL);
            my_game->my_map.construction[i][j] = 1;
            my_game->gold -= 10;
        } else
            my_game->good_buy = 0;
    }
}

void place_sprite_three(my_game_t *my_game, sfVector2i mouse_pos, int i, int j)
{
    if (my_game->sprite_type == 2) {
        if (my_game->gold >= 50) {
            my_game->gold -= 50;
            my_game->good_buy = 1;
            my_game->construction_number += 1;
            my_game->sprite[i][j] = new_sprite(WATER,   \
            "assets/sprites/farm.png", NULL);
            my_game->my_map.construction[i][j] = 2;
        } else
            my_game->good_buy = 0;
    }
}

void destroy_sprite(my_game_t *my_game, sfVector2i mouse_pos)
{
    int i = 0;
    int j = 0;

    for (int a = 0; a < my_game->my_map.size.x - 1; a++) {
        for (int b = 0; b < my_game->my_map.size.y - 1; b++) {
            in_tiles(my_game, a, b, mouse_pos);
        }
    }
    i = my_game->my_window.tile_selected.x;
    j = my_game->my_window.tile_selected.y;
    if (my_game->my_window.mouse_status == 1) {
        my_game->my_map.construction[i][j] = 0;
        my_game->sprite[i][j].sprite_name = 1;
        my_game->construction_number -= 1;
    }
}