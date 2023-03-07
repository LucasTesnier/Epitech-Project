/*
** EPITECH PROJECT, 2022
** Project
** File description:
** C4069
*/

#pragma once

#include "AComponent.hpp"

namespace nts
{
    namespace otherComponent
    {
        class C4069 : public nts::AComponent
        {

        public:
            C4069();
            ~C4069();
            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);

        protected:
            bool calcNotGate(nts::pinInfo pin1);
        private:
        };
    }
}