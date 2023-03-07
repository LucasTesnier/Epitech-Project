/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** DLLoader
*/

#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_

#include "Error/Error.hpp"
#include <dlfcn.h>
#include <iostream>

namespace arcade {
    template <typename T>
        class DLLoader {
            public:
                /**
                 * @brief Construct a new DLLoader object
                 * 
                 * @param path 
                 * @param type 
                 */

                DLLoader(const std::string &path, const std::string &type) {
                    T *(*func_entry_point)();

                    lib = dlopen(path.c_str(), RTLD_LAZY);
                    if (!lib)
                        throw arcade::ErrorLoader(dlerror(), "DLLoader : " + path);
                    *(void**)(&func_entry_point) = dlsym(lib, ("entryPoint" + type).c_str());
                    if (!func_entry_point) {
                        dlclose(lib);
                        throw arcade::ErrorLoader("Invalid entryPoint. No compatible library.", "DLLoader : " + path);
                    }
                    _instance = func_entry_point();
                    _thereIsALib = true; 
                };

                DLLoader(const std::string &path, const std::string &type, bool trying) {
                    T *(*func_entry_point)();

                    lib = dlopen(path.c_str(), RTLD_LAZY);
                    if (!lib) {
                        _thereIsALib = false;
                        throw arcade::ErrorLoader(dlerror(), "DLLoader : " + path);
                    }
                    *(void**)(&func_entry_point) = dlsym(lib, ("entryPoint" + type).c_str());
                    if (!func_entry_point) {
                        dlclose(lib);
                        throw arcade::ErrorLoader("Invalid entryPoint. No compatible library.", "DLLoader : " + path);
                    }
                    (void) trying;
                    _instance = nullptr;
                    _thereIsALib = false;
                };

                /**
                 * @brief Destroy the DLLoader object
                 * 
                 */

                ~DLLoader() {
                    if (_thereIsALib)
                        dlclose(lib);
                };

                /**
                 * @brief Get the Instance object
                 * 
                 * @return T* 
                 */

                T *getInstance() const {
                    return _instance;
                };
            private:
                void *lib;
                T *_instance;
                bool _thereIsALib;
    };
}

#endif /* !DLLOADER_HPP_ */
