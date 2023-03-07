/*
** EPITECH PROJECT, 2022
** Nano
** File description:
** Output
*/

#ifndef Output_HPP_
#define Output_HPP_

#include "AComponent.hpp"

namespace nts {
    namespace basicComponent {
        class Output : public nts::AComponent{
            public:
                Output();
                ~Output();
                void simulate(std::size_t tick);
                nts::Tristate compute(std::size_t pin);
        };
    };
}

#endif /* !Output_HPP_ */
