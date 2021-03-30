/*
** EPITECH PROJECT, 2021
** verif_and_collect.c
** File description:
** verfi and collect fonction
*/

#include "proto.h"

int verif_pos(char **stock, int i)
{
    int count = 0;

    if (stock[i][0] != 'A' && stock[i][0] != 'T') {
        write(2, "Invalid setup", 13);
        return (-1);
    }
    for (int j = 1; j < my_strlen(stock[i]) - 1; j++) {
        if ((stock[i][j] < '0' || stock[i][j] > '9') && \
            stock[i][j] != ' ' && stock[i][j] != '\t')
            return (-1);
        if (stock[i][j] == ' ' && stock[i][j + 1] >= '0' && \
            stock[i][j + 1] <= '9')
            count++;
    }
    if (stock[i][0] == 'T' && count != 3)
        return (-1);
    if (stock[i][0] == 'A' && count != 6)
        return (-1);
    return (0);
}

char **verification(int ac, char *argv[], int *lengthp)
{
    char *buffer = load_file_in_mem(argv[1]);
    char **stock;

    if (buffer == NULL)
        return (NULL);
    for (int i = 0; i < my_strlen(buffer); i++)
        if (buffer[i] == '\n')
            *lengthp += 1;
    stock = mem_alloc_2d_array(*lengthp + 1, 100);
    sort_informations(buffer, stock, *lengthp);
    for (int i = 0; i < *lengthp; i++) {
        if (verif_pos(stock, i) == -1)
            return (NULL);
    }
    return (stock);
}

void tower_collect(axe_t *ax, tower_t *towers, char **stock, int *count)
{
    float save;

    for (; stock[ax->i][ax->j] != ' ' && stock[ax->i][ax->j] != '\t'; ax->j++);
    towers[*count].position.x = my_getnbr(stock[ax->i] + ax->j);
    for (; stock[ax->i][ax->j] == ' ' || stock[ax->i][ax->j] == '\t'; ax->j++);
    for (; stock[ax->i][ax->j] != ' ' && stock[ax->i][ax->j] != '\t'; ax->j++);
    towers[*count].position.y = my_getnbr(stock[ax->i] + ax->j);
    for (; stock[ax->i][ax->j] == ' ' || stock[ax->i][ax->j] == '\t'; ax->j++);
    for (; stock[ax->i][ax->j] != ' ' && stock[ax->i][ax->j] != '\t'; ax->j++);
    save = my_getnbr(stock[ax->i] + ax->j);
    towers[*count].radius = save * 1920 / 100;
    *count += 1;
}

tower_t *make_tower(char **stock, int length)
{
    tower_t *towers;
    int number_tower = 0;
    int count = 0;
    axe_t axe;

    for (int i = 0; i < length; i++)
        if (stock[i][0] == 'T')
            number_tower++;
    towers = malloc(sizeof(tower_t) * (number_tower + 1));
    for (axe.i = 0; axe.i < length; axe.i++) {
        axe.j = 0;
        if (stock[axe.i][axe.j] == 'T')
            tower_collect(&axe, towers, stock, &count);
    }
    towers[count].radius = -1;
    return (towers);
}

void planes_collect_parsing(axe_t *ax, plane_t *planes, char **stock, \
int *count)
{
    for (; stock[ax->i][ax->j] != ' ' && stock[ax->i][ax->j] != '\t'; ax->j++);
    planes[*count].departure.x = my_getnbr(stock[ax->i] + ax->j);
    for (; stock[ax->i][ax->j] == ' ' || stock[ax->i][ax->j] == '\t'; ax->j++);
    for (; stock[ax->i][ax->j] != ' ' && stock[ax->i][ax->j] != '\t'; ax->j++);
    planes[*count].departure.y = my_getnbr(stock[ax->i] + ax->j);
    for (; stock[ax->i][ax->j] == ' ' || stock[ax->i][ax->j] == '\t'; ax->j++);
    for (; stock[ax->i][ax->j] != ' ' && stock[ax->i][ax->j] != '\t'; ax->j++);
    planes[*count].arrival.x = my_getnbr(stock[ax->i] + ax->j);
    for (; stock[ax->i][ax->j] == ' ' || stock[ax->i][ax->j] == '\t'; ax->j++);
    for (; stock[ax->i][ax->j] != ' ' && stock[ax->i][ax->j] != '\t'; ax->j++);
    planes[*count].arrival.y = my_getnbr(stock[ax->i] + ax->j);
    for (; stock[ax->i][ax->j] == ' ' || stock[ax->i][ax->j] == '\t'; ax->j++);
    for (; stock[ax->i][ax->j] != ' ' && stock[ax->i][ax->j] != '\t'; ax->j++);
}
