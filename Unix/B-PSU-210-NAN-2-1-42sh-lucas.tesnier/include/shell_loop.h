/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** prototypes of all the function on the lib
*/

#ifndef SHELL_LOOP_
#define SHELL_LOOP_

#include <stdbool.h>
#include <glob.h>
#include "struct.h"

int shell_loop(my_shell_t *shell);
int shell_loop_upgraded(my_shell_t *shell);

//echo_bultin.c

int execute_echo(char **args);

//cd_bultin.c

void change_path(my_shell_t *shell, char *to_go);
bool cd_verification(my_shell_t *shell, char *to_go);
void execute_cd(my_shell_t *shell, char **args);

//env_bultins.c

void execute_unsetenv(my_shell_t *shell, char **args);
bool setenv_error(my_shell_t *shell, char **args);
void setenv_new(char **envp, char **args);
void execute_setenv(my_shell_t *shell, char **args);

//exit_bultin.c

void execute_bultin(int size, char **args, my_shell_t *shell);

//alias_bultin.c

void display_alias_content(alias_list_t *alias_list, char *name);
void sort_alias_list(alias_list_t *alias_list, int *change);
void create_new_alias(alias_list_t *alias_list, char *name, int *alias_pos);
void change_an_alias(alias_list_t *alias_list, char **content, int pos);
void execute_alias(char **args, my_shell_t *shell);

//alias_bultin_two.c

void display_alias(alias_list_t *alias_list);
int return_alias_pos(alias_list_t *alias_list, char *name);
char *alias_replace(char *command, alias_list_t *alias_list);
void execute_unalias(char **args, my_shell_t *shell);

//execute_classic_verif.c

bool classic_command_verif(my_shell_t *shell, char **args);
void shell_error_message(int status);

//execute_classic.c

void run_classic_command(int size, char **args, my_shell_t *shell);
char *cat_command_path(char *command, char *path);
void execute_classic(int size, my_shell_t *shell, my_command_t \
*command_stack, int *pos);
void execute_classic_command(int size,
char **args, my_shell_t *shell);

//execute_pipe.c

void execute_pipe_first_child(int size, my_shell_t *shell, int *pos, int *fd);
void execute_pipe_second_child(int size, my_shell_t *shell, int *pos, int *fd);
void execute_pipe_first_parent(int size, my_shell_t *shell, int *pos, int *fd);
void execute_pipe(int size, my_shell_t *shell, my_command_t *command_stack, \
int *pos);

//execute_redirection.c

void execute_redirection_one(int size, my_shell_t *shell, my_command_t \
*command_stack, int *pos);
void execute_redirection_two(int size, my_shell_t *shell, my_command_t \
*command_stack, int *pos);
void execute_redirection_three(int size, my_shell_t *shell, my_command_t \
*command_stack, int *pos);
int redirection_four_get_content(char *word);
void execute_redirection_four(int size, my_shell_t *shell, my_command_t \
*command_stack, int *pos);

//env_utils.c

void add_env_variable(char **envp, char **argv);
int get_envp_size(char **envp);
char **dup_env_without(char **envp, int pos);
void display_env(char **envp);
char **copy_env(char **envp);

//get_change_env.c

char *pick_env_info(char *envp_i);
int get_env_length(char *str);
char *get_in_env(char **envp, char *name, int *pos);
void my_strccat(char **envp, int pos, char *replace, char *var);
void replace_var(char **envp, char *var, char *valeur, int overwrite);

//auto_completion.c

void list_all_file(char *path, int *total, char **list, char *start);
void sort_auto_completion_list(char **list, int total, int *change);
void list_all_file_direct_path(char **list, int *total, char *start);
void auto_completion(char *command, char **env);

//draw_auto_completion.c

void draw_auto_completion_tab(char *list, int size);
void draw_auto_completion_list(char **list, int total);

//free_shell.c

void free_command_stack(my_command_t *command_stack);
void free_env(char **env);
void free_shell(my_shell_t *shell);

//prompt_action.c

void put_prompt(my_shell_t *shell);
char *get_prompt(my_shell_t *shell);
char *get_str(void);
char *get_str_char_per_char(my_shell_t *shell);

//shell_loop.c

bool my_str_two_search(char *str, char **list);
int shell_loop(my_shell_t *shell);

//shell_setup.c

my_command_t *setup_command_stack(void);
my_shell_t *setup_shell(char **main_env);
int shell_setup(char **main_env);

//clean_stack.c

char *stack_clean_command(char *command);
void get_a_new_stack(my_command_t *command_stack, my_shell_t *shell);
void get_a_new_stack_upgraded(my_command_t *command_stack, my_shell_t *shell);


//execute_stack.c

void all_type_stack(int size, my_shell_t *shell, \
my_command_t *command_stack, int *pos);
void execute_loop_stack(int size, my_shell_t *shell, \
my_command_t *command_stack, int pos);
void execute_stack(my_shell_t *shell);

//execute_and_or_stack.c

void execute_and_or_stack(int size, my_shell_t *shell, my_command_t \
*command_stack, int *pos);

//fill_stack_classic.c

int fill_stack(my_shell_t *shell, my_command_t *command_stack, char *command);

//fill_stack_pipe.c

void fill_stack_pipe(my_command_t *command_stack, char *command);

//fill_stack_and_or.c

