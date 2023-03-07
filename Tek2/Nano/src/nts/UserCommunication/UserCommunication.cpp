/*
** EPITECH PROJECT, 2022
** Nano
** File description:
** UserCommunication
*/

#include "UserCommunication.hpp"
#include "Error/Error.hpp"
#include <sstream>
#include <iostream>
#include <regex>

/**
 * @brief Construct a new nts::User Communication::User Communication object
 * 
 */

nts::UserCommunication::UserCommunication()
{
    _userRequest["exit"] = std::bind(&nts::UserCommunication::requestExit, this);
    _userRequest["display"] = std::bind(&nts::UserCommunication::requestDisplay, this);
    _userRequest["simulate"] = std::bind(&nts::UserCommunication::requestSimulate, this);
    _userRequest["loop"] = std::bind(&nts::UserCommunication::requestLoop, this);
    _userRequest["dump"] = std::bind(&nts::UserCommunication::requestDump, this);

    _state = nts::UserCommunication::CommunicationState::PROMPT;
    _tick = 0;
}

/**
 * @brief get the state of the communication with the user
 * 
 * @return nts::UserCommunication::CommunicationState 
 */

nts::UserCommunication::CommunicationState nts::UserCommunication::getState() const
{
    return _state;
}

/**
 * @brief get user input request
 * 
 * @return const std::string 
 */

const std::string nts::UserCommunication::getTerminalAction() const
{
    std::string request;
    std::stringstream current;
    std::istream &stream = std::cin;

    std::getline(stream, request);
    current = std::stringstream(request);
    if (!stream) {
        if (stream.eof())
            throw nts::ErrorRequestEOF("EOF Detected !");
        throw nts::ErrorRequest("Input Failed : stream crash.", "GetTerminalAction");
    }
    current >> request;
    return request;
}

/**
 * @brief use the user input requested
 * 
 * @param request 
 */

void nts::UserCommunication::doUserRequest(const std::string &request)
{
    if (request.find("=") != std::string::npos)
        return requestValue(request);
    if (_userRequest.find(request) == _userRequest.end())
        throw nts::ErrorRequest("Request Failed : Command not registered.", "DoUserRequest : " + request);
    _userRequest[request]();
}

/**
 * @brief do exit request
 * 
 */

void nts::UserCommunication::requestExit()
{
    _state = nts::UserCommunication::CommunicationState::EXIT;
}

/**
 * @brief do display request
 * 
 */

void nts::UserCommunication::requestDisplay()
{
    std::cout << "tick: " << std::to_string(_tick) << std::endl;
    std::cout << "input(s):" << std::endl;
    for (auto &i : _chipset) {
        auto &component = getAChip(i.first);
 
        if (component.getName() == "Input" || component.getName() == "Clock")
            std::cout << "  " << i.first << ": " << component.convertStatus(component.getAStatePin(0)) << std::endl;
    }
    std::cout << "output(s):" << std::endl;
    for (auto &i : _chipset) {
        auto &component = getAChip(i.first);
    
        if (component.getName() == "Output")
            std::cout << "  " << i.first << ": " << component.convertStatus(component.getAStatePin(0)) << std::endl;
    }
}

/**
 * @brief do value request
 * 
 * @param request 
 */

void nts::UserCommunication::requestValue(const std::string &request)
{
    std::regex regex("^(\\S+)=(0|1|U)$");
    std::smatch matchRequest;
    if (regex_search(request, matchRequest, regex)) {
        if (findAChip(matchRequest.str(1)) == false)
            throw nts::ErrorRequest("Request failed : Chip not registered.", "RequestValue : " + matchRequest.str(1));
        getAChip(matchRequest.str(1)).getComingInput(matchRequest.str(2));
    } else
        throw nts::ErrorRequest("Request failed : Invalid format", "RequestValue : " + request);
}

/**
 * @brief do simulate request
 * 
 */

void nts::UserCommunication::requestSimulate()
{
    _tick += 1;
    for (auto &i : _chipset) {
        auto &component = getAChip(i.first);
    
        component.compute(0);
        component.simulate(_tick);
    }
}

/**
 * @brief do loop request
 * 
 */

void nts::UserCommunication::requestLoop()
{
    _state = nts::UserCommunication::CommunicationState::LOOP;
}

/**
 * @brief do dump request
 * 
 */

void nts::UserCommunication::requestDump()
{
    for (auto &i : _chipset)
        getAChip(i.first).dump();
}

/**
 * @brief return the chipset corresponding to his name in the chipset
 * 
 * @param key 
 * @return nts::IComponent& 
 */

nts::IComponent &nts::UserCommunication::getAChip(const std::string &key)
{
    if (_chipset.find(key) == _chipset.end())
        throw nts::ErrorComponent("Construction Failed : Component not registered.", "CreateComponent : " + key); // CHANGE THE ERROR
    return *_chipset.at(key);
}

/**
 * @brief return the chipset corresponding to his name in the chipset
 * 
 * @param key 
 * @return const nts::IComponent& 
 */

const nts::IComponent &nts::UserCommunication::getAChip(const std::string &key) const
{
    if (_chipset.find(key) == _chipset.end())
        throw nts::ErrorComponent("Construction Failed : Component not registered.", "CreateComponent : " + key); // CHANGE THE ERROR
    return *_chipset.at(key);
}

/**
 * @brief set the chipset corresponding to his name in the chipset
 * 
 * @param key 
 * @param component 
 */

void nts::UserCommunication::addAChip(const std::string &key, std::unique_ptr<nts::IComponent> &&component)
{
    _chipset.emplace(key, std::move(component));
}

/**
 * @brief search for a component name in the chipset
 * 
 * @param key 
 * @return true 
 * @return false 
 */

bool nts::UserCommunication::findAChip(const std::string &key)
{
    if (_chipset.find(key) == _chipset.end())
        return false;
    return true;
}

/**
 * @brief Destroy the nts::User Communication::User Communication object
 * 
 */

nts::UserCommunication::~UserCommunication()
{
}
