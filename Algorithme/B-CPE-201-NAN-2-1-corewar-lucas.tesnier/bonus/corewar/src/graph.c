/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** graph
*/

#include "vm.h"
#include "my_window.h"
#include <stdlib.h>
#include "my.h"
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>

void text_change_buffer(text_t *text, char *buffer)
{
    text->buffer = buffer;
    sfText_setString(text->text, buffer);
}

void text_change_is_display(text_t *text, bool is_display)
{
    text->is_display = is_display;
}

void text_change_char_size(text_t *text, int size)
{
    text->char_size = size;
    sfText_setCharacterSize(text->text, size);
}

void text_display(text_t *text, sfRenderWindow *window)
{
    if (text->is_display == true)
        sfRenderWindow_drawText(window, text->text, NULL);
}

char *my_stncat(char *dest, char const *src, int nb)
{
    int size_dest = 0;
    int size_src = 0;
    int concatenate = 0;

    if (nb < 0)
        return (0);
    while (dest[size_dest] != '\0')
        size_dest++;
    while (dest[size_src] != '\0')
        size_src++;
    for (concatenate = 0; concatenate < nb; concatenate++)
        dest[size_dest + concatenate] = src[concatenate];
    dest[size_dest + concatenate + 1] = '\0';
    return (dest);
}

void convert_rec(int nb, char *str)
{
    char res[2];

    if (nb >= 10)
        convert_rec((nb / 10), str);
    res[0] = (nb % 10) + 48;
    res[1] = '\0';
    my_stncat(str, res, 2);
}

char *text_convert_int_to_char(int nb)
{
    char *str = malloc(sizeof(char) * 1000);

    str[0] = '\0';
    if (nb < 0) {
        nb *= -1;
        str[0] = '-';
        str[1] = '\0';
    }
    convert_rec(nb, str);
    return (str);
}

text_t text_create(sfVector2f pos, char *buffer, sfFont* font, bool is_display)
{
    text_t text;

    text.text = sfText_create();
    text.pos = pos;
    sfText_setPosition(text.text, pos);
    text.buffer = buffer;
    sfText_setString(text.text, buffer);
    text.font = font;
    sfText_setFont(text.text, font);
    text.is_display = is_display;
    return (text);
}

void text_change_fill_color(text_t *text, sfColor color)
{
    text->fill_color = color;
    sfText_setFillColor(text->text, color);
}

void init_window(my_window_t *window, int width, int height)
{
    sfVideoMode mode = {width, height, 32};

    window->size.x = width;
    window->size.y = height;
    window->mode = mode;
    window->window = \
    sfRenderWindow_create(mode, "CorewAAAAAAAAAAAAAAAAAr", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window->window, 60);
}

void init_game(vm_t *machine)
{
    srand(time(NULL));
    machine->window->tab_size = (sfVector2i){128, 48};
    machine->window->rect_tab = malloc(sizeof(sfRectangleShape **) * (machine->window->tab_size.y + 1));
    machine->window->music = sfMusic_createFromFile("assets/audio/song.wav");
    machine->window->back = sfRectangleShape_create();
    machine->window->list = malloc(sizeof(sfRectangleShape *) * 10);
    machine->window->list[0] = sfRectangleShape_create();
    sfRectangleShape_setTexture(machine->window->list[0], sfTexture_createFromFile("assets/pictures/initialization.png", NULL), true);
    sfRectangleShape_setPosition(machine->window->list[0], (sfVector2f){375, 250});
    sfRectangleShape_setSize(machine->window->list[0], (sfVector2f){1200, 500});
    //
    sfRectangleShape_setTexture(machine->window->back, sfTexture_createFromFile("assets/pictures/starship.png", NULL), true);
    sfRectangleShape_setPosition(machine->window->back, (sfVector2f){0, 0});
    sfRectangleShape_setSize(machine->window->back, (sfVector2f){1920, 1080});
    machine->window->texts = malloc(sizeof(text_t) * 5);
    machine->window->texts[0] = text_create((sfVector2f){600, 800}, "None", sfFont_createFromFile("assets/fonts/arial.ttf"), false);
    text_change_char_size(&(machine->window->texts[0]), 40);
    text_change_fill_color(&(machine->window->texts[0]), (sfColor){59, 249, 243, 255});
    machine->window->texts[1] = text_create((sfVector2f){800, 800}, "None", sfFont_createFromFile("assets/fonts/arial.ttf"), false);
    text_change_char_size(&(machine->window->texts[1]), 40);
    text_change_fill_color(&(machine->window->texts[1]), (sfColor){245, 98, 255, 255});
    machine->window->texts[2] = text_create((sfVector2f){1000, 800}, "None", sfFont_createFromFile("assets/fonts/arial.ttf"), false);
    text_change_char_size(&(machine->window->texts[2]), 40);
    text_change_fill_color(&(machine->window->texts[2]), (sfColor){255, 51, 144, 255});
    machine->window->texts[3] = text_create((sfVector2f){1200, 800}, "None", sfFont_createFromFile("assets/fonts/arial.ttf"), false);
    text_change_char_size(&(machine->window->texts[3]), 40);
    text_change_fill_color(&(machine->window->texts[3]), (sfColor){0, 97, 255, 255});
    machine->window->time = sfClock_create();
    for (int i = 0; i < machine->window->tab_size.y; i++) {
        machine->window->rect_tab[i] = malloc(sizeof(sfRectangleShape *) * (machine->window->tab_size.x + 1));
        for (int j = 0; j < machine->window->tab_size.x; j++) {
            machine->window->rect_tab[i][j] = sfRectangleShape_create();
            sfRectangleShape_setPosition(machine->window->rect_tab[i][j], (sfVector2f){250 + j * 11, 285 + i * 10});
            sfRectangleShape_setSize(machine->window->rect_tab[i][j], (sfVector2f){11,10});
            sfRectangleShape_setOutlineThickness(machine->window->rect_tab[i][j], 0.5);
            sfRectangleShape_setOutlineColor(machine->window->rect_tab[i][j], sfBlack);
            sfRectangleShape_setFillColor(machine->window->rect_tab[i][j], sfBlack);
        }
    }
    sfMusic_play(machine->window->music);
    sfMusic_setLoop(machine->window->music, true);
}

