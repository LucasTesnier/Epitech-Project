/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** prototypes of all the function on the lib
*/

#include "struct.h"
#include "my.h"
#include "shell_loop.h"
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

st_local_var *init_local_var(st_local_var *local_var)
{
    local_var = malloc(sizeof(st_local_var));
    local_var->data = NULL;
    local_var->name = NULL;
    local_var->next = NULL;
    return (local_var);
}

my_command_t *setup_command_stack(void)
{
    my_command_t *command_stack = malloc(sizeof(my_command_t));

    command_stack->command = malloc(sizeof(char *) * MAX_STACK_LENGTH);
    command_stack->stack_length = 0;
    command_stack->command_type = malloc\
    (sizeof(command_type_e) * MAX_STACK_LENGTH);
    return (command_stack);
}

alias_list_t *setup_alias_list(void)
{
    alias_list_t *alias_list = malloc(sizeof(alias_list_t));

    alias_list->nbr = 0;
    alias_list->alias = malloc(sizeof(my_alias_t) * 10000);
}

my_shell_t *setup_shell(char **main_env)
{
    my_shell_t *shell = malloc(sizeof(my_shell_t));

    shell->hist = my_hist_list_create();
    shell->line = my_line_list_create();
    shell->hist_id = 0;
    shell->temp_line = 0;
    shell->prompt = 0;
    shell->local_var = init_local_var(shell->local_var);
    shell->env = copy_env(main_env);
    shell->command_stack = setup_command_stack();
    shell->alias_list = setup_alias_list();
    shell->status = GO_STATUS;
    shell->process_status = 0;
    shell->return_value = 0;
    return (shell);
}

int shell_setup(char **main_env)
{
    int return_value = 0;
    my_shell_t *shell = setup_shell(main_env);

    if (!isatty(0))
        return_value = shell_loop(shell);
    else
        return_value = shell_loop_upgraded(shell);
    free_shell(shell);
    free(shell);
    return (return_value);
}