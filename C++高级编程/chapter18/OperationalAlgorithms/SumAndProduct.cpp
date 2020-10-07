#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

template<typename Container>
void populateContainer(Container& cont)
{
	int num;

	while (true) {
		cout << "Enter a number (0 to quit): ";
		cin >> num;
		if (num == 0) {
			break;
		}
		cont.push_back(num);
	}
}

// 仿函数 
class SumAndProduct
{
public:
    void operator()(int value);
    int getSum() const { return mSum; }
    int getProduct() const { return mProduct; }

private:
    int mSum = 0;
    int mProduct = 1;
};

void SumAndProduct::operator()(int value)
{
    mSum += value;
    mProduct *= value;
}

int main(int argc, char const *argv[])
{
    vector<int> myVector;
    populateContainer(myVector);

    SumAndProduct func;
    // 调用仿函数，返回状态修改后的仿函数
    func = for_each(cbegin(myVector), cend(myVector), func);
    cout << "The sum is " << func.getSum() << endl;
    cout << "The product is " << func.getProduct() << endl;

    return 0;
}


