/*
** EPITECH PROJECT, 2021
** B-PSU-210-NAN-2-1-42sh-lucas.tesnier
** File description:
** bckslash_utils
*/
#include "shell_loop.h"
#include <stddef.h>

int backslash_counter(char *command)
{
    int counter = 0;

    if (command == NULL)
        return 0;
    for (int i = 0; command[i] != 0; i++) {
        if (command[i] == '\\')
            counter++;
    }
    return counter;
}

int check_bckslash_presence(char **args)
{
    if (args == NULL)
        return 0;
    for (int i = 0; args[i] != 0; i++) {
        if (backslash_counter(args[i]) != 0)
            return -1;
    }
    return 0;
}