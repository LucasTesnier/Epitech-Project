/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include "AGame.hpp"

const std::vector<std::string> getLibContent();

namespace arcade {
    namespace game {
        class Menu : public AGame {
            public:
                Menu(std::vector<std::string> &, std::vector<std::string> &, std::vector<arcade::score_object_t> &, std::string &);
                ~Menu();
                const std::vector<arcade::game_object_t> getPendingItems() const;
                void simulate();
                void doPendingEvent(std::vector<arcade::event_t> &);
                const arcade::game_object_t getBackground() const;
                void reset();
                arcade::game_status_t getGameStatus() const;
                const std::vector<arcade::text_object_t> getPendingTexts() const;
                arcade::game_object_t drawABox(arcade::vector2i_t pos) const;
                arcade::text_object_t drawAText(const std::string &message, std::size_t size, const std::string &back, arcade::vector2i_t pos) const;
                void drawAvailableGame(std::vector<arcade::text_object_t> &text_object) const;
                void drawAvailableGraphic(std::vector<arcade::text_object_t> &text_object) const;
                void drawSavedScore(std::vector<arcade::text_object_t> &text_object) const;
                void drawPseudo(std::vector<arcade::text_object_t> &text_object) const;
                void doCursorAction();

            protected:
                void initGame();
                void destroyGame();
                std::vector<std::string> &_v_gameLib;
                std::size_t _s_gameLib;
                std::vector<std::string> &_v_graphicLib;
                std::size_t _s_graphicLib;
                std::vector<arcade::score_object_t> &_savedScore;
                std::size_t cursor;
                std::vector<char> _v_pseudo;
                std::string _pendingGame;
                std::string _pendingGraphic;
            private:
        };
    };
};

#endif /* !MENU_HPP_ */
