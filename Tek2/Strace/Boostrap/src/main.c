/*
** EPITECH PROJECT, 2022
** Boostrap
** File description:
** main
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/reg.h>

void do_parent_job(int pid)
{
    long orig_eax;
    int status;

    int count = 0;

    while(1) {
        ptrace(PTRACE_SYSCALL, pid, NULL, NULL);
        waitpid(pid, &status, 0);
        
        
        struct user_regs_struct regs;
        ptrace(PTRACE_GETREGS, pid, 0, &regs);
        long syscall = regs.orig_rax;
        if (count % 2 == 0)
            printf("%ld(%ld, %ld, %ld, %ld, %ld, %ld)", syscall, (long)regs.rdi, (long)regs.rsi, (long)regs.rdx, (long)regs.r10, (long)regs.r8, (long)regs.r9);
        
        //ptrace(PTRACE_GETREGS, pid, 0, &regs);
        if (count % 2 == 0)
            printf(" = %ld\n", (long)regs.rax);

        //ptrace(PTRACE_SYSCALL, pid, NULL, NULL);
        //waitpid(pid, &status, 0);

        if (WIFEXITED(status))
            break;
        count++;
    }
}

void do_child_job(char *process_name, char **envp)
{
    char **args = malloc(sizeof(char *) * 2);
    args[0] = process_name;
    args[1] = NULL;

    ptrace(PTRACE_TRACEME, 0, NULL, NULL);
    execve(process_name, args, envp);
}

int main(int ac, char **av, char **envp)
{
    int pid = fork();

    if (ac != 2)
        return 84;
    if (pid != 0) {
        do_parent_job(pid);
    } else {
        do_child_job(av[1], envp);
    }
}