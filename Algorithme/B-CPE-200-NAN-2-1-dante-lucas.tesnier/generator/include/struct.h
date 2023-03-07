/*
** EPITECH PROJECT, 2020
** Include
** File description:
** Match
*/

#ifndef __Match__

typedef struct sfVector {
    int x;
    int y;
} sfVector2i;

typedef struct line {
    int *value;
    bool *vwall;
    bool *hwall;
} line_t;

typedef struct game {
    int size_x;
    int size_y;
    bool is_perfect;
    int original_y;
    int original_x;
    line_t actual_line;
    line_t prev_line;
} game_t;

#define __Match__
#endif