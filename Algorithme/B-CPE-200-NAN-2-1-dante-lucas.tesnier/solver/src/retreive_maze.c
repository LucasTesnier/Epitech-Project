/*
** EPITECH PROJECT, 2021
** solver
** File description:
** retreive_maze
*/

#include "solver.h"

static void check_entry(char *buffer, int i, int row, int curr)
{
    if (i == 0 && buffer[i] == 'X'){
        fprintf(stderr, "no start point found at (%d, %d)", 0, 0);
        exit(84);
    }
    if (buffer[i] != '\n' && !buffer[i + 1] && buffer[i - 1] != '*'){
        fprintf(stderr, "no exit found at (%d, %d)", 0, 0);
        exit(84);
    }
    if (buffer[i] != 'X' && buffer[i] != '*' && buffer[i] != '\n') {
        fprintf(stderr, "invalid token %c found at %d:%d",
        buffer[i], row, curr);
        exit(84);
    }
}

static void copy_maze(char *buffer, char **maze)
{
    int row = 0;
    int curr = 0;

    for (int i = 0; buffer[i]; i++){
        check_entry(buffer, i, row, curr);
        if (buffer[i] == 'X' || buffer[i] == '*') {
            maze[row][curr] = buffer[i];
            curr++;
        } else {
            maze[row][curr] = '\0';
            curr = 0;
            row++;
        }
    }
    free(buffer);
}

/**
 * @param buffer
 * @return maze_t* maze object;
 * @brief pair.a = width & pair.b = height
 */
maze_t *retreive_maze(char *buffer)
{
    int height = 0;
    int width = (int)strcspn(buffer, "\n");
    maze_t *new_maze = malloc(sizeof(maze_t));

    for (int i = 0; buffer[i]; i++)
        if (buffer[i] == '\n')
            height++;
    if (!new_maze)
        exit(84);
    new_maze->width_height = (pair_t){width, height};
    if (!(new_maze->maze = malloc(sizeof(char *) * height + 1)))
        exit(84);
    for (int i = 0; i < height; i++)
        if (!(new_maze->maze[i] = malloc(sizeof(char) * width + 1)))
            exit(84);
    copy_maze(buffer, new_maze->maze);
    return (new_maze);
}

char *retreive_file(char *path)
{
    FILE *f = fopen(path, "r");
    char *buffer;
    long size;

    if (!f){
        perror(path);
        exit(84);
    }
    fseek(f, 0, SEEK_END);
    size = ftell(f);
    if (size <= 0){
        fprintf(stderr, "file is empty");
        exit(84);
    }
    if (!(buffer = malloc(sizeof(char) * (size + 1))))
        exit(84);
    fseek(f, 0, SEEK_SET);
    fread(buffer, sizeof(char), size, f);
    buffer[size] = '\n';
    fclose(f);
    return (buffer);
}

void destroy_maze(maze_t *maze, graph_t *graph)
{
    if (!maze)
        return;
    if (!maze->maze || !graph)
        return;
    destroy_closed_list(graph->closed_list, maze);
    for (int i = 0; i < maze->width_height.b; i++) {
        for (int j = 0; j < maze->width_height.a; j++) {
            if (graph->graph[i][j])
                free(graph->graph[i][j]);
        }
        free(graph->graph[i]);
        free(maze->maze[i]);
    }
    destroy_openlist(graph->open_list);
    free(graph->graph);
    free(maze);
}