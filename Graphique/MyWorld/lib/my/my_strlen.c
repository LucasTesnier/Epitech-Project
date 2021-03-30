/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** counts the number of characters in a string
*/

int my_strlen(char const *str);

void my_putchar(char c);

int my_strlen(char const *str)
{
    int str_len;

    str_len = 0;
    while (str[str_len] != '\0')
        str_len++;
    return (str_len);
}
