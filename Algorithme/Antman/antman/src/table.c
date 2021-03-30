/*
** EPITECH PROJECT, 2021
** table.c
** File description:
** all table function
*/

#include "proto.h"

void fill_traduction_table(branch_t *tree, int *count, \
traduction_t **table, char *code)
{
    char *new_code = my_strdup(code);
    char *new_code_right;

    if (!tree)
        return;
    if (tree->left) {
        my_strncat(new_code, "1", 1);
        fill_traduction_table(tree->left, count, table, new_code);
    }
    if (is_leaf(tree)) {
        my_printf("%s%i:", tree->data, tree->size);
        table[*count]->charactere = tree->data[0];
        table[*count]->code = new_code;
        *count += 1;
    }
    new_code_right = my_strdup(new_code);
    new_code_right[my_strlen(new_code_right) - 1] = '\0';
    if (tree->right) {
        my_strncat(new_code_right, "0", 1);
        fill_traduction_table(tree->right, count, table, new_code_right);
    }
}

int create_traduction_table(branch_t *tree, int size, my_file_t *file)
{
    traduction_t **table = malloc(sizeof(*table) * (size + 1));
    char *code = "";
    int count = 0;

    my_putchar('&');
    if (table == NULL)
        return (-1);
    for (int i = 0; i < size; i++) {
        table[i] = malloc(sizeof(*table[i]));
        if (table[i] == NULL)
            return (-1);
        table[i]->code = malloc(sizeof(*table[i]->code) * 8);
        if (table[i]->code == NULL)
            return (-1);
    }
    fill_traduction_table(tree, &count, table, code);
    trad_buffer(table, file, count);
}

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
