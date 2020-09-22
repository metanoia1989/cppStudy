#include <iostream>
#include <boost/random.hpp>
#include "lib/math/operations.hpp"

int main(int argc, char const *argv[])
{
    std::cout << "Hello CMake!" << std::endl;
    math::operations op;
    int sum = op.sum(3, 4);
    std::cout << "Sum of 3 + 4: " << sum << std::endl;

    // Boost Random Sample
    boost::mt19937 rng;
    double mean = 2.3;
    double sta = 0.34;
    auto normal_dist = boost::random::normal_distribution<double>
        (mean, sta);
    boost::variate_generator<boost::mt19937&, boost::normal_distribution<>>
        random_generator(rng, normal_dist);

    for (size_t i = 0; i < 15; i++)
    {
        auto rand_val = random_generator();
        std::cout << "Random Val " << i + 1 << " :" << rand_val << std::endl;
    }

    return 0;
}
