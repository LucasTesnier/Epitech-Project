/*
** EPITECH PROJECT, 2021
** my_display_map
** File description:
** desc
*/

#include "my_world.h"

float init_ratio_night(float progress)
{
    float ratio_night = (progress < 0.2 || progress > 0.8) ? 0.2 - 0.5 :    \
    progress - 0.5;

    ratio_night *= (ratio_night > 0) ? -1 : 1;
    ratio_night = (ratio_night + 0.2) * 5 * 200;
    return (ratio_night);
}

void sprite_conditions_square_six(my_game_t *my_game, int i, int j)
{
    if (my_game->my_map.construction[i][j] == 6) {
        sfSprite_setScale(my_game->sprite[i][j].sprite, (sfVector2f)    \
        {(my_game->my_map.vector[i][j + 1].x -  \
            my_game->my_map.vector[i][j].x) / 175, \
            (my_game->my_map.vector[i + 1][j].y -   \
            my_game->my_map.vector[i][j].y) / 250 * 1.8});
        sfSprite_setPosition(my_game->sprite[i][j].sprite, (sfVector2f) \
        {my_game->my_map.vector[i][j].x + my_game->my_map.pos.x +   \
            (my_game->my_map.vector[i][j].x -   \
            my_game->my_map.vector[i][j + 1].x) / 2,    \
            my_game->my_map.vector[i][j].y + my_game->my_map.pos.y -    \
            ((my_game->my_map.vector[i + 1][j].y -  \
            my_game->my_map.vector[i][j].y)/ 250 * 1.8)});
        my_game->act_construction += 1;
    }
}

void display_selected_tiles(my_game_t *my_game)
{
    my_game->my_window.tile_selected.x -= my_game->radius - 1;
    my_game->my_window.tile_selected.y -= my_game->radius - 1;
    for (int a = 0; a < 2 * my_game->radius - 1 &&  \
    a + my_game->my_window.tile_selected.x + 1 < my_game->my_map.size.x &&  \
    my_game->my_window.tile_selected.x > 0; a++) {
        for (int b = 0; b < 2 * my_game->radius - 1 &&  \
        b + my_game->my_window.tile_selected.y + 1 < my_game->my_map.size.y \
        && my_game->my_window.tile_selected.y > 0; b++) {
            make_shape(my_game, my_game->my_window.tile_selected.x + a, \
            my_game->my_window.tile_selected.y + b);
        }
    }
    my_game->my_window.tile_selected.x += my_game->radius - 1;
    my_game->my_window.tile_selected.y += my_game->radius - 1;
}

void my_display_map_two(my_game_t *my_game, sfVector2i mouse_pos)
{
    sfVector2i tile = my_game->my_window.tile_selected;

    if (my_game->mod != 5 && my_game->mod != 6 && my_game->mod != 1)
        display_selected_tiles(my_game);
    else
        make_shape(my_game, tile.x, tile.y);
    if (my_game->sprite[tile.x][tile.y].sprite_name != 1) {
        sfRenderWindow_drawSprite(my_game->my_window.window,    \
        my_game->sprite[tile.x][tile.y].sprite, NULL);
    } else if (my_game->mod == 5) {
        create_buildings(my_game, tile.x, tile.y);
        display_sprite(my_game, tile.x, tile.y);
        my_game->sprite[tile.x][tile.y].sprite_name = 1;
        my_game->my_map.construction[tile.x][tile.y] = 0;
    }
}

void my_display_map(my_game_t *my_game)
{
    sfVector2i mouse_pos =  \
    sfMouse_getPositionRenderWindow(my_game->my_window.window);

    my_game->act_construction = 0;
    do_action(my_game, mouse_pos);
    my_game->gold_generation = 0;
    for (int i = 0; i < my_game->my_map.size.y - 1; i++) {
        for (int j = 0; j < my_game->my_map.size.x - 1; j++) {
            sfConvexShape_setOutlineThickness(my_game->convexShape, 0);
            make_shape(my_game, i, j);
            in_tiles(my_game, i, j, mouse_pos);
            sprite_conditions(my_game, i, j);
        }
    }
    my_game->mouse_pos = mouse_pos;
    sfConvexShape_setOutlineThickness(my_game->convexShape, 3);
    my_display_map_two(my_game, mouse_pos);
    world_border(my_game);
}