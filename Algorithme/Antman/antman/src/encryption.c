/*
** EPITECH PROJECT, 2020
** Antman_Giantman
** File description:
** encryption.c
*/

#include "my.h"
#include "proto.h"

int find_in_table(char buf, traduction_t **table, int count)
{
    for (int i = count - 1; i >= 0; i--) {
        if (table[i]->charactere == buf)
            return (i);
    }
    return (0);
}

int cut_in_8_bit(int *temp_size, int *total_size, \
traduction_t **table, char *trad_buffer)
{
    if (*temp_size % 8 == 0) {
        *total_size += *temp_size;
        write_in_file(table, trad_buffer);
        my_memset_char(trad_buffer, '\0', *temp_size);
        *temp_size = 0;
    }
}

int trad_buffer(traduction_t **table, my_file_t *file, int count)
{
    char *trad_buffer = malloc(sizeof(*trad_buffer) * (file->size + 1) * 8);
    int pos;
    int temp_size;
    int total_size = 0;

    my_putstr("~~");
    if (trad_buffer == NULL)
        return (-1);
    for (int i = 0; i < file->size; i++) {
        pos = find_in_table(file->buffer[i], table, count);
        my_strcat(trad_buffer, table[pos]->code);
        temp_size = my_strlen(trad_buffer);
        cut_in_8_bit(&temp_size, &total_size, table, trad_buffer);
    }
    total_size += temp_size;
    write_in_file(table, trad_buffer);
    my_putstr("~~~~");
    my_put_nbr(total_size);
    return (0);
}

void write_in_file(traduction_t **table, char *trad_buffer)
{
    int my_number = 0;

    for (int i = 0; trad_buffer[i]; i += 8, my_number = 0) {
        if (trad_buffer[i] == '1')
            my_number += 128;
        if (trad_buffer[i + 1] && trad_buffer[i + 1] == '1')
            my_number += 64;
        if (trad_buffer[i + 2] && trad_buffer[i + 2] == '1')
            my_number += 32;
        if (trad_buffer[i + 3] && trad_buffer[i + 3] == '1')
            my_number += 16;
        if (trad_buffer[i + 4] && trad_buffer[i + 4] == '1')
            my_number += 8;
        if (trad_buffer[i + 5] && trad_buffer[i + 5] == '1')
            my_number += 4;
        if (trad_buffer[i + 6] && trad_buffer[i + 6] == '1')
            my_number += 2;
        if (trad_buffer[i + 7] && trad_buffer[i + 7] == '1')
            my_number += 1;
        my_putchar(my_number);
    }
}
