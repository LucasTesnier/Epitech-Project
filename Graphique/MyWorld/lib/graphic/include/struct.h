/*
** EPITECH PROJECT, 2021
** struct.h
** File description:
** struct.h
*/

#ifndef __Struct__
#define __Struct__

//Text\\

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

//TextBox\\

typedef struct textbox {
    sfRectangleShape *background;
    text_t text;
    sfColor color;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f size;
    bool have_texture;
    bool is_display;
} textbox_t;

//Button\\

typedef struct buton {
    sfRectangleShape *button;
    text_t text;
    textbox_t info;
    void (*action)(void);
    void (*action_unclick)(void);
    sfVector2f area[4];
    bool have_texture;
    sfTexture *state_one;
    sfTexture *state_two;
    sfTexture *state_three;
    sfColor step_one;
    sfColor step_two;
    sfColor step_three;
    sfVector2f pos;
    sfVector2f size;
    bool is_pressed;
    bool is_up;
    bool is_display;
    bool have_textbox;
} button_t;

//ProgressBar\\

typedef struct progressbar {
    sfRectangleShape *back;
    sfCircleShape *cursor;
    bool have_texture;
    sfTexture *texture_back;
    sfTexture *texture_cursor;
    sfColor color_back;
    sfColor color_cursor;
    sfVector2f back_pos;
    sfVector2f cursor_pos;
    sfVector2f back_size;
    bool is_display;
    float progress;
} progressbar_t;

#endif
