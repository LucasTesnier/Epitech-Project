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
    + my_strlen(path) + 1));

    if (str == NULL)
        exit(0);
    my_strncat(str, path, my_strlen(path));
    my_strncat(str, "/", 1);
    my_strncat(str, command, my_strlen(command));
    str[my_strlen(command) + my_strlen(path) + 1] = '\0';
    return (str);
}

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    int size = 0;
    char **result;

    result = malloc(sizeof(char *) * (nb_rows + 1));
    if (result == NULL)
        exit(0);
    for (int i = 0; i < nb_rows; i++) {
        result[i] = malloc(sizeof(char) * (nb_cols + 1));
        if (result[i] == NULL)
            exit(0);
    }
    return (result);
}

char **segmentation(char *str)
{
    int size = 0;
    char **array;
    int act = 0;
    int count = 0;

    for (int i = 0; i < my_strlen(str) + 1; i++) {
        if (str[i] == ' ' || str[i] == ':' || str[i] == '\0' || str[i] == '=')
            size++;
    }
    array = mem_alloc_2d_array(size, 100);
    for (int i = 0; i < my_strlen(str); i++) {
	if (str[i] == ':' || str[i] == ' ' || str[i] == '=') {
            act++;
            count = 0;
        } else {
            array[act][count] = str[i];
            count++;
        }
    }
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

void shell(char *str, char **args, char **envp)
{
    int pid;
    int ret;
    int status;

    args[0] = str;
    pid = fork();
    if (pid != 0) {
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status))
            my_putstr("Segmentation fault\n");
        if (WTERMSIG(status) == 11)
            my_putstr("Segmentation fault (core dumped)\n");
    } else {
	execve(str, args, envp);
        exit(0);
    }
}
