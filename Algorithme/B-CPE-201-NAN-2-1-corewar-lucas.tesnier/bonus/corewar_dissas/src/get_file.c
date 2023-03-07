/*
** EPITECH PROJECT, 2021
** corewar_dissas
** File description:
** get_file
*/

#include "dissas.h"
#include "op.h"

static bool check_ext(char *ext, char *filepath)
{
    char *candidate = strrchr(filepath, '.');

    if (!ext)
        return (false);
    if (strcmp(ext,candidate) == 0)
        return (true);
    fprintf(stderr, "Invalid file extension : %s\n", candidate);
    return (false);
}

static bool create_asm_file(dissas_t *dissas, char *file_path)
{
    char *asm_file_path = file_path;

    if (!check_ext(".cor", file_path))
        return (false);
    while (asm_file_path[strlen(asm_file_path) - 1] != '.')
        asm_file_path[strlen(asm_file_path) - 1] = '\0';
    asm_file_path = strcat(asm_file_path, "asm");
    dissas->asm_fp = fopen(asm_file_path, "w+");
    if (!dissas->asm_fp){
        perror(asm_file_path);
        return (false);
    }
    return (true);
}

/// \brief dump .cor file into dissas struct
/// \param dissas
/// \param file_path
/// \return true / false wether dump went good
bool get_cor_file(dissas_t *dissas, char *file_path)
{
    FILE *f = fopen(file_path, "rb");

    if (!f) {
        perror("file_path");
        return (false);
    }
    fread(dissas->meta_data, sizeof(header_t), 1, f);
    dissas->meta_data->prog_size = SWAP(dissas->meta_data->prog_size);
    dissas->code = calloc(dissas->meta_data->prog_size + 1, sizeof (bytecode_t));
    fread(dissas->code, sizeof(bytecode_t), dissas->meta_data->prog_size + 1, f);
    fclose(f);
    if (!create_asm_file(dissas, file_path))
        return (false);
    return (true);
}
