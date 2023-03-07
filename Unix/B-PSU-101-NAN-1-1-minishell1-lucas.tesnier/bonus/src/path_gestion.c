/*
** EPITECH PROJECT, 2021
** path_gestion.c
** File description:
** all function for path gestion
*/

#include "proto.h"

void get_last_dir(char *path)
{
    char *new = malloc(sizeof(char) * my_strlen(path));
    int pos = 0;
    int i = 0;
    int count = 0;

    for (i = 0; i < my_strlen(path); i++) {
        if (path[i] == '/')
            count++;
    }
    for (i = 0; i < my_strlen(path); i++) {
        if (path[i] == '/')
            pos += 1;
        if (pos == count)
            break;
    }
    i++;
    pos = 0;
    for (; i < my_strlen(path); i++) {
        new[pos] = path[i];
        pos++;
    }
    new[pos] = '\0';
    my_strncpy(path, new, pos);
    path[pos] = '\0';
}

void put_prompt(char **envp)
{
    int pos = 0;
    char *path = get_in_env(envp, "PWD", &pos);

    get_last_dir(path);
    if (isatty(1) == 1) {
        my_putstr("[/");
        my_putstr(path);
        my_putstr("]$> ");
    }
}

void change_actual(old_commands_t *old_commands, int change)
{
    old_commands->actual -= change;
    if (old_commands->actual < 0)
        old_commands->actual = old_commands->command_nbr - 1;
    else if (old_commands->actual > old_commands->command_nbr - 1)
        old_commands->actual = 0;
    if (old_commands->command_nbr != 0)
        old_commands->to_print = true;
}

char *get_str(old_commands_t *old_commands)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read = 0;

    while (1) {
        if (old_commands->to_print)
            my_putstr(old_commands->old_commands[old_commands->actual]);
        read = getline(&line, &len, stdin);
        if (read == -1) {
            exit(0);
        }
        if (line[0] == '\n' && old_commands->to_print == false)
            return (NULL);
        if (line[read - 1] == '\n')
            line[read - 1] = '\0';
        if (my_strcmp(line, "+") == 0) {
            change_actual(old_commands, -1);
            return (NULL);
        }
        if (my_strcmp(line, "°") == 0) {
            change_actual(old_commands, 1);
            return (NULL);
        }
        if (old_commands->to_print) {
            char *new = malloc(sizeof(char) * my_strlen(old_commands->old_commands[old_commands->actual]) + read + 1);
            new[0] = '\0';
            my_strcat(new, old_commands->old_commands[old_commands->actual]);
            my_strcat(new, line);
            line = new;
        }
        old_commands->to_print = false;
        old_commands->old_commands[old_commands->command_nbr] = my_strdup(line);
        old_commands->command_nbr += 1;
        old_commands->actual = old_commands->command_nbr - 1;
        return (line);
    }
    return (NULL);
}

char *path_detection_three(char *command)
{
    struct stat sb;

    stat(command, &sb);
    if (sb.st_mode & S_IXUSR) {
        return ("a");
    }
    my_putstr(command);
    my_putstr(": Wrong Format\n");
    return ("b");
}

char *path_detection_two(char *command)
{
    if (access(command, X_OK) == 0 && is_directory(command) == false) {
        return (path_detection_three(command));
    } else {
        my_putstr(command);
        my_putstr(": Permission denied.\n");
        return ("b");
    }
}

char *path_detection(char **envp, char *command, int pose)
{
    char **path = segmentation(envp[pose]);
    int save= 0;

    path[0] += 5;
    if (my_str_search(command, '/') == 1) {
        if (access(command, F_OK) == 0) {
            return (path_detection_two(command));
        } else
            return (NULL);
    }
    for (; *path != NULL; path++)
        if (access(prepare_shell(command, *path), F_OK) == 0)
            return (*path);
    return (NULL);
}

char *get_path(char **envp, char *command)
{
    int pose = 0;
    char path[4];

    for (int s = 0; s == 0; pose++) {
        if (my_strlen(envp[pose]) < 3)
            break;
        path[0] = envp[pose][0];
        path[1] = envp[pose][1];
        path[2] = envp[pose][2];
        path[3] = envp[pose][3];
        if (my_strcmp(path, "PATH") == 0) {
            s = 1;
            pose--;
        }
    }
    return (path_detection(envp, command, pose));
}
