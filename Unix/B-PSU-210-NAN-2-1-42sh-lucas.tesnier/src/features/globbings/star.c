/*
** EPITECH PROJECT, 2021
** my_job_for_42sh
** File description:
** star
*/
#include "shell_loop.h"
#include <glob.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **copy_in_final_tab(int size, char **args, char ***poss)
{
    char **final_tab = malloc(sizeof(char *) * (size + 1));
    int os = 0;

    if (final_tab == NULL)
        return NULL;
    for (int i = 0; i < arr_len(args); i++) {
        for (int c = 0; c < arr_len(poss[i]); c++) {
            final_tab[os] = strdup(poss[i][c]);
            os++;
        }
    }
    final_tab[os] = NULL;
    return final_tab;
}

char **is_single(char **tab, glob_t globbuf, char *str)
{
    if (globbuf.gl_pathc == 0) {
        tab = malloc(sizeof(char *) * 2);
        if (tab == NULL)
            return NULL;
        tab[0] = strdup(str);
        tab[1] = NULL;
        return tab;
    }
    return NULL;
}

char **fill_tab(char **tab, glob_t globbuf)
{
    int i = 0;
    int c = 0;

    while (globbuf.gl_pathv[i] != 0)
        i++;
    tab = malloc(sizeof(char *) * (i + 1));
    if (tab == NULL)
        return NULL;
    for (c = 0; c < i; c++)
        tab[c] = strdup(globbuf.gl_pathv[c]);
    tab[c] = 0;
    globfree(&globbuf);
    return tab;
}

char **glob_list(char *str)
{
    glob_t globbuf;
    char **tab;
    int err = 0;

    if (str == NULL)
        return NULL;
    err = glob(str, GLOB_ERR, NULL, &globbuf);
    if ((tab = is_single(tab, globbuf, str)) != NULL) {
        return tab;
    } else
        return (fill_tab(tab, globbuf));
}

char ***fill_triple_tab(char **args, int *size)
{
    int i = 0;
    char ***stock_tabs = malloc(sizeof(char **) * (arr_len(args) + 1));

    for (i = 0; args[i] != 0; i++) {
        stock_tabs[i] = glob_list(args[i]);
        if (stock_tabs[i] == NULL)
            return NULL;
        *size += arr_len(stock_tabs[i]);
    }
    stock_tabs[i] = NULL;
    return stock_tabs;
}