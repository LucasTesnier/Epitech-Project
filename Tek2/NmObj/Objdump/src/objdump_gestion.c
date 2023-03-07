/*
** EPITECH PROJECT, 2022
** NmObj
** File description:
** objdump_gestion
*/

#include "objdump_gestion.h"
#include "is_valid_extension.h"
#include "objdump_data.h"
#include "data_traitment_64.h"
#include "data_traitment_32.h"
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdbool.h>

/**
* @brief start the objdump function (Hold the args)
*
* @param ac
* @param av
* @return int
*/
int objdump_start(int ac, char **av)
{
    int count = 0;

    if (ac == 1)
        return objdump_analyze("a.out");
    for (int i = 1; i < ac; i++)
        (objdump_analyze(av[i]) == 1) ? count++ : count;
    return (count == 0) ? 0 : 1;
}

/**
* @brief hold the analyze process of the elf file
*
* @param path
* @return int
*/
int objdump_analyze(char *path)
{
    void *buf = objdump_get_file_content(path);

    if (buf == NULL)
        return 1;
    if (!is_valid_extension(buf)) {
        fprintf(stderr, "objdump: %s: file format not recognized\n", path);
        return 1;
    }
    printf("\n%s:\t", path);
    objdump_data_traitment(buf);
    return 0;
}

/**
* @brief get the elf file content
*
* @param path
* @return void*
*/
void *objdump_get_file_content(char *path)
{
    int fd = open(path, O_RDONLY);
    struct stat s;
    void *buf;

    if (fd == -1) {
        fprintf(stderr, "objdump: '%s': No such file\n", path);
        close(fd);
        return NULL;
    }
    fstat(fd, &s);
    buf = mmap(NULL, s.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (buf == (void *)-1) {
        fprintf(stderr, "objdump: %s: file format not recognized\n", path);
        munmap(buf, s.st_size);
        close(fd);
        return NULL;
    }
    close(fd);
    return buf;
}

/**
* @brief traitment of the file data
*
* @param buf
*/
void objdump_data_traitment(void *buf)
{
    Elf64_Ehdr *elfEhdr = buf;

    if (strcmp(get_architecture(elfEhdr->e_machine), "i386") == 0) {
        display_header(elfEhdr, false);
        objdump_data_traitment_32(elfEhdr, buf);
    } else {
        display_header(elfEhdr, true);
        objdump_data_traitment_64(elfEhdr, buf);
    }
}