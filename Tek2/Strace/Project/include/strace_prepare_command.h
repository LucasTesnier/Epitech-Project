/*
** EPITECH PROJECT, 2022
** strace
** File description:
** strace_prepare_command
*/

#ifndef STRACE_PREPARE_COMMAND_H_
    #define STRACE_PREPARE_COMMAND_H_

    #include <sys/stat.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <string.h>

char *prepare_command(char *raw_command, char **env);

#endif /* !STRACE_PREPARE_COMMAND_H_ */
