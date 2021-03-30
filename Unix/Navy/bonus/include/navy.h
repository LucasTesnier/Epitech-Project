/*
** EPITECH PROJECT, 2020
** B-CPE-101-NAN-1-1-finalstumper-lucas.tesnier
** File description:
** rush3
*/

#ifndef __NAVY__

#define _GNU_SOURCE *

#include <sys/types.h>
#include <signal.h>
#include <stdbool.h>
#include <time.h>
#include <fcntl.h>
#include <SFML/Config.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "my.h"

#define SET 1
#define SHOOT 2

typedef struct data
{
    volatile int signal;
    volatile int sender_pid;
    volatile int is_connecting;
} t_data;

typedef struct game_information
{
    int pid;
    int pid_two;
    bool is_server;
    int **player_map;
    int **opponent;
} game_info_t;

typedef struct background
{
    sfTexture *texture;
    sfSprite *sprite;
}background_t;

/* signal_storage.c */
extern volatile t_data signal_storage;

/* connexion gestion */
void connexion_gestion(int ac, char *argv[], game_info_t *game_inf, sfRenderWindow *window);

/* signals sending */
void send_signal(int nb, game_info_t *game_inf);

/* setup_navy.c */
int setup_navy(int ac, char *argv[], game_info_t *game_inf, sfRenderWindow *window);
void attack_gestion(game_info_t *game_inf, char *shot);
void defense_gestion(game_info_t *game_inf);
void timer(int time);

/* ships_checker.c */
bool getcheck_file(char *path, game_info_t *game_inf);
int get_diff(char *pos, char axis);
bool check_pos(char *pos, int usage);

/* display_board.c */
void display_game(game_info_t *game_inf);

/* init_maps.c */
void initialisation_map(game_info_t *game_inf);

/* attack_receive.c */
char *get_attack_pos(game_info_t *g_info);
int receive_attack_info(char *pos, game_info_t *g_info, bool hitted);
bool is_gameover(game_info_t *g_info);

#define __NAVY__
#endif
