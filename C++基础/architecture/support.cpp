// 使用外部变量
#include <iostream>

extern double warming;
void update(double dt);
void local();

using std::cout;

/**
 * 修改全局变量
 */
void update(double dt)
{
    extern double warming;
    warming += dt;
    cout << "Updating global warming to " << warming;
    cout << " degress.\n";
}

/** 
 * 使用本地变量
 */
void local()
{
    double warming = 0.8;
    cout << "Local warming = " << warming << " degress.\n";
    cout << "But global warming = " << ::warming;
    cout << " degress.\n";
}