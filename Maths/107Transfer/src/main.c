/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** all main function
*/

#include "proto.h"

double transferr(char *str, char *str2, double cran)
{
    char *s = strdup(str);
    char *s2 = strdup(str2);
    char *t = NULL;
    double *num = malloc(sizeof(double) * (my_strlen(str)));
    double *den = malloc(sizeof(double) * (my_strlen(str)));
    double res = 0.0;
    double res2 = 0.0;
    int count = 0;
    int count1 = 0;

    t = strtok(s, "*");
    while (t != NULL) {
        num[count] = my_getnbr(t);
        count++;
        t = strtok(NULL, "*");
    }
    t = strtok(s2, "*");
    while (t != NULL) {
        den[count1] = my_getnbr(t);
        count1++;
        t = strtok(NULL, "*");
    }
    for (int i = 0; i < count; i++) {
        double op = pow(cran, i);
        res += op * num[i];
    }
    for (int i = 0; i < count1; i++) {
        double op = pow(cran, i);
        res2 += op * den[i];
    }
    if (res2 > 0.000000001 || res2 < -0.000000001)
        return (res / res2);
    exit(84);
}

int main(int ac, char *argv[])
{
    if (ac == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        printf("USAGE\n   ./105torus opt a0 a1 a2 a3 a4 n\n\nDESCRIPTION\n   opt       method option:\n                 1 for the bisection method\n                 2 for Newton's method\n                 3 for the secant method\n   a[0-4]    coefficients of the equation\n             precision (the application of the polynomial to the solution should\n             be smaller than 10^-n)\n");
        return (0);
    }
    if (ac < 3) {
        printf("./107torus [num den]\n");
        return (84);
    }
    if (ac > 2 && ac % 2 == 0) {
        my_putstr("Invalid number of args\n");
        exit(84);
    }
    for (int i = 1; i < ac; i++) {
        for (int j = 0; argv[i][j] != '\0'; j++) {
            if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '-' && argv[i][j] != '*') {
                printf("Invalid arguments\n");
                return (84);
            }
        }
    }
    for (double cran = 0.000; cran <= 1.001; cran += 0.001) {
        double res = 1.00;
        double r = 0.00;
        for (int i = 0; i <= (ac - 1) / 2; i += 2) {
            r = transferr(argv[i + 1], argv[i + 2], cran);
            if (r == -1)
                i = 1000;
            res *= r;
        }
        if (r != -1)
            printf("%.3f -> %.5f\n", cran, res);
    }
    return (0);
}
