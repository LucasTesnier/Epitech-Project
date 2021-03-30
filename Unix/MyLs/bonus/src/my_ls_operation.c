/*
** EPITECH PROJECT, 2020
** my_ls_operation.c
** File description:
** all function for ls operation
*/

#include "proto.h"

void my_ls_ops_paths(char **list, char *flag_order, int *count, int *save)
{
    display_total(list, flag_order, *count);
    sort_list_dispacher(list, *count, flag_order);
    for (int i = 0; i != *count; i++)
        my_ls_display(list[i], flag_order, *count, save);
}

void my_ls_ops_path(char *flag_order, char *argv[], int ac, int i)
{
    int count = 0;
    int save = 0;
    int padding = 0;
    struct stat sb;
    char **list = mem_alloc_2d_array(500, 100);

    if (lstat(argv[i], &sb) == -1)
        exit(84);
    if (S_ISDIR(sb.st_mode) == 1) {
        if (my_str_search('d', flag_order) == 0) {
            list[0][0] = 'M';
            read_dir(flag_order, argv[i], list, &count);
            if (list[0][0] != 'M')
                header(argv, argv[i], ac, &padding);
            my_ls_ops_paths(list, flag_order, &count, &save);
        } else
            my_ls_display(argv[i], flag_order, count, &save);
    } else {
        my_strncat(flag_order, "d", 1);
        my_ls_display(argv[i], flag_order, count, &save);
    }
}

void my_ls_op_path(char *flag_order, int count, char *argv[], int ac)
{
    for (int i = 1; i < ac; i++) {
        if (argv[i][0] != '-') {
            my_ls_ops_path(flag_order, argv, ac, i);
        }
    }
}

int my_ls_operation(char *flag_order, int path, char *argv[], int ac)
{
    int count = 0;

    if (path == 0)
        my_ls_op(flag_order);
    if (path == 1)
        my_ls_op_path(flag_order, count, argv, ac);
    return (0);
}
