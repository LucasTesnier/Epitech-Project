/*
** EPITECH PROJECT, 2021
** my_job_for_42sh
** File description:
** utils
*/
#include <stdio.h>

int arr_len(char **tab)
{
    int count = 0;

    for (int i = 0; tab[i] != 0; i++)
        count++;
    return count;
}

void print_arr(char **tab)
{
    for (int i = 0; tab[i] != 0; i++)
        printf("%s\n", tab[i]);
}