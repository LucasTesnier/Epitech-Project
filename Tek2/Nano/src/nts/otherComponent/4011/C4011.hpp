/*
** EPITECH PROJECT, 2022
** Project
** File description:
** C4011
*/

#pragma once

#include "AComponent.hpp"

namespace nts
{
    namespace otherComponent
    {
        class C4011 : public nts::AComponent
        {

        public:
            C4011();
            ~C4011();
            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);

        protected:
            bool calcNandGate(nts::pinInfo pin1, nts::pinInfo pin2);
        private:
        };
    }
}