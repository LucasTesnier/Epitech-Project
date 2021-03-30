/*
** EPITECH PROJECT, 2021
** text_zone
** File description:
** desc
*/

#include "my_world.h"

char *read_file(char const *filepath, int size)
{
    char *buffer = malloc(size + 1);
    int file_description = open(filepath, O_RDONLY);

    if (read(file_description, buffer, size) <= 0) {
        write(2, "Read is impossible", 18);
        return (NULL);
    }
    close(file_description);
    return (buffer);
}

void textzone(my_game_t *my_game)
{
    my_game->was_pressed = 1;
}

void textzones_is_pressed(my_game_t *my_game, my_window_t my_window, \
textzone_t *textzones, int max)
{
    for (int i = 0; i < max; i++) {
        button_is_up(&(textzones[i].box), my_window.window, true, my_game);
        if (my_game->was_pressed == 1) {
            my_game->was_pressed = 0;
            textzones[i].box.is_pressed = 1;
            textzones[i].box.text.buffer = malloc(sizeof(char) * \
            (textzones[i].text_size + 1));
            textzones[i].box.text.buffer[0] = '\0';
            text_change_buffer(&(textzones[i].box.text), \
            textzones[i].box.text.buffer);
            button_update_aspect(&(textzones[i].box), 2);
        }
    }
}

void textzones_write(my_game_t *my_game, my_window_t my_window, \
textzone_t *textzones, int max)
{
    char *str = malloc(sizeof(char) * 2);

    for (int i = 0; i < max; i++) {
        if (my_window.event.key.code == 59 && textzones[i].box.is_pressed \
            == true && my_strlen(textzones[i].box.text.buffer) > 0)
            textzones[i].box.text.buffer[my_strlen(textzones[i].\
            box.text.buffer) - 1] = '\0';
        if (my_window.event.key.code == sfKeyEnter && textzones[i].box.\
        is_pressed == true) {
            textzones[i].box.is_pressed = 0;
            button_update_aspect(&(textzones[i].box), 1);
        }
        if (textzones[i].box.is_pressed == true && my_strlen(textzones[i].\
        box.text.buffer) < textzones[i].text_size) {
            str[0] = convert_keyevent_to_char(my_window.event.key.code);
            str[1] = '\0';
            my_strncat(textzones[i].box.text.buffer, str, 1);
            text_change_buffer(&(textzones[i].box.text), textzones[i].\
            box.text.buffer);
        }
    }
}