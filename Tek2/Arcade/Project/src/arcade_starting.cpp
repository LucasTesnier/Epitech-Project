/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** arcade_starting
*/

#include "Error/Error.hpp"
#include "Core/Core.hpp"
#include <iostream>

/**
 * @brief
 * display usage of program
 */
void display_usage()
{
    std::cout << "USAGE: ./arcade ./lib/arcade_nameofgraphiclib.so\n";
}

/**
 * @brief start the arcade system
 *
 * @param originalLib
 */

void start_arcade(const std::string &originalLib)
{
    arcade::Core gameCore = arcade::Core();

    gameCore.setGraphicLib(originalLib);
    gameCore.loopArcade();
}

/**
 * @brief manage the arguments passed to the programms
 *
 * @param ac
 * @param av
 */

void argument_gestion(int ac, char **av)
{
    if (ac != 2) {
        throw arcade::ErrorUsage("Invalid number of argument. Must be only two argument.", "Argument_Gestion : " + std::to_string(ac));
    }
    if (!std::string(av[1]).compare("-h"))
        return display_usage();
    start_arcade(av[1]);
}