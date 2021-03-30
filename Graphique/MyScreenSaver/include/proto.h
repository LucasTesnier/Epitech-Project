/*
** EPITECH PROJECT, 2020
** B-CPE-101-NAN-1-1-finalstumper-lucas.tesnier
** File description:
** screensaver
*/

#ifndef __SCREENSAVER__

#include <math.h>
#include <SFML/Config.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my.h"
#include "time.h"

typedef struct s_my_framebuffer
{
    sfUint8 *pixels;
    int width;
    int height;
} t_my_framebuffer;

typedef struct my_line
{
    sfVector2i point_a;
    sfVector2i point_b;
    int speed;
    int pos;
    int rigth;
    int change;
    sfColor color;
} my_line;

typedef struct my_circle
{
    sfVector2i center;
    sfVector2i speed;
    int size;
    sfVector2i direction;
    sfColor color;
} my_circle;

typedef struct sprite
{
    sfSprite *sprite;
    sfTexture *texture;
} sprite_t;

t_my_framebuffer *framebuffer_create(unsigned int width, unsigned int height);
void my_put_pixel(t_my_framebuffer *framebuffer, unsigned int x, unsigned
int y, sfColor color);
void draw_line_descend(t_my_framebuffer *framebuffer, sfVector2i point_a,
sfVector2i point_b, sfColor color);
void draw_line_x(t_my_framebuffer *framebuffer, sfVector2i point_a,
sfVector2i point_b, sfColor color);
int draw_line(t_my_framebuffer *framebuffer, sfVector2i point_a, sfVector2i
point_b, sfColor color);
void my_draw_square(t_my_framebuffer *buffer, sfVector2i position, unsigned
int size, sfColor color);
int draw_circle(t_my_framebuffer *framebuffer, sfVector2i center, int radius,
sfColor color);
int screen_saver_start(char *);
void screen_saver_menu(int animation);
void random_pixel(void);
void random_laser(void);
void event_detection_two(sfRenderWindow *window, int *change, sfEvent event);
void event_detection(sfRenderWindow *window, int *change);
void adn_monster(void);
void snow_man(void);
void bubble_master(void);
void fractale(void);
void mouse_catcher(void);
my_line set_line(void);
my_circle set_circle(sfVector2i speed, sfVector2i dir, sfVector2i
center, sfColor color);
void clean_buffer(t_my_framebuffer *framebuffer);
void laser_change_color(int *change, my_line *line, int size);
void event_gestion_three(int change, sfRenderWindow *window);
void event_gestion_five(int change, sfRenderWindow *window);
void event_gestion_six(int change, sfRenderWindow *window);
void event_gestion_faur(int change, sfRenderWindow *window);
int draw_circle_f(t_my_framebuffer *framebuffer, sfVector2i center, int radius,
sfColor color);
void event_detection_m(sfRenderWindow *window, int *change, int *size);
void change_size(int *change, int *size);

#define __SCREENSAVER__
#endif
