#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

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

    // 排序容器
    sort(begin(vec), end(vec));

    while (true) {
        int num;
        cout << "Enter a number to insert (0 to quit): ";
        cin >> num;
        if (num == 0) {
            break;
        }

        if (binary_search(cbegin(vec), cend(vec), num)) {
            cout << "That number is in the vector." << endl;
        }  else {
            cout << "That number is not in the vector." << endl;
        }
    }

    return 0;
}
