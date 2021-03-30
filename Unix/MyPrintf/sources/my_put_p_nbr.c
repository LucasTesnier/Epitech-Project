/*
** EPITECH PROJECT, 2020
** my_put_p_nbr.c
** File description:
** all function for my_put_p_nbr
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/bsprintf.h"

char *my_putnbr_base(char *tab, unsigned int nbr, char const *base);

void my_put_p_nbr_conv(long *res, long max_power, char *str, int i)
{
    long change = 0;
    char base[] = "0123456789abcdef";

    if (*res - max_power >= 0) {
        for (change = 0; *res - change * max_power >= 0; change++);
        change--;
        str[i] = base[change];
        *res -= (max_power * change);
    } else
        str[i] = '0';
}

void my_put_p_nbr(long nbr)
{
    char str[150];
    long res = nbr;
    long power = 1;
    long max_power = 1;
    char base[] = "0123456789abcdef";
    int i = 0;

    if (nbr < 0)
        res = 4294967296 - (nbr * -1);
    for (; res / power >= 10; power *= 10);
    for (; max_power <= res; max_power *= 16);
    max_power /= 16;
    for (i = 0; max_power > 1; max_power /= 16) {
        my_put_p_nbr_conv(&res, max_power, str, i);
        i++;
    }
    str[i] = base[res];
    str[i + 1] = '\0';
    my_putstr("0x");
    my_putstr(str);
}
