/*
** EPITECH PROJECT, 2022
** Nano
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

#include "IComponent.hpp"
#include "Error/Error.hpp"
#include <iostream>

namespace nts {
    class AComponent : public nts::IComponent {
        public:
            std::string convertStatus(const nts::Tristate status) const;
            nts::Tristate getStatePin(const nts::pinInfo &pin) const;
            void dump() const;
            void changePinState(std::size_t pin, nts::Tristate status);
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
            const std::string &getName() const;
            nts::Tristate getAStatePin(const std::size_t pin) const;
            void getComingInput(const std::string &comingInput);


        protected:
        private:
    };
}

#endif /* !ACOMPONENT_HPP_ */
