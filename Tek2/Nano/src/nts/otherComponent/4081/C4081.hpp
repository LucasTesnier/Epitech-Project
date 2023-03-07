/*
** EPITECH PROJECT, 2022
** Project
** File description:
** C4081
*/

#pragma once

#include "AComponent.hpp"

namespace nts
{
    namespace otherComponent
    {
        class C4081 : public nts::AComponent
        {

        public:
            C4081();
            ~C4081();
            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);

        protected:
            bool calcAndGate(nts::pinInfo pin1, nts::pinInfo pin2);
        private:
        };
    }
}