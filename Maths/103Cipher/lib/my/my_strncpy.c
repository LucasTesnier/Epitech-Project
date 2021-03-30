/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** copy n characters from a strin into another
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        dest[i] = src[i];
        if (src[i] == '\0')
            return (dest);
    }
    return (dest);
}
