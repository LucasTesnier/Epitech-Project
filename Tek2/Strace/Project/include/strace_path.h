/*
** EPITECH PROJECT, 2022
** strace
** File description:
** strace_path
*/

#ifndef STRACE_PATH_H_
    #define STRACE_PATH_H_

    #include "strace_data.h"
    #include <stdlib.h>
    #include <string.h>

char **get_paths(char **env);
void free_paths(char **paths);

#endif /* !STRACE_PATH_H_ */
