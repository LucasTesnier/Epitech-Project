/*
** EPITECH PROJECT, 2021
** read.c
** File description:
** reading fonction
*/

#include "proto.h"

int fs_open_file(char const *filepath)
{
    int file_descriptor;

    file_descriptor = open(filepath, O_RDONLY);
    return (file_descriptor);
}

char *read_file(char const *filepath, int size)
{
    char *buffer = malloc(size + 1);
    int file_description = fs_open_file(filepath);

    if (read(file_description, buffer, size) <= 0) {
        write(2, "Read is impossible", 18);
        return (NULL);
    }
    close(file_description);
    return (buffer);
}

char *load_file_in_mem(char const *filepath)
{
    char *line_buf = NULL;
    size_t line_buf_size = 0;
    int size = 0;
    ssize_t line_size;
    FILE *fp = fopen(filepath, "r");

    if (!fp) {
        write(2, "Files doesn't exist", 20);
        return (NULL);
    }
    line_size = getline(&line_buf, &line_buf_size, fp);
    while (line_size >= 0) {
        size += line_size;
        line_size = getline(&line_buf, &line_buf_size, fp);
    }
    return (read_file(filepath, size));
}

void sort_informations(char *buffer, char **stock, int length)
{
    int count = 0;
    int count_two = 0;

    for (int i = 0; i < my_strlen(buffer); i++) {
        if (buffer[i] == '\n') {
            stock[count_two][count] = '\0';
            count_two += 1;
            i++;
            count = 0;
        }
        stock[count_two][count] = buffer[i];
        count++;
    }
}
