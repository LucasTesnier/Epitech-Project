/*
** EPITECH PROJECT, 2022
** Nano
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <exception>
#include <string>

namespace nts {
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

    class ErrorComponent : public nts::Error {
        public:
            ErrorComponent(std::string const &error, std::string const &component = "ComponentError");
    };

    class ErrorRequest : public nts::Error {
        public:
            ErrorRequest(std::string const &error, std::string const &component = "RequestError");
    };

    class ErrorRequestEOF : public nts::Error {
        public:
            ErrorRequestEOF(std::string const &error, std::string const &component = "RequestErrorEOF");
    };

    class ErrorParser : public nts::Error {
        public:
            ErrorParser(std::string const &error, std::string const &component = "ParserError");
    };
};

#endif /* !ERROR_HPP_ */
