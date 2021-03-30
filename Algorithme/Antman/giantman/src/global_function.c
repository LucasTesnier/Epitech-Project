/*
** EPITECH PROJECT, 2021
** global_function.c
** File description:
** all global function
*/

#include "proto.h"

bool is_leaf(branch_t *node)
{
    return (!node->left && !node->right);
}
