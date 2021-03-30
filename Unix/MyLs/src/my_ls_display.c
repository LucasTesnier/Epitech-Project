/*
** EPITECH PROJECT, 2020
** my_ls_display.c
** File description:
** all function for ls display
*/

#include "proto.h"

int display_permission(struct stat sb)
{
    my_putchar(get_file_type(sb.st_mode));
    my_putstr((sb.st_mode & S_IRUSR) ? "r" : "-");
    my_putstr((sb.st_mode & S_IWUSR) ? "w" : "-");
    my_putstr((sb.st_mode & S_IXUSR) ? "x" : "-");
    my_putstr((sb.st_mode & S_IRGRP) ? "r" : "-");
    my_putstr((sb.st_mode & S_IWGRP) ? "w" : "-");
    my_putstr((sb.st_mode & S_IXGRP) ? "x" : "-");
    my_putstr((sb.st_mode & S_IROTH) ? "r" : "-");
    my_putstr((sb.st_mode & S_IWOTH) ? "w" : "-");
    my_putstr((sb.st_mode & S_IXOTH) ? "x" : \
    (sb.st_mode & S_ISVTX) ? "T" : "-");
    my_putstr(" ");
    return (0);
}

int display_hard_link(struct stat sb)
{
    my_put_nbr(sb.st_nlink);
    my_putchar(' ');
    return (0);
}

int display_user(struct stat sb)
{
    struct passwd *pws;
    struct group *gr;

    gr = getgrgid(sb.st_gid);
    pws = getpwuid(sb.st_uid);
    my_putstr(pws->pw_name);
    my_putchar(' ');
    my_putstr(gr->gr_name);
    my_putchar(' ');
    return (0);
}

int display_size(struct stat sb)
{
    if ((sb.st_mode & S_IFCHR)) {
        my_put_nbr(major(sb.st_rdev));
        my_putstr(", ");
        my_put_nbr(minor(sb.st_rdev));
    } else {
        my_put_nbr(sb.st_size);
    }
    my_putchar(' ');
    return (0);
}

int display_date(struct stat sb)
{
    write(1, (ctime(&sb.st_mtime) + 4), (my_strlen(ctime(&sb.st_mtime)) - 13));
    my_putchar(' ');
    return (0);
}
