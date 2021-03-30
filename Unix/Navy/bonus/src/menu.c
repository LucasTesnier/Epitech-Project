/*
** EPITECH PROJECT, 2020
** menu.c
** File description:
** all menu functions
*/

#include "navy.h"

background_t create_sprite(char *path, float x, float y) {
    background_t picture;
    sfVector2f pos;

    pos.x = x;
    pos.y = y;
    picture.texture = sfTexture_createFromFile(path, NULL);
    picture.sprite = sfSprite_create();
    sfSprite_setTexture(picture.sprite, picture.texture, sfTrue);
    sfSprite_setPosition(picture.sprite, pos);
    return (picture);
}

void display_waiting_screen(sfRenderWindow *window, background_t back, game_info_t *game_inf)
{
    background_t waiting = create_sprite("include/pictures/wait.png", 750, 350);
    background_t one = create_sprite("include/typo/1.png", 0, 0);
    background_t two = create_sprite("include/typo/2.png", 0, 0);
    background_t three = create_sprite("include/typo/3.png", 0, 0);
    background_t faur = create_sprite("include/typo/4.png", 0, 0);
    background_t five = create_sprite("include/typo/5.png", 0, 0);
    background_t six = create_sprite("include/typo/6.png", 0, 0);
    background_t seven = create_sprite("include/typo/7.png", 0, 0);
    background_t height = create_sprite("include/typo/8.png", 0, 0);
    background_t nine = create_sprite("include/typo/9.png", 0, 0);
    background_t zero = create_sprite("include/typo/0.png", 0, 0);
    background_t number[] = {zero, one, two, three, faur, five, six, seven, height, nine};
    background_t wait = create_sprite("include/pictures/waiting.png", 700, 50);
    int pid = getpid();
    int nb = 0;
    int size = 1;
    sfVector2f pos;

    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, back.sprite, NULL);
    sfRenderWindow_drawSprite(window, wait.sprite, NULL);
    sfRenderWindow_drawSprite(window, waiting.sprite, NULL);
    while (pid > 0) {
        size = 0;
        for (float copy = pid; copy / (pow(10, size)) >= 10; size++);
        nb = pid / (pow(10, size));
        pos.x = 1025 - (size * 45);
        pos.y = 850;
        sfSprite_setPosition(number[nb].sprite, pos);
        sfRenderWindow_drawSprite(window, number[nb].sprite, NULL);
        pid -= nb * pow(10, size);
    }
    
    sfRenderWindow_display(window);
}

void identify_button(sfRenderWindow *window, background_t exit, background_t play, background_t options, int ac, char *av[], background_t back, game_info_t *game_inf)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f button;
    sfVector2u size;

    button = sfSprite_getPosition(exit.sprite);
    size = sfTexture_getSize(exit.texture);
    if ((mouse.x >= button.x && mouse.x <= button.x + size.x) && (mouse.y >= button.y && mouse.y <= button.y + size.y)) {
        sfRenderWindow_close(window);
    }
    button = sfSprite_getPosition(play.sprite);
    size = sfTexture_getSize(play.texture);
    if ((mouse.x >= button.x && mouse.x <= button.x + size.x) && (mouse.y >= button.y && mouse.y <= button.y + size.y)) {
        display_waiting_screen(window, back, game_inf);
        signal_storage.is_connecting = 1;
        driver(ac, av, game_inf, window);
        signal_storage.is_connecting = 2;
    }
    
}

