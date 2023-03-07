/*
** EPITECH PROJECT, 2022
** strace
** File description:
** strace_flags
*/

#include "strace_flags.h"
#include "strace_flags_tools.h"
#include <string.h>

/**
*@brief search flags in the argument, put his index in flag index
*
*@param args arguments
*@param flag_index index to fill
*@param flag searched flags
*@return true if found, false otherwise
*/
static bool search_flags(char **args, int *flag_index, char *flag)
{
    for (int x = 1; args[x]; x++) {
        if (!strcmp(args[x], flag)) {
            *flag_index = x;
            return true;
        }
    }
    return false;
}

/**
*@brief handle 3 arguments
*
*@param strace_data data needed for strace
*@param args arguments
*@return 0
*/
static int handle_three_flags(strace_data_t *strace_data, char **args)
{
    int res = 0;
    int index = 0;

    if (search_flags(args, &index, "-p")) {
        if (!args[index + 1]) {
            res = 84;
        } else {
            res = handle_pid(strace_data, args[index + 1]);
        }
    }
    if (search_flags(args, &index, "-s")) {
        strace_data->s_option = true;
    }
    if (!strace_data->s_option && (res || !strace_data->p_option))
        strace_data->command = args[1];
    return res;
}

/**
*@brief handle function for 2 arguments
*
*@param strace_data data needed for strace
*@param args arguments
*@return 0
*/
static int handle_two_flags(strace_data_t *strace_data, char **args)
{
    int index = 0;

    if (!strcmp(args[1], "-p")) {
        strace_data->s_option = false;
        return handle_pid(strace_data, args[2]);
    } else if (search_flags(args, &index, "-s")) {
        strace_data->s_option = true;
        strace_data->command = args[(index % 2) + 1];
    } else {
        strace_data->command = args[1];
    }
    return 0;
}

/**
*@brief handle multiple flags
*
*@param strace_data data needed for strace
*@param args arguments
*@param ac nb of arguments
*@return 0 if everything is clear, 84 otherwise
*/
int handle_flags(strace_data_t *strace_data, char **args, int ac)
{
    if (ac == 3) {
        return handle_two_flags(strace_data, args);
    } else {
        return handle_three_flags(strace_data, args);
    }
}
