/*
** EPITECH PROJECT, 2022
** Project
** File description:
** strace_data
*/

#include "strace_data.h"
#include <stdlib.h>
#include <stddef.h>

/**
*@brief create a strace_data_t
*
*@return strace_data_t*
*/
strace_data_t *init_strace_data(void)
{
    strace_data_t *new_data = malloc(sizeof(strace_data_t));

    if (new_data == NULL)
        return NULL;
    new_data->s_option = false;
    new_data->p_option = false;
    new_data->command = NULL;
    new_data->pid = 0;
    return new_data;
}

/**
*@brief destroy an strace_data_t
*
*@param strace_data
*/
void strace_data_destroy(strace_data_t *strace_data)
{
    if (strace_data) {
        free(strace_data);
    }
}
