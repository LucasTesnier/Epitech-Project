/*
** EPITECH PROJECT, 2021
** display_map.c
** File description:
** all function for display map
*/

#include "proto.h"

bool is_displayable(game_t game)
{
    if (game.map.size.x > COLS || game.map.size.y > LINES) {
        mvaddstr(LINES / 2, COLS / 2 - 4, "Too small");
        return (false);
    }
    return (true);
}

void display_storage(game_t game, pos_t pos)
{
    if (game.map.cases[pos.y][pos.x].empty == true) {
        if (game.map.cases[pos.y][pos.x].is_storage == true)
            mvaddch(LINES / 2 + pos.y - game.map.size.y / 2, COLS / 2 + \
            pos.x - game.map.size.x / 2, 'O');
        else
            mvaddch(LINES / 2 + pos.y - game.map.size.y / 2, COLS / 2 + \
            pos.x - game.map.size.x / 2, ' ');
    }
}

void display_other_case(game_t game, pos_t pos)
{
    if (game.map.cases[pos.y][pos.x].box == true)
        mvaddch(LINES / 2 + pos.y - game.map.size.y / 2, COLS / 2 + \
        pos.x - game.map.size.x / 2, 'X');
    if (game.map.cases[pos.y][pos.x].player == true)
        mvaddch(LINES / 2 + pos.y - game.map.size.y / 2 , COLS / 2 + \
        pos.x - game.map.size.x / 2, 'P');
    if (game.map.cases[pos.y][pos.x].wall == true)
        mvaddch(LINES / 2 + pos.y - game.map.size.y / 2, COLS / 2 + \
        pos.x - game.map.size.x / 2, '#');
}

void display_map(game_t game)
{
    pos_t pos = {0, 0};

    clear();
    if (is_displayable(game) == false)
        return;
    while (1) {
        if (game.map.cases[pos.y][pos.x].end == true) {
            pos.x = 0;
            pos.y += 1;
        }
        if (game.map.cases[pos.y][0].end == true)
            return;
        display_storage(game, pos);
        display_other_case(game, pos);
        pos.x += 1;
    }
}

int sokoban_loop(game_t game, char *buffer)
{
    int action = 0;

    while (game.is_winning == 0) {
        display_map(game);
        refresh();
        action = getch();
        action_gestion(action, &game, buffer);
        verif_win(&game);
        if (game.is_winning == 1)
            break;
        verif_loose(&game);
    }
    display_map(game);
    refresh();
    endwin();
    return (game.is_winning - 1);
}
