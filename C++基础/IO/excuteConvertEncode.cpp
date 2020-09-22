#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include "gbk2utf8.hpp"

#ifdef WIN32
#define popen _popen
#define pclose _pclose
#endif // _WIN32

std::string exec(const char* command)
{
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(command, "r"), pclose);

    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }

    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

int main(int argc, char const *argv[])
{

    std::cout << "Start\n";
    std::string res;

    res = exec("dir");
    std::cout << "命令输出: " << GbkToUtf8(res.data()) << std::endl;

    return 0;
}
