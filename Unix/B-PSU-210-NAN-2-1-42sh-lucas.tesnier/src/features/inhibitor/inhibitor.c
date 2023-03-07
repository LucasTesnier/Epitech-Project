/*
** EPITECH PROJECT, 2021
** B-PSU-210-NAN-2-1-42sh-lucas.tesnier
** File description:
** inhibitor
*/
#include "shell_loop.h"
#include <stdlib.h>
#include <string.h>

char *replace_double_bckslash(char *args_line)
{
    char *cpy = malloc(sizeof(char) * (strlen(args_line) + 1));
    int c = 0;

    if (args_line == NULL || cpy == NULL)
        return NULL;
    for (int i = 0; args_line[i] != '\0'; i++) {
        if (args_line[i] == '\\' && args_line[i + 1] != '\\')
            continue;
        cpy[c] = args_line[i];
        c++;
    }
    cpy[c] = '\0';
    return cpy;
}

char *fill_shell_backslash_list(char *command)
{
    int count = 0;
    char *bckslash_str = malloc(sizeof(char) *
    (backslash_counter(command) + 1));

    if (command == NULL || bckslash_str == NULL)
        return NULL;
    for (int i = 0; command[i] != 0; i++) {
        if (command[i] == '\\' && i != (strlen(command) - 1)) {
            bckslash_str[count] = command[i + 1];
            count++;
        }
    }
    bckslash_str[count] = '\0';
    return bckslash_str;
}

char *replace_bckslash(char *command, my_command_t *command_s)
{
    int i = 0;
    char *cpy = malloc(sizeof(char) * (strlen(command) + 1));

    if (cpy == NULL || command == NULL)
        return NULL;
    for (i = 0; command[i] != 0; i++) {
        if (command[i] == '\\') {
            cpy[i] = '\\';
            cpy[i + 1] = '\\';
            i++;
            continue;
        }
        cpy[i] = command[i];
    }
    cpy[i] = 0;
    command_s->backslash_list = fill_shell_backslash_list(command);
    return cpy;
}

void inhibitor(char **args, my_command_t *command_stack)
{
    int count = 0;

    if (command_stack->backslash_list == NULL)
        return;
    for (int i = 0; args[i] != 0; i++) {
        for (int c = 0; args[i][c] != '\0'; c++) {
            if (args[i][c] == '\\') {
                args[i][c + 1] = command_stack->backslash_list[count];
                count++;
            }
        }
        args[i] = replace_double_bckslash(args[i]);
    }
}