/*
** EPITECH PROJECT, 2022
** Nano
** File description:
** AComponent
*/

#include "AComponent.hpp"

/**
 * @brief convert a status to a String
 * 
 * @param status 
 * @return std::string 
 */

std::string nts::AComponent::convertStatus(const nts::Tristate status) const {
    return (status == nts::Tristate::TRUE) ? "1" : (status == nts::Tristate::FALSE) ? "0" : "U";
};

/**
 * @brief get the state of a pin
 * 
 * @param pin 
 * @return nts::Tristate 
 */

nts::Tristate nts::AComponent::getStatePin(const nts::pinInfo &pin) const {
    return pin.pinState;
};

/**
 * @brief get the state of a numbered pin
 * 
 * @param pin 
 * @return nts::Tristate 
 */

nts::Tristate nts::AComponent::getAStatePin(const std::size_t pin) const {
    return getStatePin(pin_list[pin]);
}

/**
 * @brief display status of all the pin
 * 
 */

void nts::AComponent::dump() const {
    std::size_t count = 0;

    std::cout << name << " Pin Status : " << std::endl;
    for(auto i : pin_list) {
        std::cout << "\tPin " << count << " : " << convertStatus(getStatePin(i)) << std::endl;
        count++;
    };
};

/**
 * @brief change the state of a pin
 * 
 * @param pin 
 * @param status 
 */

void nts::AComponent::changePinState(std::size_t pin, nts::Tristate status) {
    if (pin >= pin_list.size())
        throw nts::ErrorComponent("Change State Failed : Pin does'nt exist.", name + "::changePinState : " + std::to_string(pin));
    pin_list[pin].pinState = status;
};

/**
 * @brief set the link between two pin
 * 
 * @param pin 
 * @param other 
 * @param otherPin 
 */

void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    if (pin >= pin_list.size())
        throw nts::ErrorComponent("Link Failed : Pin does'nt exist.", name + "::setLink : " + std::to_string(pin));

    if (pin_list[pin].linkInProgress) {
        pin_list[pin].linkInProgress = false;
        return;
    }
    pin_list[pin].linkComponent = &other;
    pin_list[pin].linkPin = otherPin;
    pin_list[pin].linkInProgress = true;
    other.setLink(otherPin, *this, pin);
};

/**
 * @brief get the component name
 * 
 * @return std::string& 
 */

const std::string &nts::AComponent::getName() const
{
    return name;
}

/**
 * @brief Get the Coming Input object
 * 
 * @param comingInput 
 */

void nts::AComponent::getComingInput(const std::string &comingInput)
{
    (void) comingInput;
}
