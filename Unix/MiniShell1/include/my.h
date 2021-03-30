/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** prototypes of all the function on the lib
*/

#ifndef MY_
#define MY_
#include <stddef.h>
int *my_memset_int(int *, int, size_t);
int *my_calloc_int(size_t, size_t, int);
char *my_memset_char(char *, char, size_t);
char *my_calloc_char(size_t, size_t, char);
int compute_square_root_test(int, int);
int my_compute_square_root(int);
int compute_is_prime_test(int, int);
int is_prime_test(int);
int *convert_nbr(char const*, char const*, int*);
int *convert_to_decimal(int*, int, int);
int my_getnbr_base(char const*, char const*);
int comp_is_prime_test(int, int);
int define_base(int, char const*);
int *go_in_base(int*, int, char const*);
int *mk_cv(int *, int, char const*, int*);
int *my_putnbr_base(int*, int, char const*);
int nbr_power(int, int);
int count_taille_number(int);
int my_puissance(int);
int nb_is_positive(int);
int verif_overflow(int);
int my_show_word_array(char* const*);
int sort_array(int*, int);
int calc_str_size(char*);
void first_capitalize_letter(char*, int);
void strlowcase_all(char*, int);
char *my_strdup(char const*);
int check_is_find(char*, char*, int, int);
char **add_word_array(char**, char const*, char*, int);
int calc_number_of_words(char const*);
char *define_pos_words(char*, char const*);
char **my_str_to_word_array(char const*);
void my_putchar(char);
int my_isneg(int);
int my_put_nbr(int);
void my_swap(int*, int*);
int my_putstr(char const*);
int my_strlen(char const*);
int my_getnbr(char const*);
void my_sort_int_array(int*, int);
int my_compute_power_rec(int, int);
int my_is_prime(int);
int my_find_prime_sup(int);
char *my_strcpy(char*, char const*);
char *my_strncpy(char*, char const*, int);
char *my_revstr(char*);
char *my_strstr(char*, char const*);
int my_strcmp(char const*, char const*);
int my_strncmp(char const*, char const*, int);
char *my_strupcase(char*);
char *my_strlowcase(char*);
char *my_strcapitalize(char*);
int my_str_isalpha(char const*);
int my_str_isnum(char const*);
int my_str_islower(char const*);
int my_str_isupper(char const*);
int my_str_isprintable(char const*);
int my_showstr(char const*);
int my_showmem(char const*, int);
char *my_strcat(char*, char const*);
char *my_strncat(char*, char const*, int);

#endif
