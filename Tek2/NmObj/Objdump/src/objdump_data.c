/*
** EPITECH PROJECT, 2022
** NmObj
** File description:
** objdump_data
*/

#include "objdump_data.h"
#include "is_valid_extension.h"
#include <stdio.h>

/**
* @brief display the data content on printable form
*
* @param data
* @param data_size
*/
void section_display_data_printable(uint8_t *data, int data_size)
{
    for (int i = 0; i < 16; i++) {
        if (i < data_size)
            printf("%c", (data[i] >= 32 && data[i] <= 126) ? data[i] : '.');
        else
            printf(" ");
    }
}

/**
* @brief display the data content on hexa form
*
* @param data
* @param data_size
*/
void section_display_data_hexa(uint8_t *data, int data_size)
{
    for (int i = 0; i < 16; i++) {
        if (i < data_size)
            printf("%02x", data[i]);
        else
            printf("  ");
        if ((i + 1) % 4 == 0)
            printf(" ");
    }
}

/**
* @brief loop for display the content var 
*
* @param data
* @param data_size
*/
void section_display_data(uint8_t *data, int data_size)
{
    section_display_data_hexa(data, data_size);
    printf(" ");
    section_display_data_printable(data, data_size);
}