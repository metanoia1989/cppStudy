#include <vector>
#include <limits>
#include <iostream>


int main(int argc, const char** argv) {
    std::vector<double> doubleVector(10);    // 创建10个double
    double max = -std::numeric_limits<double>::infinity();

    for (size_t i = 0; i < doubleVector.size(); i++) {
        std::cout << "Enter score " << i + 1 << ": ";
        std::cin >> doubleVector[i];
        if (doubleVector[i] > max) {
            max = doubleVector[i];
        }
    }

    max /= 100.0;
    for (auto& element : doubleVector) {
        element /= max;
        std::cout << element << " ";
    }

    return 0;
}