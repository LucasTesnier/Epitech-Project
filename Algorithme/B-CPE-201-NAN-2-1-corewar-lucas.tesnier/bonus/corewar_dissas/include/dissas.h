/*
** EPITECH PROJECT, 2021
** corewar_dissas
** File description:
** get_cor_file
*/

#ifndef COREWAR_DISSAS_DISSAS_H
#define COREWAR_DISSAS_DISSAS_H

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "op.h"

#define SWAP(nbr) ((nbr >> 24)&0xff) | ((nbr << 8)&0xff0000) | \
((nbr >> 8)&0xff00) | ((nbr << 24)&0xff000000)

typedef unsigned char bytecode_t;

typedef struct dissas_s {
    FILE *asm_fp;
    header_t *meta_data;
    bytecode_t *code;
} dissas_t;

/* get_file.c */
bool get_cor_file(dissas_t *dissas, char *file_path);

/* dissas.c */
dissas_t *init_dissas(void);
void write_meta_data(dissas_t *new_dissas);

/* write_instr.c */
void write_instructions_from_bytecode(dissas_t *dump);

/* utils.c */
char *int_to_str(int nbr);
int get_dir_param(dissas_t *dump, int index);
short get_ind_param(dissas_t *dump, int index);

#endif //COREWAR_DISSAS_DISSAS_H
