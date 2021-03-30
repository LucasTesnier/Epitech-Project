/*
** EPITECH PROJECT, 2021
** my_cursor_tools_two
** File description:
** desc
*/

#include "my_world.h"

void cursor_tools_four(my_game_t *my_game, button_t *buttons)
{
    if (my_game->mod == 4) {
        sfRenderWindow_setMouseCursor(my_game->my_window.window,    \
        sfCursor_createFromSystem(sfCursorHelp));
        buttons[3].is_pressed = false;
        buttons[2].is_pressed = false;
        buttons[8].is_pressed = true;
        buttons[4].is_pressed = false;
        buttons[11].is_pressed = false;
        buttons[10].is_pressed = false;
    }
}

void cursor_tools_five(my_game_t *my_game, button_t *buttons)
{
    if (my_game->mod == 5) {
        sfRenderWindow_setMouseCursor(my_game->my_window.window,    \
        sfCursor_createFromSystem(sfCursorHelp));
        buttons[3].is_pressed = false;
        buttons[2].is_pressed = false;
        buttons[8].is_pressed = false;
        buttons[4].is_pressed = false;
        buttons[10].is_pressed = true;
        buttons[11].is_pressed = false;
    }
}

void cursor_tools_six(my_game_t *my_game, button_t *buttons)
{
    if (my_game->mod == 6) {
        sfRenderWindow_setMouseCursor(my_game->my_window.window,    \
        sfCursor_createFromSystem(sfCursorHelp));
        buttons[3].is_pressed = false;
        buttons[2].is_pressed = false;
        buttons[8].is_pressed = false;
        buttons[4].is_pressed = false;
        buttons[10].is_pressed = false;
        buttons[11].is_pressed = true;
    }
}