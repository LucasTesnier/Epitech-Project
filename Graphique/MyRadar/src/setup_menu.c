/*
** EPITECH PROJECT, 2021
** setup_menu.c
** File description:
** function for setup menu
*/

#include "proto.h"

sfRenderWindow *create_menu_window(void)
{
    sfRenderWindow *window;
    sfVideoMode mode = {1920, 1080, 32};

    window = sfRenderWindow_create(mode, "Planes Simulator", \
    sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(window, 32);
    return (window);
}

void key_menu(sfRenderWindow *window, sfEvent event, int *change)
{
    if (event.key.code == sfKeyEscape)
        sfRenderWindow_close(window);
    if (event.key.code == sfKeyUp)
        change[2] -= 1;
    if (event.key.code == sfKeyDown)
        change[2] += 1;
    if (change[2] == 0)
        change[2] = 3;
    if (change[2] == 4)
        change[2] = 1;
    if (event.key.code == sfKeyEnter)
        change[3] = change[2];
}

void event_menu(sfRenderWindow *window, int *change)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed)
            key_menu(window, event, change);
    }
}

sfVector2f define_pos(int *change)
{
    sfVector2f pos;

    if (change[1] == 6 * 5)
        change[1] = 6;
    if (change[2] == 1)
        pos.x = 690;
    if (change[2] == 2)
        pos.x = 592;
    if (change[2] == 3)
        pos.x = 710;
    pos.y = 100 + change[2] * 190;
    return (pos);
}

void draw_cursor(sfRenderWindow *window, int *change)
{
    background_t cursor;
    sfVector2f pos;

    if (change[1] / 6 == 1)
        cursor = setup_background("include/pictures/cursor_one.png");
    if (change[1] / 6 == 2)
        cursor = setup_background("include/pictures/cursor_two.png");
    if (change[1] / 6 == 3)
        cursor = setup_background("include/pictures/cursor_three.png");
    if (change[1] / 6 == 4)
        cursor = setup_background("include/pictures/cursor_faur.png");
    change[1] += 1;
    pos = define_pos(change);
    sfSprite_setPosition(cursor.sprite, pos);
    sfRenderWindow_drawSprite(window, cursor.sprite, NULL);
}
