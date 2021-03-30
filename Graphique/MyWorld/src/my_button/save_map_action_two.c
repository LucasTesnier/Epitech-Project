/*
** EPITECH PROJECT, 2021
** save map
** File description:
** desc
*/

#include "my_world.h"

void saving_map_game_one(my_game_t *my_game, FILE *game)
{
    fwrite("Mod : ", 6, 1, game);
    fwrite(text_convert_int_to_char(my_game->mod), \
    my_strlen(text_convert_int_to_char(my_game->mod)), 1, game);
    fwrite("\n", 1, 1, game);
    fwrite("Actual : ", 9, 1, game);
    fwrite(text_convert_int_to_char(my_game->actual), \
    my_strlen(text_convert_int_to_char(my_game->actual)), 1, game);
    fwrite("\n", 1, 1, game);
    fwrite("Toolbar On Off : ", 17, 1, game);
    fwrite(text_convert_int_to_char(my_game->toolsbar_on), \
    my_strlen(text_convert_int_to_char(my_game->toolsbar_on)), 1, game);
    fwrite("\n", 1, 1, game);
    fwrite("Texture Change : ", 17, 1, game);
    fwrite(text_convert_int_to_char(my_game->texture_change), \
    my_strlen(text_convert_int_to_char(my_game->texture_change)), 1, game);
    fwrite("\n", 1, 1, game);
    saving_map_game_two(my_game, game);
}

void saving_map_game(my_game_t *my_game)
{
    char *game_path = malloc(sizeof(char) * \
    (my_strlen(my_game->save_name) + 40));
    FILE *game;

    game_path[0] = '\0';
    my_strncat(game_path, "saves/", 6);
    my_strncat(game_path, my_game->save_name, my_strlen(my_game->save_name));
    my_strncat(game_path, "_game.legend", 12);
    game = fopen(game_path, "w+");
    fwrite("Map Size X : ", 13, 1, game);
    fwrite(text_convert_int_to_char(my_game->my_map.size.x),
    my_strlen(text_convert_int_to_char(my_game->my_map.size.x)), 1, game);
    fwrite("\n", 1, 1, game);
    fwrite("Map Size Y : ", 13, 1, game);
    fwrite(text_convert_int_to_char(my_game->my_map.size.y), \
    my_strlen(text_convert_int_to_char(my_game->my_map.size.y)), 1, game);
    fwrite("\n", 1, 1, game);
    saving_map_game_one(my_game, game);
    fclose(game);
}

void saving_map(my_game_t *my_game)
{
    saving_map_height(my_game);
    saving_map_texture(my_game);
    saving_map_sprite(my_game);
    saving_map_game(my_game);
}

void save_button_one(my_game_t *my_game, button_t *buttons)
{
    buttons[0] = button_create((sfVector2f){310, 270}, \
    (sfVector2f){250, 90}, true, true);
    button_change_texture(&(buttons[0]), "assets/buttons/confirm.png", 1);
    button_change_texture(&(buttons[0]), "assets/buttons/confirm3.png", 2);
    button_change_texture(&(buttons[0]), "assets/buttons/confirm2.png", 3);
    button_add_text("Play", \
    sfFont_createFromFile("assets/fonts/arial.ttf"), sfGreen, &(buttons[0]));
    button_add_info(&(buttons[0]), (sfVector2f){400, 50}, true, \
    "Select the moving cursor");
    button_add_action(&(buttons[0]), &(valid_new_map), &(valid_new_map));
    buttons[0].have_textbox = false;
    buttons[0].text.is_display = false;
}

button_t *save_button_setup(my_game_t *my_game)
{
    button_t *buttons = malloc(sizeof(button_t) * 3);

    save_button_one(my_game, buttons);
    return (buttons);
}