/*
** EPITECH PROJECT, 2020
** my_strncmp
** File description:
** reproduce the behavior of the strncmp function
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i;
    int dif_1;
    int dif_2;

    dif_1 = 0;
    dif_2 = 0;
    for (i = 0; i < n; i++)
        dif_1 = dif_1 + s1[i];
    for (i = 0; i < n; i++)
        dif_2 = dif_2 + s2[i];
    return (dif_1 - dif_2);
}
