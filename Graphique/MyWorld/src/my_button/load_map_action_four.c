/*
** EPITECH PROJECT, 2021
** load map
** File description:
** desc
*/

#include "my_world.h"

void loading_map_game_three(my_game_t *my_game, char *buffer, int *pos)
{
    for (; buffer[*pos] != ':'; *pos += 1);
    my_game->texture_change = my_getnbr(buffer + *pos);
    *pos += 1;
    for (; buffer[*pos] != ':'; *pos += 1);
    my_game->radius = my_getnbr(buffer + *pos);
    *pos += 1;
    for (; buffer[*pos] != ':'; *pos += 1);
    my_game->construction_number = my_getnbr(buffer + *pos);
    *pos += 1;
    for (; buffer[*pos] != ':'; *pos += 1);
    my_game->gold_generation = my_getnbr(buffer + *pos);
    *pos += 1;
    for (; buffer[*pos] != ':'; *pos += 1);
    my_game->gold = my_getnbr(buffer + *pos);
    *pos += 1;
    for (; buffer[*pos] != ':'; *pos += 1);
    my_game->sprite_type = my_getnbr(buffer + *pos);
}

void loading_map_game_two(my_game_t *my_game, char *buffer, int *pos)
{
    for (; buffer[*pos] != ':'; *pos += 1);
    my_game->my_map.size.x = my_getnbr(buffer + *pos);
    *pos += 1;
    for (; buffer[*pos] != ':'; *pos += 1);
    my_game->my_map.size.y = my_getnbr(buffer + *pos);
    *pos += 1;
    for (; buffer[*pos] != ':'; *pos += 1);
    my_game->mod = my_getnbr(buffer + *pos);
    *pos += 1;
    for (; buffer[*pos] != ':'; *pos += 1);
    my_game->actual = my_getnbr(buffer + *pos);
    *pos += 1;
    for (; buffer[*pos] != ':'; *pos += 1);
    my_game->toolsbar_on = my_getnbr(buffer + *pos);
    *pos += 1;
}

void loading_map_game_one(my_game_t *my_game, char *game_path)
{
    game_path[0] = '\0';
    my_strncat(game_path, "saves/", 6);
    my_strncat(game_path, my_game->save_name, my_strlen(my_game->save_name));
    my_strncat(game_path, "_game.legend", 12);
}

void loading_map_game(my_game_t *my_game)
{
    char *game_path = malloc(sizeof(char) * (my_strlen(my_game->save_name)\
    + 40));
    char *buffer;
    int pos = 0;

    loading_map_game_one(my_game, game_path);
    buffer = load_file_in_mem(game_path);
    loading_map_game_two(my_game, buffer, &pos);
    loading_map_game_three(my_game, buffer, &pos);
    my_game->my_window.tile_selected = (sfVector2i){0, 0};
}

void loading_map(my_game_t *my_game)
{
    loading_map_game(my_game);
    loading_map_height(my_game);
    loading_map_texture(my_game);
    loading_map_sprite(my_game);
    my_game->my_map.vector = my_vector_init(my_game->my_map);
    my_game->my_window.tile_selected = (sfVector2i){0, 0};
}