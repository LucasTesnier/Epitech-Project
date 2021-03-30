/*
** EPITECH PROJECT, 2021
** colision_and_clock.c
** File description:
** function for colision and clock
*/

#include "proto.h"

int is_intersecting_circles(tower_t *towers, sfVector2f pos2)
{
    sfVector2f center;
    float radius;
    float f2 = 10;

    for (int k = 0; towers[k].radius != -1; k++) {
        center = sfCircleShape_getPosition(towers[k].hitbox);
        radius = sfCircleShape_getRadius(towers[k].hitbox);
        if (pow((pos2.x - center.x), 2) + pow((pos2.y - center.y), 2) <=  \
            pow(radius, 2))
            return (1);
    }
    return (0);
}

void colision(plane_t *plane, int j, plane_t *planes, tower_t *towers)
{
    sfVector2f pos;

    for (int i = 0; planes[i].is_air != -1; i++) {
        if (i == j)
            i++;
        pos.x = plane->departure.x;
        pos.y = plane->departure.y;
        if ((int) plane->departure.x >= (int) planes[i].departure.x && (int) \
        plane->departure.x <= (int) planes[i].departure.x + 20 && (int) \
        plane->departure.y >= (int) planes[i].departure.y && (int) \
        plane->departure.y <= (int) planes[i].departure.y + 20 && \
        planes[i].is_air == 1 && planes[i].is_air == 1) {
            if (is_intersecting_circles(towers, pos) == 0) {
                plane->is_air = 2;
                planes[i].is_air = 2;
            }
        }
    }
}

char *my_getstr(int nb, char *str, int *count)
{
    if (nb >= 10)
        my_getstr(nb / 10, str, count);
    str[*count] = ((nb % 10) + 48);
    *count += 1;
    return (str);
}

void display_clock(sfRenderWindow *window, timer_clock_t clock, \
text_opt_t opt, plane_t *planes)
{
    sfTime time = sfClock_getElapsedTime(clock.clock);
    char *str = malloc(sizeof(char) * 10000);
    int size = 0;
    int str_nb = time.microseconds / 1000000.0 - (clock.time_lost / 32.0);

    my_getstr(str_nb, str, &size);
    str[size] = '\0';
    sfText_setString(opt.timer, str);
    sfRenderWindow_drawText(window, opt.timer, NULL);
    sfRenderWindow_drawText(window, opt.sprite_opt, NULL);
    sfRenderWindow_drawText(window, opt.hitbox_opt, NULL);
    for (int i = 0; planes[i].is_air != -1; i++) {
        if (planes[i].is_air == 0 && planes[i].limit <= str_nb)
            planes[i].is_air = 1;
    }
}

void rotation_planes(plane_t *planes, int i)
{
    if (planes[i].arrival.x < planes[i].departure.x) {
        planes[i].departure.x -= planes[i].speedx;
    }
    if (planes[i].arrival.x > planes[i].departure.x) {
        planes[i].departure.x += planes[i].speedx;
    }
    if (planes[i].arrival.y < planes[i].departure.y) {
        planes[i].departure.y -= planes[i].speedy;
    }
    if (planes[i].arrival.y > planes[i].departure.y) {
        planes[i].departure.y += planes[i].speedy;
    }
}
