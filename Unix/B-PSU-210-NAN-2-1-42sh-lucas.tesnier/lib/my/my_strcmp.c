/*
** EPITECH PROJECT, 2020
** my_strcmp.c
** File description:
** Compare deux chaines de characteres
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (!s1)
        return (s2[0]);
    else if (!s2)
        return (s1[0]);
    else if (!s1 && !s2)
        return (-1);
    while ((s2[i] && s1[i]) && (s2[i] == s1[i])) {
        i++;
    }
    return (s1[i] - s2[i]);
}