/*
** EPITECH PROJECT, 2022
** Project
** File description:
** IGraphic
*/

#ifndef IGRAPHIC_HPP_
#define IGRAPHIC_HPP_

#include <vector>
#include <string>
#include "game_object.hpp"

namespace arcade {
    namespace graphic {
        class IGraphic {
            public:
                virtual ~IGraphic() = default;
                virtual void clearScreen() = 0;     // maybe const function
                virtual void displayScreen() = 0;   // maybe const function
                virtual void drawPendingTexts(const std::vector<arcade::text_object_t> &) = 0;        // text_object_t structure need to be defined
                virtual void drawPendingGameObjects(const std::vector<arcade::game_object_t> &) = 0;
                virtual std::vector<arcade::event_t> getPendingEvent() = 0;
                virtual void displayBackground(const arcade::game_object_t &) = 0;       // need parameters ?
                virtual bool getStatus() const = 0;    // find a better name
            protected:
                virtual void initWindow(std::string const &name) = 0;           // default value set in abstract class ?
                virtual void closeWindow() = 0;
        };
    }
}


#endif /* !IGRAPHIC_HPP_ */
