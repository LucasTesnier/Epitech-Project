/*
** EPITECH PROJECT, 2022
** B-OOP-400-NAN-4-1-tekspice-lucas.tesnier
** File description:
** testParser
*/

#include <criterion/criterion.h>
#include <fstream>
#include "FileLoader/FileLoader.hpp"
#include "Error/Error.hpp"
#include "Parser/Parser.hpp"


Test(FileLoader, check_open_good_file)
{
    nts::FileLoader _fileLoader = nts::FileLoader();
    std::ifstream file = _fileLoader.loadFile("tests/Tests/fileTests/clock.nts");

    cr_assert_eq(file.is_open(), true);
}

Test(FileLoader, check_open_bad_file)
{
    nts::FileLoader _fileLoader = nts::FileLoader();
    std::ifstream file;
    try {
        file = _fileLoader.loadFile("../fileTests/badFile");
    } catch (nts::ErrorParser &error) {
        cr_assert_eq(file.is_open(), false);
    }
}

Test(FileLoader, check_goodExtention_file)
{
    nts::FileLoader _fileLoader = nts::FileLoader();
    
    cr_assert(_fileLoader.checkExtention("../fileTests/clock.nts"));
}

Test(FileLoader, check_badExtention_file)
{
    nts::FileLoader _fileLoader = nts::FileLoader();
    
    cr_assert_not(_fileLoader.checkExtention("../fileTests/clock"));
}

Test(Parser, load_file_error)
{
    nts::FileLoader _fileLoader = nts::FileLoader();
    const char *path = "../filetests/badFile";

    try {
        _fileLoader.loadFile(path);
    } catch (nts::ErrorParser &error) {
        cr_assert_str_eq(error.what(), "Open file Failed : Bad extension.");
    }
}

Test(lineIsEmpty, lineEmpty)
{
    nts::Parser _parser = nts::Parser();
    std::string str = "\t";
    cr_assert_eq(_parser.lineIsEmpty(str), true); // DOESNT SEND FALSE, NORMAL ?
}

Test(lineIsEmpty, lineIsEmpty_not)
{
    nts::Parser _parser = nts::Parser();
    std::string str = "\tzkhvrzbvu";
    cr_assert_not(_parser.lineIsEmpty(str));
}

Test(parsing, clockNts)
{
    nts::Parser _parser = nts::Parser();
    nts::UserCommunication _userCommunication = nts::UserCommunication();
    nts::System _system = nts::System(_userCommunication);

    _parser.parseFileAndLoadMap("tests/clock.nts", _system);
}

Test(parsing, andNts)
{
    nts::Parser _parser = nts::Parser();
    nts::UserCommunication _userCommunication = nts::UserCommunication();
    nts::System _system = nts::System(_userCommunication);

    _parser.parseFileAndLoadMap("tests/and.nts", _system);
}

Test(parsing, inverterNts)
{
    nts::Parser _parser = nts::Parser();
    nts::UserCommunication _userCommunication = nts::UserCommunication();
    nts::System _system = nts::System(_userCommunication);

    _parser.parseFileAndLoadMap("tests/inverter.nts", _system);
}

Test(parsing, nandNts)
{
    nts::Parser _parser = nts::Parser();
    nts::UserCommunication _userCommunication = nts::UserCommunication();
    nts::System _system = nts::System(_userCommunication);

    _parser.parseFileAndLoadMap("tests/nand.nts", _system);
}

Test(parsing, norNts)
{
    nts::Parser _parser = nts::Parser();
    nts::UserCommunication _userCommunication = nts::UserCommunication();
    nts::System _system = nts::System(_userCommunication);

    _parser.parseFileAndLoadMap("tests/nor.nts", _system);
}

Test(parsing, orNts)
{
    nts::Parser _parser = nts::Parser();
    nts::UserCommunication _userCommunication = nts::UserCommunication();
    nts::System _system = nts::System(_userCommunication);

    _parser.parseFileAndLoadMap("tests/or.nts", _system);
}

Test(parsing, xorNts)
{
    nts::Parser _parser = nts::Parser();
    nts::UserCommunication _userCommunication = nts::UserCommunication();
    nts::System _system = nts::System(_userCommunication);

    _parser.parseFileAndLoadMap("tests/xor.nts", _system);
}

Test(parsing, trueNts)
{
    nts::Parser _parser = nts::Parser();
    nts::UserCommunication _userCommunication = nts::UserCommunication();
    nts::System _system = nts::System(_userCommunication);

    _parser.parseFileAndLoadMap("tests/true.nts", _system);
}

Test(parsing, falseNts)
{
    nts::Parser _parser = nts::Parser();
    nts::UserCommunication _userCommunication = nts::UserCommunication();
    nts::System _system = nts::System(_userCommunication);

    _parser.parseFileAndLoadMap("tests/false.nts", _system);
}