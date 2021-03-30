/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** all main function
*/

#include <unistd.h>
#include "help.h"
#include "my.h"

int driver(int ac, char *av[]);

int main(int ac, char *av[])
{
    if (ac < 2 || ac > 4){
        write(2, "Bad args\n", 10);
        return (84);
    }
    if (ac == 2 && my_strcmp(av[1], "-h") == 0){
        write(1, USAGE, 204);
        return (0);
    }
    return (driver(ac, av));
}
