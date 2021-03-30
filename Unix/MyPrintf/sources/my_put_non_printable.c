/*
** EPITECH PROJECT, 2020
** my_print_no_printable.c
** File description:
** no printable char
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/bsprintf.h"

void my_put_octal_nbr_conv_np(long *res, long max_power, char *str, int i)
{
    long change = 0;
    char base[] = "01234567";

    if (*res - max_power >= 0) {
        for (change = 0; *res - change * max_power >= 0; change++);
        change--;
        str[i] = base[change];
        *res -= (max_power * change);
    } else
        str[i] = '0';
}

char *my_put_octal_nbr_np(int nbr)
{
    char *str;
    long res = nbr;
    long power = 1;
    long max_power = 1;
    char base[] = "01234567";
    int i = 0;

    if (nbr < 0)
        res = 4294967296 - (nbr * -1);
    str = malloc(sizeof(char) * res);
    for (; res / power >= 10; power *= 10);
    for (; max_power <= res; max_power *= 8);
    max_power /= 8;
    for (i = 0; max_power > 1; max_power /= 8) {
        my_put_octal_nbr_conv_np(&res, max_power, str, i);
        i++;
    }
    str[i] = base[res];
    return (str);
}

void my_put_non_printable(char *str, int change)
{
    int res = 0;
    char *save;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] == 127) {
            my_putchar('\\');
            if (change == 3)
                my_putstr("0o");
            res = str[i];
            save = my_put_octal_nbr_np(res);
            if (my_strlen(save) != 3) {
                for (int i = 0; i + my_strlen(save) < 3; i++)
                    my_putchar('0');
            }
            my_putstr(save);
        }
        if (str[i] >= 32 && str[i] != 127)
            my_putchar(str[i]);
    }
}
