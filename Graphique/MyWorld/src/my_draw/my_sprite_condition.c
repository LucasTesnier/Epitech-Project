/*
** EPITECH PROJECT, 2021
** sprite_condition
** File description:
** desc
*/

#include "my_world.h"

sfVector2f init_sprite_scale(my_game_t *my_game, int i, int j)
{
    sfVector2f vector = my_game->my_map.vector[i][j];
    sfVector2f vectorj = my_game->my_map.vector[i][j + 1];
    sfVector2f vectori = my_game->my_map.vector[i + 1][j];
    sfVector2f scale = {(vectorj.x - vector.x) / 170,   \
        (vectori.y - vector.y) / 250 * 1.8};

    return (scale);
}

void sprite_all_conditions_square(my_game_t *my_game, int i, int j)
{
    sprite_conditions_square_one(my_game, i, j);
    sprite_conditions_square_two(my_game, i, j);
    sprite_conditions_square_three(my_game, i, j);
    sprite_conditions_square_four(my_game, i, j);
    sprite_conditions_square_five(my_game, i, j);
    sprite_conditions_square_six(my_game, i, j);
}

void scale_and_pos(my_game_t *my_game, int i, int j)
{
    sfSprite_setScale(my_game->sprite[i][j].sprite, \
    init_sprite_scale(my_game, i, j));
    sfSprite_setPosition(my_game->sprite[i][j].sprite,  \
    (sfVector2f){my_game->my_map.vector[i][j].x +   \
        my_game->my_map.pos.x + (my_game->my_map.vector[i][j].x -   \
        my_game->my_map.vector[i][j + 1].x) / 2,    \
        my_game->my_map.vector[i][j].y + my_game->my_map.pos.y -    \
        ((my_game->my_map.vector[i + 1][j].y -  \
        my_game->my_map.vector[i][j].y)/ 250 * 10)});
}

void sprite_conditions_square(my_game_t *my_game, int i, int j)
{
    if (is_placable(my_game, i, j)) {
        sprite_all_conditions_square(my_game, i, j);
        if (my_game->my_map.construction[i][j] < 0) {
            scale_and_pos(my_game, i, j);
            my_game->act_construction += 1;
        }
        sfRenderWindow_drawSprite(my_game->my_window.window,    \
        my_game->sprite[i][j].sprite, NULL);
    } else {
        my_game->my_map.construction[i][j] = 0;
        my_game->sprite[i][j].sprite_name = 1;
        my_game->construction_number -= 1;
    }
}

void sprite_conditions(my_game_t *my_game, int i, int j)
{
    if (my_game->my_map.construction[i][j] != 0) {
        if (in_window(my_game, i, j) == 1) {
            sprite_conditions_square(my_game, i, j);
        } else {
            sfSprite_setPosition(my_game->sprite[i][j].sprite,  \
            (sfVector2f){-1000, -1000});
            my_game->act_construction += 1;
        }
    }
    if (my_game->my_map.construction[i][j] > 0)
        my_game->gold_generation += my_game->my_map.construction[i][j];
}