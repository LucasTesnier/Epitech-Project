/*
** EPITECH PROJECT, 2021
** test.c
** File description:
** tests unitaires
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "shell_loop.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(echo, Basic_one_word, .init=cr_redirect_stdout)
{
    char *args[] = {"echo", "Salut", NULL};

    execute_echo(args);
    cr_assert_stdout_eq_str("Salut\n");
}

Test(echo, Basic_inhib, .init=cr_redirect_stdout)
{
    char *args[] = {"echo", "\\", NULL};

    execute_echo(args);
    cr_assert_stdout_eq_str("\\\n");
}

Test(echo, Basic_inhib_word, .init=cr_redirect_stdout)
{
    char *args[] = {"echo", "test\\;test", NULL};

    execute_echo(args);
    cr_assert_stdout_eq_str("test\\;test\n");
}

Test(echo, Basic_two_words, .init=cr_redirect_stdout)
{
    char *args[] = {"echo", "Salut", "Olaf", NULL};

    execute_echo(args);
    cr_assert_stdout_eq_str("Salut Olaf\n");
}

Test(echo, Basic_none_word, .init=cr_redirect_stdout)
{
    char *args[] = {"echo", NULL};

    execute_echo(args);
    cr_assert_stdout_eq_str("\n");
}

Test(echo, N_one_word, .init=cr_redirect_stdout)
{
    char *args[] = {"echo", "-n", "Salut", NULL};

    execute_echo(args);
    cr_assert_stdout_eq_str("Salut");
}

Test(echo, N_two_words, .init=cr_redirect_stdout)
{
    char *args[] = {"echo", "-n", "Salut", "Olaf", NULL};

    execute_echo(args);
    cr_assert_stdout_eq_str("Salut Olaf");
}

Test(Shell, Setup_Shell, .init=cr_redirect_stdout)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = "SHELL=Test";
    env[1] = "PATH=/bin:/bin/ls";
    my_shell_t *shell = setup_shell(env);

    cr_assert_eq(shell->return_value, 0);
}

Test(Shell_Stack_Fill, classic, .init=cr_redirect_stdout)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = "SHELL=Test";
    env[1] = "PATH=/bin:/bin/ls";
    my_shell_t *shell = setup_shell(env);
    char *command = "ls -l";

    fill_stack(shell, shell->command_stack, command);
    cr_assert_eq(shell->return_value, 0);
}

Test(Shell_Stack_Execute, classic, .init=cr_redirect_stdout)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = "SHELL=Test";
    env[1] = "PATH=/bin:/bin/ls";
    my_shell_t *shell = setup_shell(env);
    char *command = "ls -l";

    fill_stack(shell, shell->command_stack, command);
    execute_stack(shell);
    cr_assert_eq(shell->return_value, 0);
}

Test(Shell_Stack_Execute, separators, .init=cr_redirect_stdout)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = "SHELL=Test";
    env[1] = "PATH=/bin:/bin/ls";
    my_shell_t *shell = setup_shell(env);
    char *command = "ls -l; ls -l";

    fill_stack(shell, shell->command_stack, command);
    execute_stack(shell);
    cr_assert_eq(shell->return_value, 0);
}

Test(Shell_Stack_Execute, redirection_one, .init=cr_redirect_stdout)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = "SHELL=Test";
    env[1] = "PATH=/bin:/bin/ls";
    my_shell_t *shell = setup_shell(env);
    char *command = "ls -l > t; cat t";

    fill_stack(shell, shell->command_stack, command);
    execute_stack(shell);
    cr_assert_eq(shell->return_value, 0);
}

Test(Shell_Stack_Execute, redirection_two, .init=cr_redirect_stdout)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = "SHELL=Test";
    env[1] = "PATH=/bin:/bin/ls";
    my_shell_t *shell = setup_shell(env);
    char *command = "ls -l >> t; cat t";

    fill_stack(shell, shell->command_stack, command);
    execute_stack(shell);
    cr_assert_eq(shell->return_value, 0);
}

Test(Shell_Stack_Execute, redirection_three, .init=cr_redirect_stdout)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = "SHELL=Test";
    env[1] = "PATH=/bin:/bin/ls";
    my_shell_t *shell = setup_shell(env);
    char *command = "grep a < t; cat t";

    fill_stack(shell, shell->command_stack, command);
    execute_stack(shell);
    cr_assert_eq(shell->return_value, 0);
}

Test(Shell_Stack_Execute, cd_one, .init=cr_redirect_stdout)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = "SHELL=Test";
    env[1] = "PATH=/bin:/bin/ls";
    my_shell_t *shell = setup_shell(env);
    char *command = "cd src";

    fill_stack(shell, shell->command_stack, command);
    execute_stack(shell);
    cr_assert_eq(shell->return_value, 0);
}

Test(Shell_Stack_Execute, cd_two, .init=cr_redirect_stdout)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = "SHELL=Test";
    env[1] = "PATH=/bin:/bin/ls";
    my_shell_t *shell = setup_shell(env);
    char *command = "cd src; cd -";

    fill_stack(shell, shell->command_stack, command);
    execute_stack(shell);
    cr_assert_eq(shell->return_value, 0);
}

Test(Shell_Stack_Execute, setenv, .init=cr_redirect_stdout)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = "SHELL=Test";
    env[1] = "PATH=/bin:/bin/ls";
    my_shell_t *shell = setup_shell(env);
    char *command = "setenv coucou a";

    fill_stack(shell, shell->command_stack, command);
    execute_stack(shell);
    cr_assert_eq(shell->return_value, 0);
}

Test(Shell_Stack_Execute, unsetenv, .init=cr_redirect_stdout)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = "SHELL=Test";
    env[1] = "PATH=/bin:/bin/ls";
    my_shell_t *shell = setup_shell(env);
    char *command = "setenv coucou a; unsetenv coucou";

    fill_stack(shell, shell->command_stack, command);
    execute_stack(shell);
    cr_assert_eq(shell->return_value, 0);
}

Test(Shell_Stack_Execute, alias_one, .init=cr_redirect_stdout)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = "SHELL=Test";
    env[1] = "PATH=/bin:/bin/ls";
    my_shell_t *shell = setup_shell(env);
    char *command = "alias a ls; a";

    fill_stack(shell, shell->command_stack, command);
    execute_stack(shell);
    cr_assert_eq(shell->return_value, 0);
}

Test(Shell_Stack_Execute, alias_two, .init=cr_redirect_stdout)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = "SHELL=Test";
    env[1] = "PATH=/bin:/bin/ls";
    my_shell_t *shell = setup_shell(env);
    char *command = "alias a ls; alias a; alias";

    fill_stack(shell, shell->command_stack, command);
    execute_stack(shell);
    cr_assert_eq(shell->return_value, 0);
}

Test(Shell_Stack_Execute, test_and, .init=cr_redirect_stdout)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = "SHELL=Test";
    env[1] = "PATH=/bin:/bin/ls";
    my_shell_t *shell = setup_shell(env);
    char *command = "ls && ls";

    fill_stack(shell, shell->command_stack, command);
    execute_stack(shell);
    cr_assert_eq(shell->return_value, 0);
}

Test(Shell_Stack_Execute, test_or, .init=cr_redirect_stdout)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = "SHELL=Test";
    env[1] = "PATH=/bin:/bin/ls";
    my_shell_t *shell = setup_shell(env);
    char *command = "ls && ls";

    fill_stack(shell, shell->command_stack, command);
    execute_stack(shell);
    cr_assert_eq(shell->return_value, 0);
}

Test(Shell_Stack_Execute, test_and_error, .init=cr_redirect_stdout)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = "SHELL=Test";
    env[1] = "PATH=/bin:/bin/ls";
    my_shell_t *shell = setup_shell(env);
    char *command = "ls &&";

    fill_stack(shell, shell->command_stack, command);
    execute_stack(shell);
    cr_assert_eq(shell->return_value, -1);
}

Test(Shell_Stack_Execute, test_and_or_error, .init=cr_redirect_stdout)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = "SHELL=Test";
    env[1] = "PATH=/bin:/bin/ls";
    my_shell_t *shell = setup_shell(env);
    char *command = "ls && || ls";

    fill_stack(shell, shell->command_stack, command);
    execute_stack(shell);
    cr_assert_eq(shell->return_value, -1);
}

Test(Shell_Stack_Execute, test_and_separator_error, .init=cr_redirect_stdout)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = "SHELL=Test";
    env[1] = "PATH=/bin:/bin/ls";
    my_shell_t *shell = setup_shell(env);
    char *command = "ls && ; ls";

    fill_stack(shell, shell->command_stack, command);
    execute_stack(shell);
    cr_assert_eq(shell->return_value, -1);
}

Test(Shell_Stack_Execute, test_and_redirect_one_error, .init=cr_redirect_stdout)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = "SHELL=Test";
    env[1] = "PATH=/bin:/bin/ls";
    my_shell_t *shell = setup_shell(env);
    char *command = "ls && > ls";

    fill_stack(shell, shell->command_stack, command);
    execute_stack(shell);
    cr_assert_eq(shell->return_value, -1);
}

Test(Shell_Stack_Execute, test_and_redirect_two_error, .init=cr_redirect_stdout)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = "SHELL=Test";
    env[1] = "PATH=/bin:/bin/ls";
    my_shell_t *shell = setup_shell(env);
    char *command = "ls && < ls";

    fill_stack(shell, shell->command_stack, command);
    execute_stack(shell);
    cr_assert_eq(shell->return_value, -1);
}

Test(Shell_Stack_Execute, and_redirect_three_error, .init=cr_redirect_stdout)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = "SHELL=Test";
    env[1] = "PATH=/bin:/bin/ls";
    my_shell_t *shell = setup_shell(env);
    char *command = "ls && << ls";

    fill_stack(shell, shell->command_stack, command);
    execute_stack(shell);
    cr_assert_eq(shell->return_value, -1);
}

Test(Shell_Stack_Execute, and_redirect_four_error, .init=cr_redirect_stdout)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = "SHELL=Test";
    env[1] = "PATH=/bin:/bin/ls";
    my_shell_t *shell = setup_shell(env);
    char *command = "ls && >> ls";

    fill_stack(shell, shell->command_stack, command);
    execute_stack(shell);
    cr_assert_eq(shell->return_value, -1);
}

Test(Shell_Stack_Execute, test_and_pipe_error, .init=cr_redirect_stdout)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = "SHELL=Test";
    env[1] = "PATH=/bin:/bin/ls";
    my_shell_t *shell = setup_shell(env);
    char *command = "ls && | ls";

    fill_stack(shell, shell->command_stack, command);
    execute_stack(shell);
    cr_assert_eq(shell->return_value, -1);
}

Test(Shell_Stack_Execute, test_and_and_error, .init=cr_redirect_stdout)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = "SHELL=Test";
    env[1] = "PATH=/bin:/bin/ls";
    my_shell_t *shell = setup_shell(env);
    char *command = "ls && & ls";

    fill_stack(shell, shell->command_stack, command);
    execute_stack(shell);
    cr_assert_eq(shell->return_value, -1);
}

Test(Shell_Stack_Execute, test_pipe, .init=cr_redirect_stdout)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = "SHELL=Test";
    env[1] = "PATH=/bin:/bin/ls";
    my_shell_t *shell = setup_shell(env);
    char *command = "ls | grep s";

    fill_stack(shell, shell->command_stack, command);
    execute_stack(shell);
    cr_assert_eq(shell->return_value, 0);
}

Test(Shell_Stack_Execute, set_one, .init=cr_redirect_stdout)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = "SHELL=Test";
    env[1] = "PATH=/bin:/bin/ls";
    my_shell_t *shell = setup_shell(env);
    char *command = "set";

    fill_stack(shell, shell->command_stack, command);
    execute_stack(shell);
    cr_assert_eq(shell->return_value, 0);
}

Test(Shell_Stack_Execute, set_two, .init=cr_redirect_stdout)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = "SHELL=Test";
    env[1] = "PATH=/bin:/bin/ls";
    my_shell_t *shell = setup_shell(env);
    char *command = "set test = pwd; $test";

    fill_stack(shell, shell->command_stack, command);
    execute_stack(shell);
    cr_assert_eq(shell->return_value, 0);
}

Test(Shell_Stack_Execute, set_three, .init=cr_redirect_stdout)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = "SHELL=Test";
    env[1] = "PATH=/bin:/bin/ls";
    my_shell_t *shell = setup_shell(env);
    char *command = "set; set tmp test = ls;set test1 = $test; $test1";

    fill_stack(shell, shell->command_stack, command);
    execute_stack(shell);
    cr_assert_eq(shell->return_value, 0);
}

Test(Shell_Stack_Execute, set_four, .init=cr_redirect_stdout)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = "SHELL=Test";
    env[1] = "PATH=/bin:/bin/ls";
    my_shell_t *shell = setup_shell(env);
    char *command = "set test = bonjour; echo $test";

    fill_stack(shell, shell->command_stack, command);
    execute_stack(shell);
    cr_assert_stdout_eq_str("bonjour\n");
    cr_assert_eq(shell->return_value, 0);
}

Test(Shell_Stack_Execute, set_five, .init=cr_redirect_stdout)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = "SHELL=Test";
    env[1] = "PATH=/bin:/bin/ls";
    my_shell_t *shell = setup_shell(env);
    char *command = "set test";

    fill_stack(shell, shell->command_stack, command);
    execute_stack(shell);
    cr_assert_eq(shell->return_value, 0);
}

Test(Shell_Stack_Execute, set_six, .init=cr_redirect_stdout)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = "SHELL=Test";
    env[1] = "PATH=/bin:/bin/ls";
    my_shell_t *shell = setup_shell(env);
    char *command = 
    manage_str("set test=ls tmp=pwd var = bonjour; set new_var=$test;set");

    fill_stack(shell, shell->command_stack, command);
    execute_stack(shell);
    cr_assert_stdout_eq_str("new_var\tls\ntest\tls\ntmp\tpwd\nvar\tbonjour\n");
    cr_assert_eq(shell->return_value, 0);
}

Test(Shell_Stack_Execute, set_seven, .init=cr_redirect_stdout)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = "SHELL=Test";
    env[1] = "PATH=/bin:/bin/ls";
    my_shell_t *shell = setup_shell(env);
    char *command = 
    manage_str("set var=ls; $var | ls;\
    set tmp = abeille && ls; unset tmp || pwd");

    fill_stack(shell, shell->command_stack, command);
    execute_stack(shell);
    cr_assert_eq(shell->return_value, 0);
}

Test(Shell_Stack_Execute, set_eight, .init=cr_redirect_stdout)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = "SHELL=Test";
    env[1] = "PATH=/bin:/bin/ls";
    my_shell_t *shell = setup_shell(env);
    char *command = 
    manage_str("set var=bonjour; $var && ls");

    fill_stack(shell, shell->command_stack, command);
    execute_stack(shell);
    cr_assert_eq(shell->return_value, -1);
}

Test(Shell_Stack_Execute, set_nine, .init=cr_redirect_stdout)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = "SHELL=Test";
    env[1] = "PATH=/bin:/bin/ls";
    my_shell_t *shell = setup_shell(env);
    char *command = 
    manage_str("set var=bonjour; $tmp");

    fill_stack(shell, shell->command_stack, command);
    execute_stack(shell);
    cr_assert_eq(shell->return_value, -1);
}

Test(Shell_Stack_Execute, set_ten, .init=cr_redirect_stdout)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = "SHELL=Test";
    env[1] = "PATH=/bin:/bin/ls";
    my_shell_t *shell = setup_shell(env);
    char *command = 
    manage_str("set var=bonjour tmp = $var");

    fill_stack(shell, shell->command_stack, command);
    execute_stack(shell);
    cr_assert_eq(shell->return_value, -1);
}

Test(Shell_Stack_Execute, unset_one, .init=cr_redirect_stdout)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = "SHELL=Test";
    env[1] = "PATH=/bin:/bin/ls";
    my_shell_t *shell = setup_shell(env);
    char *command = "set test; unset test";

    fill_stack(shell, shell->command_stack, command);
    execute_stack(shell);
    cr_assert_eq(shell->return_value, 0);
}

Test(Shell_Stack_Execute, unset_two, .init=cr_redirect_stdout)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = "SHELL=Test";
    env[1] = "PATH=/bin:/bin/ls";
    my_shell_t *shell = setup_shell(env);
    char *command = "unset test";

    fill_stack(shell, shell->command_stack, command);
    execute_stack(shell);
    cr_assert_eq(shell->return_value, 0);
}

Test(Shell_Stack_Execute, unset_three, .init=cr_redirect_stdout)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = "SHELL=Test";
    env[1] = "PATH=/bin:/bin/ls";
    my_shell_t *shell = setup_shell(env);
    char *command = "unset";

    fill_stack(shell, shell->command_stack, command);
    execute_stack(shell);
    cr_assert_eq(shell->return_value, 0);
}

Test(Shell_Stack_Execute, unset_four, .init=cr_redirect_stdout)
{
    char **env = malloc(sizeof(char *) * 3);
    env[0] = "SHELL=Test";
    env[1] = "PATH=/bin:/bin/ls";
    my_shell_t *shell = setup_shell(env);
    char *command = "set tmp = ls tmp1 = 5 abeille = miel;\
    set var = $abeille; set; unset tmp1 abeille var tmp";

    fill_stack(shell, shell->command_stack, command);
    execute_stack(shell);
    cr_assert_stdout_eq_str("abeille\tmiel\ntmp\tls\ntmp1\t5\nvar\tmiel\n");
    cr_assert_eq(shell->return_value, 0);
}