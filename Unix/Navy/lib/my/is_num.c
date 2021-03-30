/*
** EPITECH PROJECT, 2020
** B-CPE-110-NAN-1-1-BSQ-constant.vigneron
** File description:
** is_num
*/
char is_num(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}