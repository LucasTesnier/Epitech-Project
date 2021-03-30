/*
** EPITECH PROJECT, 2021
** my_map_init2
** File description:
** desc
*/

#include "my_world.h"

char **my_init_construction(my_map_t my_map)
{
    char **texture_name = malloc(sizeof(char *) * my_map.size.x);

    for (int i = 0; i < my_map.size.y; i++) {
        texture_name[i] = malloc(sizeof(char) * my_map.size.y);
        for (int j = 0; j < my_map.size.x; j++) {
            texture_name[i][j] = 0;
            my_init_construction2(my_map, texture_name, i, j);
        }
    }
    return (texture_name);
}

void my_init_texture_name3(my_map_t my_map, char **texture_name, int i, int j)
{
    if (my_map.map_height[i][j] < 0) {
        texture_name[i][j] = SAND;
    } else {
        if (my_map.map_height[i][j] > 35 || rand() % 35 == 34)
            texture_name[i][j] = SNOW;
        else
            texture_name[i][j] = GRASS;
    }
}

void my_init_texture_name2(my_map_t my_map, char **texture_name, int i, int j)
{
    if (i + 1 < my_map.size.x - 1 && j + 1 < my_map.size.y - 1) {
        if ((my_map.map_height[i][j] >= \
        my_map.map_height[i + 1][j] - 10    \
        && my_map.map_height[i][j] <=   \
        my_map.map_height[i + 1][j] + 10) &&    \
        (my_map.map_height[i][j] >= my_map.map_height[i][j + 1] \
        - 10 && my_map.map_height[i][j] <=  \
        my_map.map_height[i][j + 1] + 10) &&    \
        (my_map.map_height[i][j] >= \
        my_map.map_height[i + 1][j + 1] - 10 && \
        my_map.map_height[i][j] <=  \
        my_map.map_height[i + 1][j + 1] + 10)) {
            my_init_texture_name3(my_map, texture_name, i, j);
        } else {
            texture_name[i][j] = STONE;
        }
    } else
        texture_name[i][j] = GRASS;
}

char **my_init_texture_name(my_map_t my_map)
{
    char **texture_name = malloc(sizeof(char *) * my_map.size.x);

    for (int i = 0; i < my_map.size.y; i++) {
        texture_name[i] = malloc(sizeof(char) * my_map.size.y);
        for (int j = 0; j < my_map.size.x; j++) {
            my_init_texture_name2(my_map, texture_name, i, j);
        }
    }
    return (texture_name);
}

my_map_t my_map_init(sfVideoMode mode, sfVector2i size)
{
    my_map_t my_map;

    my_map.size = size;
    my_map.display_size = 75;
    my_map.height_size = (float)my_map.display_size / 10;
    my_map.angles = (sfVector2f){45, 35};
    my_map.pos = (sfVector2f){mode.width / 2, mode.height / 10};
    my_map.map_height = my_map_height_init(my_map);
    my_map.vector = my_vector_init(my_map);
    my_map.texture_name = my_init_texture_name(my_map);
    my_map.construction = my_init_construction(my_map);
    return (my_map);
}