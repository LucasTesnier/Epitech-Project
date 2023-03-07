/*
** EPITECH PROJECT, 2020
** proto.h
** File description:
** prototypes of all the function
*/

#ifndef __bsShell__
#define __bsShell_

#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <dirent.h>
#include <sys/signal.h>
#include <sys/stat.h>

//UTILS.C//

int my_str_search(char *command, char c);
bool is_directory(char *command);
char **mem_alloc_2d_array(int nb_rows, int nb_cols);
void my_puterror(char *str);

//REDIRECTION_GESTION.C//

void execute_redirection_type_one(char **envp, char *command, \
int pipe_pos, int type);
void execute_redirection_type_two(char **envp, char *command, \
int pipe_pos, int type);
void execute_redirection_type_three(char **envp, char *command, \
int pipe_pos, int type);
void execute_redirection(char **envp, char *command, int pipe_pos, int type);
int get_redirection_pos(char *command, int *type);

//PATH_GESTION.C//

char *path_detection_three(char *command);
char *path_detection_two(char *command);
char *path_detection(char **envp, char *command, int pose);
char *get_path(char **envp, char *command);

//ENV_PARSING.C//

char *pick_env_info(char *envp_i);
int get_env_length(char *str);
char *get_in_env(char **envp, char *name, int *pos);
void my_strccat(char **envp, int pos, char *replace, char *var);
void replace_var(char **envp, char *var, char *valeur, int overwrite);

//USER_ACTION.C//

void put_prompt(void);
char *get_str(void);

//PIPE_GESTION.C//

void execute_pipe_first_child(char **envp, char *command, \
int pipe_pos, int *fd);
void execute_pipe_second_child(char **envp, char *command, \
int pipe_pos, int *fd);
void execute_pipe_first_parent(char **envp, char *command, \
int pipe_pos, int *fd);
void execute_pipe(char **envp, char *command, int pipe_pos);
bool is_a_bultin(char *str);

//SETUP.C//

char *prepare_shell(char *command, char *path);
char **segmentation(char *str);
int count_args(char *str);
void shell_error_message(int status);
void shell(char *str, char **args, char **envp);

//COMMAND_SEGMENTATION.C//

char **segmentation_c(char *command, char *separators);
bool multiple_command(char *command, int *pos);
char *check_integrity(char *command);
void change_path_name(char *path);

//ENV_BULTINS.C//

bool setenv_error_message(char **argv, char **envp);
void setenv_new(char **envp, char **argv);
int get_envp_size(char **envp);
char **dup_env(char **envp, int pos);
void display_env(char **envp);

//SHELL.C//

int execute_bultin(char *command, char **envp);
int count_word(char *command);
int shell_execute_command(char **envp, char *command);
void shell_start(char **envp);

//BULTINS.C//

bool is_alpha(char c);
void execute_setenv(char **envp, char **argv);
void execute_unsetenv(char **envp, char **argv);
int execute_bultin_env(char *command, char **envp, char **argv);

//REDIRECTION_ACTION.C//

int open_file(char *path, int type);
int get_double_redir_input(char *word);

//COMMAND_REPARTITION.C//

void shell_command_repartition_verification(char **envp, char *command);
void shell_command_repartition_execute_simple_command(char **envp, \
char *command, bool fos);
void shell_command_repartition(char **envp, char *command, bool fos);

//EXECUTE_CD.C//

void execute_cd_back_two(char **argv, char **envp, int *pos, char *pwd);
int execute_cd_back(char **argv, char **envp, int pos, char *pwd);
void execute_cd_two(char **argv, char **envp, int pos, char *pwd);
void execute_cd(char **argv, char **envp);

//MAIN.C//

char **copy_env(char **envp);
int main(int ac, char **argv, char **envp);

#endif