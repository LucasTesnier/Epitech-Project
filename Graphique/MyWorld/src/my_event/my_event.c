/*
** EPITECH PROJECT, 2021
** my_event
** File description:
** desc
*/

#include "my_world.h"
#include "proto.h"

void my_event_menu(my_window_t *my_window, my_game_t *my_game,  \
button_t *buttons)
{
    while (sfRenderWindow_pollEvent(my_window->window, &my_window->event)) {
        if (my_window->event.type == sfEvtClosed)
            sfRenderWindow_close(my_window->window);
        if (my_window->event.type == sfEvtKeyPressed && \
            my_window->event.key.code == sfKeyEscape)
            sfRenderWindow_close(my_window->window);
        if (my_window->event.type == sfEvtMouseButtonPressed)
            button_is_up(&(buttons[0]), my_window->window, true, my_game);
    }
}

void select_mouse_button(my_game_t *my_game, button_t *buttons)
{
    for (int i = 0; i < 12; i++)
        button_is_up(&(buttons[i]), my_game->my_window.window, true,    \
        my_game);
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        my_game->my_window.mouse_status = 1;
    else if (sfMouse_isButtonPressed(sfMouseRight) == sfTrue)
        my_game->my_window.mouse_status = 2;
}

void my_event2(my_window_t *my_window, my_game_t *my_game, button_t *buttons)
{
    if (my_window->event.type == sfEvtKeyPressed) {
        my_game->my_map.pos.x += (my_window->event.key.code ==  \
        sfKeyRight) ? 5 : 0;
        my_game->my_map.pos.x -= (my_window->event.key.code ==  \
        sfKeyLeft) ? 5 : 0;
        my_game->my_map.pos.y += (my_window->event.key.code ==  \
        sfKeyDown) ? 5 : 0;
        my_game->my_map.pos.y -= (my_window->event.key.code ==  \
        sfKeyUp) ? 5 : 0;
    }
}

void my_event(my_window_t *my_window, my_game_t *my_game, button_t *buttons)
{
    while (sfRenderWindow_pollEvent(my_window->window, &my_window->event)) {
        if (my_window->event.type == sfEvtClosed)
            sfRenderWindow_close(my_window->window);
        if (my_window->event.type == sfEvtKeyPressed && \
            my_window->event.key.code == sfKeyEscape)
            sfRenderWindow_close(my_window->window);
        if (my_window->event.type == sfEvtMouseWheelScrolled) {
            zoom(my_game);
        }
        my_event2(my_window, my_game, buttons);
        if (my_window->event.type == sfEvtMouseButtonPressed) {
            select_mouse_button(my_game, buttons);
        }
        else if (my_window->event.type == sfEvtMouseButtonReleased)
            my_window->mouse_status = 0;
        key_shortcut(my_game, my_window);
    }
}