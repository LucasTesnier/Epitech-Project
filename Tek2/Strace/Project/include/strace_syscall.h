/*
** EPITECH PROJECT, 2022
** Project
** File description:
** strace_syscall
*/

#ifndef STRACE_SYSCALL_H_
    #define STRACE_SYSCALL_H_

    #include <sys/reg.h>
    #include <sys/user.h>
    #include <sys/types.h>
    #include "syscall.h"

void fill_actual_signal_with_regs_value(struct user_regs_struct regs,
syscall_t *actual_signal);
int get_matching_reg(syscall_t actual_signal, int i);
void display_actual_signal(syscall_t actual_signal);
void matching_actual_signal_with_signal_table(syscall_t *actual_signal);
void next_signal(int *status, pid_t pid, struct user_regs_struct *regs);

#endif /* !STRACE_SYSCALL_H_ */
