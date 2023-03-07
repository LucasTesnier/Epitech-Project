/*
** EPITECH PROJECT, 2022
** Nano
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <string>
#include <vector>

namespace nts {
    class IComponent;
    struct pinInfo;
};

namespace nts {
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };
    
    class IComponent {
        public:
            virtual ~IComponent() = default;

            virtual void simulate(std::size_t tick) = 0;
            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void changePinState(std::size_t pin, nts::Tristate status) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
            virtual void dump() const = 0;
            virtual std::string convertStatus(const nts::Tristate status) const = 0;
            virtual nts::Tristate getStatePin(const nts::pinInfo &pin) const = 0;
            virtual const std::string &getName() const = 0;
            virtual nts::Tristate getAStatePin(const std::size_t pin) const = 0;
            virtual void getComingInput(const std::string &comingInput) = 0;


        protected:
            std::vector<nts::pinInfo> pin_list;
            std::string name;
    };

    struct pinInfo{
        nts::Tristate pinState;
        nts::IComponent *linkComponent;
        std::size_t linkPin;
        bool linkInProgress;
    };
};


#endif /* !ICOMPONENT_HPP_ */
