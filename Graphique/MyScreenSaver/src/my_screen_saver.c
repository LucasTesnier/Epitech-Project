/*
** EPITECH PROJECT, 2020
** my_screen_saver.c
** File description:
** screen saver function
*/

#include "proto.h"

void screen_saver_menu(int animation)
{
    void (*animation_list[7])(void) = {random_pixel, random_laser, adn_monster\
        , snow_man, bubble_master, fractale, mouse_catcher};

    animation_list[animation - 1]();
}

void display_h(void)
{
    my_putstr("animation rendering in a CSFML window.\n\n");
    my_putstr("USAGE\n ./my_screensaver [OPTIONS] animation_id\n");
    my_putstr("  animation_id    ID of the animation to");
    my_putstr(" process (between 1 and 7\n\n");
    my_putstr("OPTIONS\n -d               print the description of all the ");
    my_putstr("animations and quit.\n -h               ");
    my_putstr("print the usage and quit\n\nUSER INTERACTIONS\n");
    my_putstr(" LEFT_ARROW       switch to the previous animation.\n");
    my_putstr(" RIGHT_ARROW      switch to the next animation.\n");
    my_putstr(" KEYBOARD R       restart the current animation\n");
    my_putstr(" UP_ARROW         modify the current animation\n");
    my_putstr(" DOWN_ARROW       modifiy the current animation\n");
    my_putstr(" MOUSE            using in pictionnary\n");
}

void display_desc(void)
{
    my_putstr("1: Milky Way, Keep your head in the stars...\n");
    my_putstr("2: M4tr1x, Choose the right pill\n");
    my_putstr("3: Adn Monster, Adn captivation\n");
    my_putstr("4: Snow Man, All i want for chistmas is youuu\n");
    my_putstr("5: Bubble Master, Sort Sort Sort !\n");
    my_putstr("6; The Fractal Road, The psychological road\n");
    my_putstr("7: Pictionary, moove your mouse !\n");
}

int screen_saver_start(char *arg)
{
    if (arg[0] == '-') {
        if (arg[1] == 'h') {
            display_h();
            return (0);
        }
        if (arg[1] == 'd') {
            display_desc();
            return (0);
        }
    }
    if (my_getnbr(arg) >= 1 && my_getnbr(arg) <= 7)
        screen_saver_menu(my_getnbr(arg));
    else {
        my_putstr("Invalid number of animation !\n");
        return (84);
    }
    return (0);
}
