/*
** EPITECH PROJECT, 2021
** solver
** File description:
** process_successor
*/

#include "solver.h"
#include "moves.h"

static void expand_node(graph_t *data, pair_t curr, maze_t *maze)
{
    if (!data->closed_list[curr.a][curr.b]
    && !is_blocked(curr.a, curr.b, maze)){
        data->newg = data->graph[data->curr_p1][data->curr_p2]->g + 1.0;
        data->newh = get_h_val(curr.a, curr.b, maze);
        data->newf = data->newg + data->newh;
        if (data->graph[curr.a][curr.b]->f == FLT_MAX
        || data->graph[curr.a][curr.b]->f > data->newf){
            data->open_list = open_list_insert(data->open_list,
            create_pv(data->newf, (pair_t){curr.a, curr.b}));
            data->graph[curr.a][curr.b]->f = data->newf;
            data->graph[curr.a][curr.b]->g = data->newg;
            data->graph[curr.a][curr.b]->h = data->newh;
            data->graph[curr.a][curr.b]->p1 = data->curr_p1;
            data->graph[curr.a][curr.b]->p2 = data->curr_p2;
        }
    }
}

bool process_successor(graph_t *data, int i, maze_t *maze)
{
    pair_t curr = (pair_t){data->curr_p1 + moves[i].a,
        data->curr_p2 + moves[i].b};

    if (is_valid(curr.a, curr.b, maze)){
        if (is_dest(curr.a, curr.b, maze)){
            data->graph[curr.a][curr.b]->p1 = data->curr_p1;
            data->graph[curr.a][curr.b]->p2 = data->curr_p2;
            get_path(data->graph, maze);
            return (true);
        } else
            expand_node(data, curr, maze);
    }
    return (false);
}