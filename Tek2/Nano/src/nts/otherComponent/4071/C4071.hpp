/*
** EPITECH PROJECT, 2022
** Project
** File description:
** C4071
*/

#pragma once

#include "AComponent.hpp"

namespace nts
{
    namespace otherComponent
    {
        class C4071 : public nts::AComponent
        {

        public:
            C4071();
            ~C4071();
            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);

        protected:
            bool calcOrGate(nts::pinInfo pin1, nts::pinInfo pin2);
        private:
        };
    }
}