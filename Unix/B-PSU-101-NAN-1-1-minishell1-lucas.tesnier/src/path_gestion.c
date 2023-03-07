/*
** EPITECH PROJECT, 2021
** path_gestion.c
** File description:
** all function for path gestion
*/

#include "proto.h"

void put_prompt(void)
{
    my_putstr("LT> ");
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