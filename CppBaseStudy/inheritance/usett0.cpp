// 使用基类示例
#include <iostream>
#include "tabtenn0.h"

int main(void)
{
    using std::cout;
    TableTennisPlayer player1("恰克", "卜丽萨", true);
    TableTennisPlayer player2("史密斯", "亚当", false);
    
    player1.Name();
    if (player1.HasTable()) {
        cout << ": has a table.\n";
    } else {
        cout << ": hasn't a table.\n";
    }

    player2.Name();
    if (player2.HasTable()) {
        cout << ": has a table.\n";
    } else {
        cout << ": hasn't a table.\n";
    }

    return 0;
}