/*
** EPITECH PROJECT, 2020
** mouse_catcher.c
** File description:
** all function for animation 7
*/

#include "proto.h"

void event_gestion_seven(int change, sfRenderWindow *window)
{
    sfRenderWindow_destroy(window);
    if (change == 1)
        screen_saver_menu(7);
    if (change == 2)
        screen_saver_menu(1);
    if (change == 3)
        screen_saver_menu(6);
}

void color_change(sfColor *color)
{
    sfColor color_l[] = {sfBlue, sfGreen, sfRed, sfWhite, sfYellow};

    if (color->g < 254)
        color->g = color->g + 1;
    else {
        if (color->b < 254)
            color->b = color->b + 1;
        else {
            *color = color_l[rand() % 5];
        }
    }
}

int animation_seven(t_my_framebuffer *framebuffer, sfRenderWindow *window, \
sfColor *color, int size)
{
    sfVector2i center = sfMouse_getPositionRenderWindow(window);

    if (center.x > 800 - size)
        for (; center.x > 800 - size && size > 0; size--);
    if (center.x < 0 + size)
        for (;center.x < 0 + size && size > 0; size--);
    if (center.y < 0 + size)
        for (;center.y < 0 + size && size > 0; size--);
    if (center.y > 600 - size)
        for (;center.y > 600 - size && size > 0; size--);
    draw_circle_f(framebuffer, center, size, *color);
    if (color->r < 254)
        color->r = color->r + 1;
    else {
        color_change(color);
    }
    return (0);
}

void change_size(int *change, int *size)
{
    if (*change == 4) {
        *change = 0;
        *size = *size + 1;
        if (*size >= 400) {
            *size = *size - 1;
        }
    }
    if (*change == 5) {
        *change = 0;
        *size = *size - 1;
        if (*size <= 0)
            *size = *size + 1;
    }
}

void mouse_catcher(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window;
    int change = 0;
    t_my_framebuffer *framebuffer = framebuffer_create(800, 600);
    sfTexture* texture = sfTexture_create(800, 600);
    sfSprite* sprite = sfSprite_create();
    sfColor color = sfBlue;
    int size = 20;

    window = sfRenderWindow_create(mode, "Mouse Catcher", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfSprite_setTexture(sprite, texture, sfTrue);
    while (sfRenderWindow_isOpen(window)) {
        event_detection_m(window, &change, &size);
        animation_seven(framebuffer, window, &color, size);
        sfTexture_updateFromPixels(texture, framebuffer->pixels, \
        framebuffer->width, framebuffer->height, 0, 0);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    event_gestion_seven(change, window);
}
