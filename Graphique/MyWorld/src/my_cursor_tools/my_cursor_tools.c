/*
** EPITECH PROJECT, 2021
** my_cursor_tools.c
** File description:
** desc
*/

#include "my_world.h"
#include "proto.h"

void cursor_tools_one(my_game_t *my_game, button_t *buttons)
{
    if (my_game->mod == 1) {
        sfRenderWindow_setMouseCursor(my_game->my_window.window,    \
        sfCursor_createFromSystem(sfCursorHand));
        buttons[3].is_pressed = false;
        buttons[4].is_pressed = false;
        buttons[8].is_pressed = false;
        buttons[10].is_pressed = false;
        buttons[11].is_pressed = false;
        buttons[2].is_pressed = true;
    }
}

void cursor_tools_two(my_game_t *my_game, button_t *buttons)
{
    if (my_game->mod == 2) {
        sfRenderWindow_setMouseCursor(my_game->my_window.window,    \
        sfCursor_createFromSystem(sfCursorArrow));
        buttons[2].is_pressed = false;
        buttons[4].is_pressed = false;
        buttons[8].is_pressed = false;
        buttons[10].is_pressed = false;
        buttons[11].is_pressed = false;
        buttons[3].is_pressed = true;
    }
}

void cursor_tools_three(my_game_t *my_game, button_t *buttons)
{
    if (my_game->mod == 3) {
        sfRenderWindow_setMouseCursor(my_game->my_window.window,    \
        sfCursor_createFromSystem(sfCursorWait));
        buttons[3].is_pressed = false;
        buttons[2].is_pressed = false;
        buttons[8].is_pressed = false;
        buttons[10].is_pressed = false;
        buttons[11].is_pressed = false;
        buttons[4].is_pressed = true;
    }
}

void cursor_tools(my_game_t *my_game, button_t *buttons)
{
    cursor_tools_one(my_game, buttons);
    cursor_tools_two(my_game, buttons);
    cursor_tools_three(my_game, buttons);
    cursor_tools_four(my_game, buttons);
    cursor_tools_five(my_game, buttons);
    cursor_tools_six(my_game, buttons);
    buttons[5].is_pressed = false;
    buttons[6].is_pressed = false;
    buttons[7].is_pressed = false;
}