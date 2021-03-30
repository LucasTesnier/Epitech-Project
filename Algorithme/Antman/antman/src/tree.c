/*
** EPITECH PROJECT, 2021
** tree.c
** File description:
** all tree functions
*/

#include "proto.h"

void cut_tree(branch_t **tree, int i)
{
    i++;
    while (tree[i] && tree[i + 1]) {
        tree[i] = tree[i + 1];
        i++;
    }
    tree[i] = NULL;
}

int tree_grows_node(branch_t **tree, int *i, int *new)
{
    if (tree[*i]->size <= tree[*i + 1]->size) {
        tree[*i] = create_node(tree[*i], tree[*i + 1]);
        if (tree[*i] == NULL)
            return (-1);
        cut_tree(tree, *i);
        *new = 1;
    }
    *i += 1;
    return (0);
}

int tree_grows(branch_t **tree, int size, my_file_t *file)
{
    int i = 0;
    int new = 0;

    while (tree[1]) {
        i = 0;
        new = 0;
        while (tree[i] && tree[i + 1] && new == 0)
            if (tree_grows_node(tree, &i, &new) == -1)
                return (-1);
        if (tree[1] && new != 1) {
            tree[i - 1] = create_node(tree[i - 1], tree[i]);
            if (tree[i - 1] == NULL)
                return (-1);
            cut_tree(tree, i - 1);
        }
    }
    return (create_traduction_table(tree[0], size, file));
}

int create_tree(int **occurence, int size, my_file_t *file)
{
    branch_t **tree = malloc(sizeof(branch_t *) * (size + 1));
    int i;

    if (tree == NULL)
        return (-1);
    for (i = 0; i < size; i++) {
        tree[i] = malloc(sizeof(branch_t));
        if (tree[i] == NULL)
            return (-1);
        tree[i]->data = malloc(sizeof(char) * 2);
        if (tree[i]->data == NULL)
            return (-1);
        tree[i]->data[0] = occurence[i][0];
        tree[i]->data[1] = '\0';
        tree[i]->size = occurence[i][1];
        tree[i]->right = NULL;
        tree[i]->left = NULL;
    }
    tree[i] = NULL;
    return (tree_grows(tree, size, file));
}

int init_tree(my_file_t *file)
{
    int **occurence = mem_alloc_2d_array(256, 2);
    int size = 0;
    int change = 1;

    if (occurence == NULL) {
        my_putstr("Error Malloc.\n");
        return (-1);
    }
    for (int i = 0; i < file->size; i++) {
        if (my_str_search(file->buffer[i], occurence, size) == -1) {
            occurence[size][0] = file->buffer[i];
            occurence[size][1] = 1;
            size++;
        } else
            occurence[my_str_search(file->buffer[i], occurence, size)][1] += 1;
    }
    while (change == 1)
        sort_list(occurence, size, &change);
    return (create_tree(occurence, size, file));
}
