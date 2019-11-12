#include <queue>
#include <functional>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    priority_queue<int, vector<int>, greater<>> myQueue;

    myQueue.push(3);
    myQueue.push(4);
    myQueue.push(2);
    myQueue.push(1);

    while (!myQueue.empty()) {
        cout << myQueue.top() << " ";
        myQueue.pop();
    }

    return 0;
}
