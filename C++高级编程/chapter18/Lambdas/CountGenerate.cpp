#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int value = 3;
    int cntLambdaCalled = 0;

    int cnt = count_if(cbegin(vec), cend(vec), 
        [value](int i){ return i > value; });
    cout << "Found " << cnt << " values > " << value << endl;

    cnt = count_if(cbegin(vec), cend(vec), 
        [value, &cntLambdaCalled](int i){ ++cntLambdaCalled; return i > value; });
    cout << "The lambda expression was called " << cntLambdaCalled << " times." << endl;
    cout << "Found " << cnt << " values > " << value << endl;

    value = 1;
    generate(begin(vec), end(vec), [&value]{ value *= 2; return value; });
    cout << "vec is : ";
    for (const auto& i : vec) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
