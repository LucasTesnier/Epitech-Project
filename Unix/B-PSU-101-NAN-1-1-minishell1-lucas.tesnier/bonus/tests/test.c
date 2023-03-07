/*
** EPITECH PROJECT, 2021
** test.c
** File description:
** tests unitaires
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "proto.h"

Test(minishell, exit, .init=cr_redirect_stdout)
{
    char **envp;
    char *command = "exit";

    execute_bultin(command, envp);
    cr_assert_stdout_eq_str("exit\n");
}

Test(minishell, env)
{
    char **envp = malloc(sizeof(char *) * 2);
    char *command = "env";

    cr_assert_eq(execute_bultin(command, envp), 1);
}

Test(minishell, cd_home)
{
    char **envp = malloc(sizeof(char *) * 1);
    char *command = "cd";

    cr_assert_eq(execute_bultin(command, envp), 1);
}

Test(minishell, cd_prec)
{
    char **envp = malloc(sizeof(char *) * 1);
    char *command = "cd -";

    cr_assert_eq(execute_bultin(command, envp), 1);
}

Test(minishell, cd_src)
{
    char **envp = malloc(sizeof(char *) * 1);
    char *command = "cd src/";

    cr_assert_eq(execute_bultin(command, envp), 1);
}

Test(minishell, setenv)
{
    char **envp = malloc(sizeof(char *) * 1);
    char *command = "setenv";

    cr_assert_eq(execute_bultin(command, envp), 1);
}

Test(minishell, setenv_already)
{
    char **envp = malloc(sizeof(char *) * 2);
    char *command = "setenv SHELL coucou";

    envp[1] = "SHELL=Test";
    envp[0] = "PATH=/bin:/bin/ls";
    cr_assert_eq(execute_bultin(command, envp), 1);
}

Test(minishell, unset_env_no)
{
    char **envp = malloc(sizeof(char *) * 1);
    char *command = "unsetenv";

    cr_assert_eq(execute_bultin(command, envp), 1);
}

Test(minishell, unset_env)
{
    char **envp = malloc(sizeof(char *) * 1);
    char *command = "unsetenv PATH";

    cr_assert_eq(execute_bultin(command, envp), 1);
}

Test(minishell, ls)
{
    char **envp = malloc(sizeof(char *) * 3);
    char *command = "ls";

    envp[0] = "SHELL=Test";
    envp[1] = "PATH=/bin:/bin/ls";
    cr_assert_eq(shell_execute_command(envp, command), 0);
}

Test(minishell, ls_args)
{
    char **envp = malloc(sizeof(char *) * 3);
    char command[] = "ls     -l\t";

    envp[0] = "SHELL=Test";
    envp[1] = "PATH=/bin:/bin/ls";
    cr_assert_eq(shell_execute_command(envp, command), 0);
}

Test(minishell, ls_path)
{
    char **envp = malloc(sizeof(char *) * 3);
    char command[] = "./bin/ls";

    envp[0] = "SHELL=Test";
    envp[1] = "PATH=/bin:/bin/ls";
    cr_assert_eq(shell_execute_command(envp, command), 0);
}
