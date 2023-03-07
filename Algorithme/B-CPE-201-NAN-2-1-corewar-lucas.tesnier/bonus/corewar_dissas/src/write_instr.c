/*
** EPITECH PROJECT, 2021
** corewar_dissas
** File description:
** write_instructions
*/

#include "op.h"
#include "dissas.h"

static int *get_params(bytecode_t code)
{
    int *params = calloc(4, sizeof(int));
    bytecode_t params_bc = code;

    if (!params)
        return (NULL);
    params[0] = (params_bc >> 6);
    params[1] = (params_bc >> 4) - (params[0] << 2);
    params[2] = (params_bc >> 2) - (params[0] << 4) - (params[1] << 2);
    return (params);
}

static int write_params_with_cbyte(dissas_t *dump, int index, int op, int param_type)
{
    char *param;

    if (param_type == 1){
        fwrite("r", sizeof(char), 1, dump->asm_fp);
        param = int_to_str(dump->code[index]);
        fwrite(param, sizeof(char), strlen(param), dump->asm_fp);
        free(param);
        return (1);
    }
    if (param_type == 2 && op != 8 && op != 9 && op != 10 && op != 11 && op != 13 && op != 14){
        param = int_to_str(get_dir_param(dump, index));
        fwrite("%", sizeof(char), 1, dump->asm_fp);
        fwrite(param, sizeof(char), strlen(param), dump->asm_fp);
        free(param);
        return (DIR_SIZE);
    }
    if (param_type == 2)
        fwrite("%", sizeof(char), 1, dump->asm_fp);
    param = int_to_str(get_ind_param(dump, index));
    fwrite(param, sizeof(char), strlen(param), dump->asm_fp);
    free(param);
    return (IND_SIZE);
}

static int write_params_with_cbyte_wrapper(dissas_t *dump, int index, int op)
{
    int *params = get_params(*(dump->code + index + 1));

    if (!params)
        return (-1);
    index ++;
    for (char i = 0; i < op_tab[op - 1].nbr_args; i++) {
        index += write_params_with_cbyte(dump, index + 1, op, params[i]);
        if (i + 1 < op_tab[op - 1].nbr_args)
            fwrite(", ", sizeof(char), 2, dump->asm_fp);
    }
    free(params);
    return (index);
}

static int write_params(dissas_t *dump, int index)
{
    char *param;

    if (dump->code[index] == 1 || dump->code[index] == 9 ||
            dump->code[index] == 12 || dump->code[index] == 15) {
        fwrite("%", sizeof(char), 1, dump->asm_fp);
        if (dump->code[index] == 1){
            param = int_to_str(get_dir_param(dump, index + 1));
            fwrite(param, sizeof(char), strlen(param), dump->asm_fp);
            free(param);
            return (DIR_SIZE + index);
        } else {
            param = int_to_str((int)get_ind_param(dump, index + 1));
            fwrite(param, sizeof(char), strlen(param), dump->asm_fp);
            free(param);
            return (IND_SIZE + index);
        }
//        param = dump->code[index];
//        param = param << 8;
//        param += dump->code[index + 1];
//        if (dump->code[index] == 1){
//            param = param << 8;
//            param += dump->code[index + 2];
//        }
//        param_towrite = int_to_str(param);
//        fwrite(param_towrite, sizeof(char), strlen(param_towrite), dump->asm_fp);
//        free(param_towrite);
//        return ((DIR_SIZE * dump->code[index] == 1) + (IND_SIZE * dump->code[index] != 1));
    } else
        return (write_params_with_cbyte_wrapper(dump, index, dump->code[index]));
}

/// \brief write into dump->cor_fd asm instructions from dump->code bytecode
/// \param dump
void write_instructions_from_bytecode(dissas_t *dump)
{
    for (int i = 0; i < dump->meta_data->prog_size; i++) {
        fwrite(op_tab[(size_t)(dump->code[i] - 1)].mnemonique, sizeof(char),
               strlen(op_tab[(size_t) (dump->code[i] - 1)].mnemonique), dump->asm_fp);
        fwrite(" ", sizeof(char), 1, dump->asm_fp);
        if ((i = write_params(dump, i)) == -1){
            fprintf(stderr, "Malloc failed");
            return;
        }
        fwrite("\n", sizeof(char), 1, dump->asm_fp);
    }
}