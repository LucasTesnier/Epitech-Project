/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-lucas.tesnier
** File description:
** parsing
*/

#ifndef PARSING_H_
#define PARSING_H_

#include <stdbool.h>
#include "asm.h"
#include "op.h"

/* imported from asm.h */
typedef struct filedata_s filedata_t;

/* check_argument_type.c */
args_type_t check_arg_type(args_type_t type, char *arg);
args_type_t check_register(char *arg);
args_type_t check_direct(char *arg);
args_type_t check_indirect(char *arg);
bool check_label(char *arg);
int check_champion_data(char *temp, char *temp_two);

/* parse_file.c */
list_t *parse_file(char *file_buffer);
filedata_t *init_filedata(void);

#endif /* !PARSING_H_ */
