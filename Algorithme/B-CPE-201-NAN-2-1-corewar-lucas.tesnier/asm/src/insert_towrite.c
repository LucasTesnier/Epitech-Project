/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-lucas.tesnier
** File description:
** insert_towrite
*/

#include "op.h"
#include "parsing.h"
#include "my.h"
#include "instructions.h"

bool check_valid_label(char *candidate)
{
    if (!candidate)
        return (false);
    for (int i = 0; candidate[i]; i++)
        if (!my_strchr(LABEL_CHARS, candidate + i))
            return (false);
    return (true);
}

/**
* @brief insert into specific entry
*
* @param entry
* @param node
* @return true false
*/
bool insert_towrite_indirect(arg_entry_t *entry)
{
    if (entry->arg[0] == LABEL_CHAR) {
        if (!check_valid_label(entry->arg + 1)) {
            my_putstr_error("\nUnknown label : ");
            my_putstr_error(entry->arg + 1);
            my_putstr_error("\n");
            return (false);
        }
    }
    return (true);
}

bool insert_towrite(arg_entry_t *ae)
{
    if ((ae->arg[0] == DIRECT_CHAR && ae->arg[1] == LABEL_CHAR)) {
        if (!check_valid_label(ae->arg + 2)) {
            my_putstr_error("\nUnknown label : ");
            my_putstr_error(ae->arg + 2);
            my_putstr_error("\n");
            return (false);
        }
    }
    if (insert_towrite_indirect(ae) == false)
        return (false);
    if (ae->arg[0] == 'r' || ae->arg[0] == DIRECT_CHAR)
        *ae->entry = my_getnbr(ae->arg + 1);
    else
        *ae->entry = my_getnbr(ae->arg);
    return (true);
}
