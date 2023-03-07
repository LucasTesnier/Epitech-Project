/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-lucas.tesnier
** File description:
** unsigned_operations
*/

#include <stdlib.h>

unsigned char *unsigned_ncopy(unsigned char *dest, unsigned char *str, \
int size)
{
    for (int i = 0; i < size; i++)
        dest[i] = str[i];
    return (dest);
}

unsigned char *my_calloc_u_char(int size, unsigned char c)
{
    unsigned char *str = malloc(sizeof(unsigned char) * size);

    if (!str)
        return (NULL);
    for (int i = 0; i < size; i++)
        str[i] = c;
    return (str);
}