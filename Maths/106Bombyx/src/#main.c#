/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** all main function
*/

#include "proto.h"

void bombyx_two(int ac, char **argv)
{
    double n = atof(argv[1]);
    int i_one = atoi(argv[2]);
    int i_two = atoi(argv[3]);
    double k = 1;
    double x = n;

    if (i_two < i_one)
        exit (84);
    if (i_two < 0 || i_one < 0)
        exit (84);
    for (; k <= 4; k += 0.01) {
        x = n;
        for (int i = 1; i <= i_two; i++) {
            if (i >= i_one) {
                if (x > 0)
                    printf("%.2f %.2f\n", k, x);
                else
                    printf("%.2f 0.00\n", k);
            }
            x = k * x * ((1000.0 - x) / 1000.0);
        }
    }
}

void bombyx(int ac, char **argv)
{
    double n = atof(argv[1]);
    double k = atof(argv[2]);
    double x = n;

    if (n < 0)
        exit(84);
    if (k < 1 || k > 4)
        exit (84);
    printf("1 %.2f\n", x);
    for (int i = 2; i <= 100; i++) {
        x = k * x * ((1000.0 - x) / 1000.0);
        if (x > 0)
            printf("%i %.2f\n", i, x);
        else
            printf("%i 0.00\n");
    }
}

int main(int ac, char *argv[])
{
    if (ac == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        printf("USAGE\n   ./105torus opt a0 a1 a2 a3 a4 n\n\nDESCRIPTION\n   opt       method option:\n                 1 for the bisection method\n                 2 for Newton's method\n                 3 for the secant method\n   a[0-4]    coefficients of the equation\n             precision (the application of the polynomial to the solution should\n             be smaller than 10^-n)\n");
        return (0);
    }
    if (ac != 3 && ac != 4) {
        printf("./106torus n [k | i0 i1]\n");
        return (84);
    }
    for (int i = 1; i < ac; i++) {
        for (int j = 0; argv[i][j] != '\0'; j++) {
            if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '-' && argv[i][j] != '+' && argv[i][j] != '.') {
                printf("Invalid arguments");
                return (84);
            }
        }
    }
    if (ac == 3)
        bombyx(ac, argv);
    if (ac == 4)
        bombyx_two(ac, argv);
    return (0);
}
