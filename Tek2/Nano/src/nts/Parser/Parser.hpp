/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Parser
*/

#pragma once

#include "../FileLoader/FileLoader.hpp"
#include "System/System.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iterator>

namespace nts
{
    class Parser
    {
    public:

        Parser();
        ~Parser();

        bool lineIsEmpty(std::string &line);

        void checkComa(std::ifstream &file, std::string &line, std::stringstream &str);

        void parseFileAndLoadMap(const char *path, nts::System &factory);

        void createMapLinks(std::stringstream &str, nts::System &factory);

    protected:
    private:
        nts::FileLoader _fileLoad;
    };
}