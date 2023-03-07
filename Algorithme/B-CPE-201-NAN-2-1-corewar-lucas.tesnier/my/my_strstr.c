/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** Reproduce the behavior of the strstr function.
*/
#include "my.h"
#include "unistd.h"

bool my_strstr(char *str, const char *to_find)
{
    int to_find_length;

    if (!str || !to_find)
        return (false);
    to_find_length = my_strlen(to_find);
    for (int i = 0; str[i]; i++) {
        if (my_strncmp(str + i, to_find, to_find_length) == 0)
            return (true);
    }
    return (false);
}
