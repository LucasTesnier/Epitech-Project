/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** cd_bultin
*/

#include "struct.h"
#include "my.h"
#include "shell_loop.h"
#include <stdlib.h>
#include <unistd.h>

void change_path(my_shell_t *shell, char *to_go)
{
    char *pwd = malloc(sizeof(char) * 1000);

    getcwd(pwd, 1000);
    replace_var(shell->env, "OLDPWD", pwd, 1);
    chdir(to_go);
    getcwd(pwd, 1000);
    replace_var(shell->env, "PWD", pwd, 1);
    shell->return_value = 0;
}

bool cd_verification(my_shell_t *shell, char *to_go)
{
    if (to_go == NULL)
        return (false);
    if (access(to_go, F_OK) == 0 && is_directory(to_go) == true)
        return (true);
    if (access(to_go, F_OK) == 0 && access(to_go, R_OK) == 0) {
        my_puterror(to_go);
        my_puterror(": Not a directory.\n");
        return (false);
    }
    if (access(to_go, F_OK) == 0) {
        my_puterror(to_go);
        my_puterror(": Permission denied.\n");
        return (false);
    }
    my_puterror(to_go);
    my_puterror(": No such file or directory.\n");
    return (false);
}

void execute_cd(my_shell_t *shell, char **args)
{
    int pos = 0;
    char *to_go;

    if (args[1] && args[2] && args[2][0] != ' ' && args[2][0] != '\t') {
        my_puterror("cd: Too many arguments.\n");
        shell->return_value = -1;
        return;
    }
    if (!args[1] || my_strcmp(args[1], "~") == 0)
        to_go = get_in_env(shell->env, "HOME", &pos);
    if (args[1]) {
        if (my_strcmp(args[1], "-") == 0 || my_strcmp(args[1], " ") == 0)
            to_go = get_in_env(shell->env, "OLDPWD", &pos);
        else
            to_go = args[1];
    }
    if (!cd_verification(shell, to_go)) {
        shell->return_value = -1;
        return;
    }
    change_path(shell, to_go);
}