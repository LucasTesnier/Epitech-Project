/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** echo_bultin
*/

#include "my.h"
#include <stdbool.h>

int execute_echo(char **args)
{
    bool skip_newline = false;
    int start = 1;

    if (args[1] && my_strcmp(args[1], "-n") == 0) {
        skip_newline = true;
        start++;
    }
    for (int i = start; args[i]; i++) {
        my_putstr(args[i]);
        if (args[i + 1])
            my_putchar(' ');
    }
    if (!skip_newline)
        my_putchar('\n');
    return (0);
}