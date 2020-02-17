#include <iostream>
#include <string>
#include <cstring>

int main()
{
    using namespace std;
    char charr1[20];
    char charr2[30] = "java sugar";
    string str1;
    string str2 = "cpp is beauty";

    // 赋值
    str1 = str2;
    strcpy(charr1, charr2);

    // 追加
    str1 += "black";
    strcat(charr1, " ugly");

    // 宽度
    int len1 = str1.size();
    int len2 = strlen(charr1);

    cout << "The string " << str1 << " contains " << len1 << " characters.\n";
    cout << "The string " << str2 << " contains " << len2 << " characters.\n";

    return 0;
}