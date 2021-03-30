/*
** EPITECH PROJECT, 2021
** save map
** File description:
** desc
*/

#include "my_world.h"

void saving_map_height(my_game_t *my_game)
{
    char *height_path = malloc(sizeof(char) * \
    (my_strlen(my_game->save_name) + 40));
    FILE *height;

    height_path[0] = '\0';
    my_strncat(height_path, "saves/", 6);
    my_strncat(height_path, my_game->save_name, \
    my_strlen(my_game->save_name));
    my_strncat(height_path, "_height.legend", 14);
    height = fopen(height_path, "w+");
    for (int i = 0; i < my_game->my_map.size.y; i++) {
        for (int j = 0; j < my_game->my_map.size.x; j++) {
            fwrite(text_convert_int_to_char(my_game->my_map.map_height[i][j])\
            , my_strlen(text_convert_int_to_char\
            (my_game->my_map.map_height[i][j])), 1, height);
            fwrite(" ", 1, 1, height);
        }
        fwrite("\n", 1, 1, height);
    }
    fclose(height);
}

void saving_map_texture(my_game_t *my_game)
{
    char *texture_path = malloc(sizeof(char) * \
    (my_strlen(my_game->save_name) + 40));
    FILE *texture;

    texture_path[0] = '\0';
    my_strncat(texture_path, "saves/", 6);
    my_strncat(texture_path, my_game->save_name, \
    my_strlen(my_game->save_name));
    my_strncat(texture_path, "_texture.legend", 15);
    texture = fopen(texture_path, "w+");
    for (int i = 0; i < my_game->my_map.size.y; i++) {
        for (int j = 0; j < my_game->my_map.size.x; j++) {
            fwrite(text_convert_int_to_char(my_game->my_map.texture_name\
            [i][j]), my_strlen(text_convert_int_to_char(my_game->my_map.\
            texture_name[i][j])), 1, texture);
            fwrite(" ", 1, 1, texture);
        }
        fwrite("\n", 1, 1, texture);
    }
    fclose(texture);
}

void saving_map_sprite(my_game_t *my_game)
{
    char *sprite_path = malloc(sizeof(char) * \
    (my_strlen(my_game->save_name) + 40));
    FILE *sprite;

    sprite_path[0] = '\0';
    my_strncat(sprite_path, "saves/", 6);
    my_strncat(sprite_path, my_game->save_name, my_strlen\
    (my_game->save_name));
    my_strncat(sprite_path, "_sprite.legend", 14);
    sprite = fopen(sprite_path, "w+");
    for (int i = 0; i < my_game->my_map.size.y; i++) {
        for (int j = 0; j < my_game->my_map.size.x; j++) {
            fwrite(text_convert_int_to_char\
            (my_game->my_map.construction[i][j]), \
            my_strlen(text_convert_int_to_char(\
            my_game->my_map.construction[i][j])), 1, sprite);
            fwrite(" ", 1, 1, sprite);
        }
        fwrite("\n", 1, 1, sprite);
    }
    fclose(sprite);
}

void saving_map_game_three(my_game_t *my_game, FILE *game)
{
    fwrite("Sprite Type : ", 14, 1, game);
    fwrite(text_convert_int_to_char(my_game->sprite_type), \
    my_strlen(text_convert_int_to_char(my_game->sprite_type)), 1, game);
    fwrite("\n", 1, 1, game);
}

void saving_map_game_two(my_game_t *my_game, FILE *game)
{
    fwrite("Radius : ", 9, 1, game);
    fwrite(text_convert_int_to_char(my_game->radius), \
    my_strlen(text_convert_int_to_char(my_game->radius)), 1, game);
    fwrite("\n", 1, 1, game);
    fwrite("Construction Number : ", 22, 1, game);
    fwrite(text_convert_int_to_char(my_game->construction_number), \
    my_strlen(text_convert_int_to_char(my_game->construction_number)), 1, game);
    fwrite("\n", 1, 1, game);
    fwrite("Gold Generations : ", 19, 1, game);
    fwrite(text_convert_int_to_char(my_game->gold_generation), \
    my_strlen(text_convert_int_to_char(my_game->gold_generation)), 1, game);
    fwrite("\n", 1, 1, game);
    fwrite("Gold : ", 7, 1, game);
    fwrite(text_convert_int_to_char(my_game->gold), \
    my_strlen(text_convert_int_to_char(my_game->gold)), 1, game);
    fwrite("\n", 1, 1, game);
    saving_map_game_three(my_game, game);
}