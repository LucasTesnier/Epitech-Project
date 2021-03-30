/*
** EPITECH PROJECT, 2020
** Include
** File description:
** push_swap
*/

#ifndef __PUSH__
#define __PUSH__

#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int push_swap(int ac, char *argv[]);
int verif_integer(int ac, char *argv[]);
int sa(int *lista, int *sizea);
void go_up(int *list, int size);
void go_back(int *list, int size);
int pb(int *listb, int *sizeb, int *lista, int *sizea);
int pa(int *lista, int *sizea, int *listb, int *sizeb);
int sc(int *lista, int *sizea, int *listb, int *sizeb);
int sb(int *listb, int *sizeb);
int sa(int *lista, int *sizea);
int rrr(int *lista, int *sizea, int *listb, int *sizeb);
int rrb(int *listb, int *sizeb);
int rra(int *lista, int *sizea);
int rr(int *lista, int *sizea, int *listb, int *sizeb);
int ra(int *lista, int *sizea);
int rb(int *listb, int *sizeb);

float **mem_alloc_2d_array_f(int nb_rows, int nb_cols);
void echange_lignes(float **M, int length, int i, int j) ;
void multiplication_lignes(float **M, int length, int i, float l) ;
void ajout_lignes(float **M, int length, int i, int j, float l);
int choix_pivot(float** M, int length, int i, int j);
int test_inverse(float **M, int length);
float **new_inverse_matrice(float **M, int length);
#endif
