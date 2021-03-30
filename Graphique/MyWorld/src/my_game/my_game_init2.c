/*
** EPITECH PROJECT, 2021
** my_game_init2
** File description:
** desc
*/

#include "my_world.h"

void my_init_sprite2(char construction, my_game_t *my_game,     \
my_sprite_t *texture_name)
{
    if (construction == -1) {
        *texture_name = new_sprite(WATER,  \
        "assets/sprites/tree1.png", NULL);
        my_game->construction_number += 1;
    }
    if (construction == -2) {
        *texture_name = new_sprite(WATER,  \
        "assets/sprites/tree2.png", NULL);
        my_game->construction_number += 1;
    }
    if (construction == -3) {
        *texture_name = new_sprite(WATER,  \
        "assets/sprites/tree3.png", NULL);
        my_game->construction_number += 1;
    }
    if (construction == -4) {
        *texture_name = new_sprite(WATER,  \
        "assets/sprites/tree4.png", NULL);
        my_game->construction_number += 1;
    }
}

void my_init_sprite3(char construction, my_game_t *my_game, \
my_sprite_t *texture_name)
{
    if (construction == -5) {
        *texture_name = new_sprite(WATER,  \
        "assets/sprites/rock1.png", NULL);
        my_game->construction_number += 1;
    }
    if (construction == -6) {
        *texture_name = new_sprite(WATER,  \
        "assets/sprites/rock2.png", NULL);
        my_game->construction_number += 1;
    }
    if (construction == -7) {
        *texture_name = new_sprite(WATER,  \
        "assets/sprites/rock3.png", NULL);
        my_game->construction_number += 1;
    }
    if (construction == -8) {
        *texture_name = new_sprite(WATER,  \
        "assets/sprites/rock4.png", NULL);
        my_game->construction_number += 1;
    }
}

void my_init_sprite4(char construction, my_game_t *my_game, \
my_sprite_t *texture_name)
{
    if (construction == -9) {
        *texture_name = new_sprite(WATER,  \
        "assets/sprites/icerock1.png", NULL);
        my_game->construction_number += 1;
    }
    if (construction == -10) {
        *texture_name = new_sprite(WATER,  \
        "assets/sprites/icerock2.png", NULL);
        my_game->construction_number += 1;
    }
    if (construction == -11) {
        *texture_name = new_sprite(WATER,  \
        "assets/sprites/icerock3.png", NULL);
        my_game->construction_number += 1;
    }
    if (construction == -12) {
        *texture_name = new_sprite(WATER,  \
        "assets/sprites/icerock4.png", NULL);
        my_game->construction_number += 1;
    }
}

my_sprite_t **my_init_sprite(my_map_t my_map, my_game_t *my_game)
{
    my_sprite_t **texture_name = malloc(sizeof(my_sprite_t *) * \
    my_map.size.x);

    for (int i = 0; i < my_map.size.y; i++) {
        texture_name[i] = malloc(sizeof(my_sprite_t) * my_map.size.y);
        for (int j = 0; j < my_map.size.x; j++) {
            texture_name[i][j].sprite_name = 1;
            my_init_sprite2(my_map.construction[i][j], my_game, \
            &texture_name[i][j]);
            my_init_sprite3(my_map.construction[i][j], my_game, \
            &texture_name[i][j]);
            my_init_sprite4(my_map.construction[i][j], my_game, \
            &texture_name[i][j]);
        }
    }
    return (texture_name);
}