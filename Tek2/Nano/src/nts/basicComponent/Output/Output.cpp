/*
** EPITECH PROJECT, 2022
** Nano
** File description:
** Output
*/

#include "Output.hpp"
#include "Error/Error.hpp"
#include <iostream>

/**
 * @brief Construct a new nts::basic Component::Output::Output object
 * 
 */

nts::basicComponent::Output::Output()
{
    nts::pinInfo temp;

    pin_list = {temp};
    pin_list[0] = nts::pinInfo {
        .pinState = nts::Tristate::UNDEFINED,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };
    name = "Output";
}

/**
 * @brief simulate the passage of volt
 * 
 * @param tick 
 */

void nts::basicComponent::Output::simulate(std::size_t tick)
{
    (void) tick;
}

/**
 * @brief compute function
 * 
 * @param pin 
 * @return nts::Tristate 
 */

nts::Tristate nts::basicComponent::Output::compute(std::size_t pin)
{
    (void) pin;
    return pin_list[0].pinState;
}

/**
 * @brief Destroy the nts::basic Component::Output::Output object
 * 
 */

nts::basicComponent::Output::~Output()
{
}
