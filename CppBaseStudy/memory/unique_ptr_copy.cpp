#include <iostream>
#include <memory>

int main(int argc, const char** argv) {
    std::unique_ptr<int> num(new int(4));
    std::unique_ptr<int> count(move(num));
    std::cout << "unique ptr value: " << *count << std::endl;

    return 0;
}