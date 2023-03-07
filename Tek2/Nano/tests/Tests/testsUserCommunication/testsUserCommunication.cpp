/*
** EPITECH PROJECT, 2022
** Nano
** File description:
** testsUserCommunication
*/

#include <criterion/criterion.h>
#include <fstream>
#include "FileLoader/FileLoader.hpp"
#include "Error/Error.hpp"
#include "Parser/Parser.hpp"

Test(parsing, displayNts)
{
    nts::Parser _parser = nts::Parser();
    nts::UserCommunication _userCommunication = nts::UserCommunication();
    nts::System _system = nts::System(_userCommunication);

    _parser.parseFileAndLoadMap("tests/xor.nts", _system);
    _userCommunication.doUserRequest("display");
}

Test(parsing, exitNts)
{
    nts::Parser _parser = nts::Parser();
    nts::UserCommunication _userCommunication = nts::UserCommunication();
    nts::System _system = nts::System(_userCommunication);

    _parser.parseFileAndLoadMap("tests/xor.nts", _system);
    _userCommunication.doUserRequest("exit");
}

Test(parsing, simulateNts)
{
    nts::Parser _parser = nts::Parser();
    nts::UserCommunication _userCommunication = nts::UserCommunication();
    nts::System _system = nts::System(_userCommunication);

    _parser.parseFileAndLoadMap("tests/xor.nts", _system);
    _userCommunication.doUserRequest("simulate");
}

Test(parsing, dumpNts)
{
    nts::Parser _parser = nts::Parser();
    nts::UserCommunication _userCommunication = nts::UserCommunication();
    nts::System _system = nts::System(_userCommunication);

    _parser.parseFileAndLoadMap("tests/xor.nts", _system);
    _userCommunication.doUserRequest("dump");
}

Test(parsing, loopNts)
{
    nts::Parser _parser = nts::Parser();
    nts::UserCommunication _userCommunication = nts::UserCommunication();
    nts::System _system = nts::System(_userCommunication);

    _parser.parseFileAndLoadMap("tests/xor.nts", _system);
    _userCommunication.doUserRequest("loop");
}

Test(parsing, requestNts)
{
    nts::Parser _parser = nts::Parser();
    nts::UserCommunication _userCommunication = nts::UserCommunication();
    nts::System _system = nts::System(_userCommunication);

    _parser.parseFileAndLoadMap("tests/xor.nts", _system);
    _userCommunication.doUserRequest("a=0");
}