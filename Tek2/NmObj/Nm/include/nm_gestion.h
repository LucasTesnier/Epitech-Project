/*
** EPITECH PROJECT, 2022
** NmObj
** File description:
** nm_gestion
*/

#ifndef NM_GESTION_H_
    #define NM_GESTION_H_

    #include "sym.h"
    #include <elf.h>
    #include <stdbool.h>

int nm_start(int ac, char **av);
int nm_analyze(char *path);
void *nm_get_file_content(char *path);
bool nm_data_traitment(void *buf);
bool nm_data_result(void *buf, Elf64_Shdr *symtab,
Elf64_Shdr *strtab, sym_t *head);

#endif /* !NM_GESTION_H_ */
