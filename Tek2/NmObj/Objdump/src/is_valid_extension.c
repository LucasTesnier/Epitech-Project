/*
** EPITECH PROJECT, 2022
** NmObj
** File description:
** is_valid_extension
*/

#include "is_valid_extension.h"
#include <elf.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static char *skipable_section[] = {
    "",
    ".bss",
    ".shstrtab",
    ".symtab",
    ".strtab",
    ".rela.text",
    ".rela.debug_info",
    ".rela.debug_aranges",
    ".rela.debug_line",
    ".rela.eh_frame",
    ".tbss",
    "__libc_freeres_ptrs",
    NULL
};

/**
* @brief check the magic number of the potential elf file
*
* @param buf
* @return true
* @return false
*/
bool is_valid_extension(void *buf)
{
    Elf64_Ehdr *elfEhdr = buf;

    if (elfEhdr->e_ident[EI_MAG0] != ELFMAG0)
        return false;
    if (elfEhdr->e_ident[EI_MAG1] != ELFMAG1)
        return false;
    if (elfEhdr->e_ident[EI_MAG2] != ELFMAG2)
        return false;
    if (elfEhdr->e_ident[EI_MAG3] != ELFMAG3)
        return false;
    return true;
}

/**
* @brief return true if is a non skipable section
*
* @param str
* @return true
* @return false
*/
bool is_valid_section(char *str)
{
    for (int i = 0; skipable_section[i] != NULL; i++) {
        if (!strcmp(str, skipable_section[i]))
            return false;
    }
    return true;
}

/**
* @brief Get the architecture info
*
* @param e_machine
* @return char*
*/
char *get_architecture(int e_machine)
{
    if (e_machine == EM_386)
        return "i386";
    if (e_machine == EM_X86_64)
        return "i386:x86-64";
    return "Unknown";
}

/**
* @brief display all the header information
*
* @param elfEhdr
* @param is64
*/
void display_header(Elf64_Ehdr *elfEhdr, bool is64)
{
    printf("file format %s\n", (is64 == true) ? "elf64-x86-64" : "elf32-i386");
    printf("architecture: %s, flags 0x%08x:\n", \
    get_architecture(elfEhdr->e_machine), elfEhdr->e_flags);
    printf("start adress 0x%016lx\n\n", elfEhdr->e_entry);
}