/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Sfml
*/

#include "Sfml.hpp"
#include <iostream>
#include "IGraphic.hpp"

/**
 * @brief linking the library with DLLoader
 *
 */

extern "C" arcade::graphic::IGraphic *entryPointGraphic(void)
{
    arcade::graphic::IGraphic *newGraphic = new arcade::graphic::Sfml;

    return newGraphic;
}

/**
 * @brief Construct a new arcade::graphic::Sfml::Sfml object
 *
 */

arcade::graphic::Sfml::Sfml()
{
    this->_sizeWindow_x = 1920;
    this->_sizeWindow_y = 1080;
    this->initWindow("Arcade SFML");
    this->_gameOver = false;
}

/**
 * @brief Destroy the arcade::graphic::Sfml::Sfml object
 *
 */

arcade::graphic::Sfml::~Sfml()
{
    closeWindow();
}

/**
 * @brief
 * close the window
 *
 */
void arcade::graphic::Sfml::closeWindow()
{
    this->_window.close();
}

/**
 * @brief
 * clear the window
 *
 */
void arcade::graphic::Sfml::clearScreen()
{
    this->_window.clear();
}

/**
 * @brief create the window with a name and the dekstop mode
 *
 * @param name
 */
void arcade::graphic::Sfml::initWindow(std::string const &name)
{
    this->_window.create(sf::VideoMode(1920, 1080), name.c_str());
}

/**
 * @brief get SFML events
 * escape close the window
 */
std::vector<arcade::event_t> arcade::graphic::Sfml::getPendingEvent()
{
    sf::Event event;
    std::vector<arcade::event_t> v_event;

    while (this->_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            _gameOver = true;
            closeWindow();
            return v_event;
        }
        if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
                case sf::Keyboard::Escape:
                    _gameOver = true;
                    break;
                case sf::Keyboard::Z:
                    v_event.push_back(event_t::UP);
                    break;
                case sf::Keyboard::S:
                    v_event.push_back(event_t::DOWN);
                    break;
                case sf::Keyboard::Q:
                    v_event.push_back(event_t::LEFT);
                    break;
                case sf::Keyboard::D:
                    v_event.push_back(event_t::RIGHT);
                    break;
                case sf::Keyboard::Up:
                    v_event.push_back(event_t::NEXT_GRAPHIC);
                    break;
                case sf::Keyboard::Down:
                    v_event.push_back(event_t::PREV_GRAPHIC);
                    break;
                case sf::Keyboard::Left:
                    v_event.push_back(event_t::PREV_GAME);
                    break;
                case sf::Keyboard::Right:
                    v_event.push_back(event_t::NEXT_GAME);
                    break;
                case sf::Keyboard::A:
                    v_event.push_back(event_t::PAUSE);
                    break;
                case sf::Keyboard::R:
                    v_event.push_back(event_t::RESTART);
                    break;
                case sf::Keyboard::E:
                    v_event.push_back(event_t::MENU);
                    break;
                case sf::Keyboard::Space:
                    v_event.push_back(event_t::ACTION);
                    break;
                default:
                    break;
            }
        }
    }
    return v_event;
}

int arcade::graphic::Sfml::transformVirtualCaseToInt(std::size_t size, bool axe_x) const
{
    int res = 0;
    float a = size;

    a *= 2;
    if (axe_x)
        res = _sizeWindow_x * (a / 100);
    else
        res = _sizeWindow_y * (a / 100);
    return res;
}

/**
 * @brief draw the background of the SFML window
 *
 */
void::arcade::graphic::Sfml::displayBackground(const arcade::game_object_t &game_object)
{
    if (!this->_bgtexture.loadFromFile(game_object.path)) {
        //THROW AN ERROR
        displaySquare(game_object.color, 0, 0, 50, 50);
        return;
    }
    this->_bgsprite.setTexture(_bgtexture);
    this->_window.draw(_bgsprite);
}

/**
 * @brief display all what as been drawn on the window
 *
 */
