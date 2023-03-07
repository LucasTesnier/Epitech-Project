/*
** EPITECH PROJECT, 2021
** solver
** File description:
** main
*/
#include "solver.h"

int main(int ac, char **av)
{
    maze_t *maze = retreive_maze(retreive_file(av[1]));
    solve_maze(maze);
    return (0);
}