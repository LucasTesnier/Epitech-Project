/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-lucas.tesnier
** File description:
** my_strchr
*/

static int is_in_needle(char c, char *needle)
{
    for (int i = 0; needle[i]; i++)
        if (needle[i] == c)
            return (1);
    return (0);
}

/**
* @brief function returns a pointer to the first occurrence
* of the character (needle) in the string (haystack)
* 
* @param haystack 
* @param needle 
* @return char* 
*/
char *my_strchr(char *haystack, char *needle)
{
    int i = 0;

    if (!haystack)
        return (0);
    while (!is_in_needle(haystack[i], needle) && haystack[i])
        i++;
    if (!haystack[i])
        return (0);
    return (haystack + i);
}