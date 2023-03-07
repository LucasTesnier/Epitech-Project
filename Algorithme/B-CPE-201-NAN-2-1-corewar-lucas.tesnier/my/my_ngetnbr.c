/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-lucas.tesnier
** File description:
** my_ngetnbr
*/

#include "my.h"

int my_ngetnbr(char const *str, int n)
{
    int i = n;
    int neg = 0;
    int complete_nbr = 0;

    for (; (str[i] > '9' || str[i] < '0') && i < my_strlen(str); i += 1) {
        if (str[i] == '-')
            neg += 1;
    }
    while ((str[i] <= '9' && str[i] >= '0') && i < my_strlen(str)) {
        complete_nbr = complete_nbr * 10 + (str[i]-'0');
        i += 1;
    }
    if (neg % 2 == 0)
        return (complete_nbr);
    else
        return (complete_nbr * -1);
}
