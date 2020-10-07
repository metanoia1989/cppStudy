#include <iostream>
#include <random>

using namespace std;

int main(int argc, char const *argv[])
{
    random_device rnd;

    // 是否连接了随机硬件设备
    cout << "Entropy: " << rnd.entropy() << endl;
    cout << "Min value: " << rnd.min() << ", Max value"
        << rnd.max() << endl;
    cout << "Random number: " << rnd() << endl;

    return 0;
}
