#include "Message.hpp"
#include <cstdlib>
#include <iostream>

int main(int argc, char const *argv[])
{
    Message say_hello("Hello, CMake World!");

    std::cout << say_hello << std::endl;

    Message say_goodbye("Goodbye, CMake World!");

    std::cout << say_goodbye << std::endl;

    return EXIT_SUCCESS;
}
