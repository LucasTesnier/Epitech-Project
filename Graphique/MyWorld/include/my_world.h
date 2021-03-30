/*
** EPITECH PROJECT, 2021
** my_world
** File description:
** desc
*/

#ifndef _MY_WORLD__
#define _MY_WORLD__

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include "proto.h"

typedef enum mat
{
    WATER,
    GRASS,
    STONE,
    SAND,
    SNOW
} mat_type_t;

// Button

void choose_grass(my_game_t *my_game);
void choose_sand(my_game_t *my_game);
void choose_snow(my_game_t *my_game);
void choose_water(my_game_t *my_game);
char convert_keyevent_to_char(sfKeyCode key);
void loading_map_game_three(my_game_t *my_game, char *buffer, int *pos);
void loading_map_game_two(my_game_t *my_game, char *buffer, int *pos);
void loading_map_game_one(my_game_t *my_game, char *game_path);
void loading_map_game(my_game_t *my_game);
void loading_map(my_game_t *my_game);
void loading_map_sprite_five(my_game_t *my_game, char *buffer, \
int *pos, sfVector2i p);
void loading_map_sprite_four(my_game_t *my_game, char *buffer, \
int *pos, sfVector2i p);
void loading_map_sprite_three(my_game_t *my_game, char *buffer, \
int *pos, sfVector2i p);
void loading_map_sprite_two(my_game_t *my_game, char *buffer, \
int *pos, sfVector2i p);
void loading_map_sprite(my_game_t *my_game);
void loading_map_texture_one(my_game_t *my_game, char *texture_path);
void loading_map_texture(my_game_t *my_game);
void loading_map_sprite_one(my_game_t *my_game, char *sprite_path);
void loading_map_sprite_seven(my_game_t *my_game, \
char *buffer, int *pos, sfVector2i p);
void loading_map_sprite_six(my_game_t *my_game, char *buffer, \
int *pos, sfVector2i p);
char *load_file_in_mem(char const *filepath);
my_sprite_t **my_init_spritee(my_map_t my_map, my_game_t *my_game);
void loading_map_height_one(my_game_t *my_game, char *height_path);
void loading_map_height_two(my_game_t *my_game, char *buffer, int *pos);
void loading_map_height(my_game_t *my_game);
void load_button_one(my_game_t *my_game, button_t *buttons);
button_t *load_button_setup(my_game_t *my_game);
void load_textzone_one(my_game_t *my_game, textzone_t *textzones);
textzone_t *load_textzone_setup(my_game_t *my_game);
my_sprite_t *load_sprite_setup(my_game_t *my_game);
my_window_t load_window_setup(my_game_t *my_game);
void load_event(my_game_t *my_game, button_t *buttons, textzone_t \
*textzones, my_window_t my_window);
void load_draw(my_game_t *my_game, button_t *buttons, textzone_t \
*textzones, my_window_t my_window);
void load_map_action(my_game_t *my_game, textzone_t *textzones, \
my_window_t my_window);
void load_map(my_game_t *my_game);
void play(my_game_t *my_game);
void update_radius(my_game_t *my_game);
void one_buy(my_game_t *my_game);
void two_buy(my_game_t *my_game);
void three_buy(my_game_t *my_game);
void four_buy(my_game_t *my_game);
void five_buy(my_game_t *my_game);
void six_buy(my_game_t *my_game);
void range_max(my_game_t *my_game);
void range_little(my_game_t *my_game);
button_t init_button_six(my_game_t *my_game, button_t *buttons);
button_t init_button_seven(my_game_t *my_game, button_t *buttons);
button_t init_button_eight(my_game_t *my_game, button_t *buttons);
button_t init_button_nine(my_game_t *my_game, button_t *buttons);
button_t init_button_ten(my_game_t *my_game, button_t *buttons);
button_t init_button_one(my_game_t *my_game, button_t *buttons);
button_t init_button_two(my_game_t *my_game, button_t *buttons);
button_t init_button_three(my_game_t *my_game, button_t *buttons);
button_t init_button_four(my_game_t *my_game, button_t *buttons);
button_t init_button_five(my_game_t *my_game, button_t *buttons);
button_t init_button_eleven(my_game_t *my_game, button_t *buttons);
button_t init_button_twelve(my_game_t *my_game, button_t *buttons);
button_t *init_button(my_game_t *my_game);
void display_button(sfRenderWindow *window, button_t *buttons);
textzone_t *new_textzone_setup(my_game_t *my_game);
my_sprite_t *new_sprite_setup(my_game_t *my_game);
my_window_t new_window_setup(my_game_t *my_game);
void new_event(my_game_t *my_game, button_t *buttons, \
textzone_t *textzones, my_window_t my_window);
void new_draw(my_game_t *my_game, button_t *buttons, textzone_t \
*textzones, my_window_t my_window);
void valid_new_map(my_game_t *my_game);
void new_button_one(my_game_t *my_game, button_t *buttons);
button_t *new_button_setup(my_game_t *my_game);
void new_textzone_one(my_game_t *my_game, textzone_t *textzones);
void new_textzone_two(my_game_t *my_game, textzone_t *textzones);
void new_map_generation(my_game_t *my_game, textzone_t \
*textzones, my_window_t my_window);
void new_map_action(my_game_t *my_game, textzone_t \
*textzones, my_window_t my_window);
void new_map(my_game_t *my_game);
void on_off_toolsbar(my_game_t *my_game);
void hand_on_off(my_game_t *my_game);
void pointer_on_off(my_game_t *my_game);
void gomme_on_off(my_game_t *my_game);
void backhoe_on_off(my_game_t *my_game);
void saving_map_game_one(my_game_t *my_game, FILE *game);
void saving_map_game(my_game_t *my_game);
void saving_map(my_game_t *my_game);
void save_button_one(my_game_t *my_game, button_t *buttons);
button_t *save_button_setup(my_game_t *my_game);
void saving_map_height(my_game_t *my_game);
void saving_map_texture(my_game_t *my_game);
void saving_map_sprite(my_game_t *my_game);
void saving_map_game_three(my_game_t *my_game, FILE *game);
void saving_map_game_two(my_game_t *my_game, FILE *game);
void save_textzone_one(my_game_t *my_game, textzone_t *textzones);
textzone_t *save_textzone_setup(my_game_t *my_game);
my_sprite_t *save_sprite_setup(my_game_t *my_game);
my_window_t save_window_setup(my_game_t *my_game);
void save_event(my_game_t *my_game, button_t *buttons, textzone_t \
*textzones, my_window_t my_window);
void save_draw(my_game_t *my_game, button_t *buttons, textzone_t \
*textzones, my_window_t my_window);
void save_map_action(my_game_t *my_game, textzone_t *textzones, \
my_window_t my_window);
void save_map(my_game_t *my_game);
void shop_button_six(my_game_t *my_game, button_t *buttons);
button_t *shop_button_setup(my_game_t *my_game);
void shop_button_one(my_game_t *my_game, button_t *buttons);
void shop_button_two(my_game_t *my_game, button_t *buttons);
void shop_button_three(my_game_t *my_game, button_t *buttons);
void shop_button_four(my_game_t *my_game, button_t *buttons);
void shop_button_five(my_game_t *my_game, button_t *buttons);
my_sprite_t *shop_sprite_setup(my_game_t *my_game);
my_window_t shop_window_setup(my_game_t *my_game);
void shop_event(my_game_t *my_game, button_t *buttons, my_window_t my_window);
void shop_display(my_game_t *my_game, button_t *buttons, \
my_sprite_t *sprites, my_window_t my_window);
void shop_on_off(my_game_t *my_game);
void terra_on_off_sprite(my_game_t *my_game, my_sprite_t *sprites);
void terra_on_off_button_zero(my_game_t *my_game, button_t *buttons);
void terra_on_off_button_one(my_game_t *my_game, button_t *buttons);
void terra_on_off_button_two(my_game_t *my_game, button_t *buttons);
void terra_on_off_button_three(my_game_t *my_game, button_t *buttons);
my_window_t terra_on_off_window(my_game_t *my_game);
button_t *terra_on_off_button_setup(my_game_t *my_game);
void terra_on_off_event(my_game_t *my_game, my_window_t \
my_window, button_t *buttons);
void terra_on_off_display(my_game_t *my_game, button_t *buttons, \
my_sprite_t *sprites, my_window_t my_window);
void terra_on_off(my_game_t *my_game);
void textzone(my_game_t *my_game);
void textzones_is_pressed(my_game_t *my_game, my_window_t my_window, \
textzone_t *textzones, int max);
void textzones_write(my_game_t *my_game, my_window_t my_window, \
textzone_t *textzones, int max);
progressbar_t *init_progress_bar(void);
void display_progress_bar(sfRenderWindow *window, progressbar_t *progressbar);
char *read_file(char const *filepath, int size);

