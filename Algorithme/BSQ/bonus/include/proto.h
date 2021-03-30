/*
** EPITECH PROJECT, 2020
** B-CPE-101-NAN-1-1-finalstumper-lucas.tesnier
** File description:
** rush3
*/

#ifndef __BSQ__

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char *load_file_in_mem(char const *filepath);
int buffer_modification(char *buffer, int *nb_rows, int *count);
int cols_setup(int *count, char *buffer, int *nb_cols);
char **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols,
int size);
int verification_map(int i, int nb_cols, char **map, char *bonus);
int find_biggest_square(char **map, int nb_rove, int nb_cols, char *square);
void transformation_first_cols(int nb_cols, char **map, int *size);
void transformation_first_row(int nb_rove, char **map, int *size);
void transformation_number(int i, int j, char **map, int *size);
void transformation_square(int *size, char **map, int nb_rove, int nb_cols);
int fs_open_file(char const *filepath);
char **mem_alloc_2d_array(int nb_rows, int nb_cols);
void find_min_number(int i, int j, char **map, int *size);
int bsq(char const *filepath, char *neutral, char *obs, char *square);

#define __BSQ__
#endif
