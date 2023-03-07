/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Parser
*/

#include "Parser.hpp"
#include "Error/Error.hpp"
#include <regex>

/**
 * @brief Construct a new nts::Parser::Parser object
 * 
 */

nts::Parser::Parser()
{
    _fileLoad = nts::FileLoader();
}

/**
 * @brief Destroy the nts::Parser::Parser object
 * 
 */

nts::Parser::~Parser()
{

}

/**
 * @brief check if line is empty
 * 
 * @param line 
 * @return true 
 * @return false 
 */

bool nts::Parser::lineIsEmpty(std::string &line)
{
    for (std::size_t i = 0; i < line.size(); i++)
        if (line[i] != '\t' && line[i] != ' ')
            return false;
    return true;
}

/**
 * @brief check for comments in the config file
 * 
 * @param file 
 * @param line 
 * @param str 
 */

void nts::Parser::checkComa(std::ifstream &file, std::string &line, std::stringstream &str)
{
    std::regex reg("^([^#]+)");
    std::smatch matchStr;

    while (getline(file, line)) {
        if (regex_search(line, matchStr, reg)) {
            line = matchStr.str(1); // compr
            if (!lineIsEmpty(line))
                str << line << std::endl;
        }
    }
}

/**
 * @brief get the component name and do the links
 * 
 * @param str 
 * @param factory 
 */

void nts::Parser::createMapLinks(std::stringstream &str, nts::System &factory)
{
    std::regex _regSearchComponent("^(\\S+)\\s+(\\S+)$");
    std::regex _regSearchLinks("^(\\S+):(\\d+)\\s+(\\S+):(\\d+)$");
    std::string component;
    std::smatch matchComponents;
    std::string temp;
    bool isChipset = false;

    while (getline(str, component) && component.find(".links:")) {
        if (regex_search(component, matchComponents, _regSearchComponent)) {
            if (factory.findAChip(matchComponents.str(2)))
                throw nts::ErrorParser("Parser Failed : Component name already use.", "createMapLinks : " + matchComponents.str(2));
            factory.addAChip(matchComponents.str(2), factory.createComponent(matchComponents.str(1)));
            isChipset = true;
        }
    }

    if (isChipset == false)
        throw nts::ErrorParser("Parser Failed : No chipset in the circuit.", "CreateMapLinks");

    if (component.find(".links:"))
        throw nts::ErrorParser("Parser Failed : No parts .links.", "CreateMapLinks");

    while (getline(str, temp)) {
        if (regex_search(temp, matchComponents, _regSearchLinks)) {
            std::string pin1 = matchComponents.str(2);
            std::string pin2 = matchComponents.str(4);

            if (!factory.findAChip(matchComponents.str(1)) || !factory.findAChip(matchComponents.str(3)))
                throw nts::ErrorParser("Parser Failed : Component name not set.", "createMapLinks : " + matchComponents.str(1) + " " + matchComponents.str(3));

            factory.getAChip(matchComponents.str(1)).setLink(std::atoi(pin1.c_str()) - 1, factory.getAChip(matchComponents.str(3)), std::atoi(pin2.c_str()) - 1);
        } else
            throw nts::ErrorParser("Parser Failed : Bad Syntax in the file to set a link.", "CreateMapLinks");
    }
}

/**
 * @brief parse file and load the component
 *
 * @param path
 * @param factory
 */

void nts::Parser::parseFileAndLoadMap(const char *path, nts::System &factory)
{
    std::ifstream file = _fileLoad.loadFile(path);
    std::stringstream str;
    std::string line;

    checkComa(file, line, str);
    std::getline(str, line);

    if (!line.find(".chipsets:"))
        createMapLinks(str, factory);
    else
        throw nts::ErrorParser("There is no part '.chipsets:' in the file.", "parseFileAndLoadMap");
}