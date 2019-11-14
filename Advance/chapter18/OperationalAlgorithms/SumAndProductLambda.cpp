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

int main(int argc, char const *argv[])
{
    vector<int> myVector;
    populateContainer(myVector);

    int sum = 0;
    int product = 1;
    for_each(cbegin(myVector), cend(myVector),
        [&sum, &product](int i){
            sum += i;
            product *= i;
    });
    cout << "The sum is " << sum << endl;
    cout << "The product is " << product << endl;

    return 0;
}

