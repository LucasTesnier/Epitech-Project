/*
** EPITECH PROJECT, 2021
** load map
** File description:
** desc
*/

#include "my_world.h"

void loading_map_texture_one(my_game_t *my_game, char *texture_path)
{
    texture_path[0] = '\0';
    my_strncat(texture_path, "saves/", 6);
    my_strncat(texture_path, my_game->save_name, my_strlen\
    (my_game->save_name));
    my_strncat(texture_path, "_texture.legend", 15);
}

void loading_map_texture(my_game_t *my_game)
{
    char *texture_path = malloc(sizeof(char) * (my_strlen(my_game->save_name)\
    + 40));
    char *buffer;
    int pos = 0;

    loading_map_texture_one(my_game, texture_path);
    buffer = load_file_in_mem(texture_path);
    my_game->my_map.texture_name = malloc(sizeof(char *) * \
    my_game->my_map.size.y);
    for (int i = 0; i < my_game->my_map.size.y; i++) {
        my_game->my_map.texture_name[i] = malloc(sizeof(char) * \
        my_game->my_map.size.x);
        for (int j = 0; j < my_game->my_map.size.x; j++) {
            my_game->my_map.texture_name[i][j] = my_getnbr(buffer + pos);
            pos += 2;
        }
        pos+= 1;
    }
}

void loading_map_sprite_one(my_game_t *my_game, char *sprite_path)
{
    sprite_path[0] = '\0';
    my_strncat(sprite_path, "saves/", 6);
    my_strncat(sprite_path, my_game->save_name, my_strlen(my_game->save_name));
    my_strncat(sprite_path, "_sprite.legend", 14);
}

void loading_map_sprite_seven(my_game_t *my_game, \
char *buffer, int *pos, sfVector2i p)
{
    if (my_getnbr(buffer + *pos) == -10) {
        my_game->sprite[p.x][p.y] = new_sprite(WATER, \
        "assets/sprites/icerock2.png", NULL);
        my_game->my_map.construction[p.x][p.y] = -10;
    }
    if (my_getnbr(buffer + *pos) == -11) {
        my_game->sprite[p.x][p.y] = new_sprite(WATER, \
        "assets/sprites/icerock3.png", NULL);
        my_game->my_map.construction[p.x][p.y] = -11;
    }
    if (my_getnbr(buffer + *pos) == -12) {
        my_game->sprite[p.x][p.y] = new_sprite(WATER, \
        "assets/sprites/icerock4.png", NULL);
        my_game->my_map.construction[p.x][p.y] = -12;
    }
    if (my_getnbr(buffer + *pos) == 0)
        my_game->my_map.construction[p.x][p.y] = 0;
}

void loading_map_sprite_six(my_game_t *my_game, char *buffer, \
int *pos, sfVector2i p)
{
    if (my_getnbr(buffer + *pos) == -7) {
        my_game->sprite[p.x][p.y] = new_sprite(WATER, \
        "assets/sprites/rock3.png", NULL);
        my_game->my_map.construction[p.x][p.y] = -7;
    }
    if (my_getnbr(buffer + *pos) == -8) {
        my_game->sprite[p.x][p.y] = new_sprite(WATER, \
        "assets/sprites/rock4.png", NULL);
        my_game->my_map.construction[p.x][p.y] = -8;
    }
    if (my_getnbr(buffer + *pos) == -9) {
        my_game->sprite[p.x][p.y] = new_sprite(WATER, \
        "assets/sprites/icerock1.png", NULL);
        my_game->my_map.construction[p.x][p.y] = -9;
    }
    loading_map_sprite_seven(my_game, buffer, pos, p);
}
