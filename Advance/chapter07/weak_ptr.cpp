#include <memory>
#include <iostream>

using std::cout;
using std::endl;
using std::weak_ptr;
using std::make_shared;

class Simple;
void useResource(weak_ptr<Simple>& weakSimple);

int main()
{
    auto sharedSimple = make_shared<Simple>();
    weak_ptr<Simple> weakSimple(sharedSimple);

    // Try to use weak_ptr
    useResource(weakSimple);

    // Reset the shared_ptr
    sharedSimple.reset();
    useResource(weakSimple);

    return 0;
}

void useResource(weak_ptr<Simple>& weakSimple)
{
    auto resource = weakSimple.lock();
    if (resource) {
        cout << "Resource still alive." << endl;
    } else {
        cout << "Resource has been freed!" << endl;
    }
}
