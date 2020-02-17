#include <random>
#include <functional>
#include <map>
#include <fstream>
#include <ctime>

using namespace std;

int main(int argc, char const *argv[])
{
    const unsigned int kStart = 1;
    const unsigned int kEnd = 99;
    const unsigned int kIterations = 1'000'000;

    // 梅森旋转分布
    random_device seeder;
    const auto seed = seeder.entropy() ? seeder() : time(nullptr);
    mt19937 eng(static_cast<mt19937::result_type>(seed));
    uniform_int_distribution<int> dist(kStart, kEnd);
    auto gen = bind(dist, eng);
    map<int, int> m;
    for (unsigned int i = 0; i < kIterations; ++i) {
        int rnd = gen();
        ++(m[rnd]);
    }

    ofstream of("res.csv");
    for (unsigned int i = kStart; i < kEnd; ++i) {
        of << i << "," << m[i] << endl; 
    }

    return 0;
}
