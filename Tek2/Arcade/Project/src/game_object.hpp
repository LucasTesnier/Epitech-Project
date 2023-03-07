/*
** EPITECH PROJECT, 2022
** ARCADE
** File description:
** game_object
*/

#ifndef GAME_OBJECT_HPP_
    #define GAME_OBJECT_HPP_

#include <string>

namespace arcade {
    typedef enum orientation_e {
        EUP = 0,
        ERIGHT = 90,
        EDOWN = 180,
        ELEFT = 270,
    } orientation_t;

    typedef enum event_e {
        UP,
        RIGHT,
        DOWN,
        LEFT,
        PREV_GRAPHIC,
        NEXT_GRAPHIC,
        NEXT_GAME,
        PREV_GAME,
        ESCAPE,
        PAUSE,
        RESTART,
        MENU,
        ACTION
    } event_t;

    typedef enum game_status_e {
        WIN,
        LOSE,
        IN_PROGRESS,
        IN_PAUSE
    } game_status_t;

    /**
    *@brief 
    *
    */

    typedef struct vector2i_s {
        std::size_t x;
        std::size_t y;
    } vector2i_t;

    /**
    *@brief object game. Storing the sprite information
    *
    */

    typedef struct game_object_s {
        std::string path;
        std::string color;
        vector2i_t pos;
        orientation_t orientation;
        vector2i_t size;
    } game_object_t;

    /**
    *@brief object text. Storing the text information
    *
    */

    typedef struct text_object_s {
        std::string message;
        std::string fontPath;
        std::size_t size;
        vector2i_t pos;
        std::string textColor;
        std::string backgroundColor;
    } text_object_t;

    /**
    *@brief object score. Storing the score information
    *
    */
    typedef struct score_object_s {
        std::string pseudo;
        int score;
    } score_object_t;
}

#endif /* !GAME_OBJECT_HPP_ */
