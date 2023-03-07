/*
** EPITECH PROJECT, 2020
** proto.h
** File description:
** prototypes of all the function
*/

#ifndef __PROTO_
#define __PROTO_

//WALL_MODIFICATION.C//

void modification_vertical_two(game_t *game, int pos, int count, int i);
void modification_vertical(game_t *game);
void modification_line(game_t *game, bool is_last);
void fill_line_with_previous(game_t *game, int actual_y);

//LAB_DRAW.C//

void draw_line_two(game_t *game, bool is_end, char *str);
void draw_line(game_t *game, bool is_end);

//SETUP_LAB.C//

game_t setup_game(int size_x, int size_y, bool is_perfect);
void loop_lab(game_t *game);
int setup_lab(int size_x, int size_y, bool is_perfect);

//MAIN.C//

int main(int ac, char *argv[]);

//VALUE_GESTION.C//

void fill_line(game_t *game, int count_min);
void change_case(game_t *game);
void update_value(game_t *game);
bool my_int_search(int *list, int nbr, int list_count);
int get_number_of_value(game_t *game, int nbr);

#endif