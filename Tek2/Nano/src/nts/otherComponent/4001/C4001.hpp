/*
** EPITECH PROJECT, 2022
** Project
** File description:
** C4001
*/

#pragma once

#include "AComponent.hpp"

namespace nts
{
    namespace otherComponent
    {
        class C4001 : public nts::AComponent
        {

        public:
            C4001();
            ~C4001();
            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);

        protected:
            bool calcNorGate(nts::pinInfo pin1, nts::pinInfo pin2);
        private:
        };
    }
}