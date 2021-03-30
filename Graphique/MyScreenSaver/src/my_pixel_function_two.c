/*
** EPITECH PROJECT, 2020
** my_pixel_function_two.c
** File description:
** all function display pixel part two
*/

#include "proto.h"

int draw_circle_f(t_my_framebuffer *framebuffer, sfVector2i center, int radius,
sfColor color)
{
    for (int i = center.x - radius; i < center.x + radius; i++) {
        for (int j = center.y - radius; j < center.y + radius; j++) {
            if (pow((i - center.x), 2) + pow((j - center.y), 2) <= \
                pow(radius, 2))
                my_put_pixel(framebuffer, i, j, color);
        }
    }
}

void event_detection_two(sfRenderWindow *window, int *change, sfEvent event)
{
    if (event.key.code == sfKeyR) {
        sfRenderWindow_close(window);
        *change = 1;
    }
    if (event.key.code == sfKeyRight) {
        sfRenderWindow_close(window);
        *change = 2;
    }
    if (event.key.code == sfKeyLeft) {
        sfRenderWindow_close(window);
        *change = 3;
    }
    if (event.key.code == sfKeyUp || event.key.code == sfKeyDown)
        *change = 4;
}

void event_detection(sfRenderWindow *window, int *change)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed) {
            event_detection_two(window, change, event);
        }
    }
}

void event_detection_two_m(sfRenderWindow *window, int *change, sfEvent event)
{
    if (event.key.code == sfKeyR) {
        sfRenderWindow_close(window);
        *change = 1;
    }
    if (event.key.code == sfKeyRight) {
        sfRenderWindow_close(window);
        *change = 2;
    }
    if (event.key.code == sfKeyLeft) {
        sfRenderWindow_close(window);
        *change = 3;
    }
    if (event.key.code == sfKeyUp)
        *change = 4;
    if (event.key.code == sfKeyDown)
        *change = 5;
}

void event_detection_m(sfRenderWindow *window, int *change, int *size)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed) {
            event_detection_two_m(window, change, event);
        }
    }
    change_size(change, size);
}
