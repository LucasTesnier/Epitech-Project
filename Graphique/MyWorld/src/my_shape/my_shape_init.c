/*
** EPITECH PROJECT, 2021
** my_shape_init.c
** File description:
** desc
*/

#include "my_world.h"


sfRectangleShape **init_shapes(void)
{
    sfRectangleShape **shapes = malloc(sizeof(sfRectangleShape *) * 2);

    shapes[0] = sfRectangleShape_create();
    sfRectangleShape_setSize(shapes[0], (sfVector2f){150, 194});
    sfRectangleShape_setPosition(shapes[0], (sfVector2f){0, 850});
    sfRectangleShape_setTexture(shapes[0],  \
    sfTexture_createFromFile("assets/pictures/toolsbar.png", NULL), true);
    return (shapes);
}

void toolsbar_animation2(button_t *buttons, sfVector2f size)
{
    if (size.x + 16 >= 300)
        buttons[2].is_display = true;
    if (size.x + 16 >= 500)
        buttons[3].is_display = true;
    if (size.x + 16 >= 700)
        buttons[4].is_display = true;
    if (size.x + 16 >= 1500)
        buttons[5].is_display = true;
    if (size.x + 16 >= 1700)
        buttons[6].is_display = true;
    if (size.x + 16 >= 1900)
        buttons[7].is_display = true;
    if (size.x + 16 >= 900)
        buttons[8].is_display = true;
    if (size.x + 16 >= 1100)
        buttons[10].is_display = true;
    if (size.x + 16 >= 1300)
        buttons[11].is_display = true;
}

void toolsbar_animation3(button_t *buttons, sfVector2f size)
{
    if (size.x - 16 < 300)
        buttons[2].is_display = false;
    if (size.x - 16 < 500)
        buttons[3].is_display = false;
    if (size.x - 16 < 700)
        buttons[4].is_display = false;
    if (size.x - 16 < 1500)
        buttons[5].is_display = false;
    if (size.x - 16 < 1700)
        buttons[6].is_display = false;
    if (size.x - 16 < 1900)
        buttons[7].is_display = false;
    if (size.x - 16 < 900)
        buttons[8].is_display = false;
    if (size.x - 16 < 1100)
        buttons[10].is_display = false;
    if (size.x - 16 < 1300)
        buttons[11].is_display = false;
}

void toolsbar_animation(sfRectangleShape **shapes, bool to_rigth,   \
button_t *buttons, my_game_t *my_game)
{
    sfVector2f size = sfRectangleShape_getSize(shapes[0]);

    buttons[9].is_display = true;
    if ((sfTime_asSeconds(sfClock_getElapsedTime(my_game->clock)) * 100)    \
    >= 1) {
        if (to_rigth && size.x < 1920) {
            sfRectangleShape_setSize(shapes[0], (sfVector2f)    \
            {size.x + 16, size.y});
            button_change_pos((sfVector2f)  \
            {size.x + 16 - 125, buttons[1].pos.y}, &(buttons[1]));
            toolsbar_animation2(buttons, size);
        }
        if (!to_rigth && size.x > 150) {
            sfRectangleShape_setSize(shapes[0], (sfVector2f)    \
            {size.x - 16, size.y});
            button_change_pos((sfVector2f)  \
            {size.x - 16 - 125, buttons[1].pos.y}, &(buttons[1]));
            toolsbar_animation3(buttons, size);
        }
    }
}