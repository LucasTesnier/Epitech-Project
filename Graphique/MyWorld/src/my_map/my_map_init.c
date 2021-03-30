/*
** EPITECH PROJECT, 2021
** my_map
** File description:
** desc
*/

#include "my_world.h"

sfVector2f my_iso_projection(int x, int y, int z, sfVector2f angles)
{
    sfVector2f point;

    point.x = cos((360 - angles.x / 2) * M_PI / 180) * \
    x - cos(angles.x / 2 * M_PI / 180) * y;
    point.y = sin(angles.y / 2 * M_PI / 180) * y + \
    sin(angles.y / 2 * M_PI / 180) * x - z;
    return (point);
}

char **my_map_height_init(my_map_t my_map)
{
    char **map;
    int i = 0;
    int j = 0;

    srand((unsigned int)((size_t)&j));
    map = malloc(sizeof(char *) * my_map.size.y);
    while (i < my_map.size.y) {
        map[i] = malloc(sizeof(char) * my_map.size.x);
        for (j = 0; j < my_map.size.x && i % 10 != 0; j++) {
            map[i][j] = map[i - 1][j];
        }
        for (j = 0; j < my_map.size.x && i % 10 == 0; j++) {
            map[i][j] = (j % 5 == 0) ? ((rand() % 60) - 15) \
        : map[i][j - 1];
        }
        i++;
    }
    return (map);
}

sfVector2f **my_vector_init(my_map_t my_map)
{
    sfVector2f **vector;
    int i = 0;
    int j = 0;

    vector = malloc(sizeof(sfVector2f *) * my_map.size.y);
    while (i < my_map.size.y) {
        vector[i] = malloc(sizeof(sfVector2f) * my_map.size.x);
        while (j < my_map.size.x) {
            vector[i][j] = my_iso_projection(i * my_map.display_size,   \
            j * my_map.display_size, my_map.map_height[i][j] *  \
            my_map.height_size, my_map.angles);
            j++;
        }
        i++;
        j = 0;
    }
    return (vector);
}

void my_init_construction3(my_map_t my_map, char **texture_name, int i, int j)
{
    if (my_map.texture_name[i][j] == GRASS) {
        if (rand() % 20 == 19) {
            texture_name[i][j] = -1 * (rand() % 8 + 1);
        }
    }
    if (my_map.texture_name[i][j] == SNOW) {
        if (rand() % 20 == 19) {
            texture_name[i][j] = -1 * (rand() % 4 + 9);
        }
    }
}

void my_init_construction2(my_map_t my_map, char **texture_name, int i, int j)
{
    if (i + 1 < my_map.size.x - 1 && j + 1 < my_map.size.y - 1) {
        if ((my_map.map_height[i][j] >= my_map.map_height[i + 1][j] \
        - 10 && my_map.map_height[i][j] <= my_map.map_height[i + 1][j]  \
        + 10) && (my_map.map_height[i][j] >=    \
        my_map.map_height[i][j + 1] - 10 && my_map.map_height[i][j] \
        <= my_map.map_height[i][j + 1] + 10) && \
        (my_map.map_height[i][j] >= my_map.map_height[i + 1][j + 1] \
        - 10 && my_map.map_height[i][j] <=  \
        my_map.map_height[i + 1][j + 1] + 10)) {
            my_init_construction3(my_map, texture_name, i, j);
        }
    }
}