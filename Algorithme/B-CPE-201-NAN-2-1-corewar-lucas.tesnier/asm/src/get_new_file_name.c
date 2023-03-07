/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-lucas.tesnier
** File description:
** get_new_file_name
*/

#include "my.h"

char *get_new_file_name(char *str)
{
    char *new = my_strdup(str);
    char *tmp = new;

    if (!new)
        exit(84);
    while ((tmp = my_strchr(tmp, "/"))) {
        tmp++;
        new = tmp;
    }
    tmp = new + (my_strlen(new) - 1);
    while (*tmp != '.')
        *(tmp--) = '\0';
    return (new);
}