/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Ncurse
*/

#ifndef NCURSE_HPP_
#define NCURSE_HPP_

#include <ncurses.h>
#include <iostream>
#include "AGraphic.hpp"
#include "game_object.hpp"

namespace arcade {
    namespace graphic {

        typedef struct pixel_s {
            int r;
            int g;
            int b;
        } pixel_t;

        class Ncurse : public AGraphic{
            public:
                Ncurse();
                ~Ncurse();

                void clearScreen();



                //Displays function
                void drawPendingGameObjects(const std::vector<arcade::game_object_t> &);
                void displayScreen();
                void displayBackground(const arcade::game_object_t &);

                //std::vector<arcade::game_object_t> getPendingEvent();

                void initWindow(std::string const &name);
                void closeWindow();
                void displayGameObject(const game_object_t &);
                std::vector<arcade::event_t> getPendingEvent();
                void drawPendingTexts(const std::vector<arcade::text_object_t> &);
                bool getStatus() const;

            protected:

                //Init settings function
                void initKeypad();
                void initColors();
                void refreshScreen();
                arcade::graphic::pixel_t transformHexaColorToPixel(const std::string &color) const;
                arcade::graphic::pixel_t transformRgbToBinary(arcade::graphic::pixel_t color);
                int transformBinarytoColor(arcade::graphic::pixel_t color);
                void displayTextObject(arcade::text_object_t text_object);

            private:
                WINDOW *_window;
                bool _isOpen;
                std::string _name;
        };
    };
};

#endif /* !NCURSE_HPP_ */
