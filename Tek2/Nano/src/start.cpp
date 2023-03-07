/*
** EPITECH PROJECT, 2022
** Nano
** File description:
** start
*/

#include <iostream>
#include "Error/Error.hpp"
#include "System/System.hpp"

/**
 * @brief verif the number of argument
 * 
 * @param ac 
 */

void verif_argument(int ac)
{
    if (ac != 2)
        throw nts::ErrorParser("Open file Failed : Not enough arguments.", "Verif_Argument : " + std::to_string(ac));
}

/**
 * @brief Starting the nts programm
 * 
 * @param ac 
 * @param av 
 * @return int 
 */

int start(int ac, char **av)
{
    try {
        nts::UserCommunication userCommunication = nts::UserCommunication();
        nts::System globalSystem = nts::System(userCommunication);

        verif_argument(ac);
        globalSystem.loop(av[1]);
        return globalSystem.getReturnValue();
    } catch (const nts::Error &error) {
        std::cout << error.what() << " " << error.getComponent() << std::endl;
        return 84;
    }
    return 0;
}