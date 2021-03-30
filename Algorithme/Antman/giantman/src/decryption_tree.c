/*
** EPITECH PROJECT, 2020
** Antman_Giantman
** File description:
** decryption_tree.c
*/

#include "proto.h"

branch_t *create_node(branch_t *left, branch_t *right)
{
    branch_t *node = malloc(sizeof(branch_t));
    int new_size = my_strlen(right->data) + my_strlen(left->data) + 1;

    if (node == NULL)
        return (NULL);
    node->data = malloc(sizeof(char) * new_size);
    if (node->data == NULL)
        return (NULL);
    my_strcpy(node->data, right->data);
    my_strcat(node->data, left->data);
    node->size = right->size + left->size;
    node->left = left;
    node->right = right;
    return (node);
}

void cut_tree(branch_t **tree, int i)
{
    i++;
    while (tree[i] && tree[i + 1]) {
        tree[i] = tree[i + 1];
        i++;
    }
    tree[i] = NULL;
}

void tree_grows(branch_t **tree, int size)
{
    int i = 0;
    int new = 0;
    branch_t *node;

    while (tree[1]) {
        i = 0;
        new = 0;
        while (tree[i] && tree[i + 1] && new == 0) {
            if (tree[i]->size <= tree[i + 1]->size) {
                tree[i] = create_node(tree[i], tree[i + 1]);
                cut_tree(tree, i);
                new = 1;
            }
            i++;
        }
        if (tree[1] && new != 1) {
            node = create_node(tree[i - 1], tree[i]);
            tree[i - 1] = create_node(tree[i - 1], tree[i]);
            cut_tree(tree, i - 1);
        }
    }
}

branch_t **create_tree(traduction_t **table, int size, my_file_t *file)
{
    branch_t **tree = malloc(sizeof(branch_t *) * (size + 1));
    int i;

    if (tree == NULL)
        return (NULL);
    for (i = 0; i < size; i++) {
        tree[i] = malloc(sizeof(branch_t));
        if (tree[i] == NULL)
            return (NULL);
        tree[i]->data = malloc(sizeof(char) * 2);
        if (tree[i]->data == NULL)
            return (NULL);
        tree[i]->data[0] = table[i]->charactere;
        tree[i]->data[1] = '\0';
        tree[i]->size = my_getnbr(table[i]->code);
        tree[i]->right = NULL;
        tree[i]->left = NULL;
    }
    tree[i] = NULL;
    tree_grows(tree, size);
    return (tree);
}
