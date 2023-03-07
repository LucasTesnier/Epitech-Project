/*
** EPITECH PROJECT, 2021
** solver
** File description:
** solver
*/

#ifndef SOLVER_SOLVER_H
#define SOLVER_SOLVER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <float.h>
#include <math.h>

typedef struct pair {
    int a;
    int b;
} pair_t;

typedef struct pair_value {
    pair_t pair;
    double f;
} pair_value_t;

typedef struct node {
    int p1;
    int p2;
    double f;
    double g;
    double h;
} node_t;

typedef struct maze {
    pair_t width_height;
    char **maze;
} maze_t;

typedef struct list {
    pair_value_t *pv;
    struct list* (*pop)(struct list* self);
    struct list* (*insert)(struct list* self, pair_value_t *pv);
    struct list *next;
} openlist_t;

typedef struct graph {
    bool **closed_list;
    openlist_t *open_list;
    node_t ***graph;
    openlist_t *popped;
    pair_value_t *curr_pair;
    int curr_p1;
    int curr_p2;
    double newg;
    double newh;
    double newf;
} graph_t;

/* retreive_maze.c */
maze_t *retreive_maze(char *buffer);
char *retreive_file(char *path);
void destroy_maze(maze_t *maze, graph_t *graph);


/* solver.c */
void solve_maze(maze_t *maze);
void get_path(node_t ***graph, maze_t *maze);

/* create_pairvalue.c */
pair_value_t *create_pv(double f, pair_t ij);

/* init_a_star.c */
graph_t *init_a_star(maze_t *maze);
node_t ***create_graph(maze_t *maze);

/* create_lists.c */
openlist_t *delete_top(openlist_t *self);
openlist_t *open_list_insert(openlist_t *self, pair_value_t *pv);
bool **create_closed_list(maze_t *maze);
openlist_t *create_open_list(pair_value_t *pair_val);
void destroy_closed_list(bool **cl, maze_t *maze);

/* utils.c */
bool is_valid(int curr_row, int curr_col, maze_t *maze);
bool is_dest(int curr_row, int curr_col, maze_t *maze);
bool is_blocked(int curr_row, int curr_col, maze_t* maze);
double get_h_val(int curr_row, int curr_col, maze_t *maze);

/* list_op.c */
void destroy_openlist(openlist_t *list);
openlist_t *openlist_push(openlist_t *list, pair_t pair);

/* process_successor.c */
bool process_successor(graph_t *data, int i, maze_t *maze);

#endif //SOLVER_SOLVER_H