void init_graph(vm_t *machine)
{
    machine->window = malloc(sizeof(my_window_t));
    init_window(machine->window, 1920, 1080);
}

void destroy_graph(vm_t *machine)
{
    sfRenderWindow_close(machine->window->window);
    sfMusic_stop(machine->window->music);
    sfMusic_destroy(machine->window->music);
}

void draw_init(vm_t *machine)
{
    int time = sfTime_asMicroseconds(sfClock_getElapsedTime(machine->window->time));
 
    if (time % 1000000 < 750000)
        sfRenderWindow_drawRectangleShape(machine->window->window, machine->window->list[0], NULL);
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(machine->window->time)) >= 29500) {
        sfRectangleShape_setTexture(machine->window->list[0], sfTexture_createFromFile("assets/pictures/3.png", NULL), true);
        sfRectangleShape_setSize(machine->window->list[0], (sfVector2f){600, 400});
        sfRectangleShape_setPosition(machine->window->list[0], (sfVector2f){675, 300});
    }
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(machine->window->time)) >= 31800) {
        sfRectangleShape_setTexture(machine->window->list[0], sfTexture_createFromFile("assets/pictures/2.png", NULL), true);
        sfRectangleShape_setSize(machine->window->list[0], (sfVector2f){600, 400});
        sfRectangleShape_setPosition(machine->window->list[0], (sfVector2f){675, 300});
    }
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(machine->window->time)) >= 34400) {
        sfRectangleShape_setTexture(machine->window->list[0], sfTexture_createFromFile("assets/pictures/1.png", NULL), true);
        sfRectangleShape_setSize(machine->window->list[0], (sfVector2f){600, 400});
        sfRectangleShape_setPosition(machine->window->list[0], (sfVector2f){675, 300});
    }
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(machine->window->time)) >= 39500) {
        sfRectangleShape_setTexture(machine->window->list[0], sfTexture_createFromFile("assets/pictures/fight.png", NULL), true);
        sfRectangleShape_setPosition(machine->window->list[0], (sfVector2f){700, 350});
        sfRectangleShape_setSize(machine->window->list[0], (sfVector2f){600, 300});
    }
}

void draw_graph(vm_t *machine, bool init)
{
    sfColor color;
    int color_id = 4;

    if (!sfRenderWindow_isOpen(machine->window->window))
        exit(my_error("The window has been closed.\n", 0));
    while (sfRenderWindow_pollEvent(machine->window->window, &(machine->window->event))) {
        if (machine->window->event.type == sfEvtClosed) {
            destroy_graph(machine);
            exit(my_error("The window has been closed.\n", 0));
        }
    }
    sfRenderWindow_clear(machine->window->window, sfBlack);
    sfVector2f size;
    int count = 0;
    float outline = 0;
    sfVector2f pos;
    sfTime temp_time = sfClock_getElapsedTime(machine->window->time);
    int time = sfTime_asMilliseconds(temp_time);
    for (int i = 0; i < machine->window->tab_size.y; i++) {
        for (int j = 0; j < machine->window->tab_size.x; j++) {
            if (machine->colors[i * machine->window->tab_size.x + j] == machine->save_colors[i * machine->window->tab_size.x + j]) {
                size.x = 11;
                size.y = 10;
                outline = 0.5;
            } else {
                count++;
                size.x = 14;
                size.y = 13;
                outline = 2;
            }
            sfRectangleShape_setSize(machine->window->rect_tab[i][j], size);
            sfRectangleShape_setOutlineThickness(machine->window->rect_tab[i][j], outline);
            color_id = machine->colors[i * machine->window->tab_size.x + j];
            //my_printf("Color[%i] = %i\n", i * 96 + j, color_id);
            if (color_id < machine->champs_number)
                sfRectangleShape_setFillColor(machine->window->rect_tab[i][j], machine->champs[machine->colors[i * machine->window->tab_size.x + j]]->color);
            else
                sfRectangleShape_setFillColor(machine->window->rect_tab[i][j],sfBlack);
            sfRenderWindow_drawRectangleShape(machine->window->window, machine->window->rect_tab[i][j], NULL);
        }
    }
    for (int i = 0; i < machine->window->tab_size.y; i++) {
        for (int j = 0; j < machine->window->tab_size.x; j++) {
            if (machine->colors[i * machine->window->tab_size.x + j] != machine->save_colors[i * machine->window->tab_size.x + j]) {
                //sfRectangleShape_setFillColor(machine->window->rect_tab[i][j], sfCyan);
                sfRenderWindow_drawRectangleShape(machine->window->window, machine->window->rect_tab[i][j], NULL);
            }
            machine->save_colors[i * machine->window->tab_size.x + j] = machine->colors[i * machine->window->tab_size.x + j];
        }
    }
    sfRenderWindow_drawRectangleShape(machine->window->window, machine->window->back, NULL);
    if (init)
        draw_init(machine);
    sfRenderWindow_display(machine->window->window);
    //printf("Count : %i\n", count);
    //sleep(1);
}
