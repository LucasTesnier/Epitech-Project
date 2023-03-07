/*
** EPITECH PROJECT, 2022
** Project
** File description:
** strace_data
*/

#ifndef STRACE_DATA_H_
    #define STRACE_DATA_H_

    #include <sys/types.h>
    #include <stdbool.h>

typedef struct strace_data_s {
    char *command;
    bool s_option;
    bool p_option;
    pid_t pid;
} strace_data_t;

strace_data_t *init_strace_data(void);
void strace_data_destroy(strace_data_t *strace_data);

#endif /* !STRACE_DATA_H_ */
