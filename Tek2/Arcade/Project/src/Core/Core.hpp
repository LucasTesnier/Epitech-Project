/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <string>
#include "DLLoader/DLLoader.hpp"
#include "Game/IGame.hpp"
#include "Graphic/IGraphic.hpp"

namespace arcade {
    class Core {
        public:
            Core();
            ~Core();
            void setGameLib(const std::string &libPath);
            arcade::DLLoader<arcade::game::IGame> &getGameLib() const;
            void setGraphicLib(const std::string &libPath);
            arcade::DLLoader<arcade::graphic::IGraphic> &getGraphicLib() const;
            void loopArcade();
            void loopGraphicLib(bool);
            void loopGameLib(bool);
            void switchToMenu();
            void updateAScore(int score);

        protected:
        private:
            arcade::DLLoader<arcade::game::IGame> *_gameLib;
            arcade::DLLoader<arcade::graphic::IGraphic> *_graphicLib;
            arcade::graphic::IGraphic *_graph;
            arcade::game::IGame *_game;
            std::vector<std::string> _v_gameLib;
            int _i_gameLib;
            std::vector<std::string> _v_graphicLib;
            int _i_graphicLib;
            std::vector<arcade::score_object_t> _savedScore;
            std::string _pseudo;
            bool _paused;
    };
};

#endif /* !CORE_HPP_ */
