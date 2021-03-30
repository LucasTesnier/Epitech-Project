/*
** EPITECH PROJECT, 2021
** menu.c
** File description:
** all menu fonctions
*/

#include "proto.h"

int play_menu(sfRenderWindow *window, int ac, char *argv[], user_t user)
{
    int ret = 0;

    sfRenderWindow_close(window);
    ret = radar_setup(ac, argv, user);
    return (ret);
}

void key_option(sfRenderWindow *window, sfEvent event, user_t *user, \
int *change)
{
    if (event.key.code == sfKeyEscape)
        sfRenderWindow_close(window);
    if (event.key.code == sfKeyEnter && change[4] == 0) {
        change[4] = 1;
    } else if (event.key.code == sfKeyEnter && change[4] == 1)
        change[4] = 0;
    if (event.key.code == sfKeyBackspace)
        change[3] = 0;
}

void event_option(sfRenderWindow *window, user_t *user, int *change)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed)
            key_option(window, event, user, change);
    }
}

void display_option(sfRenderWindow *window, background_t *sprite, \
int *change, user_t *user)
{
    event_option(window, user, change);
    if (change[4] == 0) {
        sprite[7] = create_sprite("include/pictures/tower_one.png", 835, 375);
        user->hitbox_t = sfBlue;
    }
    if (change[4] == 1) {
        sprite[7] = create_sprite("include/pictures/tower_two.png", 835, 375);
        user->hitbox_t = sfMagenta;
    }
    sfRenderWindow_drawSprite(window, sprite[0].sprite, NULL);
    sfRenderWindow_drawSprite(window, sprite[8].sprite, NULL);
    sfRenderWindow_drawSprite(window, sprite[6].sprite, NULL);
    sfRenderWindow_drawSprite(window, sprite[7].sprite, NULL);
    sfRenderWindow_display(window);
}

int display_menu(int ac, char *argv[])
{
    sfRenderWindow *window = create_menu_window();
    background_t *sprite = setup_menu_sprite();
    int change[] = {0, 6, 1, 0, 0};
    user_t user;

    user.hitbox_p = sfGreen;
    user.hitbox_t = sfBlue;
    while (sfRenderWindow_isOpen(window)) {
        if (change[3] != 2)
            event_menu(window, change);
        if (change[3] == 0)
            display_menu_screen(window, sprite, change);
        if (change[3] == 2)
            display_option(window, sprite, change, &user);
        if (change[3] == 3)
            sfRenderWindow_close(window);
        if (change[3] == 1)
            return (play_menu(window, ac, argv, user));
    }
}
