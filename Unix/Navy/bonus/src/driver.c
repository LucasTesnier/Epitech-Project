/*
** EPITECH PROJECT, 2020
** B-PSU-101-NAN-1-1-navy-lucas.tesnier
** File description:
** driver
*/
#include "navy.h"

int driver_game_gestion_server(game_info_t *game_inf, char *a_pos)
{
//    char *a_pos;

    //   while (!(a_pos = get_attack_pos(game_inf)));
    attack_gestion(game_inf, a_pos);
    signal_storage.signal = 0;
    pause();
/*    if (signal_storage.signal > 0){
        display_game(game_inf);
        write(1, "I won\n\n", 8);
        return (0);
        }*/
    game_inf->is_server = false;
    return (1);
}

int driver_game_gestion_client(game_info_t *game_inf)
{
//    write(1, "waiting for enemy's attack...\n", 31);
    defense_gestion(game_inf);
    /*if (is_gameover(game_inf)){
        timer(1);
        kill(game_inf->pid_two, SIGUSR1);
        display_game(game_inf);
        write(1, "Enemy won\n\n", 12);
        return (1);
        }*/
    timer(200000);
    kill(game_inf->pid_two, SIGUSR2);
    game_inf->is_server = true;
    return (0);
}

int driver(int ac, char *av[], game_info_t *game_inf, sfRenderWindow *window)
{
    char *a_pos;
    int attack_result;

    initialisation_map(game_inf);
    if (!getcheck_file(av[ac - 1], game_inf))
        return (84);
    setup_navy(ac, av, game_inf, window);
/*    display_game(&game_inf);
    while (true) {
        if (game_inf.is_server) {
            if (driver_game_gestion_server(a_pos, &game_inf) == 0)
                return (0);
        } else {
            if (driver_game_gestion_client(&game_inf) == 1)
                return (1);
        }
        display_game(&game_inf);
        }*/
    return (0);
}
