/*
** EPITECH PROJECT, 2021
** verification_match.c
** File description:
** verification match
*/

#include "proto.h"

int verification_match(int lines, int max)
{
    if (lines < 2 || lines > 99) {
        write(2, "Invalid numbers of lines.\n", 26);
        return (-1);
    }
}
