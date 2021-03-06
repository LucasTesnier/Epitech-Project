/*
** EPITECH PROJECT, 2020
** my_ls.c
** File description:
** all ls function
*/

#include "proto.h"

int flag_verification(int i, char *flag_order)
{
    int correct = 0;
    char flag_list[] = "lRdrta";

    for (int j = 0; j < my_strlen(flag_list); j++) {
        if (flag_order[i] == flag_list[j])
            correct = 1;
    }
    if (correct == 0) {
        my_putstr("Invalid flag");
        return (84);
    }
    return (0);
}

void flag_gestion(char *argv[], int i, int *count, char *flag_order)
{
    int size_flag = my_strlen(argv[i]);

    for (int j = 1; j < size_flag; j++) {
        flag_order[*count] = argv[i][j];
        *count = *count + 1;
    }
}

void my_ls_r_list(char *flag_order, char *path, int ac, char *argv[])
{
    struct stat sb;
    int count = 0;
    char **list = mem_alloc_2d_array(100, 100);

    list[0][0] = 0;
    my_putstr(path);
    my_putstr(":\n");
    if (lstat(path, &sb) == -1)
        exit(84);
    if (S_ISDIR(sb.st_mode) == 1) {
        my_ls_r_lists(flag_order, path, list, &count);
    }
    for (int i = 0; i < count; i++) {
        lstat(list[i], &sb);
        if (S_ISDIR(sb.st_mode) == 1) {
            my_putstr("\n");
            my_ls_r_list(flag_order, list[i], ac, argv);
        }
    }
}

int my_ls_r(char *flag_order, int path, char *argv[], int ac)
{
    char **list = mem_alloc_2d_array(100, 100);

    if (my_str_search('d', flag_order) == 1) {
        my_ls_operation(flag_order, path, argv, ac);
        return (0);
    }
    if (path == 0) {
        my_ls_r_list(flag_order, ".", ac, argv);
    }
    if (path != 0) {
        for (int i = 1; i < ac; i++) {
            if (argv[i][0] != '-') {
                my_ls_r_list(flag_order, argv[i], ac, argv);
            }
        }
    }
    return (0);
}

int my_ls_receiver(int ac, char *argv[])
{
    char *flag_order = malloc(sizeof(char) * (ac + 1));
    int count = 0;
    int path = 0;

    for (int i = 1; i < ac; i++) {
        if (argv[i][0] == '-')
            flag_gestion(argv, i, &count, flag_order);
        if (argv[i][0] != '-')
            path = 1;
    }
    for (int i = 0; i < my_strlen(flag_order); i++) {
        if (flag_verification(i, flag_order) == 84)
            return (84);
    }
    if (my_str_search('R', flag_order) == 0) {
        if (my_ls_operation(flag_order, path, argv, ac) == 84)
            return (84);
    } else
        my_ls_r(flag_order, path, argv, ac);
    return (0);
}
