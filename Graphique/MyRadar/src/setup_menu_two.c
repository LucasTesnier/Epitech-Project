/*
** EPITECH PROJECT, 2021
** setup_menu_two.c
** File description:
** next fonction for setup menu
*/

#include "proto.h"

background_t create_sprite(char *path, int x, int y)
{
    background_t sprite = setup_background(path);

    sfSprite_setPosition(sprite.sprite, (sfVector2f){x, y});
    return (sprite);
}

background_t *setup_menu_sprite(void)
{
    background_t *sprite = malloc(sizeof(background_t) * 15);

    sprite[0] = create_sprite("include/pictures/menu.png", 0, 0);
    sprite[1] = create_sprite("include/pictures/title.png", 300, 30);
    sprite[2] = create_sprite("include/pictures/play.png", 810, 300);
    sprite[3] = create_sprite("include/pictures/options.png", 712, 500);
    sprite[4] = create_sprite("include/pictures/exit.png", 830, 700);
    sprite[5] = create_sprite("include/pictures/autor.png", 1370, 1000);
    sprite[6] = create_sprite("include/pictures/opt.png", 656, 30);
    sprite[7] = create_sprite("include/pictures/tower_one.png", 100, 50);
    sprite[8] = create_sprite("include/pictures/tower_text.png", 835, 650);
    return (sprite);
}

void display_menu_screen(sfRenderWindow *window, background_t *sprite, \
int *change)
{
    for (int i = 0; i < 6; i++)
        sfRenderWindow_drawSprite(window, sprite[i].sprite, NULL);
    draw_cursor(window, change);
    sfRenderWindow_display(window);
}
