/*
** EPITECH PROJECT, 2020
** my_printf_flag.c
** File description:
** all function for dispache flags
*/

#include <stdarg.h>
#include "../include/my.h"
#include "../include/bsprintf.h"

void priority_flag(char *s, int *change, int *i)
{
    if (s[*i + 1] == '+') {
        *change = 1;
        *i = *i + 1;
    }
    if (s[*i + 1] == '-') {
        *change = 2;
        *i = *i + 1;
    }
    if (s[*i + 1] == '#') {
        *change = 3;
        *i = *i + 1;
    }
    if (s[*i + 1] == ' ') {
        *change = 4;
        for (; s[*i + 1] == ' '; *i = *i + 1);
    }
}

void basic_text(char *s, va_list ap, int i, ...)
{
    va_list p;
    int change;
    int for_print;
    char str[2];

    va_start(p, i);
    change = va_arg(p, int);
    for_print = va_arg(p, int);
    if (s[i + 1] == 's')
        my_print_space(change, for_print, va_arg(ap, char*));
    if (s[i + 1] == 'c') {
        str[0] = (va_arg(ap, int));
        str[1] = '\0';
        my_print_space(change, for_print, str);
    }
    va_end(p);
}

void dispacher_flag(char *s, va_list ap, int i, ...)
{
    va_list p;
    int change;
    int for_print;

    va_start(p, i);
    change = va_arg(p, int);
    for_print = va_arg(p, int);
    if (s[i + 1] == 'i')
        my_put_i(change, for_print, ap);
    if (s[i + 1] == 'd')
        my_put_i(change, for_print, ap);
    if (s[i + 1] == 'u')
        my_put_unsigned_nbr(va_arg(ap, int), change, for_print);
    if (s[i + 1] == 'x') {
        if (change == 3)
            my_putstr("0x");
        my_put_hexa_nbr(va_arg(ap, int), change, for_print);
    }
    va_end(p);
}

int str_search(char c)
{
    char *flag = "0123456789 +-#bScisduxXop%";

    for (int i = 0; flag[i] != '\0'; i++) {
        if (flag[i] == c)
            return (1);
    }
    return (0);
}
