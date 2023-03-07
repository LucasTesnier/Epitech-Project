/*
** EPITECH PROJECT, 2022
** Nano
** File description:
** Error
*/

#include "Error.hpp"

/**
 * @brief Construct a new nts::Error::Error object
 * 
 * @param message 
 * @param component 
 */

nts::Error::Error(std::string const &message, std::string const &component) : _component(component), _message(message)
{

}

/**
 * @brief tell the reason of the error
 * 
 * @return const char* 
 */

const char * nts::Error::what() const noexcept
{
    return _message.data();
}

/**
 * @brief tell the function whoe's come the error
 * 
 * @return const std::string& 
 */

const std::string & nts::Error::getComponent() const noexcept
{
    return _component;
}

/**
 * @brief Construct a new nts::Error Component::Error Component object
 * 
 * @param message 
 * @param component 
 */

nts::ErrorComponent::ErrorComponent(std::string const &message, std::string const &component) : nts::Error(message, component)
{

}

/**
 * @brief Construct a new nts::Error Request::Error Request object
 * 
 * @param message 
 * @param component 
 */

nts::ErrorRequest::ErrorRequest(std::string const &message, std::string const &component) : nts::Error(message, component)
{

}

/**
 * @brief Construct a new nts::Error Request E O F::Error Request E O F object
 * 
 * @param message 
 * @param component 
 */

nts::ErrorRequestEOF::ErrorRequestEOF(std::string const &message, std::string const &component) : nts::Error(message, component)
{
    
}

/**
 * @brief Construct a new nts::Error Parser::Error Parser object
 * 
 * @param message 
 * @param component 
 */

nts::ErrorParser::ErrorParser(std::string const &message, std::string const &component) : nts::Error(message, component)
{
    
}