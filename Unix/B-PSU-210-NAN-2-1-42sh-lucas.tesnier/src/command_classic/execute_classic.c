/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** execute_classic
*/

#include "struct.h"
#include "my.h"
#include "shell_loop.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void run_classic_command(int size, char **args, my_shell_t *shell)
{
    int pid;
    int ret;
    int status;
    static int process_queue = 0;

    if (!classic_command_verif(shell, args))
        return;
    pid = fork();
    if (pid != 0) {
        waitpid(pid, &status, 0);
        shell_error_message(status);
    } else {
        setpgid(0, 0);
        if (execve(args[0], args, shell->env) == -1) {
            my_putstr(args[0]);
            my_puterror(": Exec format error. Wrong Architecture.\n");
            shell->return_value = -1;
        }
        exit(0);
    }
}

char *cat_command_path(char *command, char *path)
{
    char *str = malloc(sizeof(char) * (my_strlen(command) + \
    my_strlen(path) + 2));

    if (str == NULL) {
        my_puterror("Error Malloc.\n");
        exit(0);
    }
    str[0] = '\0';
    my_strcat(str, path);
    my_strcat(str, "/");
    my_strcat(str, command);
    return (str);
}

void execute_classic_command_without_path(char **path, char **args, \
my_shell_t *shell, int size)
{
    char *str = NULL;

    for (int i = 0; path[i]; i++) {
        str = cat_command_path(args[0], path[i]);
        if (access(str, F_OK) == 0) {
            args[0] = my_strdup(str);
            run_classic_command(size, args, shell);
            shell->return_value = 0;
            free(str);
            return;
        }
        free(str);
    }
    my_puterror(args[0]);
    my_puterror(": Command not found.\n");
    shell->return_value = -1;
}

void execute_classic_command(int size, char **args, my_shell_t *shell)
{
    char **path = NULL;
    int pos = 0;

    if (my_str_search(args[0], '/') == 1) {
        run_classic_command(size, args, shell);
        return;
    }
    path = my_strtok(get_in_env(shell->env, "PATH", &pos), ":");
    if (path == NULL) {
        my_puterror(args[0]);
        my_puterror(": Command not found.\n");
        shell->return_value = -1;
        return;
    }
    shell->return_value = 0;
    execute_classic_command_without_path(path, args, shell, size);
}