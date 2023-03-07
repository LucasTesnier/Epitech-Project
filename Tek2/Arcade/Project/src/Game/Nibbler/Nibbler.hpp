/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include "AGame.hpp"
#include <vector>

#define MAP_WIDTH 50
#define MAP_HEIGHT 50
#define MAP_CHAR '.'
#define SNAKE_CHAR 'O'
#define SNAKE_HEAD_LEFT '>'
#define SNAKE_HEAD_UP 'v'
#define SNAKE_HEAD_RIGHT '<'
#define SNAKE_HEAD_DOWN '^'
#define SNAKE_APPLE_CHAR '*'

#define INITIAL_SNAKE_LENGTH 4
#define DELAY 100000

namespace arcade {
    namespace game {
        class Nibbler : public AGame {
            public:
                Nibbler();
                ~Nibbler();
                const std::vector<arcade::game_object_t> getPendingItems() const;
                void simulate();
                void doPendingEvent(std::vector<arcade::event_t> &);
                const arcade::game_object_t getBackground() const;
                void reset();
                arcade::game_status_t getGameStatus() const;
                const std::vector<arcade::text_object_t> getPendingTexts() const;
                arcade::event_t getDirection() const;
                void setApple(std::pair<int, int>);
                void updateMap();
                void updateSnakeApple(bool force_update);
                std::pair<int, int> _snake_apple;
                void updateSnakeHead(char map_array[MAP_HEIGHT][MAP_WIDTH], arcade::game::Nibbler *snake);
                void clearMap(char map_array[MAP_HEIGHT][MAP_WIDTH]);
            protected:
                void initGame();
                void destroyGame();
            private:
                bool _apple_eaten;
                std::pair<int, int> _snake_head;
                std::vector<std::pair<int, int>> _snake_parts;
                arcade::event_t _direction;
                std::pair<int, int> _apple;
                arcade::game_status_t _game_status;
                int _length_snake;
                int _snake_world_array[MAP_HEIGHT][MAP_WIDTH];
                char _map_array[MAP_HEIGHT][MAP_WIDTH];
                int _head_value;
        };
    };
};

#endif /* !NIBBLER_HPP_ */
