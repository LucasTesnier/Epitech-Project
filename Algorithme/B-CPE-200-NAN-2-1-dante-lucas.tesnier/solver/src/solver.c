/*
** EPITECH PROJECT, 2021
** solver
** File description:
** solver
*/
#include "solver.h"

static void display_maze(maze_t *maze)
{
    for (int i = 0; i < maze->width_height.b; i++) {
        if (i + 1 == maze->width_height.b)
            fputs(maze->maze[i], stdout);
        else
            puts(maze->maze[i]);
    }
}

void get_path(node_t ***graph, maze_t *maze)
{
    openlist_t *path = NULL;
    int dest_row = 0;
    int dest_col = 0;
    int curr_row = maze->width_height.b - 1;
    int curr_col = maze->width_height.a - 1;
    pair_t tmp_row_col;

    maze->maze[curr_row][curr_col] = 'o';
    while (!(graph[curr_row][curr_col]->p1 == dest_row
    && graph[curr_row][curr_col]->p2 == dest_col)) {
        path = openlist_push(path, (pair_t){curr_row, curr_col});
        maze->maze[curr_row][curr_col] = 'o';
        tmp_row_col.a = graph[curr_row][curr_col]->p1;
        tmp_row_col.b = graph[curr_row][curr_col]->p2;
        curr_row = tmp_row_col.a;
        curr_col = tmp_row_col.b;
    }
    maze->maze[tmp_row_col.a][tmp_row_col.b] = 'o';
    maze->maze[dest_row][dest_col] = 'o';
    display_maze(maze);
}

void solve_maze(maze_t *maze)
{
    graph_t *data = init_a_star(maze);
    bool arrived = false;

    while (data->open_list){
        data->popped = data->open_list;
        data->curr_pair = create_pv(data->popped->pv->f,
        data->popped->pv->pair);
        data->open_list = data->open_list->pop(data->open_list);
        data->curr_p1 = data->curr_pair->pair.a;
        data->curr_p2 = data->curr_pair->pair.b;
        data->closed_list[data->curr_p1][data->curr_p2] = true;
        for (int i = 0; i < 4; i++)
            if ((arrived = process_successor(data, i, maze)))
                return (destroy_maze(maze, data));
    }
    if (!arrived) {
        write(1, "no solution found", 17);
        exit(84);
    }
}