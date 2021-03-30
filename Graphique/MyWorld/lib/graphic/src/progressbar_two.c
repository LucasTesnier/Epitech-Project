/*
** EPITECH PROJECT, 2020
** progressbar_two.c
** File description:
** function progressbar
*/

#include "proto.h"

void progressbar_change_display(progressbar_t *progress, bool is_display)
{
    progress->is_display = is_display;
}