/*
** EPITECH PROJECT, 2021
** solver
** File description:
** utils
*/

#include "solver.h"

bool is_valid(int curr_row, int curr_col, maze_t *maze)
{
    return (curr_row >= 0 && curr_row < maze->width_height.b
    && curr_col >= 0 && curr_col < maze->width_height.a);
}

bool is_dest(int curr_row, int curr_col, maze_t *maze)
{
    return (curr_row == (maze->width_height.b - 1)
    && curr_col == (maze->width_height.a - 1));
}

bool is_blocked(int curr_row, int curr_col, maze_t* maze)
{
    return (maze->maze[curr_row][curr_col] == 'X');
}

double get_h_val(int curr_row, int curr_col, maze_t *maze)
{
    return ((double)abs(curr_row - maze->width_height.b)
    + abs(curr_col - maze->width_height.a));
}