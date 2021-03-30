/*
** EPITECH PROJECT, 2021
** global_functions.c
** File description:
** all classic fonction not in a lib
*/

#include "proto.h"

int **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    int size = 0;
    int **result;

    result = malloc(sizeof(int *) * (nb_rows + 1));
    if (result == NULL) {
        return (NULL);
    }
    for (int i = 0; i < nb_rows; i++) {
        result[i] = malloc(sizeof(int) * (nb_cols + 1));
        if (result[i] == NULL) {
            return (NULL);
        }
    }
    return (result);
}

int my_str_search(char buf, int **occurence, int size)
{
    for (int i = 0; i < size; i++) {
        if (occurence[i][0] == buf)
            return (i);
    }
    return (-1);
}

void sort_list(int **occurence, int size, int *change)
{
    int swap[] = {0, 0};

    *change = 0;
    for (int i = 0; i < size - 1; i++) {
        if (occurence[i][1] > occurence[i + 1][1]) {
            swap[0] = occurence[i][0];
            swap[1] = occurence[i][1];
            occurence[i][0] = occurence[i + 1][0];
            occurence[i][1] = occurence[i + 1][1];
            occurence[i + 1][0] = swap[0];
            occurence[i + 1][1] = swap[1];
            *change = 1;
        }
    }
}

bool is_leaf(branch_t *node)
{
    return (!node->left && !node->right);
}

void print_inorder(branch_t *root)
{
    if (!root)
        return;
    if (root->left)
        print_inorder(root->left);
    if (is_leaf(root))
        my_printf("_%S_ -> %i\n", root->data, root->size);
    if (root->right)
        print_inorder(root->right);
}
