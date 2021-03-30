/*
** EPITECH PROJECT, 2020
** my_ls_r.c
** File description:
** all function for -R
*/

#include "proto.h"

void my_ls_r_lists(char *flag_order, char *path, char **list, int *count)
{
    int save = 0;

    if (my_str_search('d', flag_order) == 0) {
        read_dir(flag_order, path, list, count);
        display_total(list, flag_order, *count);
        sort_list_dispacher(list, *count, flag_order);
        for (int i = 0; i != *count; i++) {
            my_ls_display(list[i], flag_order, *count, &save);
        }
    } else
        my_ls_display(path, flag_order, *count, &save);
}

char get_file_type(mode_t mode)
{
    switch (mode & S_IFMT) {
    case S_IFCHR: return ('c');
        break;
    case S_IFBLK: return ('b');
        break;
    case S_IFDIR: return ('d');
        break;
    case S_IFIFO: return ('p');
        break;
    case S_IFLNK: return ('l');
        break;
    case S_IFREG: return ('-');
        break;
    case S_IFSOCK: return ('k');
        break;
    default: return ('u');
        break;
    }
}

void my_ls_op(char *flag_order)
{
    int count = 0;
    char **list = mem_alloc_2d_array(500, 100);
    int save = 0;

    if (my_str_search('d', flag_order) == 0) {
        read_dir(flag_order, ".", list, &count);
        display_total(list, flag_order, count);
        sort_list_dispacher(list, count, flag_order);
        for (int i = 0; i != count; i++)
            my_ls_display(list[i], flag_order, count, &save);
    } else
        my_ls_display(".", flag_order, count, &save);
}

void read_dir(char *flag_order, char *path, char **list, int *count)
{
    DIR *dir;
    struct dirent *dp;
    char *file_name;
    char *true_name;

    dir = opendir(path);
    if (dir == NULL)
        exit(84);
    while ((dp=readdir(dir)) != NULL) {
        file_name = dp->d_name;
        if (file_name[0] == '.' && my_str_search('a', flag_order) == 0) {
        } else {
            read_dir_two(file_name, path, count, list);
        }
    }
    closedir(dir);
}

void define_color(char *path, int count)
{
    struct stat sb;
    int ex = 0;

    stat(path, &sb);
    if (S_ISDIR(sb.st_mode) == 1) {
        my_putstr("\033[1;34m");
    }
    if ((sb.st_mode & S_IXUSR))
        ex = 1;
    if (S_ISREG(sb.st_mode) == 1 && ex == 1) {
        my_putstr("\033[1;32m");
    }
    my_putstr(path + count);
}
