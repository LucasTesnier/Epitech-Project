/*
** EPITECH PROJECT, 2022
** Nano
** File description:
** System
*/

#include "System.hpp"
#include "Error/Error.hpp"
#include "basicComponent/Input/Input.hpp"
#include "basicComponent/Output/Output.hpp"
#include "basicComponent/Clock/Clock.hpp"
#include "basicComponent/False/False.hpp"
#include "basicComponent/True/True.hpp"
#include "otherComponent/4001/C4001.hpp"
#include "otherComponent/4011/C4011.hpp"
#include "otherComponent/4030/C4030.hpp"
#include "otherComponent/4069/C4069.hpp"
#include "otherComponent/4071/C4071.hpp"
#include "otherComponent/4081/C4081.hpp"
#include "Parser/Parser.hpp"
#include <iostream>
#include <utility>

/**
 * @brief Construct a new nts::System::System object
 * 
 * @param userCommunication 
 */

nts::System::System(nts::UserCommunication &userCommunication) : _userCommunication(userCommunication)
{
    _createLambdas["input"] = std::bind(&nts::System::createInput, this);
    _createLambdas["output"] = std::bind(&nts::System::createOutput, this);
    _createLambdas["clock"] = std::bind(&nts::System::createClock, this);
    _createLambdas["false"] = std::bind(&nts::System::createFalse, this);
    _createLambdas["true"] = std::bind(&nts::System::createTrue, this);
    _createLambdas["4001"] = std::bind(&nts::System::create4001, this);
    _createLambdas["4011"] = std::bind(&nts::System::create4011, this);
    _createLambdas["4030"] = std::bind(&nts::System::create4030, this);
    _createLambdas["4069"] = std::bind(&nts::System::create4069, this);
    _createLambdas["4071"] = std::bind(&nts::System::create4071, this);
    _createLambdas["4081"] = std::bind(&nts::System::create4081, this);
    _returnValue = 0;
}

/**
 * @brief Nts principal loop
 * 
 */

void nts::System::loop(const char *path)
{

    nts::Parser parsing = nts::Parser();

    parsing.parseFileAndLoadMap(path, *this);
    while(_userCommunication.getState() != nts::UserCommunication::CommunicationState::EXIT) {
        if (_userCommunication.getState() == nts::UserCommunication::CommunicationState::LOOP) {
            _userCommunication.doUserRequest("simulate");
            _userCommunication.doUserRequest("display");
        } else {
            std::cout << "> ";
            try {
                const std::string &request = _userCommunication.getTerminalAction();
            
                _userCommunication.doUserRequest(request);
            } catch (const nts::ErrorRequestEOF &error) {
                return;
            }
        }
    }
}

/**
 * @brief get the programm return value 
 * 
 * @return std::size_t 
 */

std::size_t nts::System::getReturnValue() const
{
    return _returnValue;
}

/**
 * @brief create a component factory
 * 
 * @param type 
 * @return std::unique_ptr<nts::IComponent> 
 */

std::unique_ptr<nts::IComponent> nts::System::createComponent(const std::string &type)
{
    if (_createLambdas.find(type) == _createLambdas.end())
        throw nts::ErrorComponent("Construction Failed : Component not registered.", "CreateComponent : " + type);
    return _createLambdas[type]();
}

/**
 * @brief create the input component
 * 
 * @return std::unique_ptr<nts::IComponent> 
 */

std::unique_ptr<nts::IComponent> nts::System::createInput() const
{
    std::unique_ptr<nts::IComponent> newInput(new nts::basicComponent::Input());

    return newInput;
}

/**
 * @brief create the output component
 * 
 * @return std::unique_ptr<nts::IComponent> 
 */

std::unique_ptr<nts::IComponent> nts::System::createOutput() const
{
    std::unique_ptr<nts::IComponent> newOutput(new nts::basicComponent::Output());

    return newOutput;
}

