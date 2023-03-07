/*
** EPITECH PROJECT, 2022
** NmObj
** File description:
** data_traitment_64
*/

#include "data_traitment_64.h"
#include "is_valid_extension.h"
#include "objdump_data.h"
#include <stdio.h>

/**
* @brief traitment of the 64 bits data
*
* @param elfEhdr
* @param buf
*/
void objdump_data_traitment_64(Elf64_Ehdr *elfEhdr, void *buf)
{
    Elf64_Shdr *shdr = (Elf64_Shdr *) (buf + elfEhdr->e_shoff);
    char *str = (char *) (buf + shdr[elfEhdr->e_shstrndx].sh_offset);

    for (int i = 0; i < elfEhdr->e_shnum; i++) {
        if (shdr[i].sh_size)
            section_display_info_64(shdr[i], elfEhdr, str);
    }
}

/**
* @brief display information of all the sections 64 bits
*
*/
void section_display_info_64(Elf64_Shdr section, Elf64_Ehdr *elfEhdr, \
char *str)
{
    if (!is_valid_section(&str[section.sh_name]))
        return;
    printf("Contents of section %s:\n", &str[section.sh_name]);
    for (unsigned int temp = section.sh_offset; temp < (unsigned int)
    (section.sh_offset + section.sh_size); temp += 16) {
        printf(" %04x ", (unsigned int)(section.sh_addr + temp - \
        section.sh_offset));
        section_display_data((unsigned char *)elfEhdr + temp, \
        section.sh_offset + section.sh_size - temp);
        printf("\n");
    }
}