/*
** EPITECH PROJECT, 2020
** buffer.c
** File description:
** all function for load and prepare buffer
*/

#include "../include/proto.h"

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
    buffer = malloc(size.st_size + 1);
    security = read(file_description, buffer, size.st_size);
    if (security <= 0) {
        write(2, "Read is impossible", 18);
        return (NULL);
    }
    close(file_description);
    return (buffer);
}

char **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols,
int size)
{
    char *buffer = load_file_in_mem(filepath);
    char *save = malloc(sizeof(char) * (nb_cols + 1));
    char **map = mem_alloc_2d_array(nb_rows, nb_cols);
    int count = 0;

    for (; count < nb_rows; count++) {
        my_strncpy(save, buffer + (count * (nb_cols + 1)) + size, nb_cols);
        for (int i = 0; i < nb_cols; i++) {
            map[count][i] = save[i];
        }
    }
    return (map);
}

int buffer_modification(char *buffer, int *nb_rows, int *count)
{
    int r = 0;

    if (buffer == NULL)
        return (84);
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            r++;
    }
    for (*count = 0; buffer[*count] != '\n'; *count = *count + 1);
    buffer[*count] = '\0';
    *nb_rows = my_getnbr(buffer);
    if (*nb_rows <= 0 || *nb_rows != r - 1) {
        write(2, "Invalid number", 14);
        return (84);
    }
    return (0);
}

int cols_setup(int *count, char *buffer, int *nb_cols)
{
    for (; buffer[*count + *nb_cols + 1] != '\n'; *nb_cols = *nb_cols + 1);
    for (int i = *count + 1; buffer[i] != '\0'; i += *nb_cols + 1) {
        for (*count = 0; buffer[i + *count] != '\n'; *count = *count + 1);
        if (*count != *nb_cols) {
            write(2, "Invalid map", 11);
            return (84);
        }
    }
    return (0);
}

int verification_map(int i, int nb_cols, char **map)
{
    for (int j = 0; j < nb_cols; j++) {
        if (map[i][j] != '.' && map[i][j] != 'o') {
            write(2, "Invalid map", 11);
            return (84);
        }
    }
    return (0);
}
