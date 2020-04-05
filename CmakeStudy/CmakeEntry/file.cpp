#include <boost/filesystem.hpp>
#include <iostream>

int main(int argc, char const *argv[])
{
    boost::filesystem::path p("c:/Windows/System");
    std::cout << p.string() << std::endl;
    // std::cout << p.file_string() << std::endl;
    // std::cout << p.directory_string() << std::endl;
    return 0;
}
