/*
** EPITECH PROJECT, 2022
** Nano
** File description:
** True
*/

#ifndef True_HPP_
#define True_HPP_

#include "AComponent.hpp"

namespace nts {
    namespace basicComponent {
        class True : public nts::AComponent{
            public:
                True();
                ~True();
                void simulate(std::size_t tick);
                nts::Tristate compute(std::size_t pin);
        };
    };
}

#endif /* !True_HPP_ */
