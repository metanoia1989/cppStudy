#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

int main()
{
    string word;
    vector<string> text;
    while (cin >> word) {
        text.push_back(word);
    }

    vector<int> v2;
    for (int i = 0; i != 100; ++i) {
        v2.push_back(i);
    }
    

    // 以 10 分为一个分数段统计成绩的数量：0~9, 10~19, ..., 90~99, 100
    vector<unsigned> scores(11, 0); // 11个分数段，全部初始化为0
    unsigned grade;
    while (cin >> grade) { // 读取成绩
        if (grade <= 100) { // 只处理有效的成绩
            ++scores[grade/10]; // 将对应分数段的计数值加1
        }
    }
}