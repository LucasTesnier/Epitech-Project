/*
** EPITECH PROJECT, 2021
** second display_sprite
** File description:
** desc
*/

#include "my_world.h"

void display_sprite_one(my_game_t *my_game, int i, int j)
{
    if (my_game->my_map.construction[i][j] == 3) {
        sfSprite_setScale(my_game->sprite[i][j].sprite, \
        (sfVector2f){(my_game->my_map.vector[i][j + 1].x -  \
            my_game->my_map.vector[i][j].x - 12) / 1596,    \
            (my_game->my_map.vector[i + 1][j].y -   \
            my_game->my_map.vector[i][j].y + 10)/ 929 });
        sfSprite_setPosition(my_game->sprite[i][j].sprite,  \
        (sfVector2f){my_game->my_map.vector[i][j].x +   \
            my_game->my_map.pos.x + (my_game->my_map.vector[i][j].x -   \
            my_game->my_map.vector[i][j + 1].x) / 2,    \
            my_game->my_map.vector[i][j].y + my_game->my_map.pos.y});
    }
}

void display_sprite_two(my_game_t *my_game, int i, int j)
{
    if (my_game->my_map.construction[i][j] == 1) {
        sfSprite_setScale(my_game->sprite[i][j].sprite, \
        (sfVector2f){(my_game->my_map.vector[i][j + 1].x -  \
            my_game->my_map.vector[i][j].x - 12) / 150, \
            (my_game->my_map.vector[i + 1][j].y -   \
            my_game->my_map.vector[i][j].y)/ 190 * 1.8});
        sfSprite_setPosition(my_game->sprite[i][j].sprite,  \
        (sfVector2f){my_game->my_map.vector[i][j].x +   \
            my_game->my_map.pos.x + (my_game->my_map.vector[i][j].x -   \
            my_game->my_map.vector[i][j + 1].x) / 2,    \
            my_game->my_map.vector[i][j].y + my_game->my_map.pos.y -    \
            ((my_game->my_map.vector[i + 1][j].y -  \
            my_game->my_map.vector[i][j].y)/ 190 * 1.8)});
    }
}

void display_sprite_three(my_game_t *my_game, int i, int j)
{
    if (my_game->my_map.construction[i][j] == 2) {
        sfSprite_setScale(my_game->sprite[i][j].sprite, \
        (sfVector2f){(my_game->my_map.vector[i][j + 1].x -  \
            my_game->my_map.vector[i][j].x) / 175, \
            (my_game->my_map.vector[i + 1][j].y -   \
            my_game->my_map.vector[i][j].y) / 175 * 1.6});
        sfSprite_setPosition(my_game->sprite[i][j].sprite,  \
        (sfVector2f){my_game->my_map.vector[i][j].x +   \
            my_game->my_map.pos.x + (my_game->my_map.vector[i][j].x -   \
            my_game->my_map.vector[i][j + 1].x) / 2,    \
            my_game->my_map.vector[i][j].y + my_game->my_map.pos.y -    \
            ((my_game->my_map.vector[i + 1][j].y -  \
            my_game->my_map.vector[i][j].y)/ 175 * 1.6)});
    }
}