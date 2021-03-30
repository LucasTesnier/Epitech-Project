/*
** EPITECH PROJECT, 2020
** my_random_pixel.c
** File description:
** function for random pixel animation
*/

#include "proto.h"

sfColor change_color(sfColor color)
{
    color.r = rand() % 255;
    color.g = rand() % 255;
    color.b = rand() % 255;
    return (color);
}

void choose_random_pixel(t_my_framebuffer *framebuffer)
{
    int x = rand() % framebuffer->width;
    int y = rand() % framebuffer->height;
    sfColor color;

    color = change_color(color);
    color.a = 255;
    if (framebuffer->pixels[(framebuffer->width * y + x) * 4] == 0 && \
        framebuffer->pixels[(framebuffer->width * y + x) * 4 + 1] == 0 && \
        framebuffer->pixels[(framebuffer->width * y + x) * 4 + 2] == 0)
        my_put_pixel(framebuffer, x, y, color);
    else
        choose_random_pixel(framebuffer);
}

void event_gestion(int change, sfRenderWindow *window)
{
    sfRenderWindow_destroy(window);
    if (change == 1)
        screen_saver_menu(1);
    if (change == 2)
        screen_saver_menu(2);
    if (change == 3)
        screen_saver_menu(7);
}

void random_pixel(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window;
    int change = 0;
    t_my_framebuffer *framebuffer = framebuffer_create(800, 600);
    sfTexture* texture = sfTexture_create(800, 600);
    sfSprite* sprite = sfSprite_create();

    srand(time(NULL));
    window = sfRenderWindow_create(mode, "random_pixel", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfSprite_setTexture(sprite, texture, sfTrue);
    while (sfRenderWindow_isOpen(window)) {
        event_detection(window, &change);
        sfRenderWindow_clear(window, sfBlack);
        choose_random_pixel(framebuffer);
        sfTexture_updateFromPixels(texture, framebuffer->pixels, \
        framebuffer->width, framebuffer->height, 0, 0);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    event_gestion(change, window);
}
