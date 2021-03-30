/*
** EPITECH PROJECT, 2021
** display_sprite
** File description:
** desc
*/

#include "my_world.h"

void display_sprite_four(my_game_t *my_game, int i, int j)
{
    if (my_game->my_map.construction[i][j] == 4) {
        sfSprite_setScale(my_game->sprite[i][j].sprite, \
        (sfVector2f){(my_game->my_map.vector[i][j + 1].x -  \
            my_game->my_map.vector[i][j].x) / 220, \
            (my_game->my_map.vector[i + 1][j].y -   \
            my_game->my_map.vector[i][j].y)/ 190 * 1.4});
        sfSprite_setPosition(my_game->sprite[i][j].sprite,  \
        (sfVector2f){my_game->my_map.vector[i][j].x +   \
            my_game->my_map.pos.x + (my_game->my_map.vector[i][j].x -   \
            my_game->my_map.vector[i][j + 1].x) / 2,    \
            my_game->my_map.vector[i][j].y + my_game->my_map.pos.y -    \
            ((my_game->my_map.vector[i + 1][j].y -  \
            my_game->my_map.vector[i][j].y)/ 190 * 1.4)});
    }
}

void display_sprite_five(my_game_t *my_game, int i, int j)
{
    if (my_game->my_map.construction[i][j] == 5) {
        sfSprite_setScale(my_game->sprite[i][j].sprite, \
        (sfVector2f){(my_game->my_map.vector[i][j + 1].x -  \
            my_game->my_map.vector[i][j].x) / 180, \
            (my_game->my_map.vector[i + 1][j].y -   \
            my_game->my_map.vector[i][j].y)/ 190 * 1.4});
        sfSprite_setPosition(my_game->sprite[i][j].sprite,  \
        (sfVector2f){my_game->my_map.vector[i][j].x +   \
            my_game->my_map.pos.x + (my_game->my_map.vector[i][j].x -   \
            my_game->my_map.vector[i][j + 1].x) / 2,    \
            my_game->my_map.vector[i][j].y + my_game->my_map.pos.y -    \
            ((my_game->my_map.vector[i + 1][j].y -  \
            my_game->my_map.vector[i][j].y)/ 190 * 1.4)});
    }
}

void display_sprite_six(my_game_t *my_game, int i, int j)
{
    if (my_game->my_map.construction[i][j] == 6) {
        sfSprite_setScale(my_game->sprite[i][j].sprite, \
        (sfVector2f){(my_game->my_map.vector[i][j + 1].x -  \
            my_game->my_map.vector[i][j].x) / 175, \
            (my_game->my_map.vector[i + 1][j].y -   \
            my_game->my_map.vector[i][j].y)/ 250 * 1.8});
        sfSprite_setPosition(my_game->sprite[i][j].sprite,  \
        (sfVector2f){my_game->my_map.vector[i][j].x +   \
            my_game->my_map.pos.x + (my_game->my_map.vector[i][j].x -   \
            my_game->my_map.vector[i][j + 1].x) / 2,    \
            my_game->my_map.vector[i][j].y + my_game->my_map.pos.y -    \
            ((my_game->my_map.vector[i + 1][j].y -  \
            my_game->my_map.vector[i][j].y)/ 250 * 1.8)});
    }
}

void display_all_sprite(my_game_t *my_game, int i, int j)
{
    display_sprite_one(my_game, i, j);
    display_sprite_two(my_game, i, j);
    display_sprite_three(my_game, i, j);
    display_sprite_four(my_game, i, j);
    display_sprite_five(my_game, i, j);
    display_sprite_six(my_game, i, j);
}

void display_sprite(my_game_t *my_game, int i, int j)
{
    if (my_game->my_map.map_height[i][j] >= 0 &&    \
    (my_game->my_map.map_height[i][j] >=    \
    my_game->my_map.map_height[i + 1][j] - 5 && \
    my_game->my_map.map_height[i][j] <= \
    my_game->my_map.map_height[i + 1][j] + 5) &&    \
    (my_game->my_map.map_height[i][j] >=    \
    my_game->my_map.map_height[i][j + 1] - 5 && \
    my_game->my_map.map_height[i][j] <= \
    my_game->my_map.map_height[i][j + 1] + 5) &&    \
    (my_game->my_map.map_height[i][j] >=    \
    my_game->my_map.map_height[i + 1][j + 1] - 5 && \
    my_game->my_map.map_height[i][j] <= \
    my_game->my_map.map_height[i + 1][j + 1] + 5)) {
        display_all_sprite(my_game, i, j);
        sfRenderWindow_drawSprite(my_game->my_window.window,    \
        my_game->sprite[i][j].sprite, NULL);
    }
}