/*
** EPITECH PROJECT, 2021
** solver
** File description:
** create_graph
*/

#include "solver.h"

static node_t *init_node(void)
{
    node_t *new = malloc(sizeof(node_t));

    if (!new)
        exit(84);
    new->p1 = -1;
    new->p2 = -1;
    new->f = DBL_MAX;
    new->g = DBL_MAX;
    new->h = DBL_MAX;
    return (new);
}

node_t *** create_graph(maze_t *maze)
{
    node_t ***new = malloc(sizeof(node_t**) * maze->width_height.b);

    if (!new)
        exit(84);
    for (int i = 0; i < maze->width_height.b; ++i) {
        if (!(new[i] = malloc(sizeof(node_t) * maze->width_height.a)))
            exit(84);
        for (int j = 0; j < maze->width_height.a; ++j)
            new[i][j] = init_node();
    }
    return (new);
}

static void init_graph(node_t ***graph, int p1, int p2)
{
    graph[p1][p2]->f = 0.0;
    graph[p1][p2]->g = 0.0;
    graph[p1][p2]->h = 0.0;
    graph[p1][p2]->p1 = p1;
    graph[p1][p2]->p2 = p2;
}

graph_t *init_a_star(maze_t *maze)
{
    graph_t *a_star_data = malloc(sizeof(graph_t));

    if (!a_star_data)
        exit(84);
    a_star_data->closed_list = create_closed_list(maze);
    a_star_data->graph = create_graph(maze);
    a_star_data->open_list = NULL;
    a_star_data->curr_p1 = 0;
    a_star_data->curr_p2 = 0;
    init_graph(a_star_data->graph, 0, 0);
    a_star_data->open_list = create_open_list(create_pv(0.0, (pair_t){0, 0}));
    return (a_star_data);
}