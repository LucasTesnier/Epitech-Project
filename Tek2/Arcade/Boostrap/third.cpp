/*
** EPITECH PROJECT, 2022
** Boostrap
** File description:
** third
*/

#include "IDisplayModule.hpp"
#include <iostream>

class thirdDisplay : public IDisplayModule {
    public:
        thirdDisplay();
        ~thirdDisplay() = default;
        void init();
        void stop();
        const std::string &getName() const;
    private:
        const std::string _name;
};

extern "C" IDisplayModule *entryPoint(void) {
    IDisplayModule *newModule = new thirdDisplay;
    return newModule;
}

thirdDisplay::thirdDisplay() : _name("libthird"){
}

void thirdDisplay::init() {
    std::cout << "[libthird] Loading third library..." << std::endl;
}

void thirdDisplay::stop() {
    std::cout << "[libthird] Stop third library..." << std::endl;
}

const std::string &thirdDisplay::getName(void) const{
    return _name;
}
