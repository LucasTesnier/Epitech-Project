/*
** EPITECH PROJECT, 2020
** setup_navy.c
** File description:
** all function needed for the setup
*/

#include "navy.h"

void handler_usr_one(int sig, siginfo_t *info, void *nul)
{
    signal_storage.signal = signal_storage.signal + 1;
    signal_storage.sender_pid = info->si_pid;
}

void handler_usr_two(int sig, siginfo_t *info, void *nul)
{
    signal_storage.signal = 0;
    signal_storage.sender_pid = info->si_pid;
}

void timer(int time)
{
    struct timespec tim;

    tim.tv_sec = 0;
    tim.tv_nsec = time;
    while (nanosleep(&tim, &tim) < 0)
        nanosleep(&tim, &tim);
}

void send_signal(int nb, game_info_t *game_inf)
{
    struct timespec tim;
    tim.tv_sec = 0;

    for (int i = 0; i < nb; i++) {
        tim.tv_nsec = 400000;
        kill(game_inf->pid_two, SIGUSR1);
        while (nanosleep(&tim, &tim) < 0)
            nanosleep(&tim, &tim);
    }
}

int setup_navy(int ac, char *argv[], game_info_t *game_inf)
{
    struct sigaction usr_one;
    struct sigaction usr_two;
    struct sigaction usr_one_old;
    struct sigaction usr_two_old;

    if (!game_inf)
        return (84);
    sigemptyset(&usr_one.sa_mask);
    sigemptyset(&usr_two.sa_mask);
    usr_one.sa_flags = SA_SIGINFO;
    usr_two.sa_flags = SA_SIGINFO;
    usr_one.sa_sigaction = handler_usr_one;
    usr_two.sa_sigaction = handler_usr_two;
    sigaction(SIGUSR1, &usr_one, &usr_one_old);
    sigaction(SIGUSR2, &usr_two, &usr_two_old);
    connexion_gestion(ac, argv, game_inf);
    sigemptyset(&usr_one.sa_mask);
    sigemptyset(&usr_two.sa_mask);
    signal_storage.signal = 0;
    return (0);
}
