/*
** EPITECH PROJECT, 2020
** my_isnum.c
** File description:
** check if digit
*/

int my_isnum(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}
