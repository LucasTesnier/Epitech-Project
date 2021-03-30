/*
** EPITECH PROJECT, 2021
** antman.c
** File description:
** antman function
*/

#include "proto.h"

int main(int ac, char *argv[])
{
    my_file_t file;

    if (ac != 3)
        return (84);
    if (my_open_and_read(&file, argv[1]) == 84)
        return (84);
    if (init_tree(&file) == -1) {
        my_close_file(&file);
        return (84);
    }
    return (0);
}
