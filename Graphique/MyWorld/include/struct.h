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

//Progress Bar\\

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

//  manage window
typedef struct my_window_s {
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;
    char mouse_status;
    sfVector2i tile_selected;
} my_window_t;

//  manage map
typedef struct my_map_s {
    sfVector2i size;
    char **map_height;
    float height_size;
    int display_size;
    sfVector2f **vector;
    char **texture_name;
    sfVector2f angles;
    sfVector2f pos;
    char **construction;
} my_map_t;

//manage Sprites

typedef struct my_sprite_s {
    int sprite_name;
    sfIntRect *area;
    char *pathname;
    sfImage *image;
    sfSprite *sprite;
    sfTexture *texture;
} my_sprite_t;

//manage game

typedef struct my_game_s {
    my_window_t my_window;
    my_map_t my_map;
    my_sprite_t *my_sprite;
    sfConvexShape *convexShape;
    sfClock *clock;
    sfRectangleShape **shapes;
    progressbar_t *progress_bar;
    int fps;
    int actual;
    bool toolsbar_on;
    int mod;
    int texture_change;
    my_window_t *window_choose;
    sfVector2i mouse_pos;
    sfVector2i new_size;
    int ctrl;
    int was_pressed;
    int new_map_confirm;
    int radius;
    my_sprite_t **sprite;
    int construction_number;
    int act_construction;
    int gold_generation;
    int gold;
    int sprite_type;
    int good_buy;
    char *save_name;
    sfKeyCode *shortcut;
} my_game_t;

//Button\\

typedef struct buton {
    sfRectangleShape *button;
    text_t text;
    textbox_t info;
    void (*action)(my_game_t *);
    void (*action_unclick)(my_game_t *);
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

typedef struct textzone {
    button_t box;
    int text_size;
} textzone_t;

#endif
