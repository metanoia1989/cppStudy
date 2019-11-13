#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

// 替换算法 replace() 将一个范围内匹配某个值的元素替换为新的值
// replace_if() 将一个范围内满足某个谓词的元素替换为新的值

// Function template to populate a container of ints.
// The container must support push_back().
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

int main(int argc, char const *argv[])
{
    vector<int> vec;
    populateContainer(vec);

    replace_if(begin(vec), end(vec), [](int i){ return i % 2 != 0; }, 0);

    for (const auto& i : vec) { cout << i << " "; }
    cout << endl;

    return 0;
}
