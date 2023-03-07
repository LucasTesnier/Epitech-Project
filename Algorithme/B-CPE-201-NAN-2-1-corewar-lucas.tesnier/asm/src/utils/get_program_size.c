/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-lucas.tesnier
** File description:
** get_program_size
*/

#include "op.h"
#include "asm.h"

/**
* @brief get the program size in byte
* @param meta
* @return
*/
int get_program_size(list_t *list)
{
    int size = 0;

    if (!list)
        return (-1);
    for (node_t *tmp = list->first; tmp; tmp = tmp->next) {
        if (tmp->data->is_label)
            continue;
        if (op_tab[tmp->data->op - 1].code != 1 && \
            op_tab[tmp->data->op - 1].code != 9 && \
            op_tab[tmp->data->op - 1].code != 12 && \
            op_tab[tmp->data->op - 1].code != 15)
            size += 1;
        for (int i = 0; i <= op_tab[tmp->data->op - 1].nbr_args; i++) {
            size += tmp->data->size[i];
        }
    }
    return (size);
}
