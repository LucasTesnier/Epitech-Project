/*
** EPITECH PROJECT, 2022
** NmObj
** File description:
** nm_gestion
*/

#include "nm_gestion.h"
#include "symbol_type.h"
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdbool.h>

/**
* @brief start the nm function (Hold the args)
*
* @param ac
* @param av
* @return int
*/
int nm_start(int ac, char **av)
{
    int count = 0;

    if (ac == 1)
        return nm_analyze("a.out");
    for (int i = 1; i < ac; i++) {
        if (ac != 2)
            printf("\n%s:\n", av[i]);
        (nm_analyze(av[i]) == 1) ? count++ : count;
    }
    return (count == 0) ? 0 : 1;
}

/**
* @brief hold the analyze process of the elf file
*
* @param path
* @return int
*/
int nm_analyze(char *path)
{
    void *buf = nm_get_file_content(path);

    if (buf == NULL)
        return 1;
    if (!is_valid_extension(buf)) {
        fprintf(stderr, "nm: %s: file format not recognized\n", path);
        return 1;
    }
    if (!nm_data_traitment(buf))
        fprintf(stderr, "nm: %s: no symbols\n", path);
    return 0;
}

/**
* @brief get the elf file content
*
* @param path
* @return void*
*/
void *nm_get_file_content(char *path)
{
    int fd = open(path, O_RDONLY);
    struct stat s;
    void *buf;

    if (fd == -1) {
        fprintf(stderr, "nm: '%s': No such file\n", path);
        close(fd);
        return NULL;
    }
    fstat(fd, &s);
    buf = mmap(NULL, s.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (buf == (void *)-1) {
        fprintf(stderr, "nm: %s: file format not recognized\n", path);
        munmap(buf, s.st_size);
        close(fd);
        return NULL;
    }
    close(fd);
    return buf;
}

/**
* @brief traitmen of the data contains in the elf file
*
* @param buf
*/
bool nm_data_traitment(void *buf)
{
    sym_t *head = init_sym();
    Elf64_Ehdr *elfEhdr = buf;
    Elf64_Shdr *shdr = (Elf64_Shdr *) (buf + elfEhdr->e_shoff);
    Elf64_Shdr *symtab;
    Elf64_Shdr *strtab;
    char *str = (char *) (buf + shdr[elfEhdr->e_shstrndx].sh_offset);

    for (int i = 0; i < elfEhdr->e_shnum; i++) {
        if (shdr[i].sh_size && strcmp(&str[shdr[i].sh_name], ".symtab") == 0)
            symtab = (Elf64_Shdr *) &shdr[i];
        if (shdr[i].sh_size && strcmp(&str[shdr[i].sh_name], ".strtab") == 0)
            strtab = (Elf64_Shdr *) &shdr[i];
    }
    return nm_data_result(buf, symtab, strtab, head);
}

/**
* @brief use the result of the analyze
*
* @param buf
* @param symtab
* @param strtab
* @param head
*/
bool nm_data_result(void *buf, Elf64_Shdr *symtab,
Elf64_Shdr *strtab, sym_t *head)
{
    Elf64_Ehdr *elfEhdr = buf;
    Elf64_Shdr *shdr = (Elf64_Shdr *) (buf + elfEhdr->e_shoff);
    Elf64_Sym *sym = (Elf64_Sym*) (buf + symtab->sh_offset);
    char *str = (char *) (buf + strtab->sh_offset);

    for (size_t i = 1; i < symtab->sh_size / symtab->sh_entsize; i++) {
        if (sym[i].st_info != STT_SECTION && sym[i].st_info != STT_FILE)
            add_sym_node(head, str + sym[i].st_name, sym[i].st_value,
            print_type(sym[i], shdr));
    }
    sort_sym_node(head);
    display_sym_node(head);
    if (head->size == 0)
        return false;
    return true;
}