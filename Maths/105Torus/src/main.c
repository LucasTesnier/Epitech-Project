/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** all main function
*/

#include "proto.h"

double f(double a, double b, double c, double d, double e, double x)
{
    return ((e * pow(x, 4)) + (d * pow(x, 3)) + (c * pow(x, 2)) + (b * x) + a);
}

int stop_bis(double a, double b, double c, double d, double e, int n, double x)
{
    if (x < 0)
        x = x * -1;
    if (x == 0 || x <= pow(10, n * -1))
        return (1);
    return (0);
}

int check_bis(double a, double b, double c, double d, double e, int n, double x)
{
    double res = 0;

    res = f(a, b, c, d, e, x);
    if (res == 0) {
        printf("x = %.0f\n", x);
        return (1);
    }
    return (0);
}

void bisection(double a, double b, double c, double d, double e, int n)
{
    double f_pt = 0.0;
    double s_pt = 1.0;
    double f_x = 0;
    double s_x = 0;
    double x = 0;

    if (check_bis(a, b, c, d, e, n, f_pt) == 1)
        return;
    if (check_bis(a, b, c, e, e, n, f_pt) == 1)
        return;
    for (int i = 1; i < 500; i++) {
        x = (f_pt + s_pt) / 2;
        if (i <= n) {
            printf("x = %.*f\n", i, x);
        } else {
            printf("x = %.*f\n", n, x);
        }
        f_x = f(a, b, c, d, e, x);
        s_x = f(a, b, c, d, e, f_pt);
        if (stop_bis(a, b, c, d, e, n, f_x) == 1)
            return;
        if (s_x * f_x != 0) {
            if (s_x * f_x < 0) {
                s_pt = x;
            } else {
                f_pt = x;
            }
        }
    }
}

int stop_secant(double f_pt, double s_pt, int n)
{
    double res = f_pt - s_pt;

    //printf("res : %f, precision %f\n", res, pow(10, n * -1));
    if (res < 0)
        res *= -1;
    if (res <= pow(10, (n - 1) * -1))
        return (1);
    return (0);
}

void secant(double a, double b, double c, double d, double e, int n)
{
    double f_pt = 0;
    double s_pt = 1;
    double f_x = 0;
    double s_x = 0;
    double x = 0;
    double trash = 0;

    if (f(a, b, c, d, e, f_pt) == 0) {
        printf("x = %.0f\n", f_pt);
        return;
    }
    if (f(a,b, c, d, e, s_pt) == 0) {
        printf("x = %.0f\n", s_pt);
        return;
    }
    for (int i = 1; i < 500; i++) {
        f_x = f(a, b, c, d, e, f_pt);
        s_x = f(a, b, c, d, e, s_pt);
        if ((s_x - f_x) == 0) {
            exit (0);
        }
        x = s_pt - (s_x * (s_pt - f_pt) / (s_x - f_x));
        if (stop_secant(f_pt, s_pt, n) == 1)
            break;
        if (n > 8) {
            if (modf(x * pow(10, n), &trash) * 1000000 == 0) {
                printf("x = %.*g\n", n, x);
            } else
                printf("x = %.*f\n", n, x);
        } else {
            if (i == 1)
                printf("x = %.*g\n", n, x); 
            else
                printf("x = %.*f\n", n, x);
        }
        f_pt = s_pt;
        s_pt = x;
    }
}

double df(double a, double b, double c, double d, double x)
{
    return (4 * d * pow(x, 3) + 3 * c * pow(x, 2) + 2 * b * x + a);
}

void newton(double a, double b, double c, double d, double e, int n)
{
    double x0 = 0.5;
    double f_xn = 0;
    double s_xn = 0;
    double xn = 0;

    if (f(a,b, c, d, e, x0) == 0) {
        printf("x = %.1f\n", x0);
        return;
    }
    for (int i = 1; i < 500; i++) {
        f_xn = f(a, b, c, d, e, x0);
        s_xn = df(b, c, d, e, x0);
        if (s_xn == 0)
            exit(84);
        xn = x0 - (f_xn / s_xn);
        if (round(x0 * pow(10, n)) == round(xn * pow(10, n)))
            break;
        if (i == 1)
            printf("x = 0.5\n");
        printf("x = %.*f\n",n , xn);
        x0 = xn;
    }
}

void torus(int ac, char *argv[])
{
    double a = atoi(argv[2]);
    double b = atoi(argv[3]);
    double c = atoi(argv[4]);
    double d = atoi(argv[5]);
    double e = atoi(argv[6]);
    int n = atoi(argv[7]);
    int opt = atoi(argv[1]);

    if (opt > 3 || opt < 1) {
        printf("Invalid options !\n");
        exit (84);
    }
    if (n < 0) {
        printf("Invalid precision !\n");
        exit (84);
    }
    if (opt == 1)
        bisection(a, b, c, d, e, n);
    if (opt == 3)
        secant(a, b, c, d, e, n);
    if (opt == 2)
        newton(a, b, c, d, e, n);
}

int main(int ac, char *argv[])
{
    if (ac == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        printf("USAGE\n   ./105torus opt a0 a1 a2 a3 a4 n\n\nDESCRIPTION\n   opt       method option:\n                 1 for the bisection method\n                 2 for Newton's method\n                 3 for the secant method\n   a[0-4]    coefficients of the equation\n             precision (the application of the polynomial to the solution should\n             be smaller than 10^-n)\n");
        return (0);
    }
    if (ac != 8) {
        printf("./105torus opt a0 a1 a2 a3 a4 n\n");
        return (84);
    }
    for (int i = 1; i < ac; i++) {
        for (int j = 0; argv[i][j] != '\0'; j++) {
            if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '-' && argv[i][j] != '+') {
                printf("Invalid arguments");
                return (84);
            }
        }
    }
    torus(ac, argv);
    return (0);
}
