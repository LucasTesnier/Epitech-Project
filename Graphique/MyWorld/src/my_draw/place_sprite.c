/*
** EPITECH PROJECT, 2021
** place_sprite
** File description:
** desc
*/

#include "my_world.h"

void place_sprite_four(my_game_t *my_game, sfVector2i mouse_pos, int i, int j)
{
    if (my_game->sprite_type == 4) {
        if (my_game->gold >= 1250) {
            my_game->gold -= 1250;
            my_game->good_buy = 1;
            my_game->construction_number += 1;
            my_game->sprite[i][j] = new_sprite(WATER,   \
            "assets/sprites/forge.png", NULL);
            my_game->my_map.construction[i][j] = 4;
        } else
            my_game->good_buy = 0;
    }
}

void place_sprite_five(my_game_t *my_game, sfVector2i mouse_pos, int i, int j)
{
    if (my_game->sprite_type == 5) {
        if (my_game->gold >= 6250) {
            my_game->gold -= 6250;
            my_game->good_buy = 1;
            my_game->construction_number += 1;
            my_game->sprite[i][j] = new_sprite(WATER,   \
            "assets/sprites/mansion.png", NULL);
            my_game->my_map.construction[i][j] = 5;
        } else
            my_game->good_buy = 0;
    }
}

void place_sprite_six(my_game_t *my_game, sfVector2i mouse_pos, int i, int j)
{
    if (my_game->sprite_type == 6) {
        if (my_game->gold >= 31250) {
            my_game->gold -= 31250;
            my_game->good_buy = 1;
            my_game->construction_number += 1;
            my_game->sprite[i][j] = new_sprite(WATER,   \
            "assets/sprites/tower.png", NULL);
            my_game->my_map.construction[i][j] = 6;
        } else
            my_game->good_buy = 0;
    }
}

void place_all_sprite(my_game_t *my_game, sfVector2i mouse_pos, int i, int j)
{
    if (my_game->my_map.map_height[i][j] >= 0 &&    \
    (my_game->my_map.map_height[i][j] >=    \
    my_game->my_map.map_height[i + 1][j] - 5 && \
    my_game->my_map.map_height[i][j] <= \
    my_game->my_map.map_height[i + 1][j] + 5) &&    \
    (my_game->my_map.map_height[i][j] >=    \
    my_game->my_map.map_height[i][j + 1] - 5 && \
    my_game->my_map.map_height[i][j] <= \
    my_game->my_map.map_height[i][j + 1] + 5) &&    \
    (my_game->my_map.map_height[i][j] >=    \
    my_game->my_map.map_height[i + 1][j + 1] - 5 && \
    my_game->my_map.map_height[i][j] <= \
    my_game->my_map.map_height[i + 1][j + 1] + 5)) {
        place_sprite_one(my_game, mouse_pos, i, j);
        place_sprite_two(my_game, mouse_pos, i, j);
        place_sprite_three(my_game, mouse_pos, i, j);
        place_sprite_four(my_game, mouse_pos, i, j);
        place_sprite_five(my_game, mouse_pos, i, j);
        place_sprite_six(my_game, mouse_pos, i, j);
    }
}

void place_sprite(my_game_t *my_game, sfVector2i mouse_pos)
{
    int i = 0;
    int j = 0;

    for (int a = 0; a < my_game->my_map.size.x - 1; a++) {
        for (int b = 0; b < my_game->my_map.size.y - 1; b++)
            in_tiles(my_game, a, b, mouse_pos);
    }
    i = my_game->my_window.tile_selected.x;
    j = my_game->my_window.tile_selected.y;
    if (my_game->my_window.mouse_status == 1 && (i != 0 && j != 0) &&   \
    my_game->my_map.construction[i][j] == 0) {
        place_all_sprite(my_game, mouse_pos, i, j);
    }
}