/*
** EPITECH PROJECT, 2021
** B-PSU-210-NAN-2-1-42sh-lucas.tesnier
** File description:
** manage_str
*/
#include "struct.h"
#include "my.h"
#include "shell_loop.h"
#include <stdlib.h>

char *modify_str(char *src, char *str)
{
    int i;
    int n = 0;

    for (i = 0; i < my_strlen(src); i++) {
        if (src[i + 1] == '=' && (src[i] != ' ' && src[i + 2] != ' ')) {
            str[n] = src[i];
            str[n + 1] = ' ';
            str[n + 2] = '=';
            str[n + 3] = ' ';
            i += 1;
            n += 3;
        } else
            str[n] = src[i];
        n += 1;
    }
    str[n] = '\0';
    return (str);
}

char *manage_str(char *src)
{
    char *str = malloc(sizeof(char) * 10000);

    if (str == NULL || src == NULL)
        return (NULL);
    else
        return (modify_str(src, str));
}