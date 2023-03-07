/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Sfml
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include <SFML/Graphics.hpp>
#include "AGraphic.hpp"

namespace arcade {
    namespace graphic {
        class Sfml : public AGraphic {
        public:
            Sfml();
            ~Sfml();
            void initWindow(std::string const &name);
            void closeWindow();
            void clearScreen();
            int transformVirtualCaseToInt(std::size_t size, bool axe_x) const;
            void displayBackground(const arcade::game_object_t &);
            void displayScreen();
            void displayGameObject(const game_object_t &);
            void drawPendingGameObjects(const std::vector<arcade::game_object_t> &);
            void drawPendingTexts(const std::vector<arcade::text_object_t> &);
            std::vector<arcade::event_t> getPendingEvent();
            bool getStatus() const;

        protected:
        private:
            void displayElem(std::string path, std::string color, int x, int y, int x2, int y2, int rotation);
            void displaySquare(std::string color, int x, int y, int x2, int y2);
            void displayText(arcade::text_object_t);
            sf::RenderWindow _window;
            int _sizeWindow_x;
            int _sizeWindow_y;
            bool _gameOver;
            sf::Texture _bgtexture;
            sf::Sprite _bgsprite;

        };
    };
};

#endif /* !SFML_HPP_ */
