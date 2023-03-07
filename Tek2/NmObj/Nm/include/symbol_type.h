/*
** EPITECH PROJECT, 2022
** NmObj
** File description:
** symbol_type
*/

#ifndef SYMBOL_TYPE_H_
    #define SYMBOL_TYPE_H_

    #include <stdbool.h>

char print_type(Elf64_Sym sym, Elf64_Shdr *shdr);
bool is_valid_extension(void *buf);

#endif /* !SYMBOL_TYPE_H_ */
