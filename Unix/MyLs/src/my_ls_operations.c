/*
** EPITECH PROJECT, 2020
** my_ls_operations.c
** File description:
** all function for ls operations
*/

#include "proto.h"

void reverse_list(char **list, int count)
{
    char *save;

    count--;
    for (int i = 0; i < (count + 1) / 2; i++) {
        save = malloc(sizeof(char) * my_strlen(list[i]));
        my_strncpy(save, list[i], my_strlen(list[i]));
        my_strncpy(list[i], list[count - i], my_strlen(list[count - i]));
        list[i][my_strlen(list[count - i])] = '\0';
        my_strncpy(list[count - i], save, my_strlen(save));
        list[count - i][my_strlen(save)] = '\0';
        free(save);
    }
}

void sort_list_t(char **list, int *change, int i)
{
    char *save;

    save = list[i + 1];
    list[i + 1] = list[i];
    list[i] = save;
    *change = 1;
}

void sort_list_time(char **list, int count)
{
    int change = 1;
    struct stat sb;
    long time;
    long time2;

    while (change == 1) {
        change = 0;
        for (int i = 0; i < count; i++) {
            lstat(list[i], &sb);
            time = sb.st_mtime;
            stat(list[i + 1], &sb);
            time2 = sb.st_mtime;
            if (time - time2 > 0)
                sort_list_t(list, &change, i);
        }
    }
    reverse_list(list, count);
}

void sort_list_dispacher(char **list, int count, char *flag_order)
{
    sort_list_alphebatical_order(list, count);
    if (my_str_search('t', flag_order) == 1)
        sort_list_time(list, count);
    if (my_str_search('r', flag_order) == 1)
        reverse_list(list, count);
}

void header(char *argv[], char *name, int ac, int *save)
{
    int count = 0;
    int pos = 0;

    for (int i = 0; i < ac; i++) {
        if (argv[i][0] != '-')
            count++;
    }
    if (count > 1) {
        for (int i = 0; i < my_strlen(name); i++) {
            if (name[i] == '/')
                pos = i + 1;
        }
        if (*save != 0)
            my_putchar('\n');
        *save = 1;
        my_putstr(name + pos);
        my_putstr(":\n");
    }
}
