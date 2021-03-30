/*
** EPITECH PROJECT, 2020
** button.c
** File description:
** function button
*/

#include "../../../include/proto.h"

void button_update_aspect(button_t *button, int number)
{
    if (number == 2) {
        if (button->have_texture == true)
            sfRectangleShape_setTexture(button->button, \
            button->state_two, true);
        else
            sfRectangleShape_setFillColor(button->button, button->step_two);
    } else if (number == 1) {
        if (button->have_texture == true)
            sfRectangleShape_setTexture(button->button, \
            button->state_one, true);
        else
            sfRectangleShape_setFillColor(button->button, button->step_one);
    } else if (number == 3) {
        if (button->have_texture == true)
            sfRectangleShape_setTexture(button->button, \
            button->state_three, true);
        else
            sfRectangleShape_setFillColor(button->button, button->step_three);
    }
}

void button_run_clicked(button_t *button, my_game_t *my_game)
{
    if (button->is_pressed == false) {
        button->is_pressed = true;
        button_update_aspect(button, 2);
        (button->action)(my_game);
    } else {
        button->is_pressed = false;
        button_update_aspect(button, 1);
        (button->action_unclick)(my_game);
    }
}

void button_is_up(button_t *button, sfRenderWindow *window, \
bool is_clicked, my_game_t *my_game)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);

    if (button->is_display == false)
        return;
    if (pos.x >= button->area[0].x && pos.x <= button->area[1].x && pos.y >= \
    button->area[0].y && pos.y <= button->area[2].y) {
        if (is_clicked == true)
            button_run_clicked(button, my_game);
        else {
            button_update_aspect(button, 3);
            if (button->have_textbox == true)
                textbox_change_display(&(button->info), true);
        }
    } else {
        textbox_change_display(&(button->info), false);
        if (button->is_pressed == true)
            button_update_aspect(button, 2);
        else
            button_update_aspect(button, 1);
    }
}

int my_stlen(char const *str)
{
    int str_len;

    str_len = 0;
    while (str[str_len] != '\0')
        str_len++;
    return (str_len);
}

void button_change_pos(sfVector2f pos, button_t *button)
{
    button->pos = pos;
    sfRectangleShape_setPosition(button->button, pos);
    button->area[0] = pos;
    button->area[1] = (sfVector2f){pos.x + button->size.x, pos.y};
    button->area[2] = (sfVector2f){pos.x, pos.y + button->size.y};
    button->area[3] = (sfVector2f){pos.x + \
        button->size.x, pos.y + button->size.y};
}
