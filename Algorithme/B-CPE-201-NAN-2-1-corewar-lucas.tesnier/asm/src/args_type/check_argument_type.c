/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-lucas.tesnier
** File description:
** check_argument_type
*/


#include "asm.h"
#include "op.h"
#include "my.h"
#include "instructions.h"

bool check_label(char *arg)
{
    if (!arg)
        return (false);
    if (!arg[0])
        return (false);
    if (arg[0] != LABEL_CHAR)
        return (false);
    return (check_valid_label(arg + 1));
}

args_type_t check_indirect(char *arg)
{
    if (!arg)
        return (-1);
    if (my_str_isnum(arg) || check_label(arg))
        return (T_IND);
    return (-1);
}

args_type_t check_direct(char *arg)
{
    if (!arg)
        return (-1);
    if (!arg[0])
        return (false);
    if (arg[0] != DIRECT_CHAR)
        return (-1);
    if (!check_indirect(arg + 1))
        return (-1);
    return (T_DIR);
}

args_type_t check_register(char *arg)
{
    int reg_nbr = 0;

    if (!arg)
        return (-1);
    if (!arg[0])
        return (-1);
    if (arg[0] == 'r') {
        reg_nbr = my_ngetnbr(arg, 1);
        if (reg_nbr >= 1 && reg_nbr <= REG_NUMBER)
            return (T_REG);
    }
    return (-1);
}

/**
* @brief wrapper around argument checking
* @param arg_type
* @param arg
* @return true / false wether given arg is actually from the expected type
*/
args_type_t check_arg_type(args_type_t type, char *arg)
{
    int j = 0;
    args_type_t found_type = 1;
    args_type_t (*checkers[3])(char *) = {&check_register,
        &check_direct,
        &check_register};

    if (!arg)
        return (-1);
    for (; *arg && *arg == ' ' && *arg == '\t'; arg++);
    for (int i = 0; arg[i]; i++)
        if (arg[i] == ' ' || arg[i] == '\t')
            arg[i] = '\0';
    while (j < 3) {
        found_type = found_type << 2;
        if (checkers[j](arg) != -1)
            break;
        j++;
    }
    if (!(type | found_type) || j > 3)
        return (-1);
    return (type | found_type);
}