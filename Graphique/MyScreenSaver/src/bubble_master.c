/*
** EPITECH PROJECT, 2020
** bubble_master.c
** File description:
** All function for animation 5
*/

#include "proto.h"

int *initialisation_five(void)
{
    int *list_a = malloc(sizeof(int) * 3000);

    if (list_a == NULL)
        return (NULL);
    srand(time(NULL));
    for (int i = 0; i < 800; i++) {
        list_a[i] = rand() % 599 + 1;
    }
    list_a[801] = 0;
    return (list_a);
}

int sort_line(int *list, int *change)
{
    int save = 0;

    *change = 0;
    for (int i = 0; i < 800; i++) {
        if (list[i] > list[i + 1]) {
            save = list[i];
            list[i] = list[i + 1];
            list[i + 1] = save;
            *change = 1;
        }
    }
    return (0);
}

void display_line_color(int *list, t_my_framebuffer *framebuffer, sfColor color)
{
    for (int i = 0; i < 288; i++) {
        for (int j = 0; j < list[i]; j++) {
            my_put_pixel(framebuffer, i, 600 - j, color);
        }
    }
    for (int i = 290; i < 800; i++) {
        for (int j = 0; j < list[i]; j++) {
            my_put_pixel(framebuffer, i, 600 - j, color);
        }
    }
}

void display_line(int *list, t_my_framebuffer *framebuffer)
{
    int change = 0;

    clean_buffer(framebuffer);
    sort_line(list, &change);
    if (change == 1) {
        display_line_color(list, framebuffer, sfBlue);
    } else {
        display_line_color(list, framebuffer, sfGreen);
        list[801] = list[801] + 1;
        if (list[801] > 500) {
            free(list);
            list = initialisation_five();
            list[801] = 0;
        }
    }
}

sprite_t create_sprite(int x, int y)
{
    sprite_t sprite;

    sprite.texture = sfTexture_create(x, y);
    sprite.sprite = sfSprite_create();
    sfSprite_setTexture(sprite.sprite, sprite.texture, sfTrue);
    return (sprite);
}

sfRenderWindow *window_creation(char *title)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window;

    window = sfRenderWindow_create(mode, title, sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}

void bubble_master(void)
{
    sfRenderWindow *window = window_creation("Bubble Master");
    int change = 0;
    t_my_framebuffer *framebuffer = framebuffer_create(800, 600);
    sprite_t sprite = create_sprite(800, 600);
    int *list = initialisation_five();

    if (list == NULL)
        return;
    while (sfRenderWindow_isOpen(window)) {
        event_detection(window, &change);
        sfRenderWindow_clear(window, sfBlack);
        display_line(list, framebuffer);
        sfTexture_updateFromPixels(sprite.texture, framebuffer->pixels, \
        framebuffer->width, framebuffer->height, 0, 0);
        sfRenderWindow_drawSprite(window, sprite.sprite, NULL);
        sfRenderWindow_display(window);
    }
    free(list);
    event_gestion_five(change, window);
}