void::arcade::graphic::Sfml::displayScreen()
{
    this->_window.display();
}

/**
 *
 * @brief draw a sprite at a given postition with his path
 *
 * @param path
 * @param x
 * @param y
 */
void arcade::graphic::Sfml::displayElem(std::string path, std::string color, int x, int y, int x2, int y2, int rotation)
{
    sf::Vector2f pos((float)transformVirtualCaseToInt(x, true), (float)transformVirtualCaseToInt(y, false));
    sf::Vector2f size((float)transformVirtualCaseToInt(x2, true), (float)transformVirtualCaseToInt(y2, false));
    sf::Texture texture;
    sf::Sprite sprite;
    if (path.empty() || !texture.loadFromFile(path)) {
        // std::cerr << "ERROR: cannot found texture " + path << std::endl;
        displaySquare(color, x, y, x2, y2);
    }
    sprite.setTexture(texture);
    sprite.setPosition(pos);
    (void)rotation;
    // sprite.setRotation((float)rotation);
    this->_window.draw(sprite);
}

/**
 * @brief display a square on the screen with a gameobject
 *
 * @param pos
 * @param colorstr
 */
void arcade::graphic::Sfml::displaySquare(std::string colorstr, int x, int y, int x2, int y2)
{
    sf::Vector2f pos((float)transformVirtualCaseToInt(x, true), (float)transformVirtualCaseToInt(y, false));
    sf::Vector2f size((float)transformVirtualCaseToInt(x2, true), (float)transformVirtualCaseToInt(y2, false));
    int r, g, b;
    char const *hexColor = colorstr.c_str();
    std::sscanf(hexColor, "%02x%02x%02x", &r, &g, &b);
    sf::Color color(r, g, b, 255);
    sf::RectangleShape rect;

    rect.setFillColor(color);
    rect.setPosition(pos);
    rect.setSize(size);
    this->_window.draw(rect);
}


/**
 * @brief draw a game_obect_t
 *
 * @param obj
 */
void arcade::graphic::Sfml::displayGameObject(const game_object_t &obj)
{
    this->displayElem(obj.path, obj.color, obj.pos.x, obj.pos.y, obj.size.x, obj.size.y, obj.orientation);
}

/**
 * @brief draw a vector of game object
 *
 * @param v_game
 */
void arcade::graphic::Sfml::drawPendingGameObjects(const std::vector<arcade::game_object_t> &v_game)
{
    for (auto &obj : v_game) {
        this->displayGameObject(obj);
    }
}

void arcade::graphic::Sfml::displayText(arcade::text_object_t txt)
{
    sf::Font font;
    sf::Text text;
    int r, g, b;
    char const *hexColor = ((txt.backgroundColor == "000000") ? txt.textColor.c_str() : txt.backgroundColor.c_str());
    std::sscanf(hexColor, "%02x%02x%02x", &r, &g, &b);
    sf::Color color(r, g, b, 255);
    sf::Vector2f pos((float)transformVirtualCaseToInt(txt.pos.x, true), (float)transformVirtualCaseToInt(txt.pos.y, false));
    if (!font.loadFromFile(txt.fontPath)) {
        //THROW AN ERROR
        std::cerr << "ERROR: cannot found font " + txt.fontPath << std::endl;
    }
    text.setFont(font);
    text.setString(txt.message);
    text.setCharacterSize(txt.size);
    text.setFillColor(color);
    text.setPosition(pos);
    _window.draw(text);
}

/**
 * @brief draw all texts on screen
 *
 * @param texts
 */
void arcade::graphic::Sfml::drawPendingTexts(const std::vector<arcade::text_object_t> &texts)
{
    for (auto &txt : texts) {
        this->displayText(txt);
    }
}
/**
 * @brief return the status of the window.isOpen()
 *
 * @return true
 * @return false
 */
bool arcade::graphic::Sfml::getStatus() const
{
    return !this->_gameOver;
}

