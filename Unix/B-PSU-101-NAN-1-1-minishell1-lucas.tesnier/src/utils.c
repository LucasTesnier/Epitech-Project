/*
** EPITECH PROJECT, 2021
** setup.c
** File description:
** all function for setup
*/

#include "proto.h"

int my_str_search(char *command, char c)
{
    for (int i = 0; i < my_strlen(command); i++) {
        if (command[i] == c)
            return (1);
    }
    return (0);
}

bool is_directory(char *command)
{
    DIR *dir;

    dir = opendir(command);
    if (dir == NULL) {
        closedir(dir);
        return (false);
    }
    closedir(dir);
    return (true);
}

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    int size = 0;
    char **result;

    result = malloc(sizeof(char *) * (nb_rows + 1));
    if (result == NULL)
        exit(0);
    for (int i = 0; i < nb_rows; i++) {
        result[i] = malloc(sizeof(char) * (nb_cols + 1));
        if (result[i] == NULL)
            exit(0);
    }
    return (result);
}