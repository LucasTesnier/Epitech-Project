/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** function main
*/

#include "proto.h"

int main(int ac, char **argv, char **env)
{
    old_commands_t old_commands;

    old_commands.old_commands = mem_alloc_2d_array(100, 1000);
    old_commands.command_nbr = 0;
    old_commands.actual = 0;
    old_commands.to_print = false;
    shell_start(env, &old_commands);
    return (0);
}
