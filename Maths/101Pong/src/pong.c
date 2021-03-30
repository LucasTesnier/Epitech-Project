/*
** EPITECH PROJECT, 2020
** pong.c
** File description:
** pong file
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int pong(char *cp_x, char *cp_y, char *cp_z, char *t_x, char *t_y, char *t_z, char *ctime)
{
    float velocity[3] = {0};
    float pos[3] = {0};
    float post[3] = {0};
    float p_x = atof(cp_x);
    float p_y = atof(cp_y);
    float p_z = atof(cp_z);
    int time = atoi(ctime);
    int touch = 0;
    float norme = 0.0;
    float norme_ecr = 0.0;
    float result = 0.0;

    pos[0] = atof(t_x);
    pos[1] = atof(t_y);
    pos[2] = atof(t_z);
    
    velocity[0] = pos[0] - p_x;
    velocity[1] = pos[1] - p_y;
    velocity[2] = pos[2] - p_z;
    printf("The velocity vector of the ball is:\n(%.2f, %.2f, %.2f)\n", velocity[0], velocity[1], velocity[2]);
    post[0] = pos[0];
    post[1] = pos[1];
    post[2] = pos[2];
    for (int i = 0; i < time; i++) {
        post[0] += velocity[0];
        post[1] += velocity[1];
        post[2] += velocity[2];
    }
    printf("At time t + %i, ball coordinates will be:\n(%.2f, %.2f, %.2f)\n", time, post[0], post[1], post[2]);
    if ((pos[2] >= 0 && velocity[2] < 0) || (pos[2] <= 0 && velocity[2] > 0)) 
        touch = 1;
    if (pos[2] == 0 && velocity[2] == 0)
        touch = 1;
    if (touch == 1) {
        norme = sqrt(pow(velocity[0], 2) + pow(velocity[1], 2) + pow(velocity[2], 2));
        norme_ecr = sqrt(pow(velocity[0], 2) + pow(velocity[1], 2));
        result = acos(norme_ecr / norme);
        result = result * 180.0 / M_PI;
        if (result > 90)
            result = (result - 180) * - 1;
        printf("The incidence angle is:\n%.2f degrees\n", result);
    } else {
        printf("The ball won't reach the paddle.\n");
    }
    return (0);
}
