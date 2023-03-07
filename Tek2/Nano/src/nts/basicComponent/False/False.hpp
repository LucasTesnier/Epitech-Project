/*
** EPITECH PROJECT, 2022
** Nano
** File description:
** False
*/

#ifndef False_HPP_
#define False_HPP_

#include "AComponent.hpp"

namespace nts {
    namespace basicComponent {
        class False : public nts::AComponent{
            public:
                False();
                ~False();
                void simulate(std::size_t tick);
                nts::Tristate compute(std::size_t pin);
        };
    };
}

#endif /* !False_HPP_ */
