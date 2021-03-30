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

//uncompression.c
void browse_inorder(branch_t *root, char *bit_str, int *i, bool *find);
void fill_occurence_table(traduction_t **table, int size, my_file_t *file);
traduction_t **create_occurence_table(int size);
int get_begin_chain(my_file_t *file);
int giantman(my_file_t *file);

//bit_gestion.c
int calcul_bit_chain_length(char *buffer);
int decrypte_bit_str(branch_t *tree, char *bit_str, int bit_count);
void get_char_in_bit(int i, char *buffer, char *bit_str, int *actual_size);
int get_bit_count(my_file_t *file, int begin_chain);
int create_bit_str(my_file_t *file, branch_t *tree);

//decryption_tree.c
branch_t *create_node(branch_t *left, branch_t *right);
void cut_tree(branch_t **tree, int i);
void tree_grows(branch_t **tree, int size);
branch_t **create_tree(traduction_t **table, int size, my_file_t *file);

//global_function.c
bool is_leaf(branch_t *node);

#endif
