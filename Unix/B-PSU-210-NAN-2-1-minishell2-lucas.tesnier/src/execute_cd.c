/*
** EPITECH PROJECT, 2021
** bultins.c
** File description:
** all function for bultins
*/

#include "proto.h"

void execute_cd_back_two(char **argv, char **envp, int *pos, char *pwd)
{
    if (access(get_in_env(envp, "OLDPWD", pos), F_OK) == 0 && \
    is_directory(get_in_env(envp, "OLDPWD", pos)) == true) {
        getcwd(pwd, 1000);
        chdir(get_in_env(envp, "OLDPWD", pos));
        replace_var(envp, "OLDPWD", pwd, 1);
        getcwd(pwd, 1000);
        replace_var(envp, "PWD", pwd, 1);
    } else if (access(get_in_env(envp, "OLDPWD", pos), F_OK) == 0 \
    && access(get_in_env(envp, "OLDPWD", pos), R_OK) == 0) {
        my_puterror(get_in_env(envp, "OLDPWD", pos));
        my_puterror(": Not a directory.\n");
    } else if (access(get_in_env(envp, "OLDPWD", pos), F_OK) == 0) {
        my_puterror(get_in_env(envp, "OLDPWD", pos));
        my_puterror(": Permission denied.\n");
    } else {
        if (get_in_env(envp, "OLDPWD", pos) != NULL)
            my_puterror(get_in_env(envp, "OLDPWD", pos));
        my_puterror(": No such file or directory.\n");
    }
}

int execute_cd_back(char **argv, char **envp, int pos, char *pwd)
{
    if (my_strcmp(argv[1], "-") == 0 || my_strcmp(argv[1], " ") == 0) {
        execute_cd_back_two(argv, envp, &pos, pwd);
        return (1);
    }
    return (0);
}

void execute_cd_two(char **argv, char **envp, int pos, char *pwd)
{
    if (execute_cd_back(argv, envp, pos, pwd) == 1)
        return;
    if (access(argv[1], F_OK) == 0 && is_directory(argv[1]) == true) {
        getcwd(pwd, 1000);
        replace_var(envp, "OLDPWD", pwd, 1);
        chdir(argv[1]);
        getcwd(pwd, 1000);
        replace_var(envp, "PWD", pwd, 1);
    } else if (access(argv[1], F_OK) == 0 && access(argv[1], R_OK) == 0) {
        my_puterror(argv[1]);
        my_puterror(": Not a directory.\n");
    } else if (access(argv[1], F_OK) == 0) {
        my_puterror(argv[1]);
        my_puterror(": Permission denied.\n");
    } else {
        my_puterror(argv[1]);
        my_puterror(": No such file or directory.\n");
    }
}

void execute_cd(char **argv, char **envp)
{
    int pos = 0;
    char *pwd = malloc(sizeof(char) * 1000);

    if (argv[2] && argv[2][0] != ' ' && argv[2][0] != '\t') {
        my_puterror("cd: Too many arguments.\n");
        return;
    }
    if (!argv[1] || my_strcmp(argv[1], "~") == 0) {
        getcwd(pwd, 1000);
        replace_var(envp, "OLDPWD", pwd, 1);
        chdir(get_in_env(envp, "HOME", &pos));
        getcwd(pwd, 1000);
        replace_var(envp, "PWD", pwd, 1);
        return;
    }
    execute_cd_two(argv, envp, pos, pwd);
}