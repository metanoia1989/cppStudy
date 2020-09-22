#include <cstdlib>
#include <iostream>
#include <string>

std::string say_hello()
{
#ifdef IS_WINDOWS
    return std::string("Hello from Windows!");
#elif IS_LINUX
    return std::string("Hello from Linux!");
#elif IS_MACOS
    return std::string("Hello from macOS!");
#else
    return std::string("Hello from an unknow system!");
#endif 
}

int main(int argc, char const *argv[])
{
    std::cout << say_hello() << std::endl;

    return EXIT_SUCCESS;
}
