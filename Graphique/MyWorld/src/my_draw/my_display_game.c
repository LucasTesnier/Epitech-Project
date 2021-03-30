/*
** EPITECH PROJECT, 2021
** my_display_game
** File description:
** desc
*/

#include "my_world.h"

void display_game_two(my_game_t *my_game, text_t *texts, button_t *buttons)
{
    my_game->fps++;
    buttons[0].is_display = false;
    texts[0].is_display = false;
    texts[1].is_display = true;
    texts[2].is_display = true;
    texts[3].is_display = true;
    buttons[1].is_display = true;
    my_event(&(my_game->my_window), my_game, buttons);
    update_pixel(buttons, my_game);
    for (int i = 0; i < 1; i++) {
        progressbar_update_cursor_pos(&(my_game->progress_bar[i]),  \
        my_game->my_window.window);
    }
    if (my_game->my_window.mouse_status != 1)
        my_game->mouse_pos =    \
        sfMouse_getPositionRenderWindow(my_game->my_window.window);
    my_display_map(my_game);
    sfRenderWindow_drawRectangleShape(my_game->my_window.window,    \
    my_game->shapes[0], NULL);
    display_button(my_game->my_window.window, buttons);
}

void display_game(my_game_t *my_game, text_t *texts, button_t *buttons)
{
    display_game_two(my_game, texts, buttons);
    display_text(my_game->my_window.window, texts);
    display_progress_bar(my_game->my_window.window, my_game->progress_bar);
    for (int i = 0; i < 12; i++)
        button_is_up(&(buttons[i]), my_game->my_window.window, false, my_game);
    update_text(my_game, texts);
    if (sfTime_asSeconds(sfClock_getElapsedTime(my_game->clock)) >= 1) {
        my_game->fps = 0;
        sfClock_restart(my_game->clock);
        my_game->gold += my_game->gold_generation;
    }
    cursor_tools(my_game, buttons);
    toolsbar_animation(my_game->shapes, my_game->toolsbar_on, buttons,  \
    my_game);
}

void display_menu(my_game_t *my_game, text_t *texts, my_sprite_t *sprites,  \
button_t *buttons)
{
    my_event_menu(&(my_game->my_window), my_game, buttons);
    display_sprites(my_game->my_window.window, sprites);
    display_text(my_game->my_window.window, texts);
    button_is_up(&(buttons[0]), my_game->my_window.window, false, my_game);
    display_button(my_game->my_window.window, buttons);
}