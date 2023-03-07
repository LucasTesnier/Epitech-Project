/*
** EPITECH PROJECT, 2021
** my_job_for_42sh
** File description:
** main
*/
#include "shell_loop.h"
#include <stdio.h>
#include <stdlib.h>

void free_poss(char ***poss)
{
    for (int i = 0; poss[i] != NULL; i++) {
        for (int c = 0; poss[i][c] != NULL; c++) {
            free(poss[i][c]);
        }
        free(poss[i]);
    }
    free(poss);
}

char **globbings(char **args)
{
    char **final_tab;
    int size = 0;
    char ***poss;

    poss = fill_triple_tab(args, &size);
    if (poss == NULL)
        return NULL;
    final_tab = copy_in_final_tab(size, args, poss);
    if (final_tab == NULL)
        return NULL;
    free_poss(poss);
    return final_tab;
}