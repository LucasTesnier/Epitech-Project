/*
** EPITECH PROJECT, 2021
** bultins.c
** File description:
** all function for bultins
*/

#include "struct.h"
#include "my.h"
#include "shell_loop.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void put_prompt(my_shell_t *shell)
{
    int pos = 0;
    char *pwd;

    if (isatty(0) == 1) {
        pwd = get_in_env(shell->env, "PWD", &pos);
        if (pwd != NULL) {
            my_putstr("[");
            my_putstr(pwd);
            my_putstr("] ");
        }
        my_putstr("My_Shell > ");
    }
}

char *get_prompt(my_shell_t *shell)
{
    int pos = 0;
    char *pwd;
    char *prompt = 0;

    if (isatty(0) == 1) {
        pwd = get_in_env(shell->env, "PWD", &pos);
        prompt = my_calloc_char(sizeof(char), my_strlen(pwd) + \
        my_strlen("[]My_Shell > "), 0);
        if (pwd != NULL && prompt) {
            my_strcat(prompt, "[");
            my_strcat(prompt, pwd);
            my_strcat(prompt, "]");
        }
        if (prompt)
            my_strcat(prompt, "My_Shell > ");
    }
    return (prompt);
}

char *get_str(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read = 0;

    while (1) {
        read = getline(&line, &len, stdin);
        if (read == -1) {
            exit(0);
        }
        if (line[0] == '\n')
            return (NULL);
        if (line[read - 1] == '\n')
            line[read - 1] = '\0';
        return (line);
    }
    return (NULL);
}

void put_terminal_in_raw_mode(my_shell_t *shell)
{
    tcgetattr(STDIN_FILENO, &shell->old);
    shell->raw = shell->old;
    shell->raw.c_lflag &= (~(ICANON|ECHO));
    shell->raw.c_cc[VTIME] = 0;
    shell->raw.c_cc[VMIN] = 1;
    tcsetattr(0, TCSANOW, &shell->raw);
}

char *get_str_char_per_char(my_shell_t *shell)
{
    char *command = 0;
    char c;

    put_terminal_in_raw_mode(shell);
    write_line(shell);
    while (!command) {
        read(STDIN_FILENO, &c, 1);
        if (c >= 32 && c < 127) {
            write(1, &c, 1);
            my_line_list_add_before_cursor(shell->line, c);
            erase_line(shell);
            write_line(shell);
        } else
            command = c_manage_2(shell, c);
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &shell->old);
    return (command);
}