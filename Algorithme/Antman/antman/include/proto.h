/*
** EPITECH PROJECT, 2020
** antman.c
** File description:
** antman
*/

#ifndef __ANTMAN__
#define __ANTMAN__

#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct traduction
{
    char charactere;
    char *code;
} traduction_t;

typedef struct branch
{
    char *data;
    int size;
    struct branch *right;
    struct branch *left;
} branch_t;

//-----PROTOTYPES-----------
//encryption.c
int find_in_table(char buf, traduction_t **table, int count);
int trad_buffer(traduction_t **table, my_file_t *file, int count);
void write_in_file(traduction_t **table, char *trad_buffer);

//global_functions.c
int **mem_alloc_2d_array(int nb_rows, int nb_cols);
int my_str_search(char buf, int **occurence, int size);
void sort_list(int **occurence, int size, int *change);
bool is_leaf(branch_t *node);
void print_inorder(branch_t *root);

//table.c
void fill_traduction_table(branch_t *tree, int *count, \
traduction_t **table, char *code);
int create_traduction_table(branch_t *tree, int size, my_file_t *file);
branch_t *create_node(branch_t *left, branch_t *right);

//tree.c
void cut_tree(branch_t **tree, int i);
int tree_grows_node(branch_t **tree, int *i, int *new);
int tree_grows(branch_t **tree, int size, my_file_t *file);
int create_tree(int **occurence, int size, my_file_t *file);
int init_tree(my_file_t *file);

//uncompression.c
//int giantman(char *buffer);

#endif
