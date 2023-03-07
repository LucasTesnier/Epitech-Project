/*
** EPITECH PROJECT, 2022
** Nano
** File description:
** False
*/

#include "False.hpp"
#include "Error/Error.hpp"
#include <iostream>

/**
 * @brief Construct a new nts::basic Component::False::False object
 * 
 */

nts::basicComponent::False::False()
{
    nts::pinInfo temp;

    pin_list = {temp};
    pin_list[0] = nts::pinInfo {
        .pinState = nts::Tristate::FALSE,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };
    name = "False";
}

/**
 * @brief simulate the passage of volt
 * 
 * @param tick 
 */

void nts::basicComponent::False::simulate(std::size_t tick)
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

nts::Tristate nts::basicComponent::False::compute(std::size_t pin)
{
    (void) pin;
    return pin_list[0].pinState;
}

/**
 * @brief Destroy the nts::basic Component::False::False object
 * 
 */

nts::basicComponent::False::~False()
{
}
