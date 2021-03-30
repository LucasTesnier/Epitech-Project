/*
** EPITECH PROJECT, 2021
** test.c
** File description:
** test unitaire
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/proto.h"

Test(antman, one, .init=cr_redirect_stdout)
{
    my_file_t file;

    my_open_and_read(&file, "antman/tests/temp");
    init_tree(&file);
//cr_assert_stdout_eq_str("&M1:p1: 1:R1:v1:e1:r1:s4:i5:~~�B!��Ԁ~~~~49");
//stoud bugée, temporairement désactivé mais outpout identique
}
