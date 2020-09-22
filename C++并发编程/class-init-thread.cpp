#include <thread>
#include <iostream>

class background_task
{
public:
    void operator()() 
    {
        do_something();
        do_something_else();
    }
private:
    void do_something() {
        std::cout << "do something";
    };
    void do_something_else() {
        std::cout << "do something else";
    };
};

int main(int argc, char const *argv[])
{
    background_task f;
    std::thread my_thread(f);
    my_thread.join();
    return 0;
}