void display_visual_game(sfRenderWindow *window, game_info_t *game_inf)
{
    background_t damier = create_sprite("include/pictures/damier.png", 0, 0);
    background_t navy = create_sprite("include/pictures/navy.png", 0, 0);
    background_t touch = create_sprite("include/pictures/touch.png", 0, 0);
    background_t touchs = create_sprite("include/pictures/touchs.png", 0, 0);
    background_t water = create_sprite("include/pictures/water.png", 0, 0);
    background_t turn = create_sprite("include/pictures/turn.png", 1250, 300);
    sfVector2f pos;

    sfRenderWindow_drawSprite(window, damier.sprite, NULL);
    if (game_inf->is_server)
        sfRenderWindow_drawSprite(window, turn.sprite, NULL);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (game_inf->player_map[j][i] >= 2) {
                pos.x = 780 + i * 37;
                pos.y = 91.5 + j * 37;
                sfSprite_setPosition(navy.sprite, pos);
                sfRenderWindow_drawSprite(window, navy.sprite, NULL);
            }
            if (game_inf->player_map[j][i] == -2) {
                pos.x = 780 + i * 37;
                pos.y = 91.5 + j * 37;
                sfSprite_setPosition(touch.sprite, pos);
                sfRenderWindow_drawSprite(window, touch.sprite, NULL);
            }
            if (game_inf->player_map[j][i] == -1) {
                pos.x = 780 + i * 37;
                pos.y = 91.5 + j * 37;
                sfSprite_setPosition(water.sprite, pos);
                sfRenderWindow_drawSprite(window, water.sprite, NULL);
            }
        }
    }
    pos.x = 0;
    pos.y = 500;
    sfSprite_setPosition(damier.sprite, pos);
    sfRenderWindow_drawSprite(window, damier.sprite, NULL);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (game_inf->opponent[j][i] == -1) {
                pos.x = 780 + i * 37;
                pos.y = 591.5 + j * 37;
                sfSprite_setPosition(water.sprite, pos);
                sfRenderWindow_drawSprite(window, water.sprite, NULL);
            }
            if (game_inf->opponent[j][i] == -2) {
                pos.x = 780 + i * 37;
                pos.y = 591.5 + j * 37;
                sfSprite_setPosition(touchs.sprite, pos);
                sfRenderWindow_drawSprite(window, touchs.sprite, NULL);
            }
        }
    }
}

void define_coords(sfRenderWindow *window, char *a_pos)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (mouse.x >= 780 && mouse.x <= 1077 && mouse.y >= 588 && mouse.y <= 884) {
        a_pos[0] = (mouse.x - 780) / 37 + 'A';
        a_pos[1] = (mouse.y - 588) / 37 + '1';
    } else {
        a_pos[0] = '0';
    }
        
}

int menu(int ac, char *av[])
{
    int click = 0;
    char *a_pos = malloc(sizeof(char) * 3);
    game_info_t game_inf;
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;
    sfEvent event;
    sfMusic *music;
    background_t back = create_sprite("include/pictures/background.png", 0, 0);
    background_t text = create_sprite("include/pictures/title.png", 550, 50);
    background_t exit = create_sprite("include/pictures/exit.png", 550, 800);
    background_t play = create_sprite("include/pictures/play.png", 550, 300);
    background_t options = create_sprite("include/pictures/option.png", 550, 550);

    music = sfMusic_createFromFile("include/song/fond.ogg");
    sfMusic_play(music);
    window = sfRenderWindow_create(mode, "my_navy", sfClose, NULL);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (event.type == sfEvtKeyPressed)
                if (event.key.code == sfKeyEscape)
                    sfRenderWindow_close(window);
            if (event.type == sfEvtMouseButtonPressed && signal_storage.is_connecting == 0)
                identify_button(window, exit, play, options, ac, av, back, &game_inf);
        }
        sfRenderWindow_drawSprite(window, back.sprite, NULL);
        if (signal_storage.is_connecting == 0) {
            sfRenderWindow_drawSprite(window, text.sprite, NULL);
            sfRenderWindow_drawSprite(window, exit.sprite, NULL);
            sfRenderWindow_drawSprite(window, play.sprite, NULL);
            sfRenderWindow_drawSprite(window, options.sprite, NULL);
        }
        if (signal_storage.is_connecting == 2) {
            display_visual_game(window, &game_inf);
            sfRenderWindow_display(window);
            while (sfRenderWindow_pollEvent(window, &event)) {
                if (event.type == sfEvtMouseButtonPressed)
                    click = 1;
            }
            if (game_inf.is_server && click == 1) {
                define_coords(window, a_pos);
                if (a_pos[0] != '0') {
                    if (driver_game_gestion_server(&game_inf, a_pos) == 0)
                        return (0);
                }
            } else if (game_inf.is_server == false) {
                if (driver_game_gestion_client(&game_inf) == 1)
                    return (1);
            }
            sfRenderWindow_clear(window, sfBlack);
            sfRenderWindow_drawSprite(window, back.sprite, NULL);
            display_visual_game(window, &game_inf);
        }
        click = 0;
        sfRenderWindow_display(window);
    }
}
