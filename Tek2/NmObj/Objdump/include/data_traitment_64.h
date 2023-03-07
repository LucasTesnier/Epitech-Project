/*
** EPITECH PROJECT, 2022
** NmObj
** File description:
** data_traitment_64
*/

#ifndef DATA_TRAITMENT_64_H_
    #define DATA_TRAITMENT_64_H_

    #include <elf.h>

void section_display_info_64(Elf64_Shdr section, Elf64_Ehdr *elfEhdr, \
char *str);
void objdump_data_traitment_64(Elf64_Ehdr *elfEhdr, void *buf);

#endif /* !DATA_TRAITMENT_64_H_ */
