/*
** EPITECH PROJECT, 2020
** B-CPE-101-NAN-1-1-finalstumper-lucas.tesnier
** File description:
** my_radar
*/

#ifndef __RADAR__

#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include <SFML/Config.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <stdlib.h>
#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

typedef struct background
{
    sfTexture *texture;
    sfSprite *sprite;
}background_t;

typedef struct plane
{
    sfVector2f departure;
    sfVector2f arrival;
    float speed;
    float speedx;
    float speedy;
    int limit;
    int is_air;
    background_t screen;
    sfRectangleShape *hitbox;
} plane_t;

typedef struct tower
{
    sfVector2i position;
    int radius;
    background_t screen;
    sfCircleShape *hitbox;
} tower_t;

typedef struct axe
{
    int i;
    int j;
} axe_t;

typedef struct time
{
    int time_lost;
    sfClock *clock;
} timer_clock_t;

typedef struct text
{
    sfText *timer;
    sfText *sprite_opt;
    sfText *hitbox_opt;
} text_opt_t;

typedef struct quari
{
    int top;
    int bottom;
    int right;
    int left;
    int count;
    int *list;
} quari_t;

typedef struct game
{
    plane_t *planes;
    tower_t *towers;
    timer_clock_t clock;
    text_opt_t opt;
    sfRenderWindow *window;
    int *change;
    quari_t *quari;
} game_t;

typedef struct user
{
    sfColor hitbox_p;
    sfColor hitbox_t;
} user_t;

int radar_setup(int ac, char *argv[], user_t user);
void radar_screen(plane_t *planes, tower_t *towers, user_t user);
background_t setup_background(char *path);
int display_menu(int ac, char *argv[]);
int fs_open_file(char const *filepath);
char *read_file(char const *filepath, int size);
char *load_file_in_mem(char const *filepath);
void sort_informations(char *buffer, char **stock, int length);
int verif_pos(char **stock, int i);
char **verification(int ac, char *argv[], int *lengthp);
void tower_collect(axe_t *ax, tower_t *towers, char **stock, int *count);
tower_t *make_tower(char **stock, int length);
void planes_collect_parsing(axe_t *ax, plane_t *planes, char **stock, \
int *count);
sfCircleShape *create_circle(sfVector2f position, float radius, user_t user);
sfRectangleShape *create_rect(sfVector2f position, float radius, user_t user);
void setup_sprite_towers(tower_t *towers, user_t user);
void setup_sprite(tower_t *towers, plane_t *planes, user_t user);
int is_intersecting_circles(tower_t *towers, sfVector2f pos2);
void colision(plane_t *plane, int j, plane_t *planes, tower_t *towers);
char *my_getstr(int nb, char *str, int *count);
void display_clock(sfRenderWindow *window, timer_clock_t clock, \
text_opt_t opt, plane_t *planes);
void rotation_planes(plane_t *planes, int i);
void fill_quari(game_t game, int i, sfVector2f pos);
void moove_planes(game_t game);
void display_towers(tower_t *towers, sfRenderWindow *window, plane_t *planes, \
int *change);
void key_gestion(sfRenderWindow *window, int *change, sfEvent event, \
timer_clock_t *clock);
void event_gestion(sfRenderWindow *window, int *change, timer_clock_t *clock, \
text_opt_t opt);
sfText *setup_text(int x, int y, int size);
text_opt_t setup_opt(void);
int verif_plane(plane_t *planes, sfRenderWindow *window);
background_t setup_background(char *path);
void display_paused(plane_t *planes, tower_t *towers, int *change, \
sfRenderWindow *window);
timer_clock_t setup_clock(void);
sfRenderWindow *setup_window(plane_t *planes, tower_t *towers, \
game_t *game, user_t user);
void display_info_paused(sfRenderWindow *window, text_opt_t opt);
quari_t setup_quari(int top, int bottom, int right, int left);
game_t setup_game(plane_t *planes, tower_t *towers, user_t user);
sfRenderWindow *create_menu_window(void);
void key_menu(sfRenderWindow *window, sfEvent event, int *change);
void event_menu(sfRenderWindow *window, int *change);
sfVector2f define_pos(int *change);
void draw_cursor(sfRenderWindow *window, int *change);
background_t create_sprite(char *path, int x, int y);
background_t *setup_menu_sprite(void);
void display_menu_screen(sfRenderWindow *window, background_t *sprite, \
int *change);

#define __RADAR__
#endif
