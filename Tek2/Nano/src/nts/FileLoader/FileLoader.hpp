/*
** EPITECH PROJECT, 2022
** Project
** File description:
** FileLoader
*/

#pragma once

#include <fstream>

namespace nts
{
    class FileLoader
    {
    public:
        FileLoader();
        ~FileLoader();
        
        std::ifstream loadFile(const char *path);
        bool checkExtention(const char *path);

    protected:
    private:
    };
}
