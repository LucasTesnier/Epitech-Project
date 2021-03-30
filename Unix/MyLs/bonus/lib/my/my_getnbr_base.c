/*
** EPITECH PROJECT, 2020
** my_getnbr_base
** File description:
** convert and returns a number
*/
#include <stdlib.h>
#include "../../include/my.h"

int *convert_nbr(char const *str, char const *base, int *conv_nbr)
{
    int count_str = 0;
    int i = 0;

    while (count_str < my_strlen(str)) {
        if (str[count_str] == base[i]) {
            conv_nbr[count_str] = i;
            count_str++;
            i = 0;
        } else
            i++;
    }
    return (conv_nbr);
}

int *convert_to_decimal(int *conv_nbr, int base_size, int nbr_size)
{
    int count = 0;

    while (count < nbr_size) {
        conv_nbr[count] = conv_nbr[count] * my_compute_power_rec\
        (base_size, nbr_size - 1 - count);
        count++;
    }
    count = 1;
    while (count < nbr_size) {
        conv_nbr[0] = conv_nbr[count] + conv_nbr[0];
        count++;
    }
    return (conv_nbr);
}

int my_getnbr_base(char const *str, char const *base)
{
    int *conv_nbr;

    conv_nbr = malloc(sizeof(char) * my_strlen(str) + 1);
    convert_nbr(str, base, conv_nbr);
    convert_to_decimal(conv_nbr, my_strlen(base), my_strlen(str));
    return (conv_nbr[0]);
}
