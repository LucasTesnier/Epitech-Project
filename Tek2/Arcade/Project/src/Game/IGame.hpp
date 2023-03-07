/*
** EPITECH PROJECT, 2022
** Project
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include <vector>
#include <string>
#include "game_object.hpp"

namespace arcade {
    namespace game {
        class IGame {
            public:
                virtual ~IGame() = default;
                virtual const std::vector<arcade::game_object_t> getPendingItems() const = 0;
                virtual void simulate() = 0;
                virtual void doPendingEvent(std::vector<arcade::event_t> &) = 0;
                virtual const arcade::game_object_t getBackground() const = 0;
                virtual void reset() = 0;
                virtual arcade::game_status_t getGameStatus() const = 0;
                virtual const std::vector<arcade::text_object_t> getPendingTexts() const = 0;
            protected:
                virtual void initGame() = 0;
                virtual void destroyGame() = 0;
        };
    };
};

#endif /* !IGAME_HPP_ */
