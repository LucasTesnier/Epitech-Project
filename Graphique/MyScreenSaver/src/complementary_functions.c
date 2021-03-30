/*
** EPITECH PROJECT, 2020
** complementary_functions.c
** File description:
** all complementary function
*/

#include "proto.h"

void clean_buffer(t_my_framebuffer *framebuffer)
{
    for (int i = 0; i < framebuffer->width; i++) {
        for (int j = 0; j < framebuffer->height; j++)
            my_put_pixel(framebuffer, i, j, sfBlack);
    }
}

my_line set_line(void)
{
    my_line line;

    line.speed = rand() % 3 + 1;
    line.pos = rand() % (600 / line.speed);
    line.rigth = rand() % 2;
    line.change = rand() % 2;
    line.point_a.x = 0;
    line.point_a.y = 0;
    if (line.rigth == 0) {
        line.point_b.x = 800;
        line.point_b.y = 0;
    }
    if (line.rigth == 1) {
        line.point_b.x = 0;
        line.point_b.y = 600;
    }
    line.color.r = 0;
    line.color.g = 255;
    line.color.b = 127;
    line.color.a = 150;
    return (line);
}

void laser_change_color(int *change, my_line *line, int size)
{
    sfColor color[] = {sfBlue, sfGreen, sfRed, sfWhite, sfYellow};
    int color_rand = rand() % 5;

    if (*change == 4) {
        for (int i = 0; i < size; i++)
            line[i].color = color[color_rand];
        *change = 0;
    }
}
