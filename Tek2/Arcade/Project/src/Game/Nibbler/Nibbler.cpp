/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Nibbler
*/

#include "Nibbler.hpp"
#include "IGame.hpp"
#include <iostream>
#include <unistd.h>

/**
 * @brief linking the library with DLLoader
 *
 */
extern "C" arcade::game::IGame *entryPointGame(void)
{
    arcade::game::IGame *newGame = new arcade::game::Nibbler;

    return newGame;
}

/**
 * @brief Construct a new arcade::game::Nibbler::Nibbler object
 *
 */
arcade::game::Nibbler::Nibbler()
{
    initGame();
}

/**
 * @brief Destroy the arcade::game::Nibbler::Nibbler object
 *
 */
arcade::game::Nibbler::~Nibbler()
{
}

/**
 * @brief It returns a vector of game_object_t, which is a struct containing the color, path, position, size
 * and orientation of the object
 * 
 * @return A vector of game_object_t
 */
const std::vector<arcade::game_object_t> arcade::game::Nibbler::getPendingItems() const
{
    std::vector<arcade::game_object_t> v_temp;
    arcade::vector2i_t vecpos;
    arcade::vector2i_t vecsize;
    arcade::game_object_t temp;

    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            switch (_map_array[i][j])
                {
                case MAP_CHAR:
                    break;
                case SNAKE_CHAR:
                    temp.color = "4CFF33";
                    temp.path = "./assets/snakebody.bmp";
                    vecpos.x = j;
                    vecpos.y = i;
                    temp.pos = vecpos;
                    vecsize.x = 1;
                    vecsize.y = 1;
                    temp.size = vecsize;
                    temp.orientation = EUP;
                    v_temp.push_back(temp);
                    break;
                case SNAKE_APPLE_CHAR:
                    temp.color = "FF5733";
                    temp.path = "./assets/snake_apple.bmp";
                    vecpos.x = j;
                    vecpos.y = i;
                    temp.pos = vecpos;
                    vecsize.x = 1;
                    vecsize.y = 1;
                    temp.size = vecsize;
                    temp.orientation = EUP;
                    v_temp.push_back(temp);
                    break;
                case SNAKE_HEAD_LEFT:
                    temp.color = "4933FF";
                    temp.path = "./assets/snake_head_left.bmp";
                    vecpos.x = j;
                    vecpos.y = i;
                    temp.pos = vecpos;
                    vecsize.x = 1;
                    vecsize.y = 1;
                    temp.size = vecsize;
                    v_temp.push_back(temp);
                    break;
                case SNAKE_HEAD_UP:
                    temp.color = "4933FF";
                    temp.path = "./assets/snake_head.bmp";
                    vecpos.x = j;
                    vecpos.y = i;
                    temp.pos = vecpos;
                    vecsize.x = 1;
                    vecsize.y = 1;
                    temp.size = vecsize;
                    v_temp.push_back(temp);
                    break;
                case SNAKE_HEAD_RIGHT:
                    temp.color = "4933FF";
                    temp.path = "./assets/snake_head_right.bmp";
                    vecpos.x = j;
                    vecpos.y = i;
                    temp.pos = vecpos;
                    vecsize.x = 1;
                    vecsize.y = 1;
                    temp.size = vecsize;
                    v_temp.push_back(temp);
                    break;
                case SNAKE_HEAD_DOWN:
                    temp.color = "4933FF";
                    temp.path = "./assets/snake_head_down.bmp";
                    vecpos.x = j;
                    vecpos.y = i;
                    temp.pos = vecpos;
                    vecsize.x = 1;
                    vecsize.y = 1;
                    temp.size = vecsize;
                    v_temp.push_back(temp);
                    break;
                default:
                    break;
            }
        }
    }
    return v_temp;
}

/**
 * @brief It moves the snake, checks if it's eaten an apple, checks if it's lost, checks if it's won, and
 * updates the map
 */
