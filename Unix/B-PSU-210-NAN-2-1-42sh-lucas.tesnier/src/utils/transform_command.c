/*
** EPITECH PROJECT, 2021
** transform_command.c
** File description:
** 42sh
*/

#include "shell_loop.h"

void transform_command(char **cmd, char *delim)
{
    for (int i = 0; (*cmd)[i] != '\0'; i++) {
        if (i > 0 && (*cmd)[i - 1] == delim[0] && (*cmd)[i] == delim[1]) {
            (*cmd)[i - 1] = '\t';
            (*cmd)[i] = '\t';
        }
    }
}