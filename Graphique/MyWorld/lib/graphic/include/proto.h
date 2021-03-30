/*
** EPITECH PROJECT, 2020
** B-CPE-101-NAN-1-1-finalstumper-lucas.tesnier
** File description:
** GraphLib
*/

#ifndef __GraphLib__

#include <math.h>
#include <SFML/Config.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my.h"
#include <time.h>
#include "struct.h"

//Window Loop\\

void start_window(void);

//Text\\

text_t text_create(sfVector2f pos, char *buffer, sfFont* font, bool is_display);
void text_change_pos(text_t *text, sfVector2f pos);
void text_change_buffer(text_t *text, char *buffer);
void text_change_font(text_t *text, sfFont *font);
void text_change_fill_color(text_t *text, sfColor color);
void text_change_outline_color(text_t *text, sfColor color);
void text_change_thickness(text_t *text, float thick);
void text_change_char_size(text_t *text, int size);
void text_change_is_display(text_t *text, bool is_display);
void text_display(text_t *text, sfRenderWindow *window);
char *text_convert_int_to_char(int nb);
void convert_rec(int nb, char *str);

//TextBox\\

textbox_t textbox_create(sfVector2f pos, sfVector2f size, bool have_texture);
void textbox_set_text(textbox_t *textbox, int size, char *buffer, sfFont* font);
void textbox_set_texture(textbox_t *textbox, char *texture);
void textbox_set_color(textbox_t *textbox, sfColor color);
void textbox_change_display(textbox_t *textbox, bool is_display);
void textbox_display(textbox_t *textbox, sfRenderWindow *window);

//Button\\

button_t button_create(sfVector2f pos, sfVector2f size, bool have_texture, \
bool is_display);
void button_add_action(button_t *button, void (*action)(void), \
void (*action_unclick)(void));
void button_add_text(char *buffer, sfFont *font, sfColor color, \
button_t *button);
void button_change_texture(button_t *button, char *texture, int number);
void button_change_color(button_t *button, sfColor color, int number);
void button_display(button_t *button, sfRenderWindow *window);
void button_update_aspect(button_t *button, int number);
void button_run_clicked(button_t *button);
void button_is_up(button_t *button, sfRenderWindow *window, bool is_clicked);
void button_add_info(button_t *button, sfVector2f size, \
bool have_texture, char *buffer);
void button_info_add_text(button_t *button, char *buffer, \
sfFont *font, int size);
void button_info_set_texture(button_t *button, char *path);
void button_info_set_color(button_t *button, sfColor color);
int my_stlen(char const *str);
void button_change_pos(sfVector2f pos, button_t *button);

//ProgressBar\\

progressbar_t progressbar_create(sfVector2f pos, float initial, \
sfVector2f size, bool is_display);
void progressbar_set_texture(progressbar_t *progress, \
char *texture_back, char *texture_cursor);
void progressbar_set_color(progressbar_t *progress, sfColor color_back, \
sfColor color_cursor);
void progressbar_change_display(progressbar_t *progress, bool is_display);
void progressbar_display(progressbar_t *progress, sfRenderWindow *window);
void progressbar_update_cursor_pos(progressbar_t *progress, \
sfRenderWindow *window);

#define __GraphLib__
#endif
