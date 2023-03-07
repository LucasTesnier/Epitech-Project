/*
** EPITECH PROJECT, 2021
** int_to_str
** File description:
** desc
*/
#include "dissas.h"

int int_len(int nbr)
{
    int len = 1;

    if (nbr < 0) {
        len++;
        nbr *= -1;
    }
    while (nbr > 9) {
        nbr /= 10;
        len++;
    }
    return (len);
}

char *int_to_str(int nbr)
{
    char *number = NULL;
    int len = int_len(nbr);
    int nb = nbr;

    number = malloc(sizeof(char) * (len + 1));
    if (nb < 0)
        nbr *= -1;
    number[len] = '\0';
    while (len > 0) {
        number[len - 1] = nbr % 10 + '0';
        nbr /= 10;
        len--;
    }
    if (nb < 0)
        number[0] = '-';
    return (number);
}

int get_dir_param(dissas_t *dump, int index)
{
    int param = dump->code[index];

    param = (param << 8);
    param += dump->code[index + 1];
    param = (param << 8);
    param += dump->code[index + 2];
    param = (param << 8);
    param += dump->code[index + 3];
    return (param);
}

short get_ind_param(dissas_t *dump, int index)
{
    short param = dump->code[index];

    param = (param << 8);
    param += dump->code[index + 1];
    return (param);
}