/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** asm
*/

#include "asm.h"
#include "read_file.h"
#include "my.h"
#include "champions.h"
#include "parsing.h"
#include <stdlib.h>
#include <stddef.h>

void get_good_parsed_file(char *file)
{
    for (int i = 0; i < my_strlen(file); i++) {
        if (file[i] == LABEL_CHAR && file[i + 1] == ' ')
            file[i + 1] = '\n';
    }
}

int execute_asm(char **av)
{
    char *file = readfile(av[1]);
    header_t *header = my_calloc(1, sizeof(header_t), 0);
    list_t *list;

    if (file == NULL || !header) {
        write(2, "Invalid File.\n", 14);
        return (-1);
    }
    if (fill_header_struct(file, header) != 0)
        return (-1);
    get_good_parsed_file(file);
    list = parse_file(file);
    if (!list)
        return (-1);
    header->prog_size = get_program_size(list);
    header->prog_size = SWAP(header->prog_size);
    write_into_cor_file(list, header, av[1]);
    return (0);
}

int run_prgm(int ac, char **av)
{
    int err = error_handling(ac, av);

    if (err == 1)
        return (0);
    if (execute_asm(av) < 0)
        return (84);
    return (0);
}