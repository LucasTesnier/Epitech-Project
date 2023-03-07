/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Sdl
*/

#include "Sdl.hpp"
#include "IGraphic.hpp"
#include <iostream>

/* A function that returns a pointer to a new instance of the Sdl class. */

extern "C" arcade::graphic::IGraphic *entryPointGraphic(void)
{
    arcade::graphic::IGraphic *newGraphic = new arcade::graphic::Sdl;

    return newGraphic;
}

/**
 * @brief It initializes the window
 */
arcade::graphic::Sdl::Sdl()
{
    _screenWidth = 1920;
    _screenHeight = 1080;
    _window = nullptr;
    _screenSurface = nullptr;
    _status = true;
    initWindow("Arcade SDL");
}

/**
 * @brief It closes the window
 */
arcade::graphic::Sdl::~Sdl()
{
   closeWindow();
}

/**
 * @brief It initializes the SDL library, creates a window, and initializes the SDL_ttf library
 * 
 * @param name The name of the window.
 * 
 * @return A pointer to the window surface.
 */
void arcade::graphic::Sdl::initWindow(std::string const &name = "ARCADE SFML")
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        ///THROW ERROR
        return;
    _window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _screenWidth, _screenHeight, SDL_WINDOW_SHOWN);
    if (_window == nullptr)
        //THROW ERROR
        return;
    _screenSurface = SDL_GetWindowSurface(_window);
    if (TTF_Init() < 0)
        //THROW ERROR
        return;
}

/**
 * @brief It closes the window.
 */
