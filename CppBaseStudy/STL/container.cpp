#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <list>
#include <forward_list>
#include <array>

using namespace std;

int main()
{
    /*------------------------- vector 容器的一些操作 ------------------------*/
    vector<int> vect1; 
    vect1.push_back(1); // push_back 向容器的末尾添加元素
    vect1.push_back(2);
    vect1.push_back(3);
    vect1.pop_back(); // pop_back 去除末尾的元素

    vect1.insert(vect1.begin() + 1, 8); // 插入元素在指定位置，效率低
    vect1.at(0); // at 获取某个位置的元素
    vect1.capacity(); // capacity 不分配新的内容空间下，容器最多能保存多少个元素
    vect1.size(); // size 已保存元素的数据
    vect1.empty(); // empty 容器是否为空
    vect1.front(); // front 获取第一个元素
    vect1.back(); // back 获取最后一个元素
    vect1.erase(vect1.begin() + 1); // earse：删除指定位置的元素

    vector<int> vect2;
    vect2.assign(vect1.begin(), vect1.end()); // 赋值操作
    /*---------------------------------------------------------------------*/

    // 其他容器操作和vector差不多，下面列举一些其他容器特有的操作

    /*------------------------- string 容器的一些操作 ------------------------*/
    string str1 = "Hello Ace"; // string的几种构造方法
    string str2("Hello World");
    string str3(str1, 6); // 从 str1 下标6开始构造，str3 -> Ace

    string str4= str2.substr(0, 5); // 求子串 str4 -> Hello
    string str5 = str2.substr(6); // 求子串 str5 > World
    string str6 = str2.substr(6, 11); // 求子串 str5 > World
    // string str7 = str2.substr(12); // 抛异常 out_of_range

    string str8 = str2.replace(6, 5, "Game"); // 替换 str8 -> Hello Game  从位置6开始，删除5个字符，并替换成"Game"
    string str9 = str2.append(", Hello Beauty"); // 追加字符串 str9 -> Helo World, Hello Beauty

    auto pos1 = str1.find("Ace"); // 查找字符串 pos1 -> 6 返回第一次出现字符串的位置，如果没找着，则返回npos

    int res = str1.compare("Hello, Ace"); // 比较字符串 res -> -1 根据str1是等于、大于还是小于参数指定的字符串， 返回0、整数或者负数

    string str10 = "Pi = 3.1459";
    double pi = stod(str10.substr(str10.find_first_of("+-.0123456789"))); // 数值转换： pi -> 3.14159
    /*-----------------------------------------------------------------------*/

    /*------------------------- deque 容器的一些操作 ------------------------*/
    deque<int> d1;
    d1.push_back(1); // 尾后压入元素
    d1.push_back(2);
    d1.push_back(3);
    d1.push_back(4);
    d1.push_back(5);
    d1.push_back(6);
    d1.pop_back(); // 尾后弹出一个元素
    d1.pop_front(); // 队头弹出一个元素

    d1.front(); // 取队头元素
    d1.back(); // 取队尾元素
    /*-----------------------------------------------------------------------*/

    /*------------------------- list 容器的一些操作 ------------------------*/
    list<int> l; 
    l.push_back(1); // 尾后压入元素
    l.push_back(2);
    l.push_back(3);
    l.push_front(4); // 队头压入元素
    l.push_front(5);
    l.push_front(6);

    l.pop_back(); // 尾后弹出元素
    l.pop_front(); // 队头弹出元素

    l.insert(l.begin(), 88); // 某个位置插入元素 性能好
    l.remove(2); // 删除某个元素 （删除所给值相同的所有元素）
    l.reverse(); // 倒置所有元素
    l.erase(--l.end()); // 删除某个位置的元素 性能好
    /*-----------------------------------------------------------------------*/

    /*------------------------- forward_list 容器的一些操作 ------------------------*/
    forward_list<int> fl = {1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    fl.push_front(0); // 压入元素，该容器没有 push_back 方法
    auto prev = fl.before_begin(); // 单向列表的首前元素
    auto curr = fl.begin(); // 单向列表的第一个元素

    // 循环遍历
    while (curr != fl.end()) { // 仍有元素要处理
        if (*curr % 2) { // 若元素为奇数，则删除
            curr = fl.erase_after(prev); // 删除它并移动curr
        } else {
            prev = curr; // 移动迭代器 curr，指向下一个元素怒
            ++curr;
        }
    }
    // 操作后： fl = {0, 2, 4, 6, 8}
    /*-----------------------------------------------------------------------*/

    /*------------------------- array 容器的一些操作 ------------------------*/
    array<int, 5> a1 = { 1, 2, 3, 4, 5 };
    array<array<int, 2>, 3> a2 = { 1, 2, 3, 4, 5, 6}; // 二维数组
    array<int, 5> a3 = { 6, 7, 8, 9, 10 }; 
    array<int, 5> a4; // 数组未初始化

    // array.resize(); // arrray 没有改变容器大小的操作，效率比 vector 高
    a1.swap(a3); // 交换两个数组的元素
    a4 = a1; // 数组直接赋值

    // 遍历数据元素
    for (int i = 0; i < a1.size(); ++i) {
        cout << a1[i] << endl;
    }
    /*-----------------------------------------------------------------------*/

}