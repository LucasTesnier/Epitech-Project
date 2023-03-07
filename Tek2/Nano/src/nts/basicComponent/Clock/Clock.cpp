/*
** EPITECH PROJECT, 2022
** Nano
** File description:
** Clock
*/

#include "Clock.hpp"
#include "Error/Error.hpp"
#include <iostream>

/**
 * @brief Construct a new nts::basic Component::Clock::Clock object
 * 
 */

nts::basicComponent::Clock::Clock()
{
    nts::pinInfo temp;

    pin_list = {temp};
    pin_list[0] = nts::pinInfo {
        .pinState = nts::Tristate::UNDEFINED,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };
    name = "Clock";
    _comingInput = nts::Tristate::UNDEFINED;
    _isComingInput = false;
}

/**
 * @brief stock a value requested by user
 * 
 * @param comingInput 
 */

void nts::basicComponent::Clock::getComingInput(const std::string &comingInput)
{
    _isComingInput = true;
    _comingInput = (comingInput.compare("1") == 0) ? nts::Tristate::TRUE : (comingInput.compare("0") == 0) ? nts::Tristate::FALSE : nts::Tristate::UNDEFINED;
}

/**
 * @brief simulate the passage of volt
 * 
 * @param tick 
 */

void nts::basicComponent::Clock::simulate(std::size_t tick)
{
    nts::IComponent *linkComponent = pin_list[0].linkComponent;
    std::size_t linkPin = pin_list[0].linkPin;

    if (linkComponent != nullptr)
        linkComponent->changePinState(linkPin, pin_list[0].pinState);
    (void) tick;
}

/**
 * @brief compute function
 * 
 * @param pin 
 * @return nts::Tristate 
 */

nts::Tristate nts::basicComponent::Clock::compute(std::size_t pin)
{
    (void) pin;
    if (_isComingInput) {
        pin_list[0].pinState = _comingInput;
        _isComingInput = false;
    } else {
        if (pin_list[0].pinState == nts::Tristate::UNDEFINED)
            return pin_list[0].pinState;
        pin_list[0].pinState = (pin_list[0].pinState == nts::Tristate::TRUE)? nts::Tristate::FALSE : nts::Tristate::TRUE;
    }
    return pin_list[0].pinState;
}

/**
 * @brief Destroy the nts::basic Component::Clock::Clock object
 * 
 */

nts::basicComponent::Clock::~Clock()
{
}
