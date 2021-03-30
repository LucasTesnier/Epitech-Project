/*
** EPITECH PROJECT, 2021
** load map
** File description:
** desc
*/

#include "my_world.h"

char *load_file_in_mem(char const *filepath)
{
    char *line_buf = NULL;
    size_t line_buf_size = 0;
    int size = 0;
    ssize_t line_size;
    FILE *fp = fopen(filepath, "r");

    if (!fp) {
        write(2, "Files doesn't exist", 20);
        return (NULL);
    }
    line_size = getline(&line_buf, &line_buf_size, fp);
    while (line_size >= 0) {
        size += line_size;
        line_size = getline(&line_buf, &line_buf_size, fp);
    }
    return (read_file(filepath, size));
}

my_sprite_t **my_init_spritee(my_map_t my_map, my_game_t *my_game)
{
    my_sprite_t **texture_name = malloc(sizeof(my_sprite_t *) * my_map.size.x);

    for (int i = 0; i < my_map.size.y; i++) {
        texture_name[i] = malloc(sizeof(my_sprite_t) * my_map.size.y);
        for (int j = 0; j < my_map.size.x; j++) {
            texture_name[i][j].sprite_name = 1;
        }
    }
    return (texture_name);
}

void loading_map_height_one(my_game_t *my_game, char *height_path)
{
    height_path[0] = '\0';
    my_strncat(height_path, "saves/", 6);
    my_strncat(height_path, my_game->save_name, my_strlen(my_game->save_name));
    my_strncat(height_path, "_height.legend", 14);
}

void loading_map_height_two(my_game_t *my_game, char *buffer, int *pos)
{
    *pos += 1;
    for (; buffer[*pos] != ' '; *pos += 1);
    if (buffer[*pos + 1] == '-')
        *pos +=1;
}

void loading_map_height(my_game_t *my_game)
{
    char *height_path = malloc(sizeof(char) * (my_strlen(my_game->save_name)\
    + 40));
    char *buffer;
    int pos = 0;

    loading_map_height_one(my_game, height_path);
    buffer = load_file_in_mem(height_path);
    my_game->my_map.map_height = malloc(sizeof(char *) * \
    my_game->my_map.size.y);
    for (int i = 0; i < my_game->my_map.size.y; i++) {
        my_game->my_map.map_height[i] = malloc(sizeof(char) * \
        my_game->my_map.size.x);
        for (int j = 0; j < my_game->my_map.size.x; j++) {
            my_game->my_map.map_height[i][j] = my_getnbr(buffer + pos);
            loading_map_height_two(my_game, buffer, &pos);
        }
        pos += 1;
        if (buffer[pos + 1] == '-')
            pos++;
    }
}