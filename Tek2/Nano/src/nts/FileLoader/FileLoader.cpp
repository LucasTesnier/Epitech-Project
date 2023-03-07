/*
** EPITECH PROJECT, 2022
** Project
** File description:
** FileLoader
*/

#include "FileLoader.hpp"
#include "Error/Error.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <regex>
#include <string>

/**
 * @brief Construct a new nts::File Loader::File Loader object
 * 
 */

nts::FileLoader::FileLoader()
{
}

/**
 * @brief Destroy the nts::File Loader::File Loader object
 * 
 */

nts::FileLoader::~FileLoader()
{
}

/**
 * @brief loading the config file
 * 
 * @param path 
 * @return std::ifstream 
 */

std::ifstream nts::FileLoader::FileLoader::loadFile(const char *path)
{
    if (!checkExtention(path))
        throw nts::ErrorParser("Open file Failed : Bad extension.", "LoadFile : " + std::string(path));
    
    std::ifstream _content;
    
    _content.open(path);
    
    if (_content.fail())
        throw nts::ErrorParser("Open file Failed : No such file.", "LoadFile : " + std::string(path));
    return (_content);
}

/**
 * @brief Check the file extension
 * 
 * @param path 
 * @return true 
 * @return false 
 */

bool nts::FileLoader::checkExtention(const char *path)
{
    std::string newPath = std::string(path);
    std::string checkExtention = newPath.substr(newPath.find_last_of(".") + 1);
    
    if (checkExtention != "nts")
        return (false);
    return (true);
}