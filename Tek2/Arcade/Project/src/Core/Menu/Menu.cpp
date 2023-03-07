/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Menu
*/

#include "Menu.hpp"

/**
 * @brief It initializes the menu.
 * 
 * @param v_gameLib a vector of strings containing the names of the games available
 * @param v_graphicLib a vector of strings containing the names of the graphic libraries
 * @param savedScore a vector of score_object_t, which is a struct containing a pseudo and a score.
 * @param pseudo The player's pseudo
 */
arcade::game::Menu::Menu(std::vector<std::string> &v_gameLib, std::vector<std::string> &v_graphicLib, std::vector<arcade::score_object_t> &savedScore, std::string &pseudo) : _v_gameLib(v_gameLib), _v_graphicLib(v_graphicLib), _savedScore(savedScore)
{
    _s_gameLib = _v_gameLib.size();
    _s_graphicLib = _v_graphicLib.size();
    cursor = 1;
    _v_pseudo.push_back(pseudo[0]);
    _v_pseudo.push_back(pseudo[1]);
    _v_pseudo.push_back(pseudo[2]);
    _v_pseudo.push_back(pseudo[3]);
    _pendingGame = "";
    _pendingGraphic = "";
    initGame();
}

/**
 * @brief It's the destructor of the Menu class
 */
arcade::game::Menu::~Menu()
{
}

/**
 * @brief It draws a box
 * 
 * @param pos The position of the box
 * 
 * @return A game object
 */
arcade::game_object_t arcade::game::Menu::drawABox(arcade::vector2i_t pos) const
{
    arcade::game_object_t game_object;

    game_object.path = "./assets/menu/box_bezell.bmp";
    game_object.color = "0700E3";
    game_object.pos = pos;
    game_object.orientation = arcade::orientation_t::EUP;
    game_object.size = arcade::vector2i_t {
        14,
        14
    };

    return game_object;
}

/**
 * @brief It returns a vector of game_object_t, which are the boxes that will be drawn on the screen
 * 
 * @return A vector of game_object_t
 */
const std::vector<arcade::game_object_t> arcade::game::Menu::getPendingItems() const
{
    std::vector<arcade::game_object_t> pending_item;

    pending_item.push_back(drawABox(arcade::vector2i_t {
        5,
        5
    }));
    pending_item.push_back(drawABox(arcade::vector2i_t {
        30,
        10
    }));
    pending_item.push_back(drawABox(arcade::vector2i_t {
        5,
        25
    }));
    pending_item.push_back(drawABox(arcade::vector2i_t {
        30,
        30
    }));
    return pending_item;
}

/**
 * @brief It does nothing
 */
void arcade::game::Menu::simulate()
{
    _pendingGraphic = "";
}

/**
 * @brief It handles the cursor's action
 */
void arcade::game::Menu::doCursorAction()
{
    if (cursor <= _s_gameLib) {
        _pendingGame = _v_gameLib[cursor - 1];
    }
    if (cursor > _s_gameLib && cursor <= _s_graphicLib + _s_gameLib) {
        _pendingGraphic = _v_graphicLib[cursor - _s_gameLib - 1];
    }
    if (cursor == _s_gameLib + _s_graphicLib + 1) {
        _v_pseudo[0] += 1;
        if (_v_pseudo[0] > 'Z')
            _v_pseudo[0] = 'A';
    }
    if (cursor == _s_gameLib + _s_graphicLib + 2) {
        _v_pseudo[1] += 1;
        if (_v_pseudo[1] > 'Z')
            _v_pseudo[1] = 'A';
    }
    if (cursor == _s_gameLib + _s_graphicLib + 3) {
        _v_pseudo[2] += 1;
        if (_v_pseudo[2] > 'Z')
            _v_pseudo[2] = 'A';
    }
    if (cursor == _s_gameLib + _s_graphicLib + 4) {
        _v_pseudo[3] += 1;
        if (_v_pseudo[3] > 'Z')
            _v_pseudo[3] = 'A';
    }
}

/**
 * @brief It's a function that does the pending event
 * 
 * @param event The event vector
 */
void arcade::game::Menu::doPendingEvent(std::vector<arcade::event_t> &event)
{
    for (const auto a_event : event) {
        if (a_event == arcade::event_t::UP) {
            cursor -= 1;
            if (cursor == 0)
                cursor = _s_gameLib + _s_graphicLib + 4;
        }
        if (a_event == arcade::event_t::DOWN) {
            cursor += 1;
            if (cursor > _s_gameLib + _s_graphicLib + 4)
                cursor = 1;
        }
        if (a_event == arcade::event_t::ACTION) {
            doCursorAction();
        }
    }
}

/**
 * @brief It returns a game object that represents the background of the menu
 * 
 * @return A game object
 */
const arcade::game_object_t arcade::game::Menu::getBackground() const
{
    arcade::game_object_t game_object;

    game_object.path = "./assets/menu/background.bmp";
    game_object.color = "3346FF";
    game_object.pos = arcade::vector2i_t {
        0,
        0
    };
    game_object.orientation = arcade::orientation_t::EUP;
    game_object.size = arcade::vector2i_t {
        50,
        50
    };
    return game_object;
}

/**
 * @brief This function resets the game
 */
void arcade::game::Menu::reset()
{

}

/**
 * @brief Return the game status.
 * 
 * @return The game status.
 */
arcade::game_status_t arcade::game::Menu::getGameStatus() const
{
    arcade::game_status_t game_status = arcade::game_status_t::IN_PROGRESS;

    return game_status;
}

