#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utf8cpp/utf8.h>

int main(int argc, char const *argv[])
{
    if (argc != 2) {
        std::cout << "\nUsage: docsample filename\n";
        return 0;
    }

    const char* test_file_path = argv[1];
    // 打开测试文件，必须是UTF-8编码
    std::ifstream fs8(test_file_path);
    if (!fs8.is_open()) {
        std::cout << "Counld not open " << test_file_path << std::endl;
        return 0;
    }

    unsigned line_count = 1;
    std::string line;
    // 读取文件所有的行
    while (std::getline(fs8, line)) {
        std::string::iterator end_it = utf8::find_invalid(line.begin(), line.end());
        if (end_it != line.end()) {
            std::cout << "Invalid UTF-8 encoding detected at line " << line_count << "\n";
            std::cout << "This is part is fine: " << std::string(line.begin(), end_it) << "\n";
        }
        // 获取有效部分的行宽度
        ptrdiff_t length = utf8::distance(line.begin(), end_it);
        std::cout << "Lenght of line " << line_count << " is " << length << "\n";

        std::vector<unsigned short> utf16line;
        utf8::utf8to16(line.begin(), end_it, std::back_inserter(utf16line));

        std::string utf8line;
        utf8::utf16to8(utf16line.begin(), utf16line.end(), std::back_inserter(utf8line));
        if (utf8line != std::string(line.begin(), end_it)) {
            std::cout << "Error in UTF-16 conversion at line: " << line_count << "\n";
        }

        line_count++;
    }

    return 0;
}
