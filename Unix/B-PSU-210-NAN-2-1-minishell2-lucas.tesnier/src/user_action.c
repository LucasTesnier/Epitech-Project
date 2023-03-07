/*
** EPITECH PROJECT, 2021
** bultins.c
** File description:
** all function for bultins
*/

#include "proto.h"

void put_prompt(void)
{
    if (isatty(0) == 1) {
        my_putstr("LT> ");
    }
}

char *get_str(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read = 0;

    while (1) {
        read = getline(&line, &len, stdin);
        if (read == -1) {
            exit(0);
        }
        if (line[0] == '\n')
            return (NULL);
        if (line[read - 1] == '\n')
            line[read - 1] = '\0';
        return (line);
    }
    return (NULL);
}