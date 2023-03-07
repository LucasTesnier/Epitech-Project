/*
** EPITECH PROJECT, 2021
** B-PSU-210-NAN-2-1-42sh-lucas.tesnier
** File description:
** auto_completion
*/

#include "struct.h"
#include "my.h"
#include "shell_loop.h"
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

void list_all_file(char *path, int *total, char **list, char *start)
{
    struct dirent *dp;
    DIR *dir = opendir(path);

    if (!dir)
        return;
    while ((dp = readdir(dir)) != NULL) {
        if (start == NULL || my_strncmp(start, dp->d_name, \
        my_strlen(start)) == 0) {
            list[*total] = my_strdup(dp->d_name);
            *total += 1;
        }
    }
}

void sort_auto_completion_list(char **list, int total, int *change)
{
    char *temp = NULL;

    *change = 0;
    for (int i = 1; i < total; i++) {
        if (my_strcmp(list[i], \
        list[i - 1]) < 0) {
            temp = my_strdup(list[i]);
            list[i] = my_strdup(list[i - 1]);
            list[i - 1] = my_strdup(temp);
            free(temp);
            *change = 1;
        }
    }
}

void list_all_file_direct_path(char **list, int *total, char *start)
{
    int pos = my_str_return_last_pos(start, '/');
    char *str;

    if (pos == -1)
        return;
    str = my_strdup(start);
    str[pos] = '\0';
    if (pos == my_strlen(start) - 1)
        list_all_file(str, total, list, NULL);
    else
        list_all_file(str, total, list, str + pos + 1);
}

void auto_completion(char *command, char **env)
{
    char **list = mem_alloc_2d_array(10000, 10000);
    int total = 0;
    char *start = command;
    int p = 0;
    char **multi_path = my_strtok(get_in_env(env, "PATH", &p), ":");
    int change = 1;

    if (!start || start[0] == ' ')
        start = NULL;
    if (!multi_path)
        return;
    list_all_file(".", &total, list, start);
    for (int i = 0; multi_path[i] && start != NULL; i++) {
        list_all_file(multi_path[i], &total, list, start);
    }
    if (start)
        list_all_file_direct_path(list, &total, start);
    while (change == 1)
        sort_auto_completion_list(list, total, &change);
    draw_auto_completion_list(list, total);
}