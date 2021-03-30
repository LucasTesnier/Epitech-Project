/*
** EPITECH PROJECT, 2020
** B-CPE-101-NAN-1-1-finalstumper-lucas.tesnier
** File description:
** rush3
*/

#ifndef __SCREENSAVER__

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
#include <sys/sysmacros.h>
#include <pwd.h>
#include <grp.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include "my.h"

int my_ls_receiver(int ac, char *argv[]);
int my_ls_operation(char *flag_order, int path, char *argv[], int ac);
int display_permission(struct stat sb);
int display_hard_link(struct stat sb);
int display_user(struct stat sb);
int display_size(struct stat sb);
int display_date(struct stat sb);
int my_str_search(char c, char *str);
char **mem_alloc_2d_array(int nb_rows, int nb_cols);
void read_dir(char *flag_order, char *path, char **list, int *count);
void display_total(char **list, char *flag_order, int count);
void sort_list_dispacher(char **list, int count, char *flag_order);
void header(char *argv[], char *name, int ac, int *save);
int my_ls_display(char *path, char *flag_order, int count, int *save);
void read_dir_two(char *file_name, char *path, int *count, char **list);
void my_ls_r_lists(char *flag_order, char *path, char **list, int *count);
char get_file_type(mode_t mode);
void my_ls_op(char *flag_order);
void sort_list_alphebatical_order(char **list, int count);
void define_color(char *path, int count);

#define __SCREENSAVER__
#endif
