/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** all main functions
*/

#include "proto.h"

void display_h(void)
{
    my_putstr("Air traffic simulation panel\n\n");
    my_putstr("USAGE\n");
    my_putstr(" ./my_radar [OPTIONS] path_to_script\n");
    my_putstr("  path_to_script    The path to the script file.\n\n");
    my_putstr("OPTIONS\n");
    my_putstr(" -h                print the usage and quit.\n\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr(" 'L' key        enable/disable hitboxes and areas.\n");
    my_putstr(" 'S' key        enable/disable sprites.\n");
    my_putstr(" 'P' key        paused the game.\n");
    my_putstr(" 'ENTER' key    select actual options.\n");
    my_putstr(" 'RETURN' key   return to previous page.\n");
    my_putstr(" 'ARROW' key    moove current selection.\n");
}

int main(int ac, char *argv[])
{
    if (ac != 2) {
        my_putstr("./my_radar: bad arguments: 0 givent but 1 ");
        my_putstr("is required\nretry with -h\n");
        return (84);
    }
    if (ac >= 2 && my_strcmp(argv[1], "-h") == 0) {
        display_h();
        return (0);
    }
    return (display_menu(ac, argv));
}
