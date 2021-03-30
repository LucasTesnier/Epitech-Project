/*
** EPITECH PROJECT, 2021
** load map
** File description:
** desc
*/

#include "my_world.h"

void loading_map_sprite_five(my_game_t *my_game, char *buffer, \
int *pos, sfVector2i p)
{
    if (my_getnbr(buffer + *pos) == -4) {
        my_game->sprite[p.x][p.y] = new_sprite(WATER, \
        "assets/sprites/tree4.png", NULL);
        my_game->my_map.construction[p.x][p.y] = -4;
    }
    if (my_getnbr(buffer + *pos) == -5) {
        my_game->sprite[p.x][p.y] = new_sprite(WATER, \
        "assets/sprites/rock1.png", NULL);
        my_game->my_map.construction[p.x][p.y] = -5;
    }
    if (my_getnbr(buffer + *pos) == -6) {
        my_game->sprite[p.x][p.y] = new_sprite(WATER, \
        "assets/sprites/rock2.png", NULL);
        my_game->my_map.construction[p.x][p.y] = -6;
    }
    loading_map_sprite_six(my_game, buffer, pos, p);
}

void loading_map_sprite_four(my_game_t *my_game, char *buffer, \
int *pos, sfVector2i p)
{
    if (my_getnbr(buffer + *pos) == -1) {
        my_game->sprite[p.x][p.y] = new_sprite(WATER, \
        "assets/sprites/tree1.png", NULL);
        my_game->my_map.construction[p.x][p.y] = -1;
    }
    if (my_getnbr(buffer + *pos) == -2) {
        my_game->sprite[p.x][p.y] = new_sprite(WATER, \
        "assets/sprites/tree2.png", NULL);
        my_game->my_map.construction[p.x][p.y] = -2;
    }
    if (my_getnbr(buffer + *pos) == -3) {
        my_game->sprite[p.x][p.y] = new_sprite(WATER, \
        "assets/sprites/tree3.png", NULL);
        my_game->my_map.construction[p.x][p.y] = -3;
    }
    loading_map_sprite_five(my_game, buffer, pos, p);
}

void loading_map_sprite_three(my_game_t *my_game, char *buffer, \
int *pos, sfVector2i p)
{
    if (my_getnbr(buffer + *pos) == 4) {
        my_game->sprite[p.x][p.y] = new_sprite(WATER, \
        "assets/sprites/forge.png", NULL);
        my_game->my_map.construction[p.x][p.y] = 4;
    }
    if (my_getnbr(buffer + *pos) == 5) {
        my_game->sprite[p.x][p.y] = new_sprite(WATER, \
        "assets/sprites/mansion.png", NULL);
        my_game->my_map.construction[p.x][p.y] = 5;
    }
    if (my_getnbr(buffer + *pos) == 6) {
        my_game->sprite[p.x][p.y] = new_sprite(WATER, \
        "assets/sprites/tower.png", NULL);
        my_game->my_map.construction[p.x][p.y] = 6;
    }
    loading_map_sprite_four(my_game, buffer, pos, p);
}

void loading_map_sprite_two(my_game_t *my_game, char *buffer, \
int *pos, sfVector2i p)
{
    if (my_getnbr(buffer + *pos) == 3) {
        my_game->sprite[p.x][p.y] = new_sprite(WATER, \
        "assets/sprites/test.png", NULL);
        my_game->my_map.construction[p.x][p.y] = 3;
    }
    if (my_getnbr(buffer + *pos) == 1) {
        my_game->sprite[p.x][p.y] = new_sprite(WATER, \
        "assets/sprites/house.png", NULL);
        my_game->my_map.construction[p.x][p.y] = 1;
    }
    if (my_getnbr(buffer + *pos) == 2) {
        my_game->sprite[p.x][p.y] = new_sprite(WATER, \
        "assets/sprites/farm.png", NULL);
        my_game->my_map.construction[p.x][p.y] = 2;
    }
    loading_map_sprite_three(my_game, buffer, pos, p);
}

void loading_map_sprite(my_game_t *my_game)
{
    char *sprite_path = malloc(sizeof(char) * (my_strlen(my_game->save_name)\
    + 40));
    char *buffer;
    int pos = 0;

    loading_map_sprite_one(my_game, sprite_path);
    buffer = load_file_in_mem(sprite_path);
    my_game->my_map.construction = malloc(sizeof(char *) * \
    my_game->my_map.size.y);
    my_game->sprite = my_init_spritee(my_game->my_map, my_game);
    for (int i = 0; i < my_game->my_map.size.y; i++) {
        my_game->my_map.construction[i] = malloc(sizeof(char) * \
        my_game->my_map.size.x);
        for (int j = 0; j < my_game->my_map.size.x; j++) {
            loading_map_sprite_two(my_game, buffer, &pos, (sfVector2i){i, j});
            loading_map_height_two(my_game, buffer, &pos);
        }
        pos+= 1;
        if (buffer[pos + 1] == '-')
            pos++;
    }
}