/*
** EPITECH PROJECT, 2020
** bsprintf.c
** File description:
** bs_printf
*/

#ifndef __PRINTF__
#define __PRINTF__

#include <stdarg.h>
void my_print_space(int change, int for_print, char *str);
void my_put_i(int change, int for_print, va_list ap);
int my_put_unsigned_nbr(unsigned int nb, int change, int for_print);
void my_put_hexa_nbr(int nbr, int change, int for_print);
void my_put_octal_nbr(int nbr, int change, int for_print);
void my_put_non_printable(char *str, int change);
void my_put_p_nbr(long nbr);
void my_put_bin_nbr(int nbr, int change, int for_print);
void my_put_hexa_nbr_maj(int nbr, int change, int for_print);
void priority_flag(char *s, int *change, int *i);
void basic_text(char *s, va_list ap, int i, ...);
void dispacher_flag(char *s, va_list ap, int i, ...);
void my_printf(char *s, ...);
int str_search(char c);

#endif
