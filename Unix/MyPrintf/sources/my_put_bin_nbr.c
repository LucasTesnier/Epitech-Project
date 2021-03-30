/*
** EPITECH PROJECT, 2020
** my_put_bin_nbr.c
** File description:
** put bin nbr
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/bsprintf.h"

char *my_putnbr_base(char *tab, unsigned int nbr, char const *base);

void my_print_space(int change, int for_print, char *str)
{
    if (for_print != -1 && change != 2) {
        for (int j = 0; for_print - my_strlen(str) - j > 0; j++)
            my_putchar(' ');
    }
    my_putstr(str);
    if (for_print != -1 && change == 2) {
        for (int j = 0; for_print - my_strlen(str) - j > 0; j++)
            my_putchar(' ');
    }
}

void my_put_bin_nbr(int nbr, int change, int for_print)
{
    char *str;
    long res = nbr;
    long power = 1;
    long max_power = 1;

    if (nbr < 0) {
        res = 4294967296 - (nbr * -1);
    }
    str = malloc(sizeof(char) * res);
    for (; res / power >= 10; power *= 10);
    for (; max_power <= res; max_power *= 2);
    max_power /= 2;
    for (int i = 0; max_power >= 1; max_power /= 2) {
        if (res - max_power >= 0) {
            str[i] = '1';
            res -= max_power;
        } else
            str[i] = '0';
        i++;
    }
    my_print_space(change, for_print, str);
}
