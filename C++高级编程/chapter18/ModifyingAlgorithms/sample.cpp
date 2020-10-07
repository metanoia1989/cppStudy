#include <cstddef>
#include <algorithm>
#include <vector>
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

// 抽样算法 sample() 从给定的源范围返回n个随机选择的元素，并存储在目标范围。
// 需要5个参数：
// 要从抽样的范围的首尾迭代器
// 目标范围的首迭代器，将随机选择的元素存储在目标范围
// 要选择的元素数量
// 随机数生成引擎

int main(int argc, char const *argv[])
{
    vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    const size_t numberOfSamples = 5;
    vector<int> samples(numberOfSamples);

    random_device seeder;
    const auto seed = seeder.entropy() ? seeder() : time(nullptr);
    default_random_engine engine(static_cast<default_random_engine::result_type>(seed));

    for (size_t i = 0; i < 6; i++) {
        sample(cbegin(vec), cend(vec), begin(samples), numberOfSamples, engine);

        for (const auto& sample : samples) { cout << sample << " "; }
        cout << endl;
    }

    return 0;
}

