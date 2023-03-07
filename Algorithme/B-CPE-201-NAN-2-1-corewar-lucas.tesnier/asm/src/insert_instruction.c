/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-lucas.tesnier
** File description:
** insert_instruction
*/

#include "instructions.h"
#include "asm.h"
#include "my.h"

static list_t *init_ll(filedata_t *instruction)
{
    list_t *new_ll = malloc(sizeof(list_t));
    node_t *new_node = malloc(sizeof(node_t));

    if (!new_ll || !new_node)
        exit(84);
    new_node->data = instruction;
    new_node->next = NULL;
    new_node->prev = NULL;
    new_ll->length = 1;
    new_ll->first = new_node;
    new_ll->last = new_node;
    return (new_ll);
}

/**
* @brief insert instruction object into the LL
* @param ll 
* @param instruction 
*/
list_t * insert_into_instructions(list_t *list, filedata_t *instruction)
{
    node_t *new_node;

    if (!list)
        return (init_ll(instruction));
    new_node = malloc(sizeof(*new_node));
    if (!new_node)
        exit(84);
    new_node->data = instruction;
    new_node->next = NULL;
    new_node->prev = list->last;
    if (new_node->prev)
        new_node->prev->next = new_node;
    if (!list->first)
        list->first = new_node;
    list->last = new_node;
    list->length++;
    return (list);
}
