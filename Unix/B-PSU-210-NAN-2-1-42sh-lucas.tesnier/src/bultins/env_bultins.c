/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** env_bultins
*/

#include "struct.h"
#include "my.h"
#include "shell_loop.h"
#include <stdlib.h>

void execute_unsetenv(my_shell_t *shell, char **args)
{
    int pos = 0;

    if (!args[1]) {
        my_puterror("unsetenv: Too few arguments.\n");
        shell->return_value = -1;
    }
    if (get_in_env(shell->env, args[1], &pos) != NULL) {
        dup_env_without(shell->env, pos);
        shell->return_value = 0;
    }
}

bool setenv_error(my_shell_t *shell, char **args)
{
    if (args[1] && args[2] && args[3]) {
        my_puterror("setenv: Too many arguments.\n");
        return (false);
    }
    if (!args[1])
        return (true);
    if (is_alpha(args[1][0]) == false) {
        my_puterror("setenv: Variable name must begin with a letter.\n");
        return (false);
    }
    if (my_str_search(args[1], '=') == 1) {
        my_puterror("setenv: Variable name must ");
        my_puterror("contain alphanumeric characters.\n");
        return (false);
    }
    return (true);
}

void setenv_new(char **envp, char **args)
{
    int envp_size = get_envp_size(envp);

    envp[envp_size] = malloc(sizeof(char) * my_strlen(args[1]) + 2);
    if (args[2])
        envp[envp_size] = malloc(sizeof(char) * \
        my_strlen(args[1]) + 2 + my_strlen(args[2]));
    envp[envp_size][0] = '\0';
    my_strcat(envp[envp_size], args[1]);
    my_strcat(envp[envp_size], "=");
    if (args[2])
        my_strcat(envp[envp_size], args[2]);
}

void execute_setenv(my_shell_t *shell, char **args)
{
    int pos = 0;

    if (!setenv_error(shell, args)) {
        shell->return_value = -1;
        return;
    }
    if (!args[1])
        return (display_env(shell->env));
    if (get_in_env(shell->env, args[1], &pos) != NULL) {
        if (args[2])
            replace_var(shell->env, args[1], args[2], 1);
        else
            shell->env[pos][my_strlen(args[1]) + 1] = '\0';
    } else
        setenv_new(shell->env, args);
    shell->return_value = 0;
}