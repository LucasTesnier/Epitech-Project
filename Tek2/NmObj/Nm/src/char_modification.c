/*
** EPITECH PROJECT, 2022
** NmObj
** File description:
** char_modification
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
* @brief transform an str to a version without underscore
*
* @param str
* @return char*
*/
char *transform_char_without_underscore(char *str)
{
    char *new = malloc(strlen(str) + 1);
    int count = 0;

    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] != '_' && str[i] != '.') {
            new[count] = str[i];
            count++;
        }
    }
    new[count] = '\0';
    return new;
} 