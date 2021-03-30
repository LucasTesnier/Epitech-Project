/*
** EPITECH PROJECT, 2020
** B-PSU-101-NAN-1-1-navy-lucas.tesnier
** File description:
** display_board
*/

#include "headers.h"
#include "navy.h"
#include "my.h"

static ssize_t print_conditions(int condition)
{
    if (condition == -1)
        return (write(1, "o", 1));
    if (condition == -2)
        return (write(1, "x", 1));
    if (condition == 0)
        return (write(1, ".", 1));
    return (my_put_nbr(condition));
}

static void display_enemy(game_info_t *game_inf)
{
    my_putstr("enemy's positions:\n");
    my_putstr(HEADER);
    for (int i = 0; i < 8; i++){
        my_putstr(line_headers[i]);
        for (int j = 0; j < 8; j++){
            print_conditions(game_inf->opponent[i][j]);
            (j + 1 == 8) ? write(1, "\n", 1) : write(1, " ", 1);
        }
    }
}

static void display_my(game_info_t *game_inf)
{
    my_putstr("my positions:\n");
    my_putstr(HEADER);
    for (int i = 0; i < 8; i++){
        my_putstr(line_headers[i]);
        for (int j = 0; j < 8; j++){
            print_conditions(game_inf->player_map[i][j]);
            (j + 1 == 8) ? write(1, "\n", 1) : write(1, " ", 1);
        }
    }
}

void display_game(game_info_t *game_inf)
{
    display_my(game_inf);
    write(1, "\n", 1);
    display_enemy(game_inf);
    write(1, "\n", 1);
}