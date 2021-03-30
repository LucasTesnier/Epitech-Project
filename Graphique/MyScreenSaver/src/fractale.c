/*
** EPITECH PROJECT, 2020
** fractale.c
** File description:
** all function for animation 6
*/

#include "proto.h"

void fractale_int(int *stocki, float *stock, float *change)
{
    stocki[4] = 800;
    stocki[5] = 600;
    stock[0] = 0.25 / stocki[4];
    stock[1] = 0.45 / stocki[5];
    if (change[2] > -1)
        change[0] = -0.01;
    if (change[2] < -2)
        change[0] = 0.01;
    change[2] = change[2] + change[0];
}

void fractale_calc(float *stock, int *stocki)
{
    while ((stock[2] * stock[2] + stock[3] * stock[3] < 4) && \
    (stocki[6] < 30)) {
        stock[5] = stock[2] * stock[2] - stock[3] * stock[3] + stock[4];
        stock[3] = 2 * stock[2] * stock[3] + stock[6];
        stock[2] = stock[5];
        stocki[6] = stocki[6] + 1;
    }
}

int fractale_color(float *change, int *change_r)
{
    if (*change_r == 4) {
        *change_r = 0;
        change[4] = rand() % 200 + 50;
    }
}

void initialisation_six(t_my_framebuffer *framebuffer, float *change, \
int *change_r)
{
    float stock[7] = {0};
    int stocki[7] = {0};
    sfColor color = sfBlue;
    int color_change = fractale_color(change, change_r);

    fractale_int(stocki, stock, change);
    for (stocki[1] = 1; stocki[1] <= stocki[5] - 1; stocki[1] = stocki[1] + 1) {
        for (stocki[0] = 1; stocki[0] <= stocki[4] - 1; stocki[0] = \
        stocki[0] + 1) {
            stock[4] = stocki[0] * stock[0] + change[2];
            stock[6] = stocki[1] * stock[1] + change[3];
            stock[2] = 0;
            stock[3] = 0;
            stocki[6] = 0;
            fractale_calc(stock, stocki);
            color.r = change[4] * stocki[6];
            color.g = change[4] * stocki[6];
            color.b = change[4] * stocki[6];
            my_put_pixel(framebuffer, stocki[0], stocki[1], color);
        }
    }
}

void fractale(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window;
    int change = 0;
    t_my_framebuffer *framebuffer = framebuffer_create(800, 600);
    sfTexture* texture = sfTexture_create(800, 600);
    sfSprite* sprite = sfSprite_create();
    float a_change[] = {0.01, -0.01, -1.75, -0.25, 100};

    srand(time(NULL));
    window = sfRenderWindow_create(mode, "fractale", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfSprite_setTexture(sprite, texture, sfTrue);
    while (sfRenderWindow_isOpen(window)) {
        event_detection(window, &change);
        initialisation_six(framebuffer, a_change, &change);
        sfTexture_updateFromPixels(texture, framebuffer->pixels, \
        framebuffer->width, framebuffer->height, 0, 0);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    event_gestion_six(change, window);
}
