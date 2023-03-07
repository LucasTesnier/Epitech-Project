/*
** EPITECH PROJECT, 2021
** my_window
** File description:
** desc
*/

#ifndef MY_WINDOW_H_
#define MY_WINDOW_H_

//--INCLUDE--------------------------------------------

#include <SFML/Graphics.h>
#include <stdbool.h>
#include <SFML/Audio/Music.h>

//--DEFINE---------------------------------------------

//--STRUCTURES-----------------------------------------

typedef struct text {
    sfVector2f pos;
    char *buffer;
    sfFont* font;
    sfColor fill_color;
    sfColor outline_color;
    int char_size;
    float thickness;
    sfText *text;
    bool is_display;
} text_t;

typedef struct my_window_s{
    sfVector2i size;
    sfRenderWindow *window;
    sfVideoMode mode;
    sfEvent event;
    sfRectangleShape ***rect_tab;
    sfRectangleShape *back;
    sfRectangleShape **list;
    sfVector2i tab_size;
    sfMusic *music;
    sfClock *time;
    text_t *texts;
} my_window_t;

//--PROTOTYPE------------------------------------------

typedef struct vm_s vm_t;

void init_window(my_window_t *window, int width, int height);
void init_game(vm_t *machine);
void destroy_graph(vm_t *machine);
void text_change_buffer(text_t *text, char *buffer);
void text_change_is_display(text_t *text, bool is_display);

#endif /* !MY_WINDOW_H_ */