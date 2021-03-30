/*
** EPITECH PROJECT, 2020
** my_revstr.c
** File description:
** reverse a string
*/

char *my_revstr(char *str)
{
    char change;
    int size;
    int i;

    size = 0;
    while (str[size] != '\0')
        size++;
    for (i = 0; i < size / 2; i++) {
        change = str[i];
        str[i] = str[size - i - 1];
        str[size - i - 1] = change;
    }
    return (str);
}
