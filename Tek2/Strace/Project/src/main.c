/*
** EPITECH PROJECT, 2022
** Project
** File description:
** main
*/

#include "strace_init.h"

/**
*@brief main function
*
*@param ac
*@param av
*@param envp
*@return int
*/
int main(int ac, char **av, char **envp)
{
    return strace_start(ac, av, envp);
}
