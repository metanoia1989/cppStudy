// 共用体
#include <iostream>

struct widget
{
    char brand[20];
    int type;
    union id 
    {
        long id_num;
        char id_char[20];
    } id_val;
};

int main()
{
    using namespace std;
    
    widget prize = {
        "studyCpp",
        2
    };
    
    if (prize.type == 1) {
        prize.id_val.id_num = 444;
        cout << prize.id_val.id_num;
    } else {
        prize.id_val.id_char = 4;
        cout << prize.id_val.id_char;
    }

    return 0;
}