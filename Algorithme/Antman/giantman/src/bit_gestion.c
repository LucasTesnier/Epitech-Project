/*
** EPITECH PROJECT, 2021
** bit_gestion.c
** File description:
** all functions needed for bit gestion
*/

#include "proto.h"

int calcul_bit_chain_length(char *buffer)
{
    int length = 0;
    int i = 0;

    for (; buffer[i] != '~' \
    || buffer[i + 1] != '~'; i++);
    i += 2;
    for (; buffer[i] != '~' \
    || buffer[i + 1] != '~' || buffer[i + 2] != '~' \
    || buffer[i + 3] != '~'; i++) {
        length++;
    }
    return (length);
}

int decrypte_bit_str(branch_t *tree, char *bit_str, int bit_count)
{
    int i = 0;
    bool find;

    while (bit_str[i] && i < bit_count) {
        find = false;
        browse_inorder(tree, bit_str, &i, &find);
    }
    return (0);
}

void get_char_in_bit(int i, char *buffer, char *bit_str, int *actual_size)
{
    unsigned char c = buffer[i];
    int two_pow;

    for (int pow = 7; pow >= 0; pow--) {
        two_pow = my_compute_power_rec(2, pow);
        if (c - two_pow >= 0) {
            c -= two_pow;
            bit_str[*actual_size] = '1';
            *actual_size += 1;
        } else {
            bit_str[*actual_size] = '0';
            *actual_size += 1;
        }
    }
}

int get_bit_count(my_file_t *file, int begin_chain)
{
    int begin_bit_count = begin_chain;
    int bit_count;

    for (int i = begin_bit_count; file->buffer[i] != '~' \
        || file->buffer[i + 1] != '~' || file->buffer[i + 2] != '~' \
        || file->buffer[i + 3] != '~'; i++)
        begin_bit_count++;
    begin_bit_count += 4;
    bit_count = my_getnbr(file->buffer + begin_bit_count);
    return (bit_count);
}

int create_bit_str(my_file_t *file, branch_t *tree)
{
    char *bit_str;
    int length = calcul_bit_chain_length(file->buffer);
    int begin_chain;
    int bit_count;
    int actual_size = 0;

    bit_str = malloc(sizeof(char) * (length * 8));
    if (bit_str == NULL)
        return (-1);
    begin_chain = get_begin_chain(file);
    bit_count = get_bit_count(file, begin_chain);
    for (int i = begin_chain; actual_size < bit_count; i++) {
        get_char_in_bit(i, file->buffer, bit_str, &actual_size);
    }
    if (bit_str == NULL)
        return (-1);
    return (decrypte_bit_str(tree, bit_str, bit_count));
}
