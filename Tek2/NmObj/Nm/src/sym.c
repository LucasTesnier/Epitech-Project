/*
** EPITECH PROJECT, 2022
** NmObjdump
** File description:
** sym
*/

#include "sym.h"
#include "char_modification.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
* @brief comparator function for two symbole node
*
* @param first
* @param second
* @return int
*/
int sym_node_comparator(const void *first, const void *second)
{
    sym_node_t firstChar = *(const sym_node_t *) first;
    sym_node_t secondChar = *(const sym_node_t *) second;

    char *firstC = transform_char_without_underscore(firstChar.name);
    char *secondC = transform_char_without_underscore(secondChar.name);

    int res = 0;

    if (strcmp(firstC, secondC) == 0)
        res = 1;
    else
        res = strcasecmp(firstC, secondC);
    free(firstC);
    free(secondC);
    return res;
}

/**
* @brief sorting function for all the sym node
*
* @param head
*/
void sort_sym_node(sym_t *head)
{
    qsort(head->data, head->size, sizeof(sym_node_t), sym_node_comparator);
}

/**
* @brief init the sym structure
*
* @return sym_t*
*/
sym_t *init_sym(void)
{
    sym_t *head = malloc(sizeof(sym_t));

    head->data = NULL;
    head->size = 0;
    return head;
}

/**
* @brief add a sym node in the struct
*
* @param head
* @param name
* @param adress
* @param type
*/
void add_sym_node(sym_t *head, char *name, unsigned int adress, char type)
{
    head->data = reallocarray(head->data, head->size + 1, sizeof(sym_node_t));
    sym_node_t new = {
        .name = name,
        .adress = adress,
        .type = type
    };
    head->data[head->size] = new;
    head->size += 1;
}

/**
* @brief display all the sym node
*
* @param head
*/
void display_sym_node(sym_t *head)
{
    for (size_t i = 0; i < head->size; i++) {
        if (head->data[i].adress != 0)
            printf("%16.16x %c %s\n", head->data[i].adress,
            head->data[i].type, head->data[i].name);
        else if (head->data[i].type != 'T')
            printf("%18c %s\n", head->data[i].type, head->data[i].name);
        else
            printf("%16.16x %c %s\n", head->data[i].adress,
            head->data[i].type, head->data[i].name);
    }
}