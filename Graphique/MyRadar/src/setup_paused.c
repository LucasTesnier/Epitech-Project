/*
** EPITECH PROJECT, 2021
** setup_paused.c
** File description:
** function for setup paused
*/

#include "proto.h"

sfText *setup_text(int x, int y, int size)
{
    sfText *timer = sfText_create();
    sfVector2f pos;
    sfFont *font = sfFont_createFromFile("include/fonts/arial.ttf");

    pos.x = x;
    pos.y = y;
    sfText_setFont(timer, font);
    sfText_setPosition(timer, pos);
    sfText_setCharacterSize(timer, size);
    sfText_setColor(timer, (sfColor){12, 164, 151, 255});
    return (timer);
}

text_opt_t setup_opt(void)
{
    text_opt_t opt;

    opt.timer = setup_text(1825, 40, 50);
    opt.sprite_opt = setup_text(500, 50, 30);
    opt.hitbox_opt = setup_text(1000, 50, 30);
    return (opt);
}

int verif_plane(plane_t *planes, sfRenderWindow *window)
{
    for (int i = 0; planes[i].is_air != -1; i++) {
        if (planes[i].is_air != 2)
            return (0);
    }
    sfRenderWindow_close(window);
    return (1);
}

background_t setup_background(char *path)
{
    background_t back;

    back.texture = sfTexture_createFromFile\
    (path, NULL);
    back.sprite = sfSprite_create();
    sfSprite_setTexture(back.sprite, back.texture, sfTrue);
    return (back);
}

void display_paused(plane_t *planes, tower_t *towers, int *change, \
sfRenderWindow *window)
{
    background_t back = setup_background("include/pictures/background.png");
    background_t paused;

    paused.texture = sfTexture_createFromFile\
    ("include/pictures/pause.png", NULL);
    paused.sprite = sfSprite_create();
    sfSprite_setTexture(paused.sprite, paused.texture, sfTrue);
    sfSprite_setPosition(paused.sprite, (sfVector2f){700, 300});
    sfRenderWindow_drawSprite(window, back.sprite, NULL);
    display_towers(towers, window, planes, change);
    sfRenderWindow_drawSprite(window, paused.sprite, NULL);
    change[3] += 1;
}
