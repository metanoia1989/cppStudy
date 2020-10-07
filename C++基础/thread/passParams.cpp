#include <iostream>
#include <string>
#include <thread>
#include <functional>

struct Foo
{
    int x;
    Foo(int _x) : x(_x) { }
};


void threadCallback(Foo& f, const std::string & str)
{
    std::cout<<"Passed Number = "<< f.x <<std::endl;
    std::cout<<"Passed String = "<<str<<std::endl;
}

int main()  
{
    Foo f(10);
    std::string str = "Sample String";
    std::thread threadObj(threadCallback, std::ref(f), std::cref(str));
    threadObj.join();
    return 0;
}