void arcade::graphic::Sdl::closeWindow()
{
    TTF_Quit();
    SDL_FreeSurface(_screenSurface);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

/**
 * @brief It clears the screen
 */
void arcade::graphic::Sdl::clearScreen()
{
    SDL_FillRect(_screenSurface, NULL, SDL_MapRGB(_screenSurface->format, 0xFF, 0xFF, 0xFF));
}

/**
 * @brief It transforms a virtual case size to a real case size
 * 
 * @param size the size of the case in percentage
 * @param axe_x true if you want to transform a virtual case on the x axe, false if you want to
 * transform a virtual case on the y axe.
 * 
 * @return the position of the case in the window.
 */
int arcade::graphic::Sdl::transformVirtualCaseToInt(std::size_t size, bool axe_x) const
{
    int res = 0;
    float a = size;

    a *= 2;
    if (axe_x)
        res = _screenWidth * (a / 100);
    else
        res = _screenHeight * (a / 100);
    return res;
}

/**
 * @brief It transforms a game object into a SDL_Rect
 * 
 * @param game_object The game object to transform
 * 
 * @return A SDL_Rect
 */
SDL_Rect arcade::graphic::Sdl::transformGameObjectToRect(const arcade::game_object_t &game_object) const
{
    SDL_Rect rect = SDL_Rect {
        transformVirtualCaseToInt(game_object.pos.x, true),
        transformVirtualCaseToInt(game_object.pos.y, false),
        transformVirtualCaseToInt(game_object.size.x, true),
        transformVirtualCaseToInt(game_object.size.y, false)
    };

    return rect;
}

/**
 * @brief It transforms a text object into a SDL_Rect
 * 
 * @param text_object The text object to transform
 * 
 * @return A SDL_Rect object.
 */
SDL_Rect arcade::graphic::Sdl::transformTextObjectToRect(const arcade::text_object_t &text_object) const
{
    SDL_Rect rect = SDL_Rect {
        transformVirtualCaseToInt(text_object.pos.x, true),
        transformVirtualCaseToInt(text_object.pos.y, false),
        transformVirtualCaseToInt(0, true),
        transformVirtualCaseToInt(0, false)
    };

    return rect;
}

/**
 * @brief It takes a game_object_t and displays it on the screen
 * 
 * @param game_object The game object to display
 */
void arcade::graphic::Sdl::displayRect(const arcade::game_object_t &game_object) const
{
    arcade::graphic::pixel_t color = transformHexaColorToPixel(game_object.color);
    SDL_Rect rect = transformGameObjectToRect(game_object);

    SDL_FillRect(_screenSurface, &rect, SDL_MapRGB(_screenSurface->format, color.r, color.g, color.b));
}

/**
 * @brief It converts a hexadecimal color to a pixel_t structure
 * 
 * @param color The color to transform
 * 
 * @return A pixel_t struct
 */
arcade::graphic::pixel_t arcade::graphic::Sdl::transformHexaColorToPixel(const std::string &color) const
{
    arcade::graphic::pixel_t colors;

    sscanf(color.c_str(), "%02x%02x%02x", &(colors.r), &(colors.g), &(colors.b));
    return colors;
}

/**
 * @brief It loads the image from the path given in the game_object_t, then blits it to the screen
 * 
 * @param game_object The game object to display
 * 
 * @return A pointer to the surface
 */
void arcade::graphic::Sdl::displayBackground(const arcade::game_object_t &game_object)
{
    SDL_Surface *newAsset = SDL_LoadBMP(game_object.path.c_str());

    if (newAsset == nullptr) {
        displayRect(game_object);
        return;
    }
    SDL_BlitSurface(newAsset, NULL, _screenSurface, NULL);
    SDL_FreeSurface(newAsset);
}

/**
 * @brief It updates the window surface
 */
void arcade::graphic::Sdl::displayScreen()
{
    SDL_UpdateWindowSurface(_window);
}

/**
 * @brief It takes a game_object_t and displays it on the screen
 * 
 * @param game_object The game object to display.
 * 
 * @return A rectangle
 */
void arcade::graphic::Sdl::displayGameObject(const game_object_t &game_object)
{
    SDL_Surface *newAsset = SDL_LoadBMP(game_object.path.c_str());
    if (newAsset == nullptr) {
        displayRect(game_object);
        return;
    }
    SDL_Rect rect = transformGameObjectToRect(game_object);
    SDL_BlitSurface(newAsset, NULL, _screenSurface, &rect);
    SDL_FreeSurface(newAsset);
}

/**
 * @brief It takes a text_object_t, which is a struct containing all the information needed to display a text,
 * and displays it on the screen
 * 
 * @param text_object the text object to display
 * 
 * @return A SDL_Rect
 */
void arcade::graphic::Sdl::displayTextObject(const text_object_t &text_object)
{
    TTF_Font* font = TTF_OpenFont(text_object.fontPath.c_str(), text_object.size);
    if (font == nullptr) {
        //THROW AN ERROR
        return;
    }
    arcade::graphic::pixel_t color = transformHexaColorToPixel(text_object.textColor);
    arcade::graphic::pixel_t back_color = transformHexaColorToPixel(text_object.backgroundColor);
    SDL_Rect rect = transformTextObjectToRect(text_object);

    SDL_Color colors = {(Uint8)color.r, (Uint8)color.g, (Uint8)color.b, 255};
    SDL_Color back = {(Uint8)back_color.r, (Uint8)back_color.g, (Uint8)back_color.b, 255};
    SDL_Surface *surfaceMessage;
    if (text_object.backgroundColor == "000000")
        surfaceMessage = TTF_RenderText_Solid(font, text_object.message.c_str(), colors);
    else
        surfaceMessage = TTF_RenderText_Shaded(font, text_object.message.c_str(), colors, back);
    if (surfaceMessage == nullptr) {
        //THROW AN ERROR
        return;
    }
    SDL_BlitSurface(surfaceMessage, NULL, _screenSurface, &rect);
    SDL_FreeSurface(surfaceMessage);
    TTF_CloseFont(font);
}

/**
 * @brief It takes the events that have been triggered and puts them in a vector
 * 
 * @return A vector of event_t
 */
std::vector<arcade::event_t> arcade::graphic::Sdl::getPendingEvent()
{
    std::vector<arcade::event_t> v_event;
    SDL_Event event;

    while(SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            _status = false;
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_UP:
                    v_event.push_back(event_t::NEXT_GRAPHIC);
                    break;
                case SDLK_DOWN:
                    v_event.push_back(event_t::PREV_GRAPHIC);
                    break;
                case SDLK_LEFT:
                    v_event.push_back(event_t::PREV_GAME);
                    break;
                case SDLK_RIGHT:
                    v_event.push_back(event_t::NEXT_GAME);
                    break;
                case SDLK_ESCAPE:
                    _status = false;
                    break;
                case SDLK_z:
                    v_event.push_back(event_t::UP);
                    break;
                case SDLK_s:
                    v_event.push_back(event_t::DOWN);
                    break;
                case SDLK_q:
                    v_event.push_back(event_t::LEFT);
                    break;
                case SDLK_d:
                    v_event.push_back(event_t::RIGHT);
                    break;
                case SDLK_a:
                    v_event.push_back(event_t::PAUSE);
                    break;
                case SDLK_r:
                    v_event.push_back(event_t::RESTART);
                    break;
                case SDLK_e:
                    v_event.push_back(event_t::MENU);
                    break;
                case SDLK_SPACE:
                    v_event.push_back(event_t::ACTION);
                    break;
                default:
                    break;
            }
        }
    }
    return v_event;
}

/**
 * @brief It returns the status of the SDL library
 * 
 * @return The status of the window.
 */
bool arcade::graphic::Sdl::getStatus() const
{
    return _status;
}

/**
 * @brief It takes a vector of game_object_t and displays them on the screen
 * 
 * @param game_object A vector of game_object_t.
 */
void arcade::graphic::Sdl::drawPendingGameObjects(const std::vector<arcade::game_object_t> &game_object)
{
    for (auto &obj : game_object) {
        displayGameObject(obj);
    }
}

/**
 * @brief It takes a vector of text objects and displays them on the screen
 * 
 * @param text_object a vector of text_object_t, which is a struct containing the following:
 */
void arcade::graphic::Sdl::drawPendingTexts(const std::vector<arcade::text_object_t> &text_object)
{
    for (auto &obj : text_object) {
        displayTextObject(obj);
    }
}