/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** asm
*/

#ifndef ASM_H_
#define ASM_H_

#include <stdbool.h>
#include <unistd.h>
#include "champions.h"

#define SWAP(nbr) ((nbr >> 24)&0xff) | ((nbr << 8)&0xff0000) | \
((nbr >> 8)&0xff00) | ((nbr << 24)&0xff000000)
#define SHIFT(nbr) (nbr << 16) | (nbr >> 16)

//-----STRUCTURE---------
typedef struct filedata_s {
    char **array;
    int op;
    bool is_label;
    int *size;
    int *to_write;
} filedata_t;

typedef struct node_s {
    filedata_t *data;
    struct node_s *prev;
    struct node_s *next;
} node_t;

typedef struct list_s {
    node_t *first;
    node_t *last;
    int length;
} list_t;


int run_prgm(int ac, char **av);
int error_handling(int ac, char **av);
char *get_new_file_name(char *str);

/* utils/\*.c */
size_t array_size(char **arr);
int get_program_size(list_t *list);
void display_node(node_t *node);

/* get_node_size.c */
size_t get_node_size(node_t *node);

#endif /* !ASM_H_ */
