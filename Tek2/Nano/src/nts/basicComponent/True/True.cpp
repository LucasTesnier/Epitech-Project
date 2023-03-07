/*
** EPITECH PROJECT, 2022
** Nano
** File description:
** True
*/

#include "True.hpp"
#include "Error/Error.hpp"
#include <iostream>

/**
 * @brief Construct a new nts::basic Component::True::True object
 * 
 */

nts::basicComponent::True::True()
{
    nts::pinInfo temp;

    pin_list = {temp};
    pin_list[0] = nts::pinInfo {
        .pinState = nts::Tristate::TRUE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };
    name = "True";
}

/**
 * @brief simulate the passage of volt
 * 
 * @param tick 
 */

void nts::basicComponent::True::simulate(std::size_t tick)
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

nts::Tristate nts::basicComponent::True::compute(std::size_t pin)
{
    (void) pin;
    return pin_list[0].pinState;
}

/**
 * @brief Destroy the nts::basic Component::True::True object
 * 
 */

nts::basicComponent::True::~True()
{
}
