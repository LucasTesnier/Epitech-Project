/*
** EPITECH PROJECT, 2020
** my_strncat
** File description:
** concatenates n characters of a string
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int size_dest = 0;
    int size_src = 0;
    int concatenate = 0;

    if (nb < 0)
        return (0);
    while (dest[size_dest] != '\0')
        size_dest++;
    while (dest[size_src] != '\0')
        size_src++;
    for (concatenate = 0; concatenate < nb; concatenate++)
        dest[size_dest + concatenate] = src[concatenate];
    return (dest);
}

char *my_strcat(char *dest, char const *src)
{
    int len;
    int i;

    len = my_strlen(dest);
    i = 0;
    while (src[i]) {
        dest[len + i] = src[i];
        i++;
    }
    dest[len + i] = '\0';
    return (dest);
}
