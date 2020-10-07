#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    // all_of() 所有元素都满足谓词
    vector<int> vec2 = { 1, 1, 1, 1 };
    if (all_of(cbegin(vec2), cend(vec2), [](int i){ return i == 1; })) {
        cout << "vec2 All elements are == 1" << endl;
    } else {
        cout << "vec2 Not all elements are == 1" << endl;
    }

    // any_of() 至少一个元素满足谓词
    vector<int> vec3 = { 0, 0, 1, 0 };
    if (any_of(cbegin(vec3), cend(vec3), [](int i){ return i == 1; })) {
		cout << "vec3 least one element == 1" << endl;
    } else {
        cout << "vec3 Not all elements are == 1" << endl;
    }

    // none_of() 没有元素满足谓词
    vector<int> vec4 = { 0, 0, 0, 0 };
    if (none_of(cbegin(vec4), cend(vec4), [](int i){ return i == 1; })) {
        cout << "vec4 All elements are != 1" << endl;
    } else {
        cout << "vec4 Some elements are == 1" << endl;
    }


    return 0;
}
