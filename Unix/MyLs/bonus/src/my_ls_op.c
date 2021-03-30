/*
** EPITECH PROJECT, 2020
** my_ls_op.c
** File description:
** all function for ls op
*/

#include "proto.h"

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    int size = 0;
    char **result;

    result = malloc(sizeof(char *) * (nb_rows + 1));
    for (int i = 0; i < nb_rows; i++)
        result[i] = malloc(sizeof(char) * (nb_cols + 1));
    if (result == NULL)
        exit(84);
    return (result);
}

void error(void)
{
    perror("Invalid path");
    exit(84);
}

void display_total(char **list, char *flag_order, int count)
{
    int res = 0;
    struct stat sb;

    if (my_str_search('l', flag_order) == 1) {
        for (int i = 0; i < count; i++) {
            if (lstat(list[i], &sb) == -1) {
                error();
            }
            res += sb.st_blocks;
        }
        my_putstr("total ");
        my_put_nbr(res / 2);
        my_putstr("\n");
    }
}

void sort_list_alph(int i, int *change, char **list)
{
    char *s;
    char *s2;
    char *save;

    s = malloc(sizeof(char) * my_strlen(list[i]));
    s2 = malloc(sizeof(char) * my_strlen(list[i + 1]));
    s = my_strncpy(s, list[i], my_strlen(list[i]));
    s2 = my_strncpy(s2, list[i + 1], my_strlen(list[i + 1]));
    if (my_str_islower(list[i]) == 0 || my_str_islower(list[i + 1]) \
    == 0) {
        s = my_strlowcase(s);
        s2 = my_strlowcase(s2);
    }
    if (my_strcmp(s, s2) > 0) {
        save = list[i + 1];
        list[i + 1] = list[i];
        list[i] = save;
        *change = 1;
    }
    free(s);
    free(s2);
}

void sort_list_alphebatical_order(char **list, int count)
{
    int change = 1;

    while (change == 1) {
        change = 0;
        for (int i = 0; i < count - 1; i++)
            sort_list_alph(i, &change, list);
    }
}
