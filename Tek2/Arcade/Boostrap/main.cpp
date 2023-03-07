/*
** EPITECH PROJECT, 2022
** Boostrap
** File description:
** main
*/

#include <dlfcn.h>
#include <iostream>
#include "IDisplayModule.hpp"
#include "DLLoader.hpp"

int main(int ac, char **av)
{
    char *libName[3] = {
        "./libSecond.so",
        "./libSecond.so",
        "./libSecond.so"
    };

    for (int i = 0; i < 3; i++) {
        DLLoader<IDisplayModule> displayModule = DLLoader<IDisplayModule>(libName[i]);
        //displayModule.getInstance()->init();
        //std::cout << "Lib name : " << displayModule.getInstance()->getName() << std::endl;
        //displayModule.getInstance()->stop();
    }
    return 0;
}