/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main files
*/

#include <stdio.h>
#include <stddef.h>
#include <math.h>
#include <stdlib.h>

int main(int ac, char *argv[])
{
    float test = 0.0;

    if (ac != 8) {
        write(2, "Missing arg", 11);
        return (84);
    }
    for (int i = 1; i < 8; i++) {
        for(int j = 0; j < my_strlen(argv[i]); j++) {
            if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '.' && argv [i][j] != '-' && argv[i][j] != '+') {
                write(2, "Invalid arg", 11);
                return (84);
            }
        }
    }
    for(int i = 0; i < my_strlen(argv[7]); i++) {
        if (argv[7][i] == '.') {
            write(2, "Invalid time", 12);
            return (84);
        }
    }
    if (my_getnbr(argv[7]) < 0) {
        write(2, "Invalid time", 12);
        return (84);
    }
    pong(argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
    return (0);
}
