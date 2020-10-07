#include <iostream>
#include <exception>

using namespace std;

struct MyException : public exception
{
    const char * what() const throw()
    {
        return "自定义C++异常";
    }
};

int main()
{
    try
    {
        throw MyException();
    }
    catch(const MyException& e)
    {
        std::cerr << "MyException 被捕获了 " << '\n';
        std::cerr << e.what() << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
