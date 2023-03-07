#include "Core.hpp"
#include "Error/Error.hpp"
#include "Menu/Menu.hpp"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <unistd.h>

/**
 * @brief It returns a vector of strings, each string being the path to a shared library in the lib directory
 * 
 * @return A vector of strings containing the names of the shared libraries in the lib directory.
 */
const std::vector<std::string> getLibContent()
{
    std::vector<std::string> lib_content;

    for (const auto & entry : std::filesystem::directory_iterator("./lib")) {
        std::string temp = entry.path();
        if (temp.substr(temp.find_last_of(".") + 1) == "so")
            lib_content.push_back(temp);
    }

    return lib_content;
}

/**
 * @brief It tries to load a graphic library, and if it fails, it returns false
 * 
 * @param lib The library to load
 * 
 * @return A boolean
 */
bool isAGraphicLib(const std::string &lib)
{
    try {
        arcade::DLLoader<arcade::graphic::IGraphic>(lib, "Graphic", true);
        return true;
    } catch (arcade::ErrorLoader const &error) {
        return false;
    }
}

/**
 * @brief It tries to load a game library, and if it fails, it returns false
 * 
 * @param lib The library to load
 * 
 * @return A boolean
 */
bool isAGameLib(const std::string &lib)
{
    try {
        arcade::DLLoader<arcade::game::IGame>(lib, "Game", true);
        return true;
    } catch (arcade::ErrorLoader const &error) {
        std::cout << error.what() << " " << error.getComponent() << std::endl;
        return false;
    }
}

/**
 * @brief It opens a file, writes the score and closes the file
 * 
 * @param score_object The vector of score_object_t that you want to save.
 * 
 * @return The score of the player
 */
void saveTheScore(const std::vector<arcade::score_object_t> &score_object)
{
    std::ofstream scoreFile;

    scoreFile.open("./saves/score");
    if (!scoreFile.is_open())
        // THROW AN ERROR
        return;
    for (const auto & score : score_object) {
        scoreFile << score.pseudo << " " << std::to_string(score.score) << std::endl;
    }
    scoreFile.close();
}

/**
 * @brief It opens the score file, reads it line by line, and pushes the line into a vector of score_object_t
 * 
 * @return A vector of score_object_t
 */
std::vector<arcade::score_object_t> getSavedScore()
{
    std::vector<arcade::score_object_t> savedScore;
    std::string line;
    std::ifstream scoreFile("./saves/score");

    if (!scoreFile.is_open())
        // THROW AN ERROR
        return savedScore;
    while(std::getline(scoreFile, line)) {
        savedScore.push_back(arcade::score_object_t {
            line.substr(0, line.find(" ")),
            std::stoi(line.substr(line.find(" ") + 1))
        });
    }
    scoreFile.close();
    return savedScore;
}

/**
 * @brief It returns the index of the string in the vector
 * 
 * @param lib The vector of strings that we're searching through.
 * @param actual The actual value that we want to find the index of.
 * 
 * @return The index of the string in the vector.
 */
int getIndex(std::vector<std::string> &lib, const std::string &actual)
{
    auto index = find(lib.begin(), lib.end(), actual);

    return (index - lib.begin());
}


/**
 * @brief It initializes the Core class
 */
arcade::Core::Core()
{
    std::vector<std::string> lib_content = getLibContent();

    _gameLib = nullptr;
    _graphicLib = nullptr;
    for (const auto &lib : lib_content) {
        if (isAGraphicLib(lib))
            _v_graphicLib.push_back(lib);
        else if (isAGameLib(lib))
            _v_gameLib.push_back(lib);
    }
    _savedScore = getSavedScore();
    _i_graphicLib = 0;
    _i_gameLib = 0;
    _paused = false;
    _pseudo = "AAAA";
}


/**
 * @brief It deletes the old game library and loads the new one
 * 
 * @param libPath The path to the library to load
 */
void arcade::Core::setGameLib(const std::string &libPath)
{
    if (_gameLib) {
        delete _gameLib;
        _gameLib = nullptr;
    }
    _gameLib = new DLLoader<arcade::game::IGame>(libPath, "Game");
}

arcade::DLLoader<arcade::game::IGame> &arcade::Core::getGameLib() const
{
    return *_gameLib;
}

/**
 * @brief It sets the graphic library to the one specified by the path
 * 
 * @param libPath The path to the library
 */
void arcade::Core::setGraphicLib(const std::string &libPath)
{
    if (_graphicLib) {
        delete _graphicLib;
        _graphicLib = nullptr;
    }
    _graphicLib = new DLLoader<arcade::graphic::IGraphic>(libPath, "Graphic");
    _i_graphicLib = getIndex(_v_graphicLib, libPath);
}


arcade::DLLoader<arcade::graphic::IGraphic> &arcade::Core::getGraphicLib() const
{
    return *_graphicLib;
}


