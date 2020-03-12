#include <ctime>
#include <cstdlib>
#include <iostream>

#define MAX_NUM 10

void randnum()
{
    int random;
    std::srand(std::time(nullptr));
    for (size_t i = 0; i < 10; i++) {
        random = std::rand() % MAX_NUM;
        std::cout << random << std::endl;
    }
    
}

int main(int argc, char const *argv[])
{
    std::cout << "the ten random number is " << std::endl; 
    randnum();
    return 0;
}
