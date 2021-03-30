/*
** EPITECH PROJECT, 2020
** my_radar_setup.c
** File description:
** all setup fonction needed for the radar
*/

#include "proto.h"

void planes_collect(axe_t *ax, plane_t *planes, char **stock, int *count)
{
    planes_collect_parsing(ax, planes, stock, count);
    planes[*count].speed = my_getnbr(stock[ax->i] + ax->j) / 32.0;
    planes[*count].speedy = (abs(planes[*count].arrival.y - \
    planes[*count].departure.y) * planes[*count].speed) / \
    (abs(planes[*count].arrival.x - planes[*count].departure.x) + \
    abs(planes[*count].arrival.y - planes[*count].departure.y));
    planes[*count].speedx = planes[*count].speed - \
    fabs(planes[*count].speedy);
    for (; stock[ax->i][ax->j] == ' ' || stock[ax->i][ax->j] == '\t'; ax->j++);
    for (; stock[ax->i][ax->j] != ' ' && stock[ax->i][ax->j] != '\t'; ax->j++);
    planes[*count].limit = my_getnbr(stock[ax->i] + ax->j);
    planes[*count].is_air = 0;
    if (planes[*count].limit == 0)
        planes[*count].is_air = 1;
    *count += 1;
}

plane_t *make_plane(char **stock, int length)
{
    plane_t *planes;
    int number_plane = 0;
    int count = 0;
    axe_t axe;

    for (int i = 0; i < length; i++)
        if (stock[i][0] == 'A')
            number_plane++;
    planes = malloc(sizeof(plane_t) * (number_plane + 1));
    for (axe.i = 0; axe.i < length; axe.i++) {
        axe.j = 0;
        if (stock[axe.i][axe.j] == 'A') {
            planes_collect(&axe, planes, stock, &count);
        }
    }
    planes[count].is_air = -1;
    return (planes);
}

int radar_setup(int ac, char *argv[], user_t user)
{
    char **stock;
    plane_t *planes;
    tower_t *towers;
    int length = 0;

    stock = verification(ac, argv, &length);
    if (stock == NULL)
        return (84);
    planes = make_plane(stock, length);
    if (planes == NULL)
        return (84);
    towers = make_tower(stock, length);
    if (towers == NULL)
        return (84);
    radar_screen(planes, towers, user);
    return (0);
}
