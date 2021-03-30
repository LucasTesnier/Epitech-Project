/*
** EPITECH PROJECT, 2020
** B-PSU-101-NAN-1-1-navy-lucas.tesnier
** File description:
** get_ships
*/

#define _GNU_SOURCE *

#include <stdio.h>
#include <unistd.h>
#include "navy.h"
#include "my.h"

bool check_file_content(FILE *file)
{
    int cnt = 0;
    char *line = NULL;
    size_t n = 0;
    ssize_t l_len;

    if (!file){
        write(1, "Can't open file\n", 17);
        return (false);
    }
    while ((l_len = getline(&line, &n , file)) != EOF){
        line[l_len - 1] = '\0';
        if (!check_pos(line, SET) || l_len != 8){
            return (false);
        }
        cnt++;
    }
    if (cnt != 4)
        return (false);
    return (true);
}

static bool already_placed(int size, game_info_t *g_inf)
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (g_inf->player_map[i][j] == size)
                return (true);
    return (false);
}

static bool place_ship(int size, char *start, char axis, game_info_t *game_inf)
{
    int start_coord[2] = {*start - 'A' - 1, *(start + 1) - '0' - 1};

    if (axis == 'x'){
        if (start_coord[1] + size > 8 || size < 2 || size > 5
        || already_placed(size, game_inf))
            return (false);
        for (int i = 0; i < size; i++)
            game_inf->player_map[i + start_coord[1]][start_coord[0] + 1] = size;
        return (true);
    }
    if (start_coord[0] + size > 8 || size < 2 || size > 5
    || already_placed(size, game_inf))
        return (false);
    for (int i = 0; i < size; i++)
        game_inf->player_map[start_coord[1]][i + start_coord[0] + 1] = size;
    return (true);
}

static bool set_ships(FILE *file, game_info_t *game_inf)
{
    char *line = NULL;
    size_t n = 0;
    int x_diff;
    int y_diff;

    while (getline(&line, &n, file) != EOF){
        x_diff = get_diff(line + 2, 'x');
        y_diff = get_diff(line + 2, 'y');
        if (x_diff == 0) {
            if (!place_ship(*line - '0', line + 2, 'x', game_inf))
                return (false);
        } else {
            if (!place_ship(*line - '0', line + 2, 'y', game_inf))
                return (false);
        }
    }
    fclose(file);
    return (true);
}

bool getcheck_file(char *path, game_info_t *game_inf)
{
    FILE * file;
    char *line = NULL;
    size_t n = 0;

    if (!path)
        return (false);
    file = fopen(path, "r");
    if (!file)
        return (false);
    if (!check_file_content(file))
        return (false);
    fclose(file);
    file = fopen(path, "r");
    if (!set_ships(file, game_inf))
        return (false);
    return (true);
}