/*
** EPITECH PROJECT, 2021
** execute_classic.c
** File description:
** execute_classic
*/

#include "shell_loop.h"
#include "my.h"

void execute_classic(int size, my_shell_t *shell, my_command_t \
*command_stack, int *pos)
{
    char **args = my_strtok(local_var_replace(alias_replace
    (command_stack->command[*pos], shell->alias_list), shell), " ");
    char *bultin_list[] = {"env", "setenv", "unsetenv", "echo", \
        "cd", "exit", "alias", "unalias", "set", "unset", NULL};

    if (!args || !args[0]) {
        *pos += 1;
        return;
    }
    args = globbings(args);
    if (check_bckslash_presence(args) != 0)
        inhibitor(args, command_stack);
    if (args == NULL) {
        *pos += 1;
        return;
    }
    if (my_str_two_search(args[0], bultin_list) == true)
        execute_bultin(size, args, shell);
    else
        execute_classic_command(size, args, shell);
    *pos += 1;
}