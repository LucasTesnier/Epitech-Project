/*
** EPITECH PROJECT, 2020
** Antman_Giantman
** File description:
** uncompression.c
*/

#include "proto.h"

void browse_inorder(branch_t *root, char *bit_str, int *i, bool *find)
{
    if (!root)
        return;
    if (bit_str[*i] == '1' && root->left) {
        *i += 1;
        browse_inorder(root->left, bit_str, i, find);
    }
    if (is_leaf(root)) {
        *find = true;
        write(1, root->data, 1);
    }
    if (*find == false && bit_str[*i] == '0' && root->right) {
        *i += 1;
        browse_inorder(root->right, bit_str, i, find);
    }
}

void fill_occurence_table(traduction_t **table, int size, my_file_t *file)
{
    int j = 0;
    int k;

    for (int i = 1; file->buffer[i] && file->buffer[i + 1] \
    && (file->buffer[i] != '~' || file->buffer[i + 1] != '~'); i++) {
        table[j]->charactere = file->buffer[i];
        k = 0;
        i++;
        while (file->buffer[i] && file->buffer[i] != ':') {
            table[j]->code[k] = file->buffer[i];
            k++;
            i++;
        }
        j++;
    }
    table[j] = NULL;
}

traduction_t **create_occurence_table(int size)
{
    traduction_t **table = malloc(sizeof(*table) * (size + 2));

    if (table == NULL)
        return (NULL);
    for (int i = 0; i <= size; i++) {
        table[i] = malloc(sizeof(*table[i]));
        if (table[i] == NULL)
            return (NULL);
        table[i]->code = malloc(sizeof(*table[i]->code) * 8);
        if (table[i]->code == NULL)
            return (NULL);
    }
    return (table);
}

int get_begin_chain(my_file_t *file)
{
    int begin_chain = 0;

    for (int i = 0; file->buffer[i] != '~' \
        || file->buffer[i + 1] != '~'; i++)
        begin_chain++;
    begin_chain += 2;

    return (begin_chain);
}

int giantman(my_file_t *file)
{
    int how_many_char = 0;
    traduction_t **occ_table;
    branch_t **tree;

    for (int i = 0; file->buffer[i] && file->buffer[i + 1] \
    && (file->buffer[i] != '~' || file->buffer[i + 1] != '~'); i++) {
        if (file->buffer[i] == ':' && file->buffer[i - 1] != ':')
            how_many_char++;
    }
    occ_table = create_occurence_table(how_many_char);
    if (occ_table == NULL)
        return (-1);
    fill_occurence_table(occ_table, how_many_char, file);
    tree = create_tree(occ_table, how_many_char, file);
    if (tree == NULL)
        return (-1);
    if (create_bit_str(file, tree[0]) == -1)
        return (-1);
    return (0);
}
