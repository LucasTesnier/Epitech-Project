/*
** EPITECH PROJECT, 2022
** Nano
** File description:
** Clock
*/

#ifndef Clock_HPP_
#define Clock_HPP_

#include "AComponent.hpp"

namespace nts {
    namespace basicComponent {
        class Clock : public nts::AComponent{
            public:
                Clock();
                ~Clock();
                void simulate(std::size_t tick);
                nts::Tristate compute(std::size_t pin);
                void getComingInput(const std::string &comingInput) override;
            
            private:
                nts::Tristate _comingInput;
                bool _isComingInput;
        };
    };
}

#endif /* !Clock_HPP_ */
