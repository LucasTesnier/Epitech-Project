/*
** EPITECH PROJECT, 2020
** attack_defense_gestion.c
** File description:
** all defense and function gestion
*/

#include "navy.h"

void attack_gestion(game_info_t *game_inf, char *shot)
{
    char cases = shot[0] - 'A';
    char zone = shot[1] - '1';
    struct timespec tim = {.tv_nsec = 100, .tv_sec = 0};

    kill(game_inf->pid_two, SIGUSR2);
    while (nanosleep(&tim, &tim) < 0)
        nanosleep(&tim, &tim);
    send_signal(zone + 1, game_inf);
    pause();
    send_signal(cases + 1, game_inf);
    pause();
    timer(2000000);
    if (signal_storage.signal == 2)
        receive_attack_info(shot, game_inf, false);
    if (signal_storage.signal == 3)
        receive_attack_info(shot, game_inf, true);
    kill(game_inf->pid_two, SIGUSR2);
}

static void defense_gestion_two(int cases, int zone, game_info_t *game_inf)
{
    if (zone + 1 == 0)
        zone++;
    my_putchar(cases + 'A');
    my_put_nbr(zone + 1);
    if (game_inf->player_map[zone][cases] > 0) {
        write(1, ": hit\n\n", 7);
        game_inf->player_map[zone][cases] = -2;
        send_signal(3, game_inf);
    } else {
        write(1, ": missed\n\n", 10);
        game_inf->player_map[zone][cases] = -1;
        send_signal(2, game_inf);
    }
    pause();
}

void defense_gestion(game_info_t *game_inf)
{
    int zone = 0;
    int cases = 0;
    struct timespec tim;

    tim.tv_sec = 0;
    tim.tv_nsec = 100;
    pause();
    timer(8000000);
    zone = signal_storage.signal - 1;
    signal_storage.signal = 0;
    kill(game_inf->pid_two, SIGUSR2);
    pause();
    timer(8000000);
    cases = signal_storage.signal - 1;
    kill(game_inf->pid_two, SIGUSR2);
    while (nanosleep(&tim, &tim) < 0)
        nanosleep(&tim, &tim);
    defense_gestion_two(cases, zone, game_inf);
}
