/*
** EPITECH PROJECT, 2021
** my_window_destroy
** File description:
** desc
*/

#include "my_world.h"

void my_window_destroy(my_window_t *my_window)
{
    sfRenderWindow_destroy(my_window->window);
}