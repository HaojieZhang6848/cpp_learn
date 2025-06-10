#include <iostream>
#include <cstdlib>

extern char **environ;

int main(int argc, char **argv) {
    std::cout << "Hello, CMake!" << std::endl;
    std::cout << "Environment variables:" << std::endl;
    for (char **env = environ; *env != nullptr; ++env) {
        std::cout << *env << std::endl;
    }

    std::cout << "Program arguments:" << std::endl;
    for (int i = 0; i < argc; ++i) {
        std::cout << argv[i] << std::endl;
    }
    return EXIT_SUCCESS;
}

