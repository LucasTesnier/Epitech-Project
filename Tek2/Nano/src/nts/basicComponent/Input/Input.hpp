/*
** EPITECH PROJECT, 2022
** Nano
** File description:
** Input
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include "AComponent.hpp"

namespace nts {
    namespace basicComponent {
        class Input : public nts::AComponent{
            public:
                Input();
                ~Input();
                void simulate(std::size_t tick);
                nts::Tristate compute(std::size_t pin);
                void getComingInput(const std::string &comingInput) override;

            protected:
            private:
                nts::Tristate _comingInput;
                bool _isComingInput;
        };
    };
}

#endif /* !INPUT_HPP_ */
