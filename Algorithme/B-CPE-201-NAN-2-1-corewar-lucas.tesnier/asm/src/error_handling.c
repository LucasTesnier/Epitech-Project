/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** error_handling
*/

#include "my.h"

void display_help(void)
{
    my_putstr("USAGE\n./asm file_name[.s]\nDESCRIPTION\nfile_namefile in ");
    my_putstr("bassembly language to be converted intofile_name.cor, an ");
    my_putstr("executable in the Virtual Machine.\n");
}

int error_handling(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        display_help();
        return (1);
    }
    return (0);
}