/**
 * @brief It deletes the current graphic library, increments or decrements the index of the graphic library,
 * and then sets the graphic library to the new index
 * 
 * @param isNext true if we want to go to the next library, false if we want to go to the previous one.
 */
void arcade::Core::loopGraphicLib(bool isNext)
{
    this->_graph->~IGraphic();
    if (isNext) {
        _i_graphicLib += 1;
        if ((std::size_t)_i_graphicLib >= _v_graphicLib.size())
            _i_graphicLib = 0;
    } else {
        _i_graphicLib -= 1;
        if (_i_graphicLib < 0)
            _i_graphicLib = _v_graphicLib.size() -1;
    }
    this->setGraphicLib(_v_graphicLib[_i_graphicLib]);
    _graph = getGraphicLib().getInstance();
}


/**
 * @brief It deletes the current game, increments or decrements the index of the game library vector, sets the
 * game library to the new index, and then creates a new instance of the game
 * 
 * @param isNext true if we want to go to the next game, false if we want to go to the previous game.
 */
void arcade::Core::loopGameLib(bool isNext)
{
    this->_game->~IGame();
    if (isNext) {
        _i_gameLib += 1;
        if ((std::size_t)_i_gameLib >= _v_gameLib.size())
            _i_gameLib = 0;
    } else {
        _i_gameLib -= 1;
        if (_i_gameLib < 0)
            _i_gameLib = _v_gameLib.size() - 1;
    }
    this->setGameLib(_v_gameLib[_i_gameLib]);
    _game = getGameLib().getInstance();
}

/**
 * @brief It switches the current game to the menu
 */
void arcade::Core::switchToMenu()
{
    this->_game->~IGame();
    _game = new arcade::game::Menu(_v_gameLib, _v_graphicLib, _savedScore, _pseudo);
}

/**
 * @brief It updates the score of the player in the _savedScore vector
 * 
 * @param score The score to add to the player's score
 * 
 * @return the score of the player.
 */
void arcade::Core::updateAScore(int score)
{
    std::size_t count = 0;

    for (auto &player : _savedScore) {
        if (player.pseudo == _pseudo) {
            _savedScore[count].score += score;
            return;
        }
        count++;
    }
    _savedScore.push_back(arcade::score_object_t {
        _pseudo,
        score
    });
}


/**
 * @brief It's a loop that calls the functions of the graphic library and the game library
 * 
 * @return nothing.
 */
void arcade::Core::loopArcade()
{
    _graph = getGraphicLib().getInstance();
    _game = new arcade::game::Menu(_v_gameLib, _v_graphicLib, _savedScore, _pseudo);
    std::vector<arcade::event_t> v_event;
    std::vector<arcade::text_object_t> v_text;

    while (_graph->getStatus()) {
        _graph->clearScreen();
        _graph->displayBackground(_game->getBackground());
        _graph->drawPendingGameObjects(_game->getPendingItems());
        v_text = _game->getPendingTexts();
        for (auto &txt : v_text) {
            std::size_t temp = txt.message.find("./lib/");
            if (temp != std::string::npos) {
                if (txt.fontPath == "Graphic") {
                    this->_graph->~IGraphic();
                    this->setGraphicLib(txt.message);
                    _graph = getGraphicLib().getInstance();
                } else if (txt.fontPath == "Game") {
                    this->_game->~IGame();
                    this->setGameLib(txt.message);
                    _game = getGameLib().getInstance();
                }
            }
            if (txt.fontPath == "Pseudo") {
                _pseudo = txt.message;
            }
            if (txt.fontPath == "Score" && !_paused) {
                updateAScore(std::stoi(txt.message));
            }
        }
        _graph->drawPendingTexts(v_text);
        _graph->displayScreen();
        v_event = _graph->getPendingEvent();
        for (auto &ev : v_event) {
            switch (ev)
            {
            case NEXT_GRAPHIC:
                this->loopGraphicLib(true);
                break;
            case NEXT_GAME:
                this->loopGameLib(true);
                break;
            case PREV_GRAPHIC:
                this->loopGraphicLib(false);
                break;
            case PREV_GAME:
                this->loopGameLib(false);
                break;
            case MENU:
                this->switchToMenu();
                break;
            case PAUSE:
                if (_paused)
                    _paused = false;
                else
                    _paused = true;
                break;
            case ESCAPE:
                return;
            default:
                break;
            }
        }
        if (!_paused) {
            _game->simulate();
            _game->doPendingEvent(v_event);
        }
        if (_game->getGameStatus() == arcade::game_status_t::LOSE ||
            _game->getGameStatus() == arcade::game_status_t::WIN) {
            this->switchToMenu();
        }
    }   
}

/**
 * @brief It deletes the game and graphic libraries, and saves the score
 */
arcade::Core::~Core()
{
    saveTheScore(_savedScore);
    if (_gameLib)
        delete _gameLib;
    if (_graphicLib)
        delete _graphicLib;
}