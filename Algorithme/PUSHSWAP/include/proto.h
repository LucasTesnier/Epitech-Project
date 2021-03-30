/*
** EPITECH PROJECT, 2020
** Include
** File description:
** push_swap
*/

#ifndef __PUSH__

#include "my.h"
#include <unistd.h>
#include <stdlib.h>

typedef struct linked_list
{
    int data;
    struct linked_list *next;
    struct linked_list *prev;
} linked_list_t;

int push_swap(int ac, char *argv[]);
int verif_integer(int ac, char *argv[]);
int sa(linked_list_t **lista, int *sizea);
int pb(linked_list_t **listb, int *sizeb, linked_list_t **lista, int *sizea);
int pa(linked_list_t **lista, int *sizea, linked_list_t **listb, int *sizeb);
int sc(linked_list_t **lista, int *sizea, linked_list_t **listb, int *sizeb);
int sb(linked_list_t **listb, int *sizeb);
int rrr(linked_list_t **lista, int *sizea, linked_list_t **listb, int *sizeb);
int rrb(linked_list_t **listb, int *sizeb);
int rra(linked_list_t **lista, int *sizea);
int rr(linked_list_t **lista, int *sizea, linked_list_t **listb, int *sizeb);
int ra(linked_list_t **lista, int *sizea);
int rb(linked_list_t **listb, int *sizeb);
void display_res(int *res, int size);
int setup(int ac, linked_list_t **lista, int sizea, char *argv[]);
void test(int save, int *res, unsigned int sres);
void add_ops(int *res, unsigned int *sres, int data);
void conc(linked_list_t **lista, int *sizea, int *res, int *sres);

#define __PUSH__
#endif
