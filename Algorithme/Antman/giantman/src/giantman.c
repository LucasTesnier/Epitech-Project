/*
** EPITECH PROJECT, 2021
** giantman.c
** File description:
** all function for giantman
*/

#include "proto.h"

int main(int ac, char *argv[])
{
    my_file_t file;

    if (my_open_and_read(&file, argv[1]) == 84)
        return (84);
    if (file.buffer[0] != '&') {
        my_putstr("This is not a compressed file");
        return (84);
    }
    if (giantman(&file) == -1) {
        my_close_file(&file);
        return (84);
    }
    my_close_file(&file);
    return (0);
}
