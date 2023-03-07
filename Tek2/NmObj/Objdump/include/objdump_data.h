/*
** EPITECH PROJECT, 2022
** NmObj
** File description:
** objdump_data
*/

#ifndef OBJDUMP_DATA_H_
    #define OBJDUMP_DATA_H_

    #include <stdint.h>

void section_display_data_printable(uint8_t *data, int data_size);
void section_display_data_hexa(uint8_t *data, int data_size);
void section_display_data(uint8_t *data, int data_size);

#endif /* !OBJDUMP_DATA_H_ */
