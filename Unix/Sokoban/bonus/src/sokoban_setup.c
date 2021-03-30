/*
** EPITECH PROJECT, 2021
** sokoban_setup.c
** File description:
** all function for setup sokoban
*/

#include "proto.h"

void setup_screen(void)
{
    initscr();
    if (has_colors() == FALSE) {
        endwin();
        my_putstr("Your terminal does not support color\n");
        return;
    }
    start_color();
    init_pair(2, COLOR_RED, COLOR_YELLOW);
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
    keypad(stdscr, TRUE);
    cbreak();
    noecho();
    clear();
}

pos_t define_size(char *buffer)
{
    pos_t size;
    int count = 0;
    size.x = 0;
    size.y = 0;

    for (int i = 0; buffer[i]; i++) {
        if (buffer[i] == '\n') {
            if (size.x < count)
                size.x = count;
            count = 0;
            size.y += 1;
        }
        if (buffer[i] != '\n')
            count++;
    }
    return (size);
}

game_t setup_struct(char *buffer)
{
    game_t game;
    pos_t size = define_size(buffer);

    game.is_winning = 0;
    game.map.size = size;
    game.map.cases = mem_alloc_2d_array_case(size.y + 10, size.x + 10);
    filling_cases(&game, buffer);
    return (game);
}

int sokoban_setup(char *path)
{
    char *buffer = load_file_in_mem(path);
    game_t game;

    if (buffer == NULL)
        return (84);
    if (verification_map(buffer) == -1)
        return (84);
    game = setup_struct(buffer);
    setup_screen();
    sokoban_loop(game, buffer);
    return (0);
}
