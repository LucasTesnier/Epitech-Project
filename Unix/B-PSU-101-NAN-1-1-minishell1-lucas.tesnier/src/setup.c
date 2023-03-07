/*
** EPITECH PROJECT, 2021
** setup.c
** File description:
** all function for setup
*/

#include "proto.h"

char *prepare_shell(char *command, char *path)
{
    char *str = malloc(sizeof(char) * (my_strlen(command) \
    + my_strlen(path) + 3));

    if (str == NULL)
        exit(0);
    str[0] = '\0';
    my_strncat(str, path, my_strlen(path));
    my_strncat(str, "/", 1);
    my_strncat(str, command, my_strlen(command));
    str[my_strlen(command) + my_strlen(path) + 1] = '\0';
    return (str);
}

char **segmentation(char *str)
{
    int size = 0;
    char **array;
    int act = 0;
    int count = 0;

    for (int i = 0; i < my_strlen(str) + 1; i++)
        if (str[i] == ' ' || str[i] == ':' || str[i] == '\0' || str[i] == '=')
            size++;
    array = mem_alloc_2d_array(size, 1000);
    for (int i = 0; i < my_strlen(str); i++)
        if (str[i] == ':' || str[i] == ' ' || str[i] == '=') {
            array[act][count] = '\0';
            act++;
            count = 0;
        } else {
            array[act][count] = str[i];
            array[act][count + 1] = '\0';
            count++;
        }
    array[act][count] = '\0';
    return (array);
}

int count_args(char *str)
{
    int size = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == ' ' || str[i] == ':')
            size++;
    }
    return (size);
}

void shell_error_message(int status)
{
    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == 11)
            my_putstr("Segmentation fault");
        if (WTERMSIG(status) == 8)
            my_putstr("Floating exception");
        if (WCOREDUMP(status))
            my_putstr(" (core dumped)");
        my_putchar('\n');
    }
}

void shell(char *str, char **args, char **envp)
{
    int pid;
    int ret;
    int status;

    args[0] = str;
    pid = fork();
    if (pid != 0) {
        waitpid(pid, &status, 0);
        shell_error_message(status);
    } else {
        if (execve(str, args, envp) == -1) {
            my_putstr(str);
            my_putstr(": Exec format error. Wrong Architecture.\n");
        }
        exit(0);
    }
}
