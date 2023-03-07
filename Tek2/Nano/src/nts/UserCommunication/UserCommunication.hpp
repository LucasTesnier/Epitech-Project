/*
** EPITECH PROJECT, 2022
** Nano
** File description:
** UserCommunication
*/

#ifndef USERCOMMUNICATION_HPP_
#define USERCOMMUNICATION_HPP_

#include <map>
#include <memory>
#include <functional>
#include "IComponent.hpp"

namespace nts {
    class UserCommunication {
        public:
            enum CommunicationState{
                PROMPT,
                LOOP,
                EXIT
            };

            UserCommunication();
            ~UserCommunication();
            const std::string getTerminalAction() const;
            void doUserRequest(const std::string &);
            nts::UserCommunication::CommunicationState getState() const;
            nts::IComponent &getAChip(const std::string &key);
            const nts::IComponent &getAChip(const std::string &key) const;
            void addAChip(const std::string &key, std::unique_ptr<nts::IComponent> &&component);
            bool findAChip(const std::string &key);

        protected:
        private:

            void requestExit();
            void requestDisplay();
            void requestValue(const std::string &);
            void requestSimulate();
            void requestLoop();
            void requestDump();

            std::map<const std::string, std::function<void()>> _userRequest;

            nts::UserCommunication::CommunicationState _state;

            std::map<const std::string, std::unique_ptr<nts::IComponent>> _chipset;

            std::size_t _tick;
    };
};

#endif /* !USERCOMMUNICATION_HPP_ */
