/*
** EPITECH PROJECT, 2021
** key_and_moove.c
** File description:
** function for key detection and moove
*/

#include "proto.h"

void fill_quari(game_t game, int i, sfVector2f pos)
{
    for (int j = 0; j < 4; j++) {
        if (pos.x >= game.quari[j].left && pos.x <= game.quari[j].right \
        && pos.y >= game.quari[j].top && pos.y <= game.quari[j].bottom && \
        game.planes[i].is_air == 1) {
            game.quari[j].list[game.quari[j].count] = i;
            game.quari[j].count += 1;
        }
    }
}

void moove_planes(game_t game)
{
    sfVector2f pos;

    for (int i = 0; i < 4; i++)
        game.quari[i].count = 0;
    for (int i = 0; game.planes[i].is_air != -1; i++) {
        if (game.planes[i].arrival.x == floor(game.planes[i].departure.x + \
            0.5) && game.planes[i].arrival.y == floor(game.planes[i]. \
            departure.y + 0.5))
            game.planes[i].is_air = 2;
        rotation_planes(game.planes, i);
        pos.x = game.planes[i].departure.x - 10;
        pos.y = game.planes[i].departure.y - 10;
        sfSprite_setPosition(game.planes[i].screen.sprite, pos);
        sfRectangleShape_setPosition(game.planes[i].hitbox, (sfVector2f)\
        {pos.x + 10, pos.y + 10});
        fill_quari(game, i, pos);
        colision(&game.planes[i], i, game.planes, game.towers);
    }
}

void display_towers(tower_t *towers, sfRenderWindow *window, plane_t *planes, \
int *change)
{
    for (int i = 0; towers[i].radius != -1; i++) {
        if (change[0] == 0)
            sfRenderWindow_drawSprite(window, towers[i].screen.sprite, NULL);
        if (change[1] == 0)
            sfRenderWindow_drawCircleShape(window, towers[i].hitbox, NULL);
    }
    for (int i = 0; planes[i].is_air != -1; i++) {
        if (planes[i].is_air == 1) {
            if (change[0] == 0)
                sfRenderWindow_drawSprite(window, planes[i].screen.sprite, \
                NULL);
            if (change[1] == 0)
                sfRenderWindow_drawRectangleShape(window, planes[i].hitbox, \
                NULL);
        }
    }
}

void key_gestion(sfRenderWindow *window, int *change, sfEvent event, \
timer_clock_t *clock)
{
    if (event.key.code == sfKeyEscape)
        sfRenderWindow_close(window);
    if (event.key.code == sfKeyS && change[0] == 0)
        change[0] = 1;
    else if (event.key.code == sfKeyS && change[0] == 1)
        change[0] = 0;
    if (event.key.code == sfKeyL && change[1] == 0)
        change[1] = 1;
    else if (event.key.code == sfKeyL && change[1] == 1)
        change[1] = 0;
    if (event.key.code == sfKeyP && change[2] == 1) {
        change[2] = 0;
        clock->time_lost += change[3];
    }
    else if (event.key.code == sfKeyP && change[2] == 0) {
        change[2] = 1;
        change[3] = 0;
    }
}

void event_gestion(sfRenderWindow *window, int *change, timer_clock_t *clock, \
text_opt_t opt)
{
    sfEvent event;

    sfRenderWindow_clear(window, sfBlack);
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed)
            key_gestion(window, change, event, clock);
    }
    if (change[0] == 0)
        sfText_setString(opt.sprite_opt, "Show Sprites : ON");
    if (change[0] == 1)
        sfText_setString(opt.sprite_opt, "Show Sprites : OFF");
    if (change[1] == 0)
        sfText_setString(opt.hitbox_opt, "Show Hitboxes : ON");
    if (change[1] == 1)
        sfText_setString(opt.hitbox_opt, "Show Hitboxes : OFF");
}
