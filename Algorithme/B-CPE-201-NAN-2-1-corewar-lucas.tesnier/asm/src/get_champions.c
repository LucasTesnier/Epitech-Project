/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** get_champion
*/

#include "my.h"
#include "asm.h"
#include "champions.h"
#include <stdlib.h>

char *get_string_between_hat(char *str)
{
    char **buffer = my_strtok(str, "\"");
    char *res = my_strdup(buffer[0]);

    my_free_char_array(buffer);
    return (res);
}

char *get_champion_name(char *file)
{
    char **buffer = my_strtok(file, "\n");
    char *str = NULL;
    char *tmp;

    if (!buffer)
        exit(84);
    for (int i = 0; buffer[i]; i++) {
        tmp = buffer[i];
        while (*tmp == ' ' || *tmp == '\t')
            tmp++;
        if (my_strncmp(tmp, NAME_CMD_STRING, 5) == 0) {
            str = get_string_between_hat(tmp + 7);
            break;
        }
    }
    my_free_char_array(buffer);
    return (str);
}

char *get_champion_comment(char *file)
{
    char **buffer = my_strtok(file, "\n");
    char *str = NULL;
    char *tmp;

    for (int i = 0; buffer[i]; i++) {
        tmp = buffer[i];
        while (*tmp == ' ' || *tmp == '\t')
            tmp++;
        if (my_strncmp(tmp, COMMENT_CMD_STRING, 7) == 0) {
            str = get_string_between_hat(tmp + 9);
            break;
        }
    }
    my_free_char_array(buffer);
    return (str);
}

int check_champion_data(char *temp, char *temp_two)
{
    if (temp == NULL) {
        write(2, "Invalid Champion Name.\n", 24);
        return (-1);
    }
    if (temp_two == NULL) {
        write(2, "Invalid Champion Description.\n", 31);
        return (-1);
    }
    return (0);
}

int fill_header_struct(char *file, header_t *header)
{
    char *temp = NULL;
    char *temp_two = NULL;

    temp = get_champion_name(file);
    temp_two = get_champion_comment(file);
    if (check_champion_data(temp, temp_two) < 0)
        return (-1);
    for (int i = 0; i <= PROG_NAME_LENGTH; i++)
        header->prog_name[i] = '\0';
    for (int i = 0; i <= COMMENT_LENGTH; i++)
        header->comment[i] = '\0';
    my_strncpy(header->prog_name, temp, PROG_NAME_LENGTH);
    my_strncpy(header->comment, temp_two, COMMENT_LENGTH);
    header->magic = COREWAR_EXEC_MAGIC;
    header->magic = SWAP(header->magic);
    return (0);
}
