/*
** EPITECH PROJECT, 2022
** NmObj
** File description:
** objdump_gestion
*/

#ifndef OBJDUMP_GESTION_H_
    #define OBJDUMP_GESTION_H_

    #include <elf.h>

int objdump_start(int ac, char **av);
int objdump_analyze(char *path);
void *objdump_get_file_content(char *path);
void objdump_data_traitment(void *buf);

#endif /* !OBJDUMP_GESTION_H_ */
