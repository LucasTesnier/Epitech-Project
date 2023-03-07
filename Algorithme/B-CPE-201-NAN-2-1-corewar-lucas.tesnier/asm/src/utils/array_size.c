/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-lucas.tesnier
** File description:
** utils
*/
#include <unistd.h>

size_t array_size(char **arr)
{
    size_t size = 0;

    if (!arr)
        return (size);
    while (arr[size++]);
    return (size - 1);
}
