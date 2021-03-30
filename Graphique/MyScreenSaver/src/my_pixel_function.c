/*
** EPITECH PROJECT, 2020
** my_pixel_function.c
** File description:
** all function for display pixel
*/

#include "proto.h"

t_my_framebuffer *framebuffer_create(unsigned int width, unsigned int height)
{
    t_my_framebuffer *framebuffer;

    framebuffer = malloc(sizeof(t_my_framebuffer));
    framebuffer->pixels = malloc(width * height * 32 / 8);
    framebuffer->width = width;
    framebuffer->height = height;
    return (framebuffer);
}

void my_put_pixel(t_my_framebuffer *framebuffer, unsigned int x,
unsigned int y, sfColor color)
{
    framebuffer->pixels[(framebuffer->width * y + x) * 4] = color.r;
    framebuffer->pixels[(framebuffer->width * y + x) * 4 + 1] = color.g;
    framebuffer->pixels[(framebuffer->width * y + x) * 4 + 2] = color.b;
    framebuffer->pixels[(framebuffer->width * y + x) * 4 + 3] = color.a;
}

int draw_circle(t_my_framebuffer *framebuffer, sfVector2i center, int radius,
sfColor color)
{
    for (int i = center.x - radius; i < center.x + radius; i++) {
        for (int j = center.y - radius; j < center.y + radius; j++) {
            if (pow((i - center.x), 2) + pow((j - center.y), 2) == \
                pow(radius, 2))
                my_put_pixel(framebuffer, i, j, color);
        }
    }
}
