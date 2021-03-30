/*
** EPITECH PROJECT, 2020
** Include
** File description:
** Match
*/

#ifndef __Match__

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
#include <time.h>

//Struct\\

typedef struct game {
    int **map;
    int max;
    int lines;
    bool is_winning;
} game_t;


//Display Game\\

void display_map(game_t *game);

//Get User\\

char *get_str(bool is_lines);
int get_action(game_t *game, bool is_lines);
bool verif_matches(int *action, game_t *game);
int *get_user(game_t *game);
void get_str_put(bool is_lines);

//IA\\

int *get_ai(game_t *game);
bool verif_rand(int *action, game_t *game);
int get_total_bit(char **bin_map, game_t *game);
bool have_enough_stick(game_t *game);
int	my_square_root(int nb);

//Bit Operation\\

int define_bin_max(game_t *game);
char *convert_nbr_in_bin(game_t *game, int size, int nbr);
char **convert_map_in_bin(game_t *game);

//Loop\\

bool verif_win(game_t *game);
int loop_match(game_t *game);
int loop_match_ia(game_t *game, int *action);

//Setup Match\\

game_t setup_game(int lines, int max);
void fill_map(game_t *game);
int setup_match(int lines, int max);

//Stick Operations\\

int get_nbr_stick(game_t *game, int lines);
void remove_stick(int *action, game_t *game);
void add_stick(int *act, game_t *game);

//Verification Match\\

int verification_match(int lines, int max);

#define __Match__
#endif
