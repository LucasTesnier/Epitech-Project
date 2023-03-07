/*
** EPITECH PROJECT, 2021
** bultins.c
** File description:
** all function for bultins
*/

#include <stdbool.h>
#include <stddef.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

bool is_alpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (true);
    return (false);
}

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

void my_puterror(char *str)
{
    write(2, str, my_strlen(str));
}