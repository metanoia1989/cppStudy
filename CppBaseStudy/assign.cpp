#include <iostream>
// ����������ô�� ������ͦƯ����
int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    float tree = 3;
    int guess (3.9832);
    int debt = 7.2E2;
    cout << "tree = " << tree << endl;
    cout << "guess = " << guess << endl;
    cout << "debt = " << debt << endl;
    return 0;
}