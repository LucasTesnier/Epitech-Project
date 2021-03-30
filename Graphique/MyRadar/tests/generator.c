/*
** EPITECH PROJECT, 2021
** generator.c
** File description:
** generate test file
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int ac, char *argv[])
{
    char sentence[1000];
    FILE *fptr;

    srand(time(NULL));
    fptr = fopen(argv[3], "w");
    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }
    int nbr_a = atoi(argv[1]);
    for (int i = 0; i < nbr_a; i++) {
        int dx = rand() % 1920;
        int dy = rand() % 1080;
        int ax = rand() % 1920;
        int ay = rand() % 1080;
        int speed = rand() % 20 + 1;
        int time = rand() % 10;
        fprintf(fptr, "A  %i %i  %i %i  %i  %i\n", dx, dy, ax, ay, speed, time);
    }
    int nbr_t = atoi(argv[2]);
    for (int i = 0; i < nbr_t; i++) {
        int tx = rand() % 1920;
        int ty = rand() % 1080;
        int r = rand() % 20 + 1;
        fprintf(fptr, "T  %i %i  %i\n", tx, ty, r);
    }
    fclose(fptr);
    return 0;
}
