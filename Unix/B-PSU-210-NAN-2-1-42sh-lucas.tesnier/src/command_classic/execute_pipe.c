/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** execute_pipe
*/

#include "struct.h"
#include "my.h"
#include "shell_loop.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void execute_pipe_first_child(int size, my_shell_t *shell, int *pos, int *fd)
{
    dup2(fd[1], STDOUT_FILENO);
    close(fd[0]);
    close(fd[1]);
    *pos += 1;
    all_type_stack(size, shell, shell->command_stack, pos);
    exit(0);
}

void execute_pipe_second_child(int size, my_shell_t *shell, int *pos, int *fd)
{
    dup2(fd[0], STDIN_FILENO);
    close(fd[1]);
    close(fd[0]);
    all_type_stack(size, shell, shell->command_stack, pos);
    exit(0);
}

void execute_pipe_first_parent(int size, my_shell_t *shell, int *pos, int *fd)
{
    int pid = fork();

    *pos = stack_return_classic_pos(shell->command_stack->command_type, \
    *pos, size);
    *pos += 1;
    if (pid == 0) {
        execute_pipe_second_child(size, shell, pos, fd);
    } else {
        int status;
        close(fd[0]);
        close(fd[1]);
        waitpid(pid, &status, 0);
        *pos = stack_return_classic_pos(shell->command_stack->command_type, \
        *pos, size);
        *pos += 1;
    }
}

void execute_pipe(int size, my_shell_t *shell, my_command_t *command_stack, \
int *pos)
{
    int fd[2];
    pipe(fd);
    pid_t pid = fork();

    if (pid == 0) {
        execute_pipe_first_child(size, shell, pos, fd);
    } else {
        execute_pipe_first_parent(size, shell, pos, fd);
    }
}