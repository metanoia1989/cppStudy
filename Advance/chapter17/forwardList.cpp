#include <iostream>
#include <forward_list>

using namespace std;

int main(int argc, char const *argv[])
{
    forward_list<int> list1 = { 5, 6 };
    forward_list<int> list2 = { 1, 2, 3, 4 };
    forward_list<int> list3 = { 7, 8, 9 };

    list1.splice_after(list1.before_begin(), list2);
    list1.push_front(0);

    auto iter = list1.before_begin();
    auto iterTemp = iter;
    while (++iterTemp != end(list1)) {
        ++iter;
    }
    list1.insert_after(iter, cbegin(list3), cend(list3));

    for (auto& i : list1) {
        cout << i << ' ';
    }

    return 0;
}