// Tools Bar
sfRectangleShape **init_shapes(void);
void toolsbar_animation(sfRectangleShape **shapes, bool to_rigth, \
button_t *buttons, my_game_t *my_game);

//Cursor Tools
void cursor_tools_four(my_game_t *my_game, button_t *buttons);
void cursor_tools_five(my_game_t *my_game, button_t *buttons);
void cursor_tools_six(my_game_t *my_game, button_t *buttons);
void cursor_tools_one(my_game_t *my_game, button_t *buttons);
void cursor_tools_two(my_game_t *my_game, button_t *buttons);
void cursor_tools_three(my_game_t *my_game, button_t *buttons);
void cursor_tools(my_game_t *my_game, button_t *buttons);

//  my_draw
void change_tile_texture2(my_game_t *my_game, sfVector2i mouse_pos, int i,  \
int j);
void change_tile_texture(my_game_t *my_game, sfVector2i mouse_pos);
void create_building2(my_game_t *my_game, int i, int j);
void create_buildings(my_game_t *my_game, int i, int j);
void display_sprite_four(my_game_t *my_game, int i, int j);
void display_sprite_five(my_game_t *my_game, int i, int j);
void display_sprite_six(my_game_t *my_game, int i, int j);
void display_all_sprite(my_game_t *my_game, int i, int j);
void display_sprite(my_game_t *my_game, int i, int j);
void display_tiles2(my_game_t *my_game, int i, int j, int type);
void display_tiles(my_game_t *my_game, int i, int j, int type);
void do_action2(my_game_t *my_game, sfVector2i mouse_pos);
void do_action(my_game_t *my_game, sfVector2i mouse_pos);
int on_right(sfVector2f pos1, sfVector2f pos2, sfVector2i point,    \
sfVector2f pos);
int in_tiles(my_game_t *my_game, int i, int j, sfVector2i mouse_pos);
int in_window2(my_game_t *game, int i, int j);
int in_window(my_game_t *game, int i, int j);
int is_placable(my_game_t *my_game, int i, int j);
int make_shape(my_game_t *my_game, int i, int j);
void move_map_position(my_game_t *my_game, sfVector2i mouse_pos,    \
sfVector2u window_size);
void display_game_two(my_game_t *my_game, text_t *texts, button_t *buttons);
void display_game(my_game_t *my_game, text_t *texts, button_t *buttons);
void display_menu(my_game_t *my_game, text_t *texts, my_sprite_t *sprites,  \
button_t *buttons);
float init_ratio_night(float progress);
void sprite_conditions_square_six(my_game_t *my_game, int i, int j);
void display_selected_tiles(my_game_t *my_game);
void my_display_map_two(my_game_t *my_game, sfVector2i mouse_pos);
void my_display_map(my_game_t *my_game);
sfVector2f init_sprite_scale(my_game_t *my_game, int i, int j);
void sprite_all_conditions_square(my_game_t *my_game, int i, int j);
void scale_and_pos(my_game_t *my_game, int i, int j);
void sprite_conditions_square(my_game_t *my_game, int i, int j);
void sprite_conditions(my_game_t *my_game, int i, int j);
void place_sprite_one(my_game_t *my_game, sfVector2i mouse_pos, int i, int j);
void place_sprite_two(my_game_t *my_game, sfVector2i mouse_pos, int i, int j);
void place_sprite_three(my_game_t *my_game, sfVector2i mouse_pos, int i, int j);
void destroy_sprite(my_game_t *my_game, sfVector2i mouse_pos);
void place_sprite_four(my_game_t *my_game, sfVector2i mouse_pos, int i, int j);
void place_sprite_five(my_game_t *my_game, sfVector2i mouse_pos, int i, int j);
void place_sprite_six(my_game_t *my_game, sfVector2i mouse_pos, int i, int j);
void place_all_sprite(my_game_t *my_game, sfVector2i mouse_pos, int i, int j);
void place_sprite(my_game_t *my_game, sfVector2i mouse_pos);
void reset_altitude2(my_game_t *my_game, sfVector2i mouse_pos, int i, int j);
void reset_altitude(my_game_t *my_game, sfVector2i mouse_pos);
void display_sprite_one(my_game_t *my_game, int i, int j);
void display_sprite_two(my_game_t *my_game, int i, int j);
void display_sprite_three(my_game_t *my_game, int i, int j);
void shadow(my_game_t *my_game, int i, int j);
void sprite_conditions_square_one(my_game_t *my_game, int i, int j);
void sprite_conditions_square_two(my_game_t *my_game, int i, int j);
void sprite_conditions_square_three(my_game_t *my_game, int i, int j);
void sprite_conditions_square_four(my_game_t *my_game, int i, int j);
void sprite_conditions_square_five(my_game_t *my_game, int i, int j);
void up_and_down_tile2(my_game_t *my_game, int k, sfVector2i pos1);
void up_and_down_tile(my_game_t *my_game, int k, sfVector2i mouse_pos);
void build(my_game_t *my_game, sfVector2i mouse_pos);
void world_border2(my_game_t *my_game, sfConvexShape *convex);
void world_border(my_game_t *my_game);

