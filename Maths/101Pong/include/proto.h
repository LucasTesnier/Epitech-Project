/*
** EPITECH PROJECT, 2020
** B-CPE-101-NAN-1-1-finalstumper-lucas.tesnier
** File description:
** rush3
*/

#ifndef __BISTRO__

char *infin_mod_base(char *nb1, char *nb2, char *base, char *op);
char *infin_div_base(char *nb1, char *nb2, char *base, char *op);
int my_str_search_bis(char c, char *search);
void get_add(char *expr, char *base, char *ops, int *i);
int my_str_search(char c, char *search);
void get_signe_next(char *expr, char *ops, int *i, int count);
void get_signe_next_bis(char *expr, char *ops, int *i, int count);
int test_unit_bis(int size, char *expr, char **av);
void get_signe(char *expr, char *base, char *ops);
char *infin_mul_base(char *nb1, char *nb2, char *base, char *operators);
char *make_op_scale(char *save, char *ops, char *b, int pos_scale);
void *eval_expr_bis(char *expr, char *save, char *ops);
int get_expr(int size, char *expr);
int check_scale(char *expr, char *ops, char *b);
int define_priority(int cnt, int change, char *save, char *ops);
char *define_scnd_nmbr(int pos_scale, \
char *first_number, char *ops, char *save);
char *make_op(char *save, char **stock, int pos_scale);
char *infin_add_base(char *s1, char *s2, char *base, char *op_set);

#define __BISTRO__
#endif
