/*
** EPITECH PROJECT, 2022
** Project
** File description:
** test
*/

#include "Core.hpp"
#include <iostream>
#include <string>

void argument_gestion(int ac, char **av);


/**
 * @brief It's a main function that takes in arguments and then calls the argument_gestion function
 * 
 * @param ac the number of arguments
 * @param av The list of arguments passed to the program.
 * 
 * @return The return value of the main function is the exit status of the program.
 */
int main(int ac, char **av)
{
    srand(time(NULL));
    try {
        argument_gestion(ac, av);
    } catch (arcade::Error const &error) {
        std::cout << error.what() << " " << error.getComponent() << std::endl;
        return 84;
    }
    return 0;
}