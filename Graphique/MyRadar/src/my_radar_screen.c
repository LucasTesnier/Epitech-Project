/*
** EPITECH PROJECT, 2020
** my_radar_screen.c
** File description:
** all screen function
*/

#include "proto.h"

sfRectangleShape *create_visual_quari(sfVector2f position, sfVector2f size, \
sfColor color_e)
{
    sfRectangleShape *shape = sfRectangleShape_create();
    sfColor color = sfBlue;

    color.a = 0;
    sfRectangleShape_setPosition(shape, position);
    sfRectangleShape_setFillColor(shape, color);
    sfRectangleShape_setOutlineColor(shape, color_e);
    sfRectangleShape_setOutlineThickness(shape, 2);
    sfRectangleShape_setSize(shape, size);
    return (shape);
}

void display_quari(game_t game)
{
    for (int i = 0; i < 4; i++)
        if (game.quari[i].count != 0)
            sfRenderWindow_drawRectangleShape(game.window, \
            create_visual_quari((sfVector2f)\
            {game.quari[i].left, game.quari[i].top}, \
            (sfVector2f){960, 540}, sfGreen), NULL);
}

void display_game(game_t game, background_t back)
{
    sfRenderWindow_drawSprite(game.window, back.sprite, NULL);
    moove_planes(game);
    display_towers(game.towers, game.window, game.planes, game.change);
    if (game.change[1] == 0)
        display_quari(game);
    display_clock(game.window, game.clock, game.opt, game.planes);
    sfRenderWindow_display(game.window);
    verif_plane(game.planes, game.window);
}

void display_global_paused(game_t game)
{
    display_paused(game.planes, game.towers, game.change, game.window);
    display_info_paused(game.window, game.opt);
}

void radar_screen(plane_t *planes, tower_t *towers, user_t user)
{
    game_t game = setup_game(planes, towers, user);
    background_t back = setup_background("include/pictures/background.png");

    while (sfRenderWindow_isOpen(game.window)) {
        event_gestion(game.window, game.change, &game.clock, game.opt);
        if (game.change[2] == 0) {
            display_game(game, back);
        } else
            display_global_paused(game);
    }
}
