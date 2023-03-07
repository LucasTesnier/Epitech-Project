/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-lucas.tesnier
** File description:
** parse_file
*/

#include "op.h"
#include "asm.h"
#include "instructions.h"
#include "my.h"

filedata_t *init_filedata(void)
{
    filedata_t *new_op = malloc(sizeof(filedata_t));

    if (!new_op)
        exit(84);
    new_op->array = NULL;
    new_op->op = 0;
    new_op->is_label = false;
    new_op->size = NULL;
    new_op->to_write = NULL;
    return (new_op);
}

char *my_saferbuffer(char *buff)
{
    char *safe = my_calloc_char(sizeof(char), my_strlen(buff) + 3, 0);

    if (!safe)
        exit(84);
    my_strcpy(safe, buff);
    safe[my_strlen(safe)] = '\n';
    safe[my_strlen(safe)] = '\0';
    return (safe);
}

/**
* @brief retrive asm instructions from file and insert them into a LL
* exits on error
* @param file_buffer 
* @return list_t * 
*/
list_t *parse_file(char *file_buffer)
{
    char *cursor = my_saferbuffer(file_buffer);
    list_t *new_list = NULL;

    while ((cursor = my_strchr(cursor, "\n"))){
        cursor++;
        while (*cursor == ' ' || *cursor == '\t')
            cursor++;
        if (*cursor && *cursor != '\n' && *cursor != COMMENT_CHAR
        && *cursor != *NAME_CMD_STRING){
            new_list = insert_into_instructions(new_list,
            create_instruction(cursor));
        }
    }
    parse_labels(new_list);
    return (new_list);
}
