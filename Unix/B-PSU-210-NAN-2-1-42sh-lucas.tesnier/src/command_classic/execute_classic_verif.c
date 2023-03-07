/*
** EPITECH PROJECT, 2021
** B-PSU-210-NAN-2-1-42sh-lucas.tesnier
** File description:
** execute_classic_verif
*/

#include "struct.h"
#include "my.h"
#include "shell_loop.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

void shell_error_message(int status)
{
    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == 11)
            my_puterror("Segmentation fault");
        if (WTERMSIG(status) == 8)
            my_puterror("Floating exception");
        if (WCOREDUMP(status))
            my_puterror(" (core dumped)");
        my_putchar('\n');
    }
}

bool classic_command_verif(my_shell_t *shell, char **args)
{
    struct stat sb;

    if (access(args[0], F_OK) != 0) {
        my_puterror(args[0]);
        my_puterror(": Command not found.\n");
        return (false);
    }
    if (access(args[0], X_OK) != 0 || is_directory(args[0]) != false) {
        my_puterror(args[0]);
        my_puterror(": Permission denied.\n");
        return (false);
    }
    stat(args[0], &sb);
    if (sb.st_mode & S_IXUSR) {
        return (true);
    }
    my_puterror(args[0]);
    my_puterror(": Wrong Format\n");
    return (false);
}