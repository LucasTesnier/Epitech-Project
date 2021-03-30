/*
** EPITECH PROJECT, 2020
** Antman_Giantman
** File description:
** giantman.h
*/

#ifndef _GIANTMAN_
#define _GIANTMAN_
//-----NEEDED-INCLUDES---
#include "proto.h"

//-----PROTOTYPES--------
branch_t **create_tree(traduction_t **table, int size, my_file_t *file);
int giantman(my_file_t *file);

#endif