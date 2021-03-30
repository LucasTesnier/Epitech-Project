/*
** EPITECH PROJECT, 2020
** complementary_functions.c
** File description:
** all complementary functions
*/

#include "proto.h"

void event_gestion_three(int change, sfRenderWindow *window)
{
    sfRenderWindow_destroy(window);
    if (change == 1)
        screen_saver_menu(3);
    if (change == 2)
        screen_saver_menu(4);
    if (change == 3)
        screen_saver_menu(2);
}

my_circle set_circle(sfVector2i speed, sfVector2i dir, sfVector2i
center, sfColor color)
{
    my_circle circle;

    circle.center.x = center.x;
    circle.center.y = center.y;
    circle.speed.x = speed.x;
    circle.speed.y = speed.y;
    circle.size = 25;
    circle.direction.x = dir.x;
    circle.direction.y = dir.y;
    circle.color = color;
    return (circle);
}

void event_gestion_five(int change, sfRenderWindow *window)
{
    sfRenderWindow_destroy(window);
    if (change == 1)
        screen_saver_menu(5);
    if (change == 2)
        screen_saver_menu(6);
    if (change == 3)
        screen_saver_menu(4);
}

void event_gestion_six(int change, sfRenderWindow *window)
{
    sfRenderWindow_destroy(window);
    if (change == 1)
        screen_saver_menu(6);
    if (change == 2)
        screen_saver_menu(7);
    if (change == 3)
        screen_saver_menu(5);
}

void event_gestion_faur(int change, sfRenderWindow *window)
{
    sfRenderWindow_destroy(window);
    if (change == 1)
        screen_saver_menu(4);
    if (change == 2)
        screen_saver_menu(5);
    if (change == 3)
        screen_saver_menu(3);
}
