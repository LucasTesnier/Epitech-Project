/*
** EPITECH PROJECT, 2020
** B-PSU-101-NAN-1-1-navy-lucas.tesnier
** File description:
** is_alpha_maj
*/

int is_alpha_maj(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    return (0);
}