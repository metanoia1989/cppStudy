#include <iostream>
#include <string>
#include <memory>

// Objects allocated on the stack are automatically destroyed when they go out of scope

class A
{
public:
    A(std::string name) : m_name(name) 
    {
        std::cout << "对象" << m_name << "创建了" << std::endl;
    }

    ~A() 
    {
        std::cout << "对象" << m_name << "销毁了" << std::endl;
    } 

private:
    std::string m_name;
};



int main(int argc, char const *argv[])
{
    {
        std::cout << "进入局部作用域" << std::endl;
        std::unique_ptr<A> obj01(new A("Smith"));
        std::unique_ptr<A> obj02(new A("Jone"));
    }
    std::cout << "离开局部作用域" << std::endl;
    return 0;
}

// **********************
// 输出结果：
//  进入局部作用域
// 对象Smith创建了
// 对象Jone创建了
// 对象Jone销毁了
// 对象Smith销毁了
// 离开局部作用域
// **********************