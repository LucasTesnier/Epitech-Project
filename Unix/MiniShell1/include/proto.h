/*
** EPITECH PROJECT, 2020
** Include
** File description:
** 104
*/

#ifndef __bsShell__

#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

//shell.c\\

int execute_bultin(char *command, char **envp);
int count_word(char *command);
char **segmentation_c(char *command, char *separators);
int shell_execute_command(char **envp, char *command);
void shell_start(char **envp);

//bultins.c\\

void execute_cd_two(char **argv, char **envp, int pos, char *pwd);
void execute_cd(char **argv, char **envp);
void execute_setenv(char **envp, char **argv);
void execute_unsetenv(char **envp, char **argv);
int execute_bultin_env(char *command, char **envp, char **argv);

//env_parsing.c\\

void display_env(char **envp);
char *pick_env_info(char *envp_i);
char *get_in_env(char **envp, char *name, int *pos);
void my_strccat(char **envp, int pos, char *replace, char *var);
void replace_var(char **envp, char *var, char *valeur, int overwrite);

//path_gestion.c\\

void put_prompt(void);
char *get_str(void);
int my_str_search(char *command, char c);
char *path_detection(char **envp, char *command, int pose);
char *get_path(char **envp, char *command);

//setup.c\\

char *prepare_shell(char *command, char *path);
char **mem_alloc_2d_array(int nb_rows, int nb_cols);
char **segmentation(char *str);
int count_args(char *str);
void shell(char *str, char **args, char **envp);

#define __bsShell__
#endif
