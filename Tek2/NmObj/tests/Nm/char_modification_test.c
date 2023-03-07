/*
** EPITECH PROJECT, 2022
** NmObj
** File description:
** char_modification
*/

#include <criterion/criterion.h>
#include "char_modification.h"

Test(transform_char_without_underscore, classic) {
    cr_assert_str_eq(transform_char_without_underscore("hey"), "hey");
}

Test(transform_char_without_underscore, one) {
    cr_assert_str_eq(transform_char_without_underscore("he_y"), "hey");
}

Test(transform_char_without_underscore, multiple) {
    cr_assert_str_eq(transform_char_without_underscore("_he_y"), "hey");
}

Test(transform_char_without_underscore, empty) {
    cr_assert_str_eq(transform_char_without_underscore(""), "");
}

Test(transform_char_without_underscore, only) {
    cr_assert_str_eq(transform_char_without_underscore("_"), "");
}

Test(transform_char_without_underscore, point) {
    cr_assert_str_eq(transform_char_without_underscore("hey."), "hey");
}