/*
** EPITECH PROJECT, 2021
** main
** File description:
** desc
*/

#include "my_world.h"
#include "proto.h"

void display_progress_bar(sfRenderWindow *window, progressbar_t *progressbar)
{
    for (int i = 0; i < 1; i++) {
        progressbar_display(&(progressbar[i]), window);
    }
}

progressbar_t *init_progress_bar(void)
{
    progressbar_t *progress = malloc(sizeof(progressbar_t) * 3);

    progress[0] = progressbar_create((sfVector2f){710, 25}, 0.50,   \
    (sfVector2f){500, 40}, true);
    progressbar_set_texture(&(progress[0]), \
    "assets/progress_bar/back.png", "assets/progress_bar/cursor.png");
    return (progress);
}

int calc_ratio(float progress)
{
    int ratio = 0;

    if (progress > 0.25 && progress < 0.75)
        ratio = (progress - 0.5) * 2 * 200;
    else
        ratio = (0.25 - 0.5) * 2 * 200;
    if (ratio >= 0)
        ratio *= -1;
    return (ratio);
}

void actual_play(my_game_t *my_game, text_t *texts, \
button_t *buttons, my_sprite_t *sprites)
{
    if (my_game->actual == 1)
        display_game(my_game, texts, buttons);
    else if (my_game->actual == 2)
        display_menu(my_game, texts, sprites, buttons);
}

int main(void)
{
    my_game_t my_game = my_game_init((sfVector2i){100, 100});
    text_t *texts = init_text();
    my_sprite_t *sprites = sprite_init();
    button_t *buttons = init_button(&my_game);
    int ratio = 0;

    my_game.sprite_type = 1;
    sfRenderWindow_setFramerateLimit(my_game.my_window.window, 60);
    while (sfRenderWindow_isOpen(my_game.my_window.window)) {
        ratio = calc_ratio(my_game.progress_bar->progress);
        if (sfRenderWindow_hasFocus(my_game.my_window.window) == sfTrue) {
            sfRenderWindow_clear(my_game.my_window.window, (sfColor)    \
            {150 + ratio, 150 + ratio, 150 + ratio, 255});
            actual_play(&my_game, texts, buttons, sprites);
        }
        sfRenderWindow_display(my_game.my_window.window);
    }
    return (0);
}