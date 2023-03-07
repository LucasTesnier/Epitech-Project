/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** execute_redirection
*/

#include "struct.h"
#include "my.h"
#include "shell_loop.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

void execute_redirection_one(int size, my_shell_t *shell, my_command_t \
*command_stack, int *pos)
{
    pid_t pid = fork();
    int status;
    int file = 0;

    if (pid != 0) {
        waitpid(pid, &status, 0);
        *pos += 1;
    } else {
        if (command_stack->command[*pos][0] == ' ')
            command_stack->command[*pos] += 1;
        file = open(command_stack->command[*pos], O_WRONLY | O_TRUNC | \
        O_CREAT, 0664);
        dup2(file, 1);
        close(file);
        *pos += 1;
        all_type_stack(size, shell, command_stack, pos);
        exit(0);
    }
}

void execute_redirection_two(int size, my_shell_t *shell, my_command_t \
*command_stack, int *pos)
{
    pid_t pid = fork();
    int status;
    int file = 0;

    if (pid != 0) {
        waitpid(pid, &status, 0);
        *pos += 1;
    } else {
        if (command_stack->command[*pos][0] == ' ')
            command_stack->command[*pos] += 1;
        file = open(command_stack->command[*pos], O_WRONLY | O_APPEND | \
        O_CREAT, 0664);
        dup2(file, 1);
        close(file);
        *pos += 1;
        all_type_stack(size, shell, command_stack, pos);
        exit(0);
    }
}

void execute_redirection_three(int size, my_shell_t *shell, my_command_t \
*command_stack, int *pos)
{
    pid_t pid = fork();
    int status;
    int file = 0;

    if (pid != 0) {
        waitpid(pid, &status, 0);
        *pos += 1;
    } else {
        if (command_stack->command[*pos][0] == ' ')
            command_stack->command[*pos] += 1;
        file = open(command_stack->command[*pos], O_RDONLY);
        dup2(file, 0);
        close(file);
        *pos += 1;
        all_type_stack(size, shell, command_stack, pos);
        exit(0);
    }
}

int redirection_four_get_content(char *word)
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

void execute_redirection_four(int size, my_shell_t *shell, my_command_t \
*command_stack, int *pos)
{
    pid_t pid = fork();
    int status;
    int file = 0;

    if (pid != 0) {
        waitpid(pid, &status, 0);
        *pos += 1;
    } else {
        if (command_stack->command[*pos][0] == ' ')
            command_stack->command[*pos] += 1;
        file = redirection_four_get_content(command_stack->command[*pos]);
        dup2(file, 0);
        close(file);
        *pos += 1;
        all_type_stack(size, shell, command_stack, pos);
        exit(0);
    }
}