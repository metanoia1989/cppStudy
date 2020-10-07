#include <fmt/format.h>
#include <string>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::string s = fmt::format("I'd rather be {1} than {0}.", "right", "happy");
    std::cout << s << std::endl;
    return 0;
}
