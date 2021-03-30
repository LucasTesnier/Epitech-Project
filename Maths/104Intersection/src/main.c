/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** all main function
*/

#include "proto.h"

void intersection(int ac, char *argv[])
{
    float opt, xp, yp, zp, xv, yv, zv;
    double p;
    double part_a, part_b, part_c, delta, lambda, lambda_one, lambda_two;

    opt = atof(argv[1]);
    xp = atof(argv[2]);
    yp = atof(argv[3]);
    zp = atof(argv[4]);
    xv = atof(argv[5]);
    yv = atof(argv[6]);
    zv = atof(argv[7]);
    p = atof(argv[8]);
    if (xv == 0 && yv == 0 && zv == 0) {
        printf("Vector direction NULL");
        exit(84);
    }
    if (opt == 1) {
        if (p <= 0) {
            printf("Invalid radius");
            exit(84);
        }
        printf("Sphere of radius %.0f\n", p);
        part_a = pow(xv, 2) + pow(yv, 2) + pow(zv, 2);
        part_b = 2 * (xp * xv + yp * yv + zp * zv);
        part_c = pow(xp, 2) + pow(yp, 2) + pow(zp, 2) - pow(p, 2);
    } else if (opt == 2) {
        if (p <= 0) {
            printf("Invalid radius");
            exit(84);
        }
        printf("Cylinder of radius %.0f\n", p);
        part_a = pow(xv, 2) + pow(yv, 2);
        part_b = 2 * (xv * xp + yv * yp);
        part_c = pow(xp, 2) + pow(yp, 2) - pow(p, 2);
    } else if (opt == 3 && p > 0 && p < 90) {
        printf("Cone with a %.0f degree angle\n", p);
        p = p * 3.14159265358979323846 / 180;
        //printf("Angle : %f, tan : %f", p, tan(p));
        part_a = pow(xv, 2) + pow(yv, 2) - (pow(tan(p), 2) * pow(zv, 2));
        part_b = 2 * (xp * xv + yp * yv - (pow(tan(p), 2) * zp * zv));
        part_c = pow(xp, 2) + pow(yp, 2) - (pow(tan(p), 2) * pow(zp, 2));
    } else {
        printf("./104intersection opt xp yp zp xv yv zv p\n");
        exit(84);
    }
    printf("Line passing through the point (%.0f, %.0f, %.0f) and parallel to the vector (%.0f, %.0f, %.0f)\n", xp, yp, zp, xv, yv, zv);
    if (part_a * part_a < 0.00001 && part_a * part_a > -0.00001 && part_b * part_b < 0.00001 && part_b * part_b > -0.00001 && part_c * part_c < 0.00001 && part_c * part_c > -0.00001) {
        printf("There is an infinite number of intersection points.\n");
        exit(0);
    }
    delta = pow(part_b, 2) - 4 * part_a * part_c;
    if (opt == 2 && xv == 0 && yv == 0 && zv != 0) {
        if (pow(xp, 2) + pow(yp, 2) == pow(p, 2)) {
            printf("There is an infinite number of intersection points.\n");
            exit(0);
        } else {
            printf("No intersection point.\n");
            exit(0);
        }
    }
    if (opt == 3 && (pow(xv, 2) + pow(yv, 2) - pow(tan(p), 2)) <= 0.00000000001 && (pow(xv, 2) + pow(yv, 2) - pow(tan(p), 2)) >= -0.00000000001) {
        printf("There is an infinite number of intersection points.\n");
        exit(0);
    }
    if (opt == 3 && part_a <= 0.0001 && part_a >= -0.0001) {
        lambda = -part_c / part_b;
        printf("1 intersection point:\n");
        printf("(%.3f, %.3f, %.3f)\n", xp + xv * lambda, yp + yv * lambda, zp + zv * lambda);
        exit(0);
    }
    if (delta < 0) {
        printf("No intersection point.\n");
    } else if (delta >= -0.00001 && delta <= 0.00001) {
        lambda = -part_b / ( 2 * part_a);
        printf("1 intersection point:\n");
        printf("(%.3f, %.3f, %.3f)\n", xp + xv * lambda, yp + yv * lambda, zp + zv * lambda);
    } else if (delta > 0) {
        lambda_two = (-part_b - sqrtf(delta)) / (2 * part_a);
        lambda_one = (-part_b + sqrtf(delta)) / (2 * part_a);
        printf("2 intersection points:\n");
        printf("(%.3f, %.3f, %.3f)\n", xp + xv * lambda_one, yp + yv * lambda_one, zp + zv * lambda_one);
        printf("(%.3f, %.3f, %.3f)\n", xp + xv * lambda_two, yp + yv * lambda_two, zp + zv * lambda_two);
    }
}

int main(int ac, char *argv[])
{
    if (ac == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        printf("USAGE\n   ./104intersection opt xp yp zp xv yv zv p\n\nDESCRIPTION\n   opt\t\t  surface option: 1 for a sphere, 2 for a cylinder, 3 for a cone\n   (xp, yp, zp)   coordinates of a point by wich the light ray passes through\n   (xv, yv, zv)   coordinates of a vector parallel to the light ray\n   p\t\t  parameter: radius of the sphere, radius of the cylinder, or \n\t\t  angle formed by the cone and the Z-axis\n");
        return (0);
    }
    if (ac != 9 || (ac == 1 && argv[1][0] != '-' && argv[1][0] != 'h')) {
        printf("./104intersection opt xp yp zp xv yv zv p\n");
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
    intersection(ac, argv);
    return (0);
}
