/*
** EPITECH PROJECT, 2020
** my_putnbr_base
** File description:
** convert and displays a decimal number into agiven base.
*/

#include "../../include/my.h"

void my_putchar(char c);

int define_base(int nbr, char const *base)
{
    int base_value;

    base_value = 0;
    while (base[base_value] != '\0')
        base_value++;
    return (base_value);
}

int nbr_power(int nbr, int power)
{
    int i;
    int result;

    result = nbr;
    if (power == 0)
        return (1);
    if (power < 0)
        return (0);
    for (i = power; i > 1; i--) {
        result = result * nbr;
    }
    return (result);
}

int *my_putnbr_base(int *tab, int nbr, char const *base)
{
    int base_value;
    int max_base = 1;
    int actual_base = 1;
    int stock[2];

    if (nbr == 0 || nbr == 1) {
        tab[0] = base[nbr];
        return (tab);
    }
    base_value = define_base(nbr, base);
    while (nbr > max_base) {
        max_base = nbr_power(base_value, actual_base);
        actual_base++;
    }
    actual_base = actual_base - 2;
    max_base = nbr_power(base_value, actual_base);
    stock[0] = base_value;
    stock[1] = actual_base;
    mk_cv(stock, nbr, base, tab);
    return (tab);
}

int *mk_cv(int *stock, int nbr, char const *base, int *tab)
{
    int number_result;
    int max_base;
    int base_val = stock[0];
    int act_base = stock[1];

    max_base = act_base;
    while (act_base >= 0) {
        number_result = nbr / (nbr_power(base_val, act_base));
        if (number_result > 0) {
            tab[max_base - act_base] = number_result;
            nbr = nbr - (number_result * nbr_power(base_val, act_base));
        } else {
            tab[max_base - act_base] = 0;
        }
        act_base--;
    }
    go_in_base(tab, max_base, base);
    return (tab);
}

int *go_in_base(int *tab, int max_base, char const *base)
{
    int change;
    int i;
    int reverse[1000] = {0};

    i = 0;
    while (i <= max_base) {
        change = tab[i];
        tab[i] = base[change];
        i++;
    }
    return (tab);
}
