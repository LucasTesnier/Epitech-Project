/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-lucas.tesnier
** File description:
** call_labels
*/

#include "my.h"
#include "asm.h"
#include "instructions.h"

bool has_bytecode(node_t *tmp)
{
    if (op_tab[tmp->data->op - 1].code != 1 && \
        op_tab[tmp->data->op - 1].code != 9 && op_tab[tmp->data->op - 1].code \
        != 12 && op_tab[tmp->data->op - 1].code != 15)
        return (true);
    return (false);
}

void find_that_label(list_t *list, node_t *node, int i, int node_offset)
{
    node_t *tmp = list->first;
    int label_offset = 0;

    while (tmp) {
        if (!tmp->data->is_label) {
            has_bytecode(tmp) ? label_offset += 1 : 0;
            label_offset += get_node_size(tmp);
            tmp = tmp->next;
            continue;
        }
        if (my_strcmp(tmp->data->array[0], node->data->array[i] + 2) == 0) {
            node->data->to_write[i] = label_offset - node_offset;
            return;
        }
        tmp = tmp->next;
    }
}

void find_corr_label(list_t *list, node_t *node, int off)
{
    int offset = off;

    for (int i = 0; i <= op_tab[node->data->op - 1].nbr_args; i++) {
        if (node->data->array[i][0] == DIRECT_CHAR && \
            node->data->array[i][1] == LABEL_CHAR)
            find_that_label(list, node, i, offset);
    }
}

/**
* @brief modifies filedata->towrite when label is called
*
* @param list
*/
int parse_labels(list_t *list)
{
    int off = 0;

    if (!list)
        return (-1);
    for (node_t *node = list->first; node; node = node->next) {
        if (!node->data->is_label) {
            find_corr_label(list, node, off);
            has_bytecode(node) ? off += 1: 0;
            off += get_node_size(node);
        }
    }
    return (0);
}