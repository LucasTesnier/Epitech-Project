/*
** EPITECH PROJECT, 2020
** B-PSU-101-NAN-1-1-navy-lucas.tesnier
** File description:
** attack
*/

#include <stdio.h>
#include "my.h"
#include "navy.h"

char *get_attack_pos(game_info_t *g_inf)
{
    char *line = NULL;
    size_t n = 0;
    ssize_t len;
    write(1, "attack: ", 9);
    len = getline(&line, &n, stdin);
    if (len != 3 || !check_pos(line, SHOOT)){
        write(1, "wrong position\n", 16);
        return (NULL);
    }
    line[len - 1] = '\0';
    return (line);
}

bool is_gameover(game_info_t *g_info)
{
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++)
            if (g_info->player_map[i][j] > 0)
                return (false);
    }
    return (true);
}

int receive_attack_info(char *pos, game_info_t *g_info, bool hitted)
{
    int int_pos[2] = {*pos - 'A', *(pos + 1) - '1'};
    int cell = g_info->opponent[int_pos[1]][int_pos[0]];

    write(1, pos, 2);
    if (hitted) {
        write(1, ": hit\n\n", 7);
        g_info->opponent[int_pos[1]][int_pos[0]] = -2;
    } else {
        write(1, ": missed\n\n", 10);
        g_info->opponent[int_pos[1]][int_pos[0]] = -1;
    }
}

