/*
** EPITECH PROJECT, 2022
** strace
** File description:
** strace_help
*/

#include "strace_uniq_command.h"
#include <string.h>
#include <stdio.h>

/**
*@brief print the usage in the standard output
*/
static void display_help(void)
{
    puts("USAGE: ./strace [-s] [-p <pid> | <command>]");
}

/**
*@brief handle one argument
*
*@param strace_data data needed for strace
*@param command first argument
*@return 0 if the command is valid, 84 otherwise
*/
int handle_unique_command(strace_data_t *strace_data, char *command)
{
    if (!strcmp(command, "--help")) {
        display_help();
        return 1;
    } else if (command[0] == '-') {
        return 84;
    } else {
        strace_data->command = command;
    }
    return 0;
}
