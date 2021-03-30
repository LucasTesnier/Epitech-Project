/*
** EPITECH PROJECT, 2020
** circle_game.c
** File description:
** all function for animation 3
*/

#include "proto.h"

my_circle *initialisation(void)
{
    my_circle *circle_stock = malloc(sizeof(my_circle) * 4);
    sfVector2i speed;
    sfVector2i dir;
    sfVector2i center;
    sfColor color;

    speed.x = 2;
    speed.y = 2;
    dir.x = 1;
    center.x = 400;
    center.y = 300;
    color = sfBlue;
    circle_stock[0] = set_circle(speed, dir, center, color);
    speed.x = -2;
    circle_stock[1] = set_circle(speed, dir, center, color);
    speed.y = -2;
    circle_stock[2] = set_circle(speed, dir, center, color);
    speed.x = 2;
    circle_stock[3] = set_circle(speed, dir, center, color);
    return (circle_stock);
}

void display_circle_two(my_circle *circle_stock, t_my_framebuffer \
*framebuffer, int i)
{
    if (circle_stock[i].direction.x == 1)
        circle_stock[i].size += 1;
    if (circle_stock[i].direction.x == -1)
        circle_stock[i].size -= 1;
    if (circle_stock[i].center.x + circle_stock[i].speed.x + circle_stock\
        [i].size > 800 || circle_stock[i].center.x + circle_stock[i].speed\
        .x - circle_stock[i].size < 0)
        circle_stock[i].speed.x = circle_stock[i].speed.x * -1;
    if (circle_stock[i].center.y + circle_stock[i].speed.y + circle_stock\
        [i].size > 600 || circle_stock[i].center.y + circle_stock[i].\
        speed.y - circle_stock[i].size < 0)
        circle_stock[i].speed.y = circle_stock[i].speed.y * -1;
}

void adn_change_color(int *change, sfColor *color)
{
    sfColor color_l[] = {sfBlue, sfGreen, sfRed, sfWhite, sfYellow};

    if (*change == 4) {
        color[0] = color_l[rand() % 5];
        color[1] = color_l[rand() % 5];
        while (color[1].r == color[0].r && color[1].g == color[0].g && \
            color[1].b == color[0].b)
            color[1] = color_l[rand() % 5];
        *change = 0;
    }
}

void display_circle(my_circle *circle_stock, t_my_framebuffer *framebuffer, \
sfColor *color, int *change)
{
    adn_change_color(change, color);
    for (int i = 0; i < 4; i++) {
        draw_circle(framebuffer, circle_stock[i].center, circle_stock[i].size, \
        circle_stock[i].color);
        circle_stock[i].center.x = circle_stock[i].center.x + circle_stock[i].\
        speed.x;
        circle_stock[i].center.y = circle_stock[i].center.y + circle_stock[i].\
        speed.y;
        if (circle_stock[i].size + 1 > 24) {
            circle_stock[i].direction.x = -1;
            circle_stock[i].color = color[0];
        }
        if (circle_stock[i].size - 1 < 2) {
            circle_stock[i].direction.x = 1;
            circle_stock[i].color = color[1];
        }
        display_circle_two(circle_stock, framebuffer, i);
    }
}

void adn_monster(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window;
    int change = 0;
    t_my_framebuffer *framebuffer = framebuffer_create(800, 600);
    sfTexture* texture = sfTexture_create(800, 600);
    sfSprite* sprite = sfSprite_create();
    my_circle *circle_stock = initialisation();
    sfColor color[] = {sfBlue, sfRed};

    window = sfRenderWindow_create(mode, "Adn Monster", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfSprite_setTexture(sprite, texture, sfTrue);
    while (sfRenderWindow_isOpen(window)) {
        event_detection(window, &change);
        display_circle(circle_stock, framebuffer, color, &change);
        sfTexture_updateFromPixels(texture, framebuffer->pixels, \
        framebuffer->width, framebuffer->height, 0, 0);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    event_gestion_three(change, window);
}
