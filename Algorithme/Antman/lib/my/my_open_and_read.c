/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** my_open_and_read.c
*/

#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int my_open_and_read(my_file_t *file, char *filepath)
{
    struct stat files_stats;

    file->fd = open(filepath, O_RDONLY);
    if (file->fd <= 0) {
        my_putstr("The file can not be open.\n");
        return (84);
    }
    stat(filepath, &files_stats);
    file->size = files_stats.st_size;
    file->buffer = my_calloc_char(sizeof(char), file->size + 1, '\0');
    if (file->buffer == NULL)
        return (84);
    if (read(file->fd, file->buffer, file->size) <= 0) {
        my_putstr("The file can not be read.\n");
        return (84);
    }
    return (0);
}
