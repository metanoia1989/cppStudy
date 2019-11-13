#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

// 复制算法 copy_if() 将满足给定谓词的所有元素复制到目标范围
// copy_if 返回目标范围内最后一个复制的元素后面那个位置的迭代器，以便确定从目标容器中删除的元素个数

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
    auto endIterator = copy_if(cbegin(vec1), cend(vec1), begin(vec2), 
        [](int i){ return i % 2 == 0; });
    vec2.erase(endIterator, end(vec2));
    for (const auto& i : vec2) { cout << i << " "; }
    cout << endl;

    return 0;
}

