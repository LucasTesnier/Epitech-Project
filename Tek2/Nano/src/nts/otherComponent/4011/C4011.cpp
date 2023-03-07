/*
** EPITECH PROJECT, 2022
** Project
** File description:
** C4011
*/

#include "C4011.hpp"

/**
 * @brief Construct a new nts::other Component::C4011::C4011 object
 * 
 */

nts::otherComponent::C4011::C4011()
{
    nts::pinInfo temp;

    pin_list = {temp, temp, temp, temp, temp, temp, temp, temp, temp, temp, temp, temp, temp, temp};
    for (int i = 0; i != 14; i++) {
        pin_list[i] = nts::pinInfo{
            .pinState = nts::Tristate::UNDEFINED,
            .linkComponent = nullptr,
            .linkPin = 0,
            .linkInProgress = false};
    }
    name = "4011";
}

/**
 * @brief calcul the Nand gate
 * 
 * @param pin1 
 * @param pin2 
 * @return true 
 * @return false 
 */

bool nts::otherComponent::C4011::calcNandGate(nts::pinInfo pin1, nts::pinInfo pin2)
{
    if (pin1.pinState == nts::Tristate::TRUE && pin2.pinState == nts::Tristate::TRUE)
        return false;
    return true;
}

/**
 * @brief simulate a tick
 * 
 * @param tick 
 */

void nts::otherComponent::C4011::simulate(std::size_t tick)
{
    nts::IComponent *linkComponent1 = pin_list[2].linkComponent;
    std::size_t linkPin1 = pin_list[2].linkPin;
    nts::IComponent *linkComponent2 = pin_list[3].linkComponent;
    std::size_t linkPin2 = pin_list[3].linkPin;
    nts::IComponent *linkComponent3 = pin_list[9].linkComponent;
    std::size_t linkPin3 = pin_list[9].linkPin;
    nts::IComponent *linkComponent4 = pin_list[10].linkComponent;
    std::size_t linkPin4 = pin_list[10].linkPin;
    
    if (linkComponent1 != nullptr)
        linkComponent1->changePinState(linkPin1, pin_list[2].pinState);
    if (linkComponent2 != nullptr)
        linkComponent2->changePinState(linkPin2, pin_list[3].pinState);
    if (linkComponent3 != nullptr)
        linkComponent3->changePinState(linkPin3, pin_list[9].pinState);
    if (linkComponent4 != nullptr)
        linkComponent4->changePinState(linkPin4, pin_list[10].pinState);
    (void) tick;
}

/**
 * @brief compute the state of a pin
 * 
 * @param pin 
 * @return nts::Tristate 
 */

nts::Tristate nts::otherComponent::C4011::compute(std::size_t pin)
{
    (void) pin;
    if (calcNandGate(pin_list[0], pin_list[1]))
        pin_list[2].pinState = nts::Tristate::TRUE;
    else
        pin_list[2].pinState = nts::Tristate::FALSE;
    
    if (calcNandGate(pin_list[4], pin_list[5]))
        pin_list[3].pinState = nts::Tristate::TRUE;
    else
        pin_list[3].pinState = nts::Tristate::FALSE;
    
    if (calcNandGate(pin_list[7], pin_list[8]))
        pin_list[9].pinState = nts::Tristate::TRUE;
    else
        pin_list[9].pinState = nts::Tristate::FALSE;
    
    if (calcNandGate(pin_list[11], pin_list[12]))
        pin_list[10].pinState = nts::Tristate::TRUE;
    else
        pin_list[10].pinState = nts::Tristate::FALSE;


    if (pin_list[0].pinState == nts::Tristate::UNDEFINED || pin_list[1].pinState == nts::Tristate::UNDEFINED)
        pin_list[2].pinState = nts::Tristate::UNDEFINED;
   
    if (pin_list[4].pinState == nts::Tristate::UNDEFINED || pin_list[5].pinState == nts::Tristate::UNDEFINED)
        pin_list[3].pinState = nts::Tristate::UNDEFINED;
    
    if (pin_list[7].pinState == nts::Tristate::UNDEFINED || pin_list[8].pinState == nts::Tristate::UNDEFINED)
        pin_list[9].pinState = nts::Tristate::UNDEFINED;
  
    if (pin_list[10].pinState == nts::Tristate::UNDEFINED || pin_list[12].pinState == nts::Tristate::UNDEFINED)
        pin_list[10].pinState = nts::Tristate::UNDEFINED;
    return nts::Tristate::UNDEFINED;
}

/**
 * @brief Destroy the nts::other Component::C4011::C4011 object
 * 
 */

nts::otherComponent::C4011::~C4011()
{
    
}