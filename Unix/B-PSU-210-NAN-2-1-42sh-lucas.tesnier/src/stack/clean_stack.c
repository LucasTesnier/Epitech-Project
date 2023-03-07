/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** clean_stack
*/

#include "struct.h"
#include "my.h"
#include "shell_loop.h"
#include <stdlib.h>

char *stack_clean_command(char *command)
{
    char *clean_command = malloc(sizeof(char) * (my_strlen(command) + 1));
    char **command_parse = my_strtok(command, " \t");

    clean_command[0] = '\0';
    for (int i = 0; command_parse[i]; i++) {
        my_strcat(clean_command, my_strdup(command_parse[i]));
        if (command_parse[i + 1])
            my_strcat(clean_command, " ");
        free(command_parse[i]);
    }
    free(command_parse);
    return (clean_command);
}

void get_a_new_stack(my_command_t *command_stack, my_shell_t *shell)
{
    char *command = NULL;

    for (int i = 0; i < command_stack->stack_length; i++)
        free(command_stack->command[i]);
    command_stack->stack_length = 0;
    put_prompt(shell);
    command = manage_str(get_str());
    if (backslash_counter(command) != 0)
        command = replace_bckslash(command, command_stack);
    if (command == NULL) {
        get_a_new_stack(command_stack, shell);
        return;
    }
    if (fill_stack(shell, command_stack, command) == -1) {
        free(command);
        get_a_new_stack(command_stack, shell);
        return;
    }
    free(command);
}

void get_a_new_stack_upgraded(my_command_t *command_stack, my_shell_t *shell)
{
    char *command = NULL;

    for (int i = 0; i < command_stack->stack_length; i++)
        free(command_stack->command[i]);
    command_stack->stack_length = 0;
    command = manage_str(get_str_char_per_char(shell));
    if (backslash_counter(command) != 0)
        command = replace_bckslash(command, command_stack);
    if (command == NULL) {
        get_a_new_stack(command_stack, shell);
        return;
    }
    if (fill_stack(shell, command_stack, command) == -1) {
        free(command);
        get_a_new_stack(command_stack, shell);
        return;
    }
    free(command);
}