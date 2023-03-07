/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-lucas.tesnier
** File description:
** get_node_size
*/

#include "asm.h"
#include "op.h"

size_t get_node_size(node_t *node)
{
    size_t size = 0;
    char args_nb;

    if (!node)
        return (0);
    args_nb = op_tab[node->data->op - 1].nbr_args;
    for (int i = 0; i <= args_nb; i++)
        size += node->data->size[i];
    return (size);
}
