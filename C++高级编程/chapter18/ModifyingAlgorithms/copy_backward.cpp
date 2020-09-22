#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

// 复制算法 copy_backward() 将源范围的元素反向复制到目标范围。从目标范围的最后位置开始修改

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
    vector<int> vec1, vec2;

    populateContainer(vec1);

    vec2.resize(size(vec1));

    copy_backward(cbegin(vec1), cend(vec1), end(vec2));

    cout << "vec1: ";
    for (const auto& i : vec1) { cout << i << " "; }
    cout << endl;

    cout << "vec2: ";
    for (const auto& i : vec2) { cout << i << " "; }

    return 0;
}
