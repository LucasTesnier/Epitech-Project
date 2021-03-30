/*
** EPITECH PROJECT, 2021
** verification_map.c
** File description:
** all functions for verification
*/

#include "proto.h"

int my_strsearch(char c)
{
    char *str = "P#\nO X";
    int size = my_strlen(str);

    for (int i = 0; i < size; i++) {
        if (c == str[i])
            return (1);
    }
    return (0);
}

int error_display(bool have_player, int nbr_box, int nbr_storage)
{
    if (have_player == false) {
        my_putstr("Invalid number of player in the map.\n");
        return (-1);
    }
    if (nbr_box < nbr_storage) {
        my_putstr("Invalid nbr of box.\n");
        return (-1);
    }
    return (0);
}

int verification_map(char *buffer)
{
    bool have_player = false;
    int nbr_storage = 0;
    int nbr_box = 0;

    for (int i = 0; i < my_strlen(buffer); i++) {
        if (my_strsearch(buffer[i]) == 0) {
            my_putstr("Invalid Characteres !\n");
            return (-1);
        }
        if (buffer[i] == 'P' && have_player == false)
            have_player = true;
        else if (buffer[i] == 'P') {
            have_player = false;
            break;
        }
        if (buffer[i] == '#')
            nbr_box++;
        if (buffer[i] == 'O')
            nbr_storage++;
    }
    return (error_display(have_player, nbr_box, nbr_storage));
}
