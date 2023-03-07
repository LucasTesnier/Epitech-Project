/*
** EPITECH PROJECT, 2022
** Nano
** File description:
** Input
*/

#include "Input.hpp"
#include "Error/Error.hpp"

/**
 * @brief Construct a new nts::basic Component::Input::Input object
 * 
 */

nts::basicComponent::Input::Input()
{
    nts::pinInfo temp;

    pin_list = {temp};
    pin_list[0] = nts::pinInfo {
        .pinState = nts::Tristate::UNDEFINED,
        .linkComponent = nullptr,
        .linkPin = 0,
        .linkInProgress = false
    };
    name = "Input";
    _comingInput = nts::Tristate::UNDEFINED;
    _isComingInput = false;
}

/**
 * @brief stock a value requested by user
 * 
 * @param comingInput 
 */

void nts::basicComponent::Input::getComingInput(const std::string &comingInput)
{
    _isComingInput = true;
    _comingInput = (comingInput.compare("1") == 0) ? nts::Tristate::TRUE : (comingInput.compare("0") == 0) ? nts::Tristate::FALSE : nts::Tristate::UNDEFINED;
}

/**
 * @brief simualte the passage of volt
 * 
 * @param tick 
 */

void nts::basicComponent::Input::simulate(std::size_t tick)
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

nts::Tristate nts::basicComponent::Input::compute(std::size_t pin)
{
    (void) pin;
    if (_isComingInput) {
        _isComingInput = false;
        pin_list[0].pinState = _comingInput;
    }
    return pin_list[0].pinState;
}

/**
 * @brief Destroy the nts::basic Component::Input::Input object
 * 
 */

nts::basicComponent::Input::~Input()
{
    
}
