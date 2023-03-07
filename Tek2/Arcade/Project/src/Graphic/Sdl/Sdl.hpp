/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Sdl
*/

#ifndef SDL_HPP_
#define SDL_HPP_

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include "AGraphic.hpp"

namespace arcade {
    namespace graphic {

        typedef struct pixel_s {
            int r;
            int g;
            int b;
        } pixel_t;
    
        class Sdl : public AGraphic {
            public:
                Sdl();
                ~Sdl();
                void initWindow(std::string const &name);
                void closeWindow();
                void clearScreen();
                void displayBackground(const arcade::game_object_t &);
                void displayScreen();
                void displayGameObject(const game_object_t &);
                std::vector<arcade::event_t> getPendingEvent();
                void drawPendingGameObjects(const std::vector<arcade::game_object_t> &);
                void drawPendingTexts(const std::vector<arcade::text_object_t> &);
                bool getStatus() const;
                arcade::graphic::pixel_t transformHexaColorToPixel(const std::string &) const;
                int transformVirtualCaseToInt(std::size_t size, bool axe_x) const;
                SDL_Rect transformGameObjectToRect(const arcade::game_object_t &game_object) const;
                void displayRect(const arcade::game_object_t &game_object) const;
                void displayTextObject(const text_object_t &text_object);
                SDL_Rect transformTextObjectToRect(const arcade::text_object_t &text_object) const;

            protected:
            private:
                SDL_Window *_window;
                SDL_Surface *_screenSurface;
                int _screenWidth;
                int _screenHeight;
                bool _status;
        };
    };
};

#endif /* !SDL_HPP_ */
