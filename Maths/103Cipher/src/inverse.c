/*
** EPITECH PROJECT, 2020
** Cipher-103
** File description:
** inverse.c
*/

#include "../include/proto.h"

void echange_lignes(float **M, int length, int i, int j) 
{
    float temp;

    for (int k = 0; k < length; k++) {
        temp = M[i][k];
        M[i][k] = M[j][k];
        M[j][k] = temp;
    }
}

void multiplication_lignes(float **M, int length, int i, float l) 
{
    for (int k = 0; k < length; k++) {
        M[i][k] = l * M[i][k];
    }
}

void ajout_lignes(float **M, int length, int i, int j, float l)
{
    for (int k = 0; k < length; k++) {
        M[i][k] = M[i][k] + l * M[j][k];
    }
}

int choix_pivot(float** M, int length, int i, int j)
{
    int k = i;

    while(k < length && M[k][j] == 0)
        k++;
    if (k == length)
        return (-1);
    else
        return (k);
}

int test_inverse(float **M, int length)
{
    float **N = mem_alloc_2d_array_f(length, length);
    int i, j, r;

    for (i = 0; i < length; i++)
        for (j = 0; j < length; j++)
            N[i][j] = M[i][j];
    i = 0;
    j = 0;
    while (i < length && j < length && r != -1) {
        r = choix_pivot(N, length, i, j);
        if (r == -1)
            j++;
        else {
            if (r != i)
                echange_lignes(N, length, i, r);
            if (N[i][j] != 1)
                multiplication_lignes(N, length, i, 1 / N[i][j]);
            for (int k = i + 1; k < length; k++) {
                if(N[k][j] != 0)
                    ajout_lignes(N, length, k, i, -N[k][j]);
            }
            i++;
            j++;
        }
    }
    if (r == -1)
        return (0);
    else
        return (1); 
}

float **new_inverse_matrice(float **M, int length)
{
    float **N = mem_alloc_2d_array_f(length, length);
    float **P = mem_alloc_2d_array_f(length, length);
    int i, j;
    float r, p, l;

    for(i = 0; i < length; i++) {
        for (j = 0; j < length; j++) {
            N[i][j] = M[i][j];
            if (i == j)
                P[i][j] = 1;
            else
                P[i][j] = 0;
        }
    }
    for (j = 0; j < length; j++) {
        r = choix_pivot(N, length, j ,j);
        if (r != j) {
            echange_lignes(N, length, j, r);
            echange_lignes(P, length, j, r);
        }
        if (N[j][j] != 1) {
            p = 1 / N[j][j];
            multiplication_lignes(N, length, j, p);
            multiplication_lignes(P, length, j, p);
        }
        for (i = 0; i < length; i++) {
            if (i != j && N[i][j] != 0) {
                l = -(N[i][j]);
                ajout_lignes(N, length, i, j, l);
                ajout_lignes(P, length, i, j, l);
            }
        }
    }
    return (P);
}