void fill_stack_or(my_command_t *command_stack, char *command);
void fill_stack_and(my_command_t *command_stack, char *command);

//fill_stack_redirection.c

int fill_stack_redirection_one(my_command_t *command_stack, char *command);
int fill_stack_redirection_two(my_command_t *command_stack, char *command);
int fill_stack_redirection_three(my_command_t *command_stack, char *command);
int fill_stack_redirection_four(my_command_t *command_stack, char *command);
void fill_stack_redirection_global(my_command_t *command_stack, char *command);

//fill_stack_redirection_part_two.c

void fill_stack_redirection_write(my_command_t *command_stack, char *command, \
bool find, char **command_parse);

//fill_stack_separators.c

void fill_stack_separators(my_command_t *command_stack, char *command);

//fill_stack_ampersand.c

void fill_stack_ampersand(my_command_t *command_stack, char *command);

//return_position_stack.c

int stack_return_classic_pos(command_type_e *type, int pos, int size);
int stack_return_separators_pos(command_type_e *type, int pos, int size);
void check_amp(my_shell_t *shell, my_command_t *command_stack, int *pos);

//my_strtok.c

bool is_a_delimiter(char c, char *delimiters);
int how_many_word(char *str, char *delimiters);
char *catch_the_word(char *str, char *delimiters, int begin);
char **my_strtok(char *str, char *delimiters);
int my_str_return_last_pos(char *str, char find);

//globbings

char **globbings(char **args);
void free_poss(char ***poss);
char ***fill_triple_tab(char **args, int *size);
char **glob_list(char *str);
char **fill_tab(char **tab, glob_t globbuf);
char **is_single(char **tab, glob_t globbuf, char *str);
char **copy_in_final_tab(int size, char **args, char ***poss);

//transform_command.c

void transform_command(char **command, char *delimeters);

// verf_and_or_stack.c

bool verif_and_or_stack(my_shell_t *shell, char *cmd);

//local_var.c

void display_local_var(st_local_var *local_var,
my_shell_t *shell, int *change);
char *local_var_replace(char *command, my_shell_t *shell);
st_local_var *execute_set(char **args, my_shell_t *shell,
st_local_var *local_var);
st_local_var *check_local_var_names(st_local_var *local_var, char *name);
st_local_var *execute_unset(char **args, my_shell_t *shell,
st_local_var *local_var);
st_local_var *sort_local_var(st_local_var *local_var,
int *change, my_shell_t *shell);
st_local_var *check_local_var_name(st_local_var *local_var, char *name);
//inhibitor

int backslash_counter(char *command);
int check_bckslash_presence(char **args);
char *replace_double_bckslash(char *args_line);
char *fill_shell_backslash_list(char *command);
char *replace_bckslash(char *command, my_command_t *command_s);
void inhibitor(char **args, my_command_t *command_stack);

//utils.c

int arr_len(char **tab);
bool is_alpha(char c);
int my_str_search(char *command, char c);
bool is_directory(char *command);
char **mem_alloc_2d_array(int nb_rows, int nb_cols);
void my_puterror(char *str);
void print_arr(char **tab);
char *manage_str(char *src);

//my_history_list_create.c
my_hist_list_t *my_hist_list_create(void);
void my_hist_list_destroy(my_hist_list_t *list);

//my_hist_noad_create.c
my_hist_noad_t *my_hist_noad_create(char *line);
void my_hist_noad_destroy(my_hist_noad_t *noad);

//my_hist_list_tools.c
bool my_hist_list_add_at_beginning(my_hist_list_t *list, char *line);

//my_line_list_create.c
my_line_list_t *my_line_list_create(void);
void my_line_list_destroy(my_line_list_t *list);

//my_line_noad_create.c
my_line_noad_t *my_line_noad_create(char c);
void my_line_noad_destroy(my_line_list_t *line, my_line_noad_t *noad);

//my_line_list_add.c
bool my_line_list_add_at_beginning(my_line_list_t *list, char c);
bool my_line_list_add_before_cursor(my_line_list_t *list, char c);
bool my_line_list_add_after_cursor(my_line_list_t *list, char c);
bool my_line_list_add_at_end(my_line_list_t *list, char c);

//my_line_list_tools.c
char *my_line_list_transform_to_line(my_line_list_t *list);
void my_line_list_delete_before_cursor(my_line_list_t *line);
char *my_line_list_get_auto_completion_line(my_line_list_t *line);
void erase_line(my_shell_t *shell);
void write_line(my_shell_t *shell);

//my_line_list_new_line_check.c
bool new_line_mandatory_exec(my_shell_t *shell, char *line);
bool new_line_mandatory_hist(my_shell_t *shell, char *line);

//my_line_list_chage_hist.c
bool my_line_list_change_older_hist(my_shell_t *shell);
bool my_line_list_change_newer_hist(my_shell_t *shell);

//my_line_list_cursor.c
bool my_line_list_move_cursor_to_left(my_line_list_t *list);
bool my_line_list_move_cursor_to_right(my_line_list_t *list);

//prompt_manager.c
bool check_backspace(my_shell_t *shell, char c);
bool check_ctrl_d(my_shell_t *shell, char c);
bool check_auto_completion(my_shell_t *shell, char c);
char *check_new_line(my_shell_t *shell, char c);
bool check_escape_sequence(my_shell_t *shell, char c);

//char_manage.c
char *c_manage_2(my_shell_t *shell, char c);

#endif