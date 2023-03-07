/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-lucas.tesnier
** File description:
** write_into_cor_file
*/

#include "my.h"
#include "asm.h"
#include "op.h"
#include "parsing.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

char *get_args_bytes(filedata_t *data)
{
    char *args = my_calloc_char(sizeof(char), 4, 0);

    if (args == NULL)
        exit(84);
    for (int i = 0; i < op_tab[data->op - 1].nbr_args; i++) {
        if (check_register(data->array[i + 1]) != -1)
            args[i] = 1;
        else if (check_direct(data->array[i + 1]) != -1)
            args[i] = 2;
        if (check_indirect(data->array[i + 1]) != -1)
            args[i] = 3;
    }
    return (args);
}

void write_bytecode(int fd, node_t *node)
{
    unsigned char byte = 0;
    int shift = 6;
    char *args = get_args_bytes(node->data);

    for (int i = 0; i <= op_tab[node->data->op - 1].nbr_args; i++) {
        byte += (args[i] << shift);
        shift -= 2;
    }
    write(fd, &byte, 1);
    free(args);
}

void swap_and_write(int fd, int i, node_t *node)
{
    int swapped = 0;

    swapped = node->data->to_write[i];
    if (i == 1 && node->data->op != 1 && node->data->op != 9 \
        && node->data->op != 12 && node->data->op != 15)
        write_bytecode(fd, node);
    if (node->data->size[i] > 1) {
        swapped = SWAP(node->data->to_write[i]);
        if (node->data->size[i] == 2)
            swapped = SHIFT(swapped);
    }
    write(fd, &swapped, node->data->size[i]);
}

void write_into_cor_file(list_t *list, header_t *header, char *name)
{
    FILE *f;
    node_t *node = list->first;
    char *path = my_strdup(get_new_file_name(name));

    if (!path)
        exit(84);
    if (!(path = (realloc(path, my_strlen(path) + 5))))
        exit(84);
    my_strcat(path, "cor");
    f = fopen(path, "wb+");
    if (!f)
        exit(84);
    write(f->_fileno, header, sizeof(header_t));
    for (; node; node = node->next) {
        for (int i = 0; i <= op_tab[node->data->op - 1].nbr_args \
            && !node->data->is_label; i++)
            swap_and_write(f->_fileno, i, node);
    }
    free(path);
    fclose(f);
}