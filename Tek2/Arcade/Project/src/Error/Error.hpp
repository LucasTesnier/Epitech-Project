/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <exception>
#include <string>

namespace arcade {
    class Error : public std::exception {
        public:
            Error(std::string const &message, std::string const &component = "Unknow");
            const char *what() const noexcept override;
            const std::string &getComponent() const noexcept;

        protected:
        private:
            std::string const _component;
            std::string const _message;
    };

    class ErrorGraphic : public Error {
        public:
            ErrorGraphic(std::string const &message, std::string const &component = "Unknow");
    };

    class ErrorGame : public Error {
        public:
            ErrorGame(std::string const &message, std::string const &component = "Unknow");
    };

    class ErrorCore : public Error {
        public:
            ErrorCore(std::string const &message, std::string const &component = "Unknow");
    };

    class ErrorLoader : public Error {
        public:
            ErrorLoader(std::string const &message, std::string const &component = "Unknow");
    };

    class ErrorUsage : public Error {
        public:
            ErrorUsage(std::string const &message, std::string const &component = "Unknow");
    };
};

#endif /* !ERROR_HPP_ */
