/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-lucas.tesnier
** File description:
** instructions
*/

#ifndef INSTRUCTIONS_H_
#define INSTRUCTIONS_H_

#include "asm.h"

typedef struct arg_entry_s {
    int op_code;
    int *entry;
    char *arg;
    int arg_idx;
} arg_entry_t;

/* insert_towrite.c */
bool insert_towrite(arg_entry_t *ae);
bool check_valid_label(char *candidate);
bool insert_towrite_indirect(arg_entry_t *entry);

/* insert_size.c */
int insert_size(int op_code, int *entry, char *arg, int arg_idx);

/* create_instruction.c */
filedata_t *create_instruction(char *line);
list_t * insert_into_instructions(list_t *list, filedata_t *instruction);

/* labels_manager/search_label_calls.c */
int contains_label_call(node_t *node, char *label);
void find_in_previous_instructions(node_t *node);
void find_in_next_instructions(node_t *node);

/* labels_manager/compute_label_offsetc */
int parse_labels(list_t *list);

#endif /* !INSTRUCTIONS_H_ */