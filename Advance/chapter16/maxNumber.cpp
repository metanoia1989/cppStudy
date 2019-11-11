#include <limits>
#include <iostream>

using std::numeric_limits;

int main()
{
    std::cout << "int: " << std::endl;
    std::cout << "Max int value: " << numeric_limits<int>::max() << std::endl;
    std::cout << "Min int value: " << numeric_limits<int>::min() << std::endl;
    std::cout << "Lowest int value: " << numeric_limits<int>::lowest() << std::endl;

    std::cout << std::endl << "double: " << std::endl;
    std::cout << "Max double value: " << numeric_limits<double>::max() << std::endl;
    std::cout << "Min double value: " << numeric_limits<double>::min() << std::endl;
    std::cout << "Lowest double value: " << numeric_limits<double>::lowest() << std::endl;
}