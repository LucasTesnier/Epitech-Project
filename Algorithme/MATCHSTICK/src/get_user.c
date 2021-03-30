/*
** EPITECH PROJECT, 2021
** get_user.c
** File description:
** function for getting user action
*/

#include "proto.h"

void get_str_put(bool is_lines)
{
    if (is_lines == true) {
        my_putstr("Line: ");
    } else {
        my_putstr("Matches: ");
    }
}

char *get_str(bool is_lines)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read = 0;

    while (1) {
        get_str_put(is_lines);
        read = getline(&line, &len, stdin);
        if (read == -1) {
            my_putchar('\n');
            return ("exit");
        }
        if (line[0] == '\n')
            return (NULL);
        if (line[read - 1] == '\n')
            line[read - 1] = '\0';
        return (line);
    }
    return (NULL);
}

int get_action(game_t *game, bool is_lines)
{
    char *action = get_str(is_lines);
    int number = 0;

    if (action == NULL) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (-2);
    }
    if (my_strcmp(action, "exit") == 0)
        return (-1);
    if (my_str_isnum(action) != 1) {
        my_putstr("Error\n");
        return (-2);
    }
    number = my_getnbr(action);
    if (is_lines == true) {
        if (number < 1 || number > game->lines) {
            my_putstr("Error: this line is out of range\n");
            return (get_action(game, true));
        }
    }
    return (number);
}

bool verif_matches(int *action, game_t *game)
{
    if (action[1] > game->max) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(game->max);
        my_putstr(" matches per turn\n");
        return (false);
    }
    if (action[1] <= 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return (false);
    }
    if (get_nbr_stick(game, action[0] - 1) < action[1]) {
        my_putstr("Error: not enough matches on this line\n");
        return (false);
    }
    return (true);
}

int *get_user(game_t *game)
{
    int *action = malloc(sizeof(int) * 2);

    action[0] = get_action(game, true);
    if (action[0] == -1)
        return (NULL);
    if (action[0] == -2)
        return (get_user(game));
    action[1] = get_action(game, false);
    if (action[1] == -1)
        return (NULL);
    if (action[1] == -2 || verif_matches(action, game) == false) {
        return (get_user(game));
    }
    my_putstr("Player removed ");
    my_put_nbr(action[1]);
    my_putstr(" match(es) from line ");
    my_put_nbr(action[0]);
    my_putchar('\n');
    return (action);
}