/**
 * @brief create the clock component
 * 
 * @return std::unique_ptr<nts::IComponent> 
 */

std::unique_ptr<nts::IComponent> nts::System::createClock() const
{
    std::unique_ptr<nts::IComponent> newClock(new nts::basicComponent::Clock());

    return newClock;
}

/**
 * @brief create the False component
 * 
 * @return std::unique_ptr<nts::IComponent> 
 */

std::unique_ptr<nts::IComponent> nts::System::createFalse() const
{
    std::unique_ptr<nts::IComponent> newFalse(new nts::basicComponent::False());

    return newFalse;
}

/**
 * @brief create the True component
 * 
 * @return std::unique_ptr<nts::IComponent> 
 */

std::unique_ptr<nts::IComponent> nts::System::createTrue() const
{
    std::unique_ptr<nts::IComponent> newTrue(new nts::basicComponent::True());

    return newTrue;
}

/**
 * @brief create the 4001 component
 * 
 * @return std::unique_ptr<nts::IComponent> 
 */

std::unique_ptr<nts::IComponent> nts::System::create4001() const
{
    std::unique_ptr<nts::IComponent> new4001(new nts::otherComponent::C4001());

    return new4001;
}

/**
 * @brief create the 4011 component
 * 
 * @return std::unique_ptr<nts::IComponent> 
 */

std::unique_ptr<nts::IComponent> nts::System::create4011() const
{
    std::unique_ptr<nts::IComponent> new4011(new nts::otherComponent::C4011());

    return new4011;
}

/**
 * @brief create the 4030 component
 * 
 * @return std::unique_ptr<nts::IComponent> 
 */

std::unique_ptr<nts::IComponent> nts::System::create4030() const
{
    std::unique_ptr<nts::IComponent> new4030(new nts::otherComponent::C4030());

    return new4030;
}

/**
 * @brief create the 4069 component
 * 
 * @return std::unique_ptr<nts::IComponent> 
 */

std::unique_ptr<nts::IComponent> nts::System::create4069() const
{
    std::unique_ptr<nts::IComponent> new4069(new nts::otherComponent::C4069());

    return new4069;
}

/**
 * @brief create the 4071 component
 * 
 * @return std::unique_ptr<nts::IComponent> 
 */

std::unique_ptr<nts::IComponent> nts::System::create4071() const
{
    std::unique_ptr<nts::IComponent> new4071(new nts::otherComponent::C4071());

    return new4071;
}

/**
 * @brief create the 4081 component
 * 
 * @return std::unique_ptr<nts::IComponent> 
 */

std::unique_ptr<nts::IComponent> nts::System::create4081() const
{
    std::unique_ptr<nts::IComponent> new4081(new nts::otherComponent::C4081());

    return new4081;
}

/**
 * @brief return the chipset corresponding to his name in the chipset
 * 
 * @param key 
 * @return nts::IComponent& 
 */

nts::IComponent &nts::System::getAChip(const std::string &key)
{
    return _userCommunication.getAChip(key);
}

/**
 * @brief return the chipset corresponding to his name in the chipset
 * 
 * @param key 
 * @return const nts::IComponent& 
 */

const nts::IComponent &nts::System::getAChip(const std::string &key) const
{
    return _userCommunication.getAChip(key);
}

/**
 * @brief set the chipset corresponding to his name in the chipset
 * 
 * @param key 
 * @param component 
 */

void nts::System::addAChip(const std::string &key, std::unique_ptr<nts::IComponent> &&component)
{
    _userCommunication.addAChip(key, std::move(component));
}

/**
 * @brief search for a component name in the chipset
 * 
 * @param key 
 * @return true 
 * @return false 
 */

bool nts::System::findAChip(const std::string &key)
{
    return _userCommunication.findAChip(key);
}

/**
 * @brief Destroy the nts::System::System object
 * 
 */

nts::System::~System()
{
}