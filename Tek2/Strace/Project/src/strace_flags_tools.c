/*
** EPITECH PROJECT, 2022
** strace
** File description:
** strace_flags_tools
*/

#include "strace_flags_tools.h"
#include <ctype.h>
#include <stdlib.h>

/**
*@brief verify is a string is a number
*
*@param str data needed for strace
*@return 0
*/
static bool is_number(char *str)
{
    for (size_t x = 0; str[x]; x++) {
        if (!isdigit(str[x]))
            return false;
    }
    return true;
}

/**
*@brief verify if str_pid and store it it strace_date
*
*@param strace_data data needed for strace
*@param str_pid pid in string
*@return 0
*/
int handle_pid(strace_data_t *strace_data, char *str_pid)
{
    strace_data->p_option = true;
    if (!is_number(str_pid))
        return 84;
    strace_data->pid = atoi(str_pid);
    return 0;
}
