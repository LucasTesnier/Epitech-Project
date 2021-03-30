/*
** EPITECH PROJECT, 2021
** read.c
** File description:
** all function for read files
*/

#include "proto.h"

int fs_open_file(char const *filepath)
{
    int file_descriptor;

    file_descriptor = open(filepath, O_RDONLY);
    return (file_descriptor);
}

case_t **mem_alloc_2d_array_case(int nb_rows, int nb_cols)
{
    int size = 0;
    case_t **result;

    result = malloc(sizeof(case_t *) * (nb_rows + 1));
    for (int i = 0; i < nb_rows; i++)
        result[i] = malloc(sizeof(case_t) * (nb_cols + 1));
    return (result);
}

void delete_enter(char *buffer)
{
    for (int i = my_strlen(buffer); i > 0; i--) {
        if (buffer[i - 1] != '\n')
            break;
        else
            buffer[i] = '\0';
    }
}

char *load_file_in_mem(char const *filepath)
{
    char *buffer;
    struct stat size;
    int security = -1;
    int file_description = fs_open_file(filepath);

    if (file_description == -1) {
        write(2, "Files doesn't exist", 20);
        return (NULL);
    }
    stat(filepath, &size);
    buffer = malloc(size.st_size + 2);
    security = read(file_description, buffer, size.st_size);
    if (security <= 0) {
        write(2, "Read is impossible", 18);
        return (NULL);
    }
    buffer[security] = '\n';
    buffer[security + 1] = '\0';
    close(file_description);
    delete_enter(buffer);
    return (buffer);
}
