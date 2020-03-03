#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

#ifdef WIN32
#include <windows.h>
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
#ifdef WIN32
    SetConsoleOutputCP(65001);
    CONSOLE_FONT_INFOEX info {0}; // 以下设置字体来支持中文显示
    info.cbSize = sizeof(info);
    info.dwFontSize.Y = 16; // leave X as zeor
    info.FontWeight = FW_NORMAL;
    wcscpy(info.FaceName, L"Consolas");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &info);
#endif // WIN32

    std::cout << "Start\n";
    std::string res;

    res = exec("ls");
    std::cout << "命令输出: " << res << std::endl;


    return 0;
}
