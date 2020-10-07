#include <iostream>

using namespace std;

/* 接收端类 */
class Dst
{
private: 
    double m_dblValue;
    int m_nCount;
public:
    // get 函数
    double value()
    {
        return m_dblValue;
    }

    int count()
    {
        return m_nCount;
    }

    // set 函数
    void setValue(double v)
    {
        m_dblValue = v;
    }

    void seCount(int n)
    {
        if (n < 1) {
            m_nCount = 1;
        } else {
            m_nCount = n;
        }
    }


    // 处理数据函数
    double DoSomething()
    {
        double dblResult = m_dblValue / m_nCount;
        return dblResult;
    }
};

/* 源端类 */
class Src
{
public:
    void SendDataTo(Dst &theDst)
    {
        // 通过 set 函数传递数据
        theDst.setValue(2.0);
        theDst.seCount(3);
    }
};


int main()
{
    // 定义两个对象
    Dst theDst;
    Src theSrc;
    // 传递数据
    theSrc.SendDataTo(theDst);
    // 接收端处理
    cout << theDst.DoSomething();
    return 0;
}
