/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** fill_stack
*/

#include "struct.h"
#include "my.h"
#include "shell_loop.h"
#include <stdlib.h>

int fill_stack_redirection_one(my_command_t *command_stack, char *command)
{
    char **command_parse;
    char **name;

    command_parse = my_strtok(command, ">");
    if (!command_parse[1]) {
        free(command_parse[0]);
        free(command_parse);
        return (0);
    }
    name = my_strtok(command_parse[1], "< ");
    command_stack->command[command_stack->stack_length] = my_strdup(name[0]);
    command_stack->command_type[command_stack->stack_length] = REDIRECTION_ONE;
    command_stack->stack_length += 1;
    free(command_parse[0]);
    free(command_parse[1]);
    free(command_parse);
    return (1);
}

int fill_stack_redirection_two(my_command_t *command_stack, char *command)
{
    char *new_command = my_strdup(command);
    char **command_parse;
    char **name;

    for (int i = 0; i < my_strlen(new_command); i++) {
        if (new_command[i] == '>' && new_command[i + 1] == '>') {
            new_command[i] = '\t';
            new_command[i + 1] = '\t';
        }
    }
    command_parse = my_strtok(new_command, "\t");
    if (!command_parse[1])
        return (0);
    name = my_strtok(command_parse[1], "< ");
    command_stack->command[command_stack->stack_length] = my_strdup(name[0]);
    command_stack->command_type[command_stack->stack_length] = REDIRECTION_TWO;
    command_stack->stack_length += 1;
    return (1);
}

int fill_stack_redirection_three(my_command_t *command_stack, char *command)
{
    char **command_parse;
    char **name;

    command_parse = my_strtok(command, "<");
    if (!command_parse[1]) {
        free(command_parse[0]);
        free(command_parse);
        return (0);
    }
    name = my_strtok(command_parse[1], "> ");
    command_stack->command[command_stack->stack_length] = my_strdup(name[0]);
    command_stack->command_type[command_stack->stack_length] = \
    REDIRECTION_THREE;
    command_stack->stack_length += 1;
    free(command_parse[0]);
    free(command_parse[1]);
    free(command_parse);
    return (1);
}

int fill_stack_redirection_four(my_command_t *command_stack, char *command)
{
    char *new_command = my_strdup(command);
    char **command_parse;
    char **name;

    for (int i = 0; i < my_strlen(new_command); i++) {
        if (new_command[i] == '<' && new_command[i + 1] == '<') {
            new_command[i] = '\t';
            new_command[i + 1] = '\t';
        }
    }
    command_parse = my_strtok(new_command, "\t");
    if (!command_parse[1])
        return (0);
    name = my_strtok(command_parse[1], "> ");
    command_stack->command[command_stack->stack_length] = my_strdup(name[0]);
    command_stack->command_type[command_stack->stack_length] = \
    REDIRECTION_FOUR;
    command_stack->stack_length += 1;
    return (1);
}

void fill_stack_redirection_global(my_command_t *command_stack, char *command)
{
    bool find = false;
    char **command_parse;

    if (fill_stack_redirection_two(command_stack, command) != 1) {
        if (fill_stack_redirection_one(command_stack, command) == 1)
            find = true;
    } else
        find = true;
    if (fill_stack_redirection_four(command_stack, command) != 1) {
        if (fill_stack_redirection_three(command_stack, command) == 1)
            find = true;
    } else
        find = true;
    fill_stack_redirection_write(command_stack, command, find, command_parse);
}