//  my_event
void my_event_menu(my_window_t *my_window, my_game_t *my_game,  \
button_t *buttons);
void select_mouse_button(my_game_t *my_game, button_t *buttons);
void my_event2(my_window_t *my_window, my_game_t *my_game, button_t *buttons);
void my_event(my_window_t *my_window, my_game_t *my_game, button_t *buttons);
void key_shortcut2(my_game_t *my_game, my_window_t *my_window);
void key_shortcut(my_game_t *my_game, my_window_t *my_window);
void zoom2(my_game_t *my_game, sfVector2i mouse_pos);
void zoom(my_game_t *my_game);

//  my_game
my_game_t my_game_init(sfVector2i size);
void my_game_destroy(my_game_t *my_game);
sfKeyCode *init_shortcut(void);
void my_game_init2(my_game_t *my_game);
void my_init_sprite2(char construction, my_game_t *my_game,     \
my_sprite_t *texture_name);
void my_init_sprite3(char construction, my_game_t *my_game, \
my_sprite_t *texture_name);
void my_init_sprite4(char construction, my_game_t *my_game, \
my_sprite_t *texture_name);
my_sprite_t **my_init_sprite(my_map_t my_map, my_game_t *my_game);

//  my_map
void my_map_destroy(my_map_t *my_map);
sfVector2f my_iso_projection(int x, int y, int z, sfVector2f angles);
char **my_map_height_init(my_map_t my_map);
sfVector2f **my_vector_init(my_map_t my_map);
void my_init_construction3(my_map_t my_map, char **texture_name, int i, int j);
void my_init_construction2(my_map_t my_map, char **texture_name, int i, int j);
char **my_init_construction(my_map_t my_map);
void my_init_texture_name3(my_map_t my_map, char **texture_name, int i, int j);
void my_init_texture_name2(my_map_t my_map, char **texture_name, int i, int j);
char **my_init_texture_name(my_map_t my_map);
my_map_t my_map_init(sfVideoMode mode, sfVector2i size);

//  my_shape
sfRectangleShape **init_shapes(void);
void toolsbar_animation2(button_t *buttons, sfVector2f size);
void toolsbar_animation3(button_t *buttons, sfVector2f size);
void toolsbar_animation(sfRectangleShape **shapes, bool to_rigth,   \
button_t *buttons, my_game_t *my_game);

//  my_sprite
my_sprite_t *my_sprite_init(void);
void display_sprites(sfRenderWindow *window, my_sprite_t *sprites);
my_sprite_t *sprite_init(void);
my_sprite_t new_sprite(int sprite_name, char *pathname, sfIntRect *area);

//  my_text
void display_text(sfRenderWindow *window, text_t *texts);
text_t *init_text(void);
void init_text2(text_t *texts);
void update_text(my_game_t *my_game, text_t *texts);
void update_fps_text(my_game_t *my_game, text_t *texts);
void update_generation_text(my_game_t *my_game, text_t *texts);
void update_gold_text(my_game_t *my_game, text_t *texts);
void update_pixel(button_t *buttons, my_game_t *my_game);

//  my_window
my_window_t my_window_init(void);
void my_window_destroy(my_window_t *my_window);

#endif /* !_MY_WORLD__ */
