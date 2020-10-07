#include <cstddef>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

// 复制算法 copy_n 从源范围复制n个元素到目标范围
// copy_n 不会进行任何边界检查，一定要确保起始迭代器
// 递增复制n个要复制的元素之后，不会超过集合的 end()

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
    size_t cnt = 0;
    cout << "Enter number of elements you want to copy: ";
    cin >> cnt;
    cnt = min(cnt, size(vec1));
    vec2.resize(cnt);
    copy_n(cbegin(vec1), cnt, begin(vec2));
    for (const auto& i : vec2) { cout << i << " "; }
    cout << endl;

    return 0;
}
