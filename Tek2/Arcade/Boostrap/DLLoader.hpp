/*
** EPITECH PROJECT, 2022
** Boostrap
** File description:
** DLLoader
*/

#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_

#include "iostream"

template <typename T>
    class DLLoader {
        public:
            DLLoader(const std::string &path) {
                T *(*func_entry_point)();

                lib = dlopen(path.c_str(), RTLD_LAZY);
                if (!lib)
                    std::cout << "AAAAA" << std::endl;
                *(void**)(&func_entry_point) = dlsym(lib, "entryPoint");
                //if (!func_entry_point)
                    //dlclose(lib);
                    //THROW ERRORRRRRR
                _instance = func_entry_point();     
            };
            ~DLLoader() {
                dlclose(lib);
            };
            T *getInstance() const {
                return _instance;
            };
        private:
            void *lib;
            T *_instance;
};

#endif /* !DLLOADER_HPP_ */
