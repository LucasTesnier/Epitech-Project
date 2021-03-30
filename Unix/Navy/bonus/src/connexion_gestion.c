/*
** EPITECH PROJECT, 2020
** connexion_gestion.c
** File description:
** all connexion function
*/

#include "navy.h"

static void connexion_gestion_client(int ac, game_info_t *game_inf,
char *argv[])
{
    if (ac == 3) {
        game_inf->is_server = false;
        game_inf->pid_two = my_getnbr(argv[1]);
        kill(game_inf->pid_two, SIGUSR2);
        timer(100000);
        kill(game_inf->pid_two, SIGUSR1);
        pause();
        pause();
        if (signal_storage.signal == 1) {
            kill(game_inf->pid_two, SIGUSR2);
            timer(100000);
            kill(game_inf->pid_two, SIGUSR1);
            pause();
            pause();
            if (signal_storage.signal == 1) {
//                my_putstr("successfully connected\n\n");
                kill(game_inf->pid_two, SIGUSR2);
            }
        }
    }
}

static void connexion_gestion_server(game_info_t *game_inf)
{
    if (signal_storage.signal == 1) {
        //       my_putstr("enemy connected\n\n");
        game_inf->pid_two = signal_storage.sender_pid;
        kill(signal_storage.sender_pid, SIGUSR2);
        timer(100000);
        kill(signal_storage.sender_pid, SIGUSR1);
        pause();
    }
}

void connexion_gestion(int ac, char *argv[], game_info_t *game_inf, sfRenderWindow *window)
{
    sfEvent event;

    game_inf->pid = getpid();
    my_putstr("my_pid: ");
    my_put_nbr(game_inf->pid);
    my_putchar('\n');
    if (ac == 2) {
        game_inf->is_server = true;
        //my_putstr("waiting for enemy connection...\n\n");
        while (signal_storage.signal != 1) {
            while (sfRenderWindow_pollEvent(window, &event)) {
                if (event.type == sfEvtClosed) {
                    sfRenderWindow_close(window);
                    return;
                }
                if (event.type == sfEvtKeyPressed)
                    if (event.key.code == sfKeyEscape) {
                        sfRenderWindow_close(window);
                        return;
                    }
            }
            
        }
        signal_storage.signal = 0;
        kill(signal_storage.sender_pid, SIGUSR2);
        timer(100000);
        kill(signal_storage.sender_pid, SIGUSR1);
        pause();
        pause();
        connexion_gestion_server(game_inf);
    }
    connexion_gestion_client(ac, game_inf, argv);
}