void arcade::game::Nibbler::simulate()
{

    std::pair<int, int> movement_part;
    switch (_direction) {
        case LEFT:
            movement_part = std::make_pair(_snake_head.first, _snake_head.second - 1);
            break;
        case UP:
            movement_part = std::make_pair(_snake_head.first - 1, _snake_head.second);
            break;
        case RIGHT:
            movement_part = std::make_pair(_snake_head.first, _snake_head.second + 1);
            break;
        case DOWN:
            movement_part = std::make_pair(_snake_head.first + 1, _snake_head.second);
            break;
        default:
            break;
        }
    _snake_head = movement_part;
    _snake_parts.push_back(movement_part);
    _apple_eaten = _snake_head.first == _apple.first && _snake_head.second == _apple.second;
    if (_apple_eaten)
        _length_snake++;
    else {
        std::pair<int, int> tail = _snake_parts.front();
        _snake_world_array[tail.first][tail.second]--;
        _snake_parts.erase(_snake_parts.begin());
    }
    // _head_value = ++_snake_world_array[_snake_head.first][_snake_head.second];
    // if (_head_value > 1) {
    //     std::cout << "1er if\n";
    // }
    if ((_snake_head.first < 0 ||
        _snake_head.first >= MAP_WIDTH - 1 ||
        _snake_head.second < 0 ||
        _snake_head.second >= MAP_HEIGHT)) {
        _game_status = LOSE;
    }
    if (_map_array[_snake_head.first][_snake_head.second] == SNAKE_CHAR)
        _game_status = LOSE;
    if (_length_snake == MAP_WIDTH * MAP_HEIGHT - 1)
        _game_status = WIN;
    updateMap();
    usleep(DELAY);
}

/**
 * @brief It checks if the event is a direction change, and if it is, it checks if the direction is not the
 * opposite of the current direction, and if it isn't, it changes the direction
 * 
 * @param events A vector of events that happened since the last call to doPendingEvent.
 */
void arcade::game::Nibbler::doPendingEvent(std::vector<arcade::event_t> &events)
{
    for (auto &ev : events) {
        switch (ev) {
            case UP:
                if (_direction != DOWN)
                    _direction = UP;
                break;
            case DOWN:
                if (_direction != UP)
                    _direction = DOWN;
                break;
            case RIGHT:
                if (_direction != LEFT)
                    _direction = RIGHT;
                break;
            case LEFT:
                if (_direction != RIGHT)
                    _direction = LEFT;
                break;
            case RESTART:
                reset();
                break;
            default:
                break;
        }
    }
}

/**
 * @brief It returns a game_object_t struct with the path to the background image, the position of the image,
 * the color of the image, and the orientation of the image
 * 
 * @return The background of the game
 */
const arcade::game_object_t arcade::game::Nibbler::getBackground() const
{
    arcade::vector2i_t v {v.x = 0, v.y = 0};
    arcade::game_object_t bg;
    bg.path = "./assets/snake_backgrund.bmp";
    bg.pos = v;
    bg.color = "4C704B";
    bg.orientation = EUP;

    return bg;
}

/**
 * @brief It clears the map, clears the snake, and then initializes the game
 */
void arcade::game::Nibbler::reset()
{
    clearMap(_map_array);
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            _snake_world_array[i][j] = 0;
        }
    }
    _snake_parts.clear();
    initGame();
}

/**
 * @brief It returns the game status
 * 
 * @return The game status.
 */
arcade::game_status_t arcade::game::Nibbler::getGameStatus() const
{
    return _game_status;
}

/**
 * @brief It returns a vector of text_object_t, which contains the score of the player
 * 
 * @return A vector of text_object_t
 */
const std::vector<arcade::text_object_t> arcade::game::Nibbler::getPendingTexts() const
{
    std::vector<arcade::text_object_t> v_temp;
    arcade::text_object_t score;
    score.message = "SCORE: " + std::to_string(_length_snake - INITIAL_SNAKE_LENGTH + 1);
    score.fontPath = "./assets/font/arial.ttf";
    score.pos = arcade::vector2i_t {
        40,
        2
    };
    score.textColor = "f22b2b";
    score.backgroundColor = "000000";
    score.size = 50;
    v_temp.push_back(score);
    v_temp.push_back(arcade::text_object_t {
            std::to_string(_length_snake - INITIAL_SNAKE_LENGTH + 1),
            "Score",
            0,
            arcade::vector2i_t {
                0,
                0
            },
            "FF1493",
            "000000"
        });
    return v_temp;
}

