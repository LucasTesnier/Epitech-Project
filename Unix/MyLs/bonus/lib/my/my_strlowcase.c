/*
** EPITECH PROJECT, 2020
** my_strlowcase
** File description:
** puts every letter in lower case
*/

char *my_strlowcase(char *str)
{
    int size;
    int i;

    size = 0;
    while (str[size] != '\0')
        size++;
    for (i = 0; i < size; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
    return (str);
}
