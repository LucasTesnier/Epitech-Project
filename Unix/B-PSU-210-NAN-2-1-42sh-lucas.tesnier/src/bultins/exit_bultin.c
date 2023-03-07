/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** exit_bultin
*/

#include "struct.h"
#include "my.h"
#include "shell_loop.h"

void execute_new_bultin(int size, char **args, my_shell_t *shell)
{
    if (my_strcmp(args[0], "echo") == 0)
        execute_echo(args);
    if (my_strcmp(args[0], "alias") == 0)
        execute_alias(args, shell);
    if (my_strcmp(args[0], "unalias") == 0)
        execute_unalias(args, shell);
    if (my_strcmp(args[0], "set") == 0)
        shell->local_var = execute_set(args + 1, shell, shell->local_var);
    if (my_strcmp(args[0], "unset") == 0)
        shell->local_var = execute_unset(args + 1, shell, shell->local_var);
}

void execute_bultin(int size, char **args, my_shell_t *shell)
{
    if (my_strcmp(args[0], "exit") == 0) {
        my_putstr("exit\n");
        if (args[1])
            shell->return_value = my_getnbr(args[1]) % 256;
        shell->status = END_STATUS;
    }
    if (my_strcmp(args[0], "env") == 0) {
        display_env(shell->env);
        shell->return_value = 0;
    }
    if (my_strcmp(args[0], "unsetenv") == 0)
        execute_unsetenv(shell, args);
    if (my_strcmp(args[0], "setenv") == 0)
        execute_setenv(shell, args);
    if (my_strcmp(args[0], "cd") == 0)
        execute_cd(shell, args);
    execute_new_bultin(size, args, shell);
}