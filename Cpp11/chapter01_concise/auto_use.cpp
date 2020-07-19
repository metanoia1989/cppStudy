#include <map>
#include <iostream>

// auto 使用场景，简化返回值类型的声明

class Foo
{
public:
    static int get(void)
    {
        return 0;
    }
};

class Bar
{
public:
    static const char* get(void)
    {
        return "0";
    }
};

template <typename A>
void func(void)
{
    auto val = A::get();
    std::cout << val << std::endl;
}

int main(int argc, char const *argv[])
{
    std::map<double, double> resultMap;
    for (auto it = resultMap.begin(); it != resultMap.end(); ++it)
    {
        // TODO: do somethind
    }

    // std::unordered_multimap<int, int> resultMultiMap;
    // auto range = resultMultiMap.equal_range(key);

    func<Foo>();
    func<Bar>();

    return 0;
}

