/*
** EPITECH PROJECT, 2020
** Include
** File description:
** Soko
*/

#ifndef __Soko__

#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdbool.h>
#include <curses.h>

//Struct\\

typedef struct pos
{
    int x;
    int y;
} pos_t;

typedef struct cases
{
    pos_t pos;
    bool is_storage;
    bool empty;
    bool box;
    bool player;
    bool wall;
    bool end;
} case_t;

typedef struct map
{
    pos_t size;
    case_t **cases;
}map_t;

typedef struct game
{
    map_t map;
    bool is_winning;
} game_t;

//Display Map\\

bool is_displayable(game_t game);
void display_storage(game_t game, pos_t pos);
void display_other_case(game_t game, pos_t pos);
void display_map(game_t game);
int sokoban_loop(game_t game, char *buffer);

//Loosing Winning\\

void verif_win(game_t *game);
bool box_is_stuck_down(game_t *game, pos_t pos);
bool box_is_stuck_up(game_t *game, pos_t pos);
bool box_is_stuck(game_t *game, pos_t pos);
void verif_loose(game_t *game);

//Moove\\

bool moove_box(game_t *game, int x, int y, pos_t pos);
void moove_player_to_empty(game_t *game, int x, int y, pos_t pos);
void moove_player(game_t *game, int x, int y);
int action_gestion(int action, game_t *game, char *buffer);

//Read\\

int fs_open_file(char const *filepath);
case_t **mem_alloc_2d_array_case(int nb_rows, int nb_cols);
void delete_enter(char *buffer);
char *load_file_in_mem(char const *filepath);

//Setup Cases\\

void set_false_case(pos_t pos, game_t *game);
void set_true_case(pos_t pos, game_t *game, char *buffer, int i);
void filling_cases(game_t *game, char *buffer);

//Sokoban Setup\\

void setup_screen(void);
pos_t define_size(char *buffer);
game_t setup_struct(char *buffer);
int sokoban_setup(char *path);

//Verification Map\\

int my_strsearch(char c);
int error_display(bool have_player, int nbr_box, int nbr_storage);
int verification_map(char *buffer);

#define __Soko__
#endif
