/*
** EPITECH PROJECT, 2021
** B-PSU-210-NAN-2-1-42sh-lucas.tesnier
** File description:
** draw_auto_completion
*/

#include "my.h"

void draw_auto_completion_tab(char *list, int size)
{
    for (int j = my_strlen(list); j < size; j++)
        my_putchar(' ');
}

void draw_auto_completion_list(char **list, int total)
{
    int size = 0;

    for (int i = 0; i < total; i++) {
        if (my_strlen(list[i]) > size)
            size = my_strlen(list[i]);
    }
    size += 2;
    for (int i = 0; i < total; i++) {
        my_putstr(list[i]);
        if (i % 4 != 3 && i + 1 < total)
            draw_auto_completion_tab(list[i], size);
        else
            my_putstr("\n");
    }
}