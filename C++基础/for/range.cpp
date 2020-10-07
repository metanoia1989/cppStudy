// 基于范围的 for 循环

#include <iostream>

int main()
{
    using namespace std;
    double prices[5] = { 4.99, 10.00, 6.87, 7.99, 8.48 };
    for (double &x: prices) {
        x = x * 2;
        cout << x << endl;
    }
}