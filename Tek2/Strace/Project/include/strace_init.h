/*
** EPITECH PROJECT, 2022
** Project
** File description:
** strace_init
*/

#ifndef STRACE_INIT_H_
    #define STRACE_INIT_H_
    #define COMMAND_ERROR -2
    #define PID_ERROR -1

    #include "strace_data.h"

int strace_start(int ac, char **av, char **envp);

#endif /* !STRACE_INIT_H_ */
