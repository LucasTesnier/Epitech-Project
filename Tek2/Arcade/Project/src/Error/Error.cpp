/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Error
*/

#include "Error.hpp"

/**
 * @brief Construct a new arcade::Error::Error object
 * 
 * @param message 
 * @param component 
 */

arcade::Error::Error(std::string const &message, std::string const &component) : _component(component), _message(message)
{
}

/**
 * @brief tell the purpose of the Error
 * 
 * @return const char* 
 */

const char *arcade::Error::what() const noexcept
{
    return _message.data();
}

/**
 * @brief tell the function who cause the Error
 * 
 * @return const std::string& 
 */

const std::string &arcade::Error::getComponent() const noexcept
{
    return _component;
}

/**
 * @brief Construct a new arcade::Error Graphic::Error Graphic object
 * 
 * @param message 
 * @param component 
 */

arcade::ErrorGraphic::ErrorGraphic(std::string const &message, std::string const &component) : arcade::Error(message, component)
{

}

/**
 * @brief Construct a new arcade::Error Game::Error Game object
 * 
 * @param message 
 * @param component 
 */

arcade::ErrorGame::ErrorGame(std::string const &message, std::string const &component) : arcade::Error(message, component)
{

}

/**
 * @brief Construct a new arcade::Error Core::Error Core object
 * 
 * @param message 
 * @param component 
 */

arcade::ErrorCore::ErrorCore(std::string const &message, std::string const &component) : arcade::Error(message, component)
{

}

/**
 * @brief Construct a new arcade::Error Loader::Error Loader object
 * 
 * @param message 
 * @param component 
 */

arcade::ErrorLoader::ErrorLoader(std::string const &message, std::string const &component) : arcade::Error(message, component)
{

}

/**
 * @brief Construct a new arcade::Error Usage::Error Usage object
 * 
 * @param message 
 * @param component 
 */

arcade::ErrorUsage::ErrorUsage(std::string const &message, std::string const &component) : arcade::Error(message, component)
{

}