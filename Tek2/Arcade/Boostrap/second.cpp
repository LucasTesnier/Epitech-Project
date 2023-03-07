/*
** EPITECH PROJECT, 2022
** Boostrap
** File description:
** second
*/

#include "IDisplayModule.hpp"
#include <iostream>

class secondDisplay : public IDisplayModule {
    public:
        secondDisplay();
        ~secondDisplay() = default;
        
};

extern "C" IDisplayModule *entryPoint(void) {
    IDisplayModule *newModule = new secondDisplay;
    return newModule;
}

secondDisplay::secondDisplay(){
}
