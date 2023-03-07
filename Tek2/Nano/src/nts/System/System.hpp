/*
** EPITECH PROJECT, 2022
** Nano
** File description:
** System
*/

#ifndef SYSTEM_HPP_
#define SYSTEM_HPP_

#include "IComponent.hpp"
#include "UserCommunication/UserCommunication.hpp"
#include <memory>
#include <map>
#include <functional>

namespace nts {
    class System {
        public:
            System(nts::UserCommunication &userCommunication);
            ~System();
            std::unique_ptr<nts::IComponent> createComponent(const std::string &type);
            void loop(const char *path);
            std::size_t getReturnValue() const;
            nts::IComponent &getAChip(const std::string &key);
            const nts::IComponent &getAChip(const std::string &key) const;
            void addAChip(const std::string &key, std::unique_ptr<nts::IComponent> &&component);
            bool findAChip(const std::string &key);

        protected:
        private:
            std::unique_ptr<nts::IComponent> createInput() const;
            std::unique_ptr<nts::IComponent> createOutput() const;
            std::unique_ptr<nts::IComponent> createClock() const;
            std::unique_ptr<nts::IComponent> createFalse() const;
            std::unique_ptr<nts::IComponent> createTrue() const;
            std::unique_ptr<nts::IComponent> create4001() const;
            std::unique_ptr<nts::IComponent> create4011() const;
            std::unique_ptr<nts::IComponent> create4030() const;
            std::unique_ptr<nts::IComponent> create4071() const;
            std::unique_ptr<nts::IComponent> create4081() const;
            std::unique_ptr<nts::IComponent> create4069() const;

            std::map<const std::string, std::function<std::unique_ptr<nts::IComponent>()>> _createLambdas;
            
            nts::UserCommunication &_userCommunication;

            std::size_t _returnValue;
    };
};

#endif /* !SYSTEM_HPP_ */
