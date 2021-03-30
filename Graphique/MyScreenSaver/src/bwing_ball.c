/*
** EPITECH PROJECT, 2020
** bwing_ball.c
** File description:
** all function for animation 4
*/

#include "proto.h"

my_circle set_circle_faur(sfVector2i speed, sfVector2i dir, sfVector2i
center, sfColor color)
{
    my_circle circle;

    circle.center.x = center.x;
    circle.center.y = center.y;
    circle.speed.x = speed.x;
    circle.speed.y = speed.y;
    circle.size = 5 + (rand() % 10);
    circle.direction.x = dir.x;
    circle.direction.y = dir.y;
    circle.color = color;
    return (circle);
}

my_circle *initialisation_faur(int *random)
{
    my_circle *circle_stock = malloc(sizeof(my_circle) * 8);
    sfVector2i speed;
    sfVector2i dir;
    sfVector2i center;
    sfColor color;

    srand(time(NULL));
    *random = rand() % 100 + 30;
    circle_stock = malloc(sizeof(my_circle) * (*random));
    center.x = rand() % 785 + 11;
    center.y = rand() % 510 + 11;
    speed.x = 0;
    speed.y = rand() % 4 + 2;
    color = sfBlue;
    for (int i = 0; i < *random; i++) {
        color.a = rand() % 100 + 1;
        circle_stock[i] = set_circle_faur(speed, dir, center, color);
        center.x = rand() % 785 + 16;
        center.y = rand() % 510 + 16;
    }
    return (circle_stock);
}

void snow_change_color(my_circle *circle_stock, int *random, int *change)
{
    sfColor color[] = {sfBlue, sfGreen, sfRed, sfWhite, sfYellow};
    int random_c = rand() % 5;

    if (*change == 4) {
        for (int i = 0; i < *random; i++) {
            circle_stock[i].color = color[random_c];
            circle_stock[i].color.a = rand() % 100 + 1;
        }
        *change = 0;
    }
}

void display_circle_faur(my_circle *circle_stock, t_my_framebuffer
*framebuffer, int *random, int *change)
{
    clean_buffer(framebuffer);
    snow_change_color(circle_stock, random, change);
    for (int i = 0; i < *random; i++) {
        draw_circle_f(framebuffer, circle_stock[i].center, circle_stock[i]. \
        size, circle_stock[i].color);
        circle_stock[i].center.y = circle_stock[i].center.y + circle_stock[i]\
        .speed.y;
        if (circle_stock[i].center.y + circle_stock[i].speed.y + circle_stock\
        [i].size >= 600) {
            circle_stock[i].center.y = 0 + circle_stock[i].size;
            circle_stock[i].speed.y = rand() % 4 + 2;
            circle_stock[i].center.x = rand() % 785 + circle_stock[i].size;
        }
    }
}

void snow_man(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window;
    int change = 0;
    t_my_framebuffer *framebuffer = framebuffer_create(800, 600);
    sfTexture* texture = sfTexture_create(800, 600);
    sfSprite* sprite = sfSprite_create();
    int random = 0;
    my_circle *circle_stock = initialisation_faur(&random);

    window = sfRenderWindow_create(mode, "Snow Man", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfSprite_setTexture(sprite, texture, sfTrue);
    while (sfRenderWindow_isOpen(window)) {
        event_detection(window, &change);
        display_circle_faur(circle_stock, framebuffer, &random, &change);
        sfTexture_updateFromPixels(texture, framebuffer->pixels, \
        framebuffer->width, framebuffer->height, 0, 0);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    event_gestion_faur(change, window);
}
