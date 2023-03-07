/*
** EPITECH PROJECT, 2021
** bultins.c
** File description:
** all function for bultins
*/

#include "proto.h"
#include <fcntl.h>

int open_file(char *path, int type)
{
    int fd = 0;

    change_path_name(path);
    if (type == 0)
        fd = open(path, O_WRONLY | O_TRUNC | O_CREAT, 0664);
    if (type == 1) {
        fd = open(path + 1, O_WRONLY | O_APPEND | O_CREAT, 0664);
    }
    if (type == 2) {
        fd = open(path, O_RDONLY);
    }
    return (fd);
}

int get_double_redir_input(char *word)
{
    char *str = malloc(sizeof(char) * 100000);
    char *prec = NULL;

    str[0] = '\0';
    while (prec == NULL || my_strcmp(prec, word) != 0) {
        my_putstr("? ");
        if (prec != NULL) {
            my_strcat(str, prec);
            my_strcat(str, "\n");
        }
        prec = get_str();
    }
    int fd = open("read", O_WRONLY | O_TRUNC | O_CREAT, 0664);
    write(fd, str, my_strlen(str));
    close(fd);
    return (open("read", O_RDONLY));
}