/*
** EPITECH PROJECT, 2020
** random_laser.c
** File description:
** all function for random laser
*/

#include "proto.h"

void display_random_laser(t_my_framebuffer *framebuffer, my_line *line)
{
    if (line->rigth == 0) {
        for (int i = 0; i < line->point_b.x; i++)
            my_put_pixel(framebuffer, i, line->pos * line->speed, line->color);
        if (line->pos * line->speed >= 600)
            line->change = -1;
    }
    if (line->rigth == 1) {
        for (int i = 0; i < line->point_b.y; i++)
            my_put_pixel(framebuffer, line->pos * line->speed, i, line->color);
        if (line->pos * line->speed >= 800)
            line->change = -1;
    }
    if (line->pos * line->speed <= 0)
        line->change = 1;
    if (line->change == 1)
        line->pos = line->pos + 1;
    else
        line->pos = line->pos - 1;
}

void event_gestion_two(int change, sfRenderWindow *window)
{
    sfRenderWindow_destroy(window);
    if (change == 1)
        screen_saver_menu(2);
    if (change == 2)
        screen_saver_menu(3);
    if (change == 3)
        screen_saver_menu(1);
}

sfRenderWindow *create_window(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window;

    window = sfRenderWindow_create(mode, "random_laser", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}

my_line *set_random(int *number_line)
{
    my_line *line_stock;

    srand(time(NULL));
    *number_line = rand() % 100;
    line_stock = malloc(sizeof(my_line) * (*number_line + 1));
    for (int i = 0; i < *number_line; i++)
        line_stock[i] = set_line();
    return (line_stock);
}

void random_laser(void)
{
    sfRenderWindow *window = create_window();
    t_my_framebuffer *framebuffer = framebuffer_create(800, 600);
    sfTexture* texture = sfTexture_create(800, 600);
    sfSprite* sprite = sfSprite_create();
    int number_line = 0;
    my_line *line_stock = set_random(&number_line);
    int change = 0;

    sfSprite_setTexture(sprite, texture, sfTrue);
    while (sfRenderWindow_isOpen(window)) {
        event_detection(window, &change);
        clean_buffer(framebuffer);
        laser_change_color(&change, line_stock, number_line);
        for (int i = 0; i < number_line; i++)
            display_random_laser(framebuffer, &line_stock[i]);
        sfTexture_updateFromPixels(texture, framebuffer->pixels, \
        framebuffer->width, framebuffer->height, 0, 0);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    event_gestion_two(change, window);
}
