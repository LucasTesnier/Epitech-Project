/*
** EPITECH PROJECT, 2022
** NmObj
** File description:
** symbol_type
*/

#include "sym.h"
#include <elf.h>
#include <stdbool.h>

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
* @brief Hold the complex type define
*
* @param sym
* @return char
*/
char get_complex_type(Elf64_Sym sym)
{
    if (ELF64_ST_BIND(sym.st_info) == STB_GNU_UNIQUE)
        return 'u';
    if (ELF64_ST_BIND(sym.st_info) == STB_WEAK && sym.st_shndx == SHN_UNDEF)
        return 'w';
    if (ELF64_ST_BIND(sym.st_info) == STB_WEAK)
        return 'W';
    if (ELF64_ST_BIND(sym.st_info) == STB_WEAK &&
        ELF64_ST_TYPE(sym.st_info) == STT_OBJECT && sym.st_shndx == SHN_UNDEF)
        return 'v';
    if (ELF64_ST_BIND(sym.st_info) == STB_WEAK &&
        ELF64_ST_TYPE(sym.st_info) == STT_OBJECT)
        return 'V';
    if (sym.st_shndx == SHN_UNDEF)
        return 'U';
    if (sym.st_shndx == SHN_ABS)
        return 'A';
    if (sym.st_shndx == SHN_COMMON)
        return 'C';
    return '?';
}

/**
* @brief Get the sh type of the symbole
*
* @param sym
* @param shdr
* @return char
*/
char get_sh_type(Elf64_Sym sym, Elf64_Shdr *shdr)
{
    if (shdr[sym.st_shndx].sh_type == SHT_NOBITS &&
        shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
        return 'B';
    if (shdr[sym.st_shndx].sh_type == SHT_PROGBITS &&
        shdr[sym.st_shndx].sh_flags == SHF_ALLOC)
        return 'R';
    if (shdr[sym.st_shndx].sh_type == SHT_PROGBITS &&
        shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
        return 'D';
    if (shdr[sym.st_shndx].sh_type == SHT_PROGBITS &&
        shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_EXECINSTR))
        return 'T';
    if (shdr[sym.st_shndx].sh_type == SHT_DYNAMIC)
        return 'D';
    if (shdr[sym.st_shndx].sh_type == 15 || shdr[sym.st_shndx].sh_type == 14)
        return 'D';
    return '?';
}

/**
* @brief Put the type in maj if necessary
*
* @param sym
* @param c
* @return char
*/
char get_maj_type(Elf64_Sym sym, char c)
{
    if (ELF64_ST_BIND(sym.st_info) == STB_LOCAL && c != '?')
        c += 32;
    return c;
}

/**
* @brief display the type of the symb
*
* @param sym
* @param shdr
* @return char 
*/
char print_type(Elf64_Sym sym, Elf64_Shdr *shdr)
{
    char c;

    c = get_complex_type(sym);
    if (c == '?')
        c = get_sh_type(sym, shdr);
    return get_maj_type(sym, c);
}