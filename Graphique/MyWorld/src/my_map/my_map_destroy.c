/*
** EPITECH PROJECT, 2021
** my_map_detroy
** File description:
** desc
*/

#include "my_world.h"

void my_map_destroy(my_map_t *my_map)
{
    free(my_map->map_height);
    free(my_map->vector);
}