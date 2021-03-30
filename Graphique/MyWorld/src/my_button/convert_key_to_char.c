/*
** EPITECH PROJECT, 2021
** convert_key_to_char
** File description:
** desc
*/

#include "my_world.h"

char convert_keyevent_to_char(sfKeyCode key)
{
    if (key >= sfKeyA && key <= sfKeyZ)
        return (key + 'a');
    if (key >= sfKeyNum0 && key <= sfKeyNum9)
        return (key - sfKeyNum0 + '0');
    if (key >= sfKeyNumpad0 && key <= sfKeyNumpad9)
        return (key - sfKeyNumpad0 + '0');
    return ('\0');
}