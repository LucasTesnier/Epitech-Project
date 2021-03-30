/*
** EPITECH PROJECT, 2020
** B-PSU-101-NAN-1-1-navy-constant.vigneron
** File description:
** ships_checker
*/
#include "navy.h"
#include "my.h"
#include <time.h>

int get_diff(char *pos, char axis)
{
    if (!is_alpha_maj(*pos) || !is_alpha_maj(*(pos + 3))
        || !is_num(*(pos + 1)) || !is_num(*(pos + 4)))
        return (0);

    if (axis == 'x')
        return (ABS((int)(*pos - 'A') - (int)(*(pos + 3) - 'A')));
    return (ABS(my_getnbr(pos + 1) - my_getnbr(pos + 4)));
}

static bool check_pos_set(char *pos)
{
    int x_diff;
    int y_diff;

    if (*pos < '2' || *pos > '5')
        return (false);
    x_diff = get_diff(pos + 2, 'x');
    y_diff = get_diff(pos + 2, 'y');
    if (x_diff < y_diff)
        my_swap(&x_diff, &y_diff);
    if (x_diff + 1 != *pos - '0')
        return (false);
    if ((!x_diff && y_diff) || (x_diff && !y_diff))
        return (true);
    else
        return (false);
}

static bool check_pos_shoot(char *pos)
{
    if (my_strlen(pos) != 3)
        return (false);
    if ((*pos < 'A' || *pos > 'H')
        || (*(pos + 1) - '0') <= 0 || (*(pos + 1) - '0') > 8)
        return (false);
    return (true);
}

bool check_pos(char *pos, int usage)
{
    if (usage == SET)
        return (check_pos_set(pos));
    if (usage == SHOOT)
        return (check_pos_shoot(pos));
    return (false);
}