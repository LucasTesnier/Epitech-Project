/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-lucas.tesnier
** File description:
** create_instruction
*/

#include "asm.h"
#include "instructions.h"
#include "parsing.h"
#include "op.h"
#include "my.h"

static int get_op(char *op)
{
    while (*op && (*op == '\t' || *op == ' '))
        op++;
    for (int i = my_strlen(op) - 1; (op[i] == '\t' || op[i] == ' '); i--)
        op[i] = '\0';
    for (int i = 0; op_tab[i].code; i++)
        if (my_strcmp(op, op_tab[i].mnemonique) == 0)
            return (op_tab[i].code);
    return (0);
}

static void init_args_coding_std_compliant(filedata_t *entry, char **args)
{
    arg_entry_t ae;

    for (int i = 1; i <= op_tab[entry->op - 1].nbr_args; i++){
        if (check_arg_type(op_tab[entry->op - 1].type[i - 1], args[i]) == -1) {
            my_print_char_two_d_array(args);
            my_putstr_error("\nwrong arg detected\n");
            exit(84);
        }
        ae.op_code = entry->op;
        ae.entry = entry->to_write + i;
        ae.arg = args[i];
        ae.arg_idx = i;
        if (!insert_towrite(&ae)) {
            entry->op = 0;
            return;
        }
        insert_size(entry->op, entry->size + i, args[i], i);
    }
}

static void init_args(filedata_t *entry, char **args)
{
    entry->op = get_op(args[0]);
    if (array_size(args) - 1 != (size_t)(op_tab[entry->op - 1].nbr_args)
    || (entry->op) == 0) {
        my_putstr_error(args[0]);
        my_putstr_error(" : invalid instruction\n");
        exit(84);
    }
    entry->to_write = my_calloc_int(sizeof(int), \
    op_tab[entry->op - 1].nbr_args + 2, 0);
    entry->size = my_calloc_int(sizeof(int), \
    op_tab[entry->op - 1].nbr_args + 2, 0);
    if (!entry->to_write || !entry->size)
        exit(84);
    entry->to_write[0] = entry->op;
    entry->size[0] = 1;
    init_args_coding_std_compliant(entry, args);
}

static filedata_t *fill_instruction(char *line, filedata_t *entry)
{
    char *tmp = my_strchr(line, "\n");
    char **args = NULL;

    *tmp = '\0';
    args = my_strtok(line, ", \t");
    if (!args)
        exit(84);
    entry->array = args;
    if (args[0][my_strlen(args[0]) - 1] == LABEL_CHAR) {
        args[0][my_strlen(args[0]) - 1] = '\0';
        entry->is_label = true;
        *tmp = '\n';
        return (entry);
    }
    init_args(entry, args);
    *tmp = '\n';
    return (entry);
}

/**
* @brief
* @param line
* @return
*/
filedata_t *create_instruction(char *line)
{
    filedata_t *new_entry = init_filedata();

    new_entry = fill_instruction(line, new_entry);
    return (new_entry);
}