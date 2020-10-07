#include <string>
#include <iostream>

using std::cout;
using std::endl;

class Loggable
{
public:
    virtual ~Loggable() = default;
    virtual std::string getLogMessage() const = 0;
};

class Foo : public Loggable
{
public:
    std::string getLogMessage() const override;
};

std::string Foo::getLogMessage() const
{
    return "Hello Logger.";
}

void logObject(const Loggable& loggableObject)
{
    cout << typeid(loggableObject).name() << ": ";
    cout << loggableObject.getLogMessage() << endl;
}