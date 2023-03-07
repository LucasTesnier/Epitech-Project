/*
** EPITECH PROJECT, 2022
** NmObj
** File description:
** is_valid_extension
*/

#ifndef IS_VALID_EXTENSION_H_
    #define IS_VALID_EXTENSION_H_

    #include <stdbool.h>
    #include <elf.h>

bool is_valid_extension(void *buf);
bool is_valid_section(char *str);
char *get_architecture(int e_machine);
void display_header(Elf64_Ehdr *elfEhdr, bool is64);

#endif /* !IS_VALID_EXTENSION_H_ */
