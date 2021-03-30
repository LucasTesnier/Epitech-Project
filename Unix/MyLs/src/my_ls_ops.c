/*
** EPITECH PROJECT, 2020
** my_ls_ops.c
** File description:
** all function for ls ops
*/

#include "proto.h"

int my_str_search(char c, char *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == c)
            return (1);
    }
    return (0);
}

void display_symlink(struct stat sb, char *flag_order, char *path)
{
    char buf[1024];
    int len = 0;

    if (S_ISLNK(sb.st_mode) && my_str_search('l', flag_order)) {
        my_putstr(" -> ");
        len = readlink(path, buf, sizeof(buf) - 1);
        buf[len] = '\0';
        my_putstr(buf);
    }
}

void display_name(char *path, int cnt, int *save, char *flag_order)
{
    int count = 0;
    struct stat sb;

    lstat(path, &sb);
    if (my_str_search('d', flag_order) == 0) {
        for (int i = 0; i < my_strlen(path); i++) {
            if (path[i] == '/')
                count = i + 1;
        }
    }
    my_putstr(path + count);
    display_symlink(sb, flag_order, path);
    if (cnt != -1) {
        if (*save < cnt - 1) {
            *save = *save + 1;
            my_putstr("  ");
        } else
            my_putstr("\n");
    } else
        my_putchar('\n');
}

int my_ls_display(char *path, char *flag_order, int count, int *save)
{
    struct stat sb;

    if (lstat(path, &sb) == -1) {
        perror("Invalid path");
        exit(84);
    }
    if (my_str_search('l', flag_order) == 1) {
        display_permission(sb);
        display_hard_link(sb);
        display_user(sb);
        display_size(sb);
        display_date(sb);
        display_name(path, -1, save, flag_order);
    } else
        display_name(path, count, save, flag_order);
    return (0);
}

void read_dir_two(char *file_name, char *path, int *count, char **list)
{
    char *true_name;

    true_name = malloc(sizeof(char) * (my_strlen(path) * \
    my_strlen(file_name)));
    my_strncpy(true_name, path, my_strlen(path));
    true_name[my_strlen(path)] = '/';
    true_name[my_strlen(path) + 1] = '\0';
    my_strncat(true_name, file_name, my_strlen(file_name));
    true_name[my_strlen(file_name) + my_strlen(path) + 1] = '\0';
    my_strncpy(list[*count], true_name, my_strlen(true_name));
    list[*count][my_strlen(true_name)] = '\0';
    *count = *count + 1;
    free(true_name);
}
