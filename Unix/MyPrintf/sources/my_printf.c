/*
** EPITECH PROJECT, 2020
** my_printf.c
** File description:
** printf
*/

#include <stdarg.h>
#include "../include/my.h"
#include "../include/bsprintf.h"

void dispacher_flag_three(char *s, va_list ap, int i, ...)
{
    va_list p;
    int change;
    int for_print;

    va_start(p, i);
    change = va_arg(p, int);
    for_print = va_arg(p, int);
    if (s[i + 1] == 'o') {
        if (change == 3)
            my_putstr("0");
        my_put_octal_nbr(va_arg(ap, int), change, for_print);
    }
    if (s[i + 1] == 'S')
        my_put_non_printable(va_arg(ap, char *), change);
    if (s[i + 1] == '%')
        my_putchar('%');
    if (s[i + 1] == 'p')
        my_put_p_nbr((long long) va_arg(ap, void *));
    va_end(p);
}

void dispacher_flag_two(char *s, va_list ap, int i, ...)
{
    va_list p;
    int change;
    int for_print;

    va_start(p, i);
    change = va_arg(p, int);
    for_print = va_arg(p, int);
    if (s[i + 1] == 'b') {
        if (change == 3)
            my_putstr("0b");
        my_put_bin_nbr(va_arg(ap, int), change, for_print);
    }
    if (s[i + 1] == 'X') {
        if (change == 3)
            my_putstr("0X");
        my_put_hexa_nbr_maj(va_arg(ap, int), change, for_print);
    }
    dispacher_flag_three(s, ap, i, change, for_print);
    va_end(p);
}

void my_put_i(int change, int for_print, va_list ap)
{
    int nbr;
    int length = 0;

    nbr = va_arg(ap, int);
    if (change == 1 && nbr >= 0)
        my_putchar('+');
    if (change == 4 && nbr >= 0)
        my_putchar(' ');
    for (int j = 1; nbr / j >= 10; j *= 10)
        length++;
    length++;
    if (for_print != -1 && change != 2) {
        for (int j = 0; for_print - length - j > 0; j++)
            my_putchar(' ');
    }
    my_put_nbr(nbr);
    if (for_print != -1 && change == 2) {
        for (int j = 0; for_print - length - j > 0; j++)
            my_putchar(' ');
    }
}

int my_printf_bis(char *s, va_list ap, int count, int i)
{
    int change = 0;
    int for_print = -1;

    if (s[i] != '%' || (s[i] == '%' && str_search(s[i + 1]) == 0))
        my_putchar(s[i]);
    else {
        priority_flag(s, &change, &i);
        if (s[i + 1] >= '0' && s[i + 1] <= '9') {
            for_print = my_getnbr(s + i + 1);
            for (int j = 1; for_print / j >= 10; j *=10) {
                i++;
            }
            i++;
        }
        basic_text(s, ap, i, change, for_print);
        dispacher_flag(s, ap, i, change, for_print);
        dispacher_flag_two(s, ap, i, change, for_print);
        i++;
    }
    return (i);
}

void my_printf(char *s, ...)
{
    va_list ap;
    int count = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '%')
            count++;
    }
    va_start(ap, s);
    for (int i = 0; s[i] != '\0'; i++) {
        i = my_printf_bis(s, ap, count, i);
    }
    va_end(ap);
}
