/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** prototypes of all the function on the lib
*/

#ifndef STRUCT_
#define STRUCT_

#include <termios.h>

#define END_STATUS -1
#define GO_STATUS 1
#define MAX_STACK_LENGTH 3000

typedef struct local_var {
    char *name;
    char *data;
    struct local_var *next;
} st_local_var;

typedef enum {
    NONE,
    CLASSIC,
    REDIRECTION_ONE,
    REDIRECTION_TWO,
    REDIRECTION_THREE,
    REDIRECTION_FOUR,
    PIPE,
    SEPARATORS,
    AND,
    OR,
} command_type_e;

typedef struct my_hist_noad_s
{
    int id;
    char *line;
    struct my_hist_noad_s *prev;
    struct my_hist_noad_s *next;
}my_hist_noad_t;

typedef struct my_hist_list_s
{
    int length;
    int next_id;
    my_hist_noad_t *first;
    my_hist_noad_t *last;
}my_hist_list_t;

typedef struct my_line_noad_s
{
    int id;
    char c;
    struct my_line_noad_s *prev;
    struct my_line_noad_s *next;
}my_line_noad_t;

typedef struct my_line_list_s
{
    int length;
    int next_id;
    my_line_noad_t *first;
    my_line_noad_t *last;
}my_line_list_t;

typedef struct my_command_s {
    char **command;
    command_type_e *command_type;
    int stack_length;
    char *backslash_list;
} my_command_t;

typedef struct my_alias_s {
    char *name;
    char *command;
} my_alias_t;

typedef struct alias_list_s {
    my_alias_t *alias;
    int nbr;
} alias_list_t;

typedef struct my_shell_s {
    int status;
    int return_value;
    int hist_id;
    char *temp_line;
    char *prompt;
    char **env;
    struct termios old;
    struct termios raw;
    my_line_list_t *line;
    my_hist_list_t *hist;
    st_local_var *local_var;
    my_command_t *command_stack;
    alias_list_t *alias_list;
    int process_status;
} my_shell_t;

#endif