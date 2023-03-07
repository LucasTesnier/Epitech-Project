/*
** EPITECH PROJECT, 2022
** NmObj
** File description:
** data_traitment_32
*/

#ifndef DATA_TRAITMENT_32_H_
    #define DATA_TRAITMENT_32_H_

    #include <elf.h>

void objdump_data_traitment_32(Elf64_Ehdr *elfEhdr, void *buf);
void section_display_info_32(Elf32_Shdr section, Elf64_Ehdr *elfEhdr, \
char *str);

#endif /* !DATA_TRAITMENT_32_H_ */
