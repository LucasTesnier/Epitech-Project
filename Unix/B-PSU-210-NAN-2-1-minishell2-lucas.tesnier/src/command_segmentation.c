/*
** EPITECH PROJECT, 2021
** bultins.c
** File description:
** all function for bultins
*/

#include "proto.h"

char **segmentation_c(char *command, char *separators)
{
    char **args;
    int nb = count_word(command);
    int i = 0;
    char *s = my_strdup(command);
    char *t = NULL;

    if ((args = malloc(sizeof(char *) * (nb + 1))) == NULL)
        exit(0);
    t = strtok(s, separators);
    while (t != NULL) {
        if (i < nb) {
            args[i] = malloc(sizeof(char) * (1 + my_strlen(t)));
            my_strncpy(args[i], t, my_strlen(t));
            i++;
        } else
            break;
        t = strtok(NULL, separators);
    }
    args[i] = NULL;
    return (args);
}

void get_next(char *command, int pos)
{
    for (int i = pos; command[i] == ' ' || command[i] == ';' \
        || command[i] == '\t'; i++)
        command[i] = ' ';
}

bool multiple_command(char *command, int *pos)
{
    for (int i = 0; command[i] == ';'; i++) {
        command[i] = ' ';
    }
    for (int i = 0; i < my_strlen(command); i++) {
        if (command[i] == ';') {
            get_next(command, i + 1);
            command[i] = '\0';
            *pos += i + 1;
            return (true);
        }
    }
    return (false);
}

char *check_integrity(char *command)
{
    bool is_good = false;

    for (int i = 0; i < my_strlen(command); i++) {
        if (command[i] != ' ' && command[i] != '\t')
            is_good = true;
    }
    if (is_good == false)
        command = NULL;
    return (command);
}

void change_path_name(char *path)
{
    for (int i = 0; i < my_strlen(path); i++) {
        if (path[i] == ' ' || path[i] == '\t') {
            path[i] = '\0';
            break;
        }
    }
}