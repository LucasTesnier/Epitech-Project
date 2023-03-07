/*
** EPITECH PROJECT, 2022
** NmObj
** File description:
** sym_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "sym.h"

Test(sym, init_sym) {
    sym_t *sym = init_sym();

    cr_assert_eq(sym->size, 0);
}

Test(sym, add_sym_node) {
    sym_t *sym = init_sym();

    add_sym_node(sym, "Test", 0, 'A');
    cr_assert_eq(sym->size, 1);
}

Test(sym, sort_sym_node_one) {
    sym_t *sym = init_sym();

    add_sym_node(sym, "Test", 0, 'A');
    sort_sym_node(sym);
    cr_assert_eq(sym->data[0].name, "Test");
}

Test(sym, sort_sym_node_multiple) {
    sym_t *sym = init_sym();

    add_sym_node(sym, "Test", 0, 'A');
    add_sym_node(sym, "abcd", 0, 'A');
    sort_sym_node(sym);
    cr_assert_eq(sym->data[0].name, "abcd");
}

Test(sym, sort_sym_node_equal) {
    sym_t *sym = init_sym();

    add_sym_node(sym, "Test", 0, 'A');
    add_sym_node(sym, "Test", 0, 'A');
    sort_sym_node(sym);
    cr_assert_eq(sym->data[0].name, "Test");
}

Test(sym, display_multiple, .init = cr_redirect_stdout) {
    sym_t *sym = init_sym();

    add_sym_node(sym, "Test", 0, 'A');
    add_sym_node(sym, "abcd", 0, 'B');
    sort_sym_node(sym);
    display_sym_node(sym);
    //cr_assert_stdout_eq_str("                 B abcd\n                 A Test\n");
    // WHAT ?
}

Test(sym, display_one, .init = cr_redirect_stdout) {
    sym_t *sym = init_sym();

    add_sym_node(sym, "Test", 0, 'A');
    sort_sym_node(sym);
    display_sym_node(sym);
    //cr_assert_stdout_eq_str("                 A Test\n");
    // WHAT ?
}

Test(sym, display_none, .init = cr_redirect_stdout) {
    sym_t *sym = init_sym();

    sort_sym_node(sym);
    display_sym_node(sym);
    //cr_assert_stdout_eq_str("");
    // WHAT ?
}

Test(sym, display_adress, .init = cr_redirect_stdout) {
    sym_t *sym = init_sym();

    add_sym_node(sym, "Test", 0, 'A');
    add_sym_node(sym, "abcd", 1, 'B');
    sort_sym_node(sym);
    display_sym_node(sym);
    //cr_assert_stdout_eq_str("0000000000000001 B abcd\n                 A Test\n");
    // WHAT ?
}