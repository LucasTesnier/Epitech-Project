/*
** EPITECH PROJECT, 2022
** Boostrap
** File description:
** first
*/

#include "IDisplayModule.hpp"
#include <iostream>

class firstDisplay : public IDisplayModule {
    public:
        firstDisplay();
        ~firstDisplay() = default;
        void init();
        void stop();
        const std::string &getName() const;
    private:
        const std::string _name;
};

extern "C" IDisplayModule *entryPoint(void) {
    IDisplayModule *newModule = new firstDisplay;
    return newModule;
}

firstDisplay::firstDisplay() : _name("libfirst"){
}

void firstDisplay::init() {
    std::cout << "[libfirst] Loading first library..." << std::endl;
}

void firstDisplay::stop() {
    std::cout << "[libfirst] Stop first library..." << std::endl;
}

const std::string &firstDisplay::getName(void) const{
    return _name;
}