/**
 * @brief It draws a text
 * 
 * @param message The text to display
 * @param size The size of the text
 * @param back background color of the text
 * @param pos The position of the text
 * 
 * @return A text object
 */
arcade::text_object_t arcade::game::Menu::drawAText(const std::string &message, std::size_t size, const std::string &back, arcade::vector2i_t pos) const
{
    arcade::text_object_t text;

    text.message = message;
    text.fontPath = "assets/font/arial.ttf";
    text.size = size;
    text.pos = pos;
    text.textColor = "FF1493";
    text.backgroundColor = back;
    return text;
}

/**
 * @brief It draws the available games in the menu
 * 
 * @param text_object The vector of text_object_t that will be used to draw the text.
 */
void arcade::game::Menu::drawAvailableGame(std::vector<arcade::text_object_t> &text_object) const
{
    std::size_t y = 6;
    std::size_t count = 1;
    std::string back = "000000";

    text_object.push_back(drawAText("Available Games", 30, "000000", arcade::vector2i_t {
            9,
            y
    }));
    y += 3;
    for (const auto & lib : _v_gameLib) {
        if (cursor <= _s_gameLib && cursor >= 1 && cursor == count)
            back = "0700E3";
        else
            back = "000000";
        text_object.push_back(drawAText(lib, 25, back, arcade::vector2i_t {
            7,
            y
        }));
        y += 2;
        count += 1;
    }
}

/**
 * @brief It draws the available graphic libraries
 * 
 * @param text_object The vector of text_object_t that will be used to draw the text.
 */
void arcade::game::Menu::drawAvailableGraphic(std::vector<arcade::text_object_t> &text_object) const
{
    std::size_t y = 11;
    std::string back = "000000";
    std::size_t count = 1;

    text_object.push_back(drawAText("Available Graphics", 30, "000000", arcade::vector2i_t {
            34,
            y
    }));
    y += 3;
    for (const auto & lib : _v_graphicLib) {
         if (cursor <= _s_graphicLib + _s_gameLib && cursor > _s_gameLib && cursor == _s_gameLib + count)
            back = "0700E3";
        else
            back = "000000";
        text_object.push_back(drawAText(lib, 25, back, arcade::vector2i_t {
            32,
            y
        }));
        y += 2;
        count++;
    }
}

/**
 * @brief It draws the saved scores on the screen
 * 
 * @param text_object The vector of text_object_t to fill
 */
void arcade::game::Menu::drawSavedScore(std::vector<arcade::text_object_t> &text_object) const
{
    std::size_t y = 26;

    text_object.push_back(drawAText("Hightests Scores !", 30, "000000", arcade::vector2i_t {
        9,
        y
    }));
    y += 3;
    for (const auto & score : _savedScore) {
        if (y > 26 + 2 * 5)
            break;
        text_object.push_back(drawAText(score.pseudo + "        " + std::to_string(score.score), 25, "000000", arcade::vector2i_t {
            7,
            y
        }));
        y += 2;
    }
}

/**
 * @brief It draws the pseudo that the user is currently typing
 * 
 * @param text_object The vector of text_object_t that will be filled by the function.
 */
void arcade::game::Menu::drawPseudo(std::vector<arcade::text_object_t> &text_object) const
{
    std::size_t y = 34;
    std::string back = "000000";
    std::size_t count = 1;

    text_object.push_back(drawAText("Select pseudo", 30, "000000", arcade::vector2i_t {
            y,
            31
    }));
    y = 32;
    for (const auto & letter : _v_pseudo) {
         if (cursor <= _s_graphicLib + _s_gameLib + 4 && cursor > _s_gameLib + _s_graphicLib && cursor == _s_gameLib + _s_graphicLib + count)
            back = "0700E3";
        else
            back = "000000";
        text_object.push_back(drawAText(std::string(1, letter), 45, back, arcade::vector2i_t {
            y,
            35
        }));
        y += 3;
        count++;
    }
}

/**
 * @brief It returns a vector of text_object_t, which is a struct containing the text to display, the font,
 * the size, the position, the color and the background color
 * 
 * @return A vector of text_object_t
 */
const std::vector<arcade::text_object_t> arcade::game::Menu::getPendingTexts() const
{
    std::vector<arcade::text_object_t> text_object;

    text_object.push_back(drawAText("The Revenge Arcade", 40, "000000", arcade::vector2i_t {
        20,
        2
    }));
    drawAvailableGame(text_object);
    drawAvailableGraphic(text_object);
    drawSavedScore(text_object);
    drawPseudo(text_object);
    if (_pendingGame != "") {
        text_object.push_back(arcade::text_object_t {
            _pendingGame,
            "Game",
            0,
            arcade::vector2i_t {
                0,
                0
            },
            "FF1493",
            "000000"
        });
    }
    if (_pendingGraphic != "") {
        text_object.push_back(arcade::text_object_t {
            _pendingGraphic,
            "Graphic",
            0,
            arcade::vector2i_t {
                0,
                0
            },
            "FF1493",
            "000000"
        });
    }
    text_object.push_back(arcade::text_object_t {
            std::string(_v_pseudo.begin(), _v_pseudo.end()),
            "Pseudo",
            0,
            arcade::vector2i_t {
                0,
                0
            },
            "FF1493",
            "000000"
        });
    return text_object;
}

/**
 * @brief It initializes the game
 */
void arcade::game::Menu::initGame()
{

}

/**
 * @brief It destroys the game
 */
void arcade::game::Menu::destroyGame()
{

}