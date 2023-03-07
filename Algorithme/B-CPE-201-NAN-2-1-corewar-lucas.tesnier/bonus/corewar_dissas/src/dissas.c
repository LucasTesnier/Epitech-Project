/*
** EPITECH PROJECT, 2021
** corewar_dissas
** File description:
** get_cor_file
*/

#include "dissas.h"

void write_meta_data(dissas_t *dump)
{
    fwrite(".name \"", 7, 1, dump->asm_fp);
    fwrite(dump->meta_data->prog_name, strlen(dump->meta_data->prog_name), 1, dump->asm_fp);
    fwrite("\"\n.comment \"", 12, 1, dump->asm_fp);
    fwrite(dump->meta_data->comment, strlen(dump->meta_data->comment), 1, dump->asm_fp);
    fwrite("\"\n\n", 3, 1, dump->asm_fp);
}

dissas_t *init_dissas()
{
    dissas_t *new_dissas = calloc(1, sizeof(dissas_t));

    if (!new_dissas)
        return (NULL);
    new_dissas->meta_data = calloc(1, sizeof(header_t));
    if (!new_dissas->meta_data)
        return (NULL);
    return (new_dissas);
}
