/*
** EPITECH PROJECT, 2022
** B-OOP-400-NAN-4-1-tekspice-lucas.tesnier
** File description:
** C4030
*/

#pragma once

#include "AComponent.hpp"

namespace nts
{
    namespace otherComponent
    {
        class C4030 : public nts::AComponent
        {

        public:
            C4030();
            ~C4030();
            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);

        protected:
            bool calcXorGate(nts::pinInfo pin1, nts::pinInfo pin2);
        private:
        };
    }
}
