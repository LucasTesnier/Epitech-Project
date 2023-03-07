/*
** EPITECH PROJECT, 2022
** NmObjdump
** File description:
** sym
*/

#ifndef SYM_H_
    #define SYM_H_

    #include <stddef.h>

typedef struct sym_node_s {
    char *name;
    unsigned int adress;
    char type;
} sym_node_t;

typedef struct sym_s {
    sym_node_t *data;
    size_t size;
} sym_t;

void sort_sym_node(sym_t *head);
sym_t *init_sym(void);
void add_sym_node(sym_t *head, char *name, unsigned int adress, char type);
void display_sym_node(sym_t *head);

#endif /* !SYM_H_ */