/**
 * @brief It returns the direction of the snake
 * 
 * @return The direction of the snake.
 */
arcade::event_t arcade::game::Nibbler::getDirection() const
{
    return _direction;
}

/**
 * @brief It initializes the game
 */
void arcade::game::Nibbler::initGame()
{
    _direction = RIGHT;
    _game_status = IN_PROGRESS;
    _length_snake = INITIAL_SNAKE_LENGTH;
    for (int i = 0; i < INITIAL_SNAKE_LENGTH; i++) {
        std::pair<int, int> snake_part = std::make_pair(MAP_HEIGHT / 2, MAP_WIDTH / 2 - (INITIAL_SNAKE_LENGTH / 2) + i);
        _snake_parts.push_back(snake_part);
        _snake_world_array[snake_part.first][snake_part.second] = 1;
    }
    _snake_head = _snake_parts[_snake_parts.size() - 1];
    clearMap(_map_array);
    updateSnakeApple(true);
}

/**
 * @brief It destroys the game
 */
void arcade::game::Nibbler::destroyGame()
{
}

/**
 * @brief It sets the apple's position
 * 
 * @param apple The position of the apple
 */
void arcade::game::Nibbler::setApple(std::pair<int, int> apple)
{
    _apple = apple;
}

/**
 * @brief It clears the map by filling it with the character MAP_CHAR
 * 
 * @param map_array the map array to clear
 */
void arcade::game::Nibbler::clearMap(char map_array[MAP_HEIGHT][MAP_WIDTH])
{
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            map_array[i][j] = MAP_CHAR;
        }
    }
}

/**
 * @brief It updates the map array
 */
void arcade::game::Nibbler::updateMap()
{
    clearMap(_map_array);
    std::vector<std::pair<int, int>> snake_parts = _snake_parts;
    for (long unsigned int i = 0; i < snake_parts.size(); i++) {
        std::pair<int, int> tmp = snake_parts[i];
        _map_array[tmp.first][tmp.second] = SNAKE_CHAR;
    }
    updateSnakeHead(_map_array, this);
    updateSnakeApple(false);
    _map_array[_snake_apple.first][_snake_apple.second] = SNAKE_APPLE_CHAR;
    // std::cout << std::endl;
    // for (int i = 0; i < MAP_HEIGHT; i++)
    // {
    //     for (int j = 0; j < MAP_WIDTH; j++)
    //     {
    //         std::cout << _snake_world_array[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
}

/**
 * @brief It generates a random position for the apple, and if the position is not occupied by the snake, it
 * sets the apple to that position
 * 
 * @param force_update if true, the apple will be updated even if it hasn't been eaten.
 */
void arcade::game::Nibbler::updateSnakeApple(bool force_update)
{
    if (_apple_eaten || force_update) {
        while (true) {
            int rand_x = rand() % MAP_WIDTH;
            int rand_y = rand() % MAP_HEIGHT;
            if (_map_array[rand_x][rand_y] == MAP_CHAR) {
                _snake_apple = std::make_pair(rand_x, rand_y);
                setApple(_snake_apple);
                _apple_eaten = false;
                break;
            }
        }
    }
}

/**
 * @brief It updates the snake head's character in the map array
 * 
 * @param map_array The map array that will be displayed on the screen.
 * @param snake The snake object
 */
void arcade::game::Nibbler::updateSnakeHead(char map_array[MAP_HEIGHT][MAP_WIDTH], arcade::game::Nibbler *snake)
{
    char snake_head_ch = SNAKE_CHAR;

    switch (snake->getDirection()) {
        case arcade::event_t::LEFT:
            snake_head_ch = SNAKE_HEAD_LEFT;
            break;
        case arcade::event_t::UP:
            snake_head_ch = SNAKE_HEAD_UP;
            break;
        case arcade::event_t::RIGHT:
            snake_head_ch = SNAKE_HEAD_RIGHT;
            break;
        case arcade::event_t::DOWN:
            snake_head_ch = SNAKE_HEAD_DOWN;
            break;
        default:
            break;
    }
    std::pair<int, int> snake_head = snake->_snake_head;
    map_array[snake_head.first][snake_head.second] = snake_head_ch;
}