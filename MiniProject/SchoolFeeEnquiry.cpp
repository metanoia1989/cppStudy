#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <iomanip>
#include <dos.h>
#include <conio.h>
#include <windows.h>

using namespace std;

int i, j, li, lp, rec, valid;

COORD coord = {0, 0};

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void help();

//*************************************************
// 全局变量定义
//*************************************************
char ch, choice;

//*************************************************
// 绘制行、盒子的类
//*************************************************
class DRAW 
{
public:
    void LINE_HOR(int, int, int, char);
    void LINE_VER(int, int, int, char);
    void BOX(int, int, int, int, char);
};

void DRAW::LINE_HOR(int column1, int column2, int row, char c)
{
    for (column1; column2 <= column2; column1++) {
        gotoxy(column1, row);
        cout << c;
    }
}

void DRAW::LINE_VER(int row1, int row2, int column, char c)
{
    for (row1; row1 <= row2; row1++) {
        gotoxy(column, row1);
        cout << c;
    }
}

void DRAW::BOX(int column1, int row1, int column2, int row2, char c)
{
    char ch = 218;
    char c1, c2, c3, c4;
    char l1 = 196, l2 = 179;
    if (c == ch) {
        c1 = 218;
        c2 = 191;
        c3 = 192;
        c4 = 217;
        l1 = 196;
        l2 = 179;
    } else {
        c1 = c2 = c3 = c4 = c;
        l1 = l2 = c;
    }
    gotoxy(column1, row1);
    cout << c1;
    gotoxy(column2, row1);
    cout << c2;
    gotoxy(column1, row2);
    cout << c3;
    gotoxy(column2, row2);
    cout << c4;
    column1++;
    column2--;

    LINE_HOR(column1, column2, row1, l1);
    LINE_HOR(column1, column2, row2, l1);
    column1--;
    column2++;
    row1++;
    row2--;
    LINE_VER(row1, row2, column1, 12);
    LINE_VER(row1, row2, column2, 12);
}

//*************************************************
// 学费类
//*************************************************
class FEE
{
public:
    void ADDITION(void);
    void MODIFICATION(void);
    void FEE_SLIP(void);
    void LIST(void);
    void HELP(void);

private:
    int Class;
    float tuition, ac, science, computer, activity;
    void DISPLAY(int);
    void MODIFY_RECORD(int, float, float, float, float, float);
} fee;

// 添加费用到费用列表
void FEE::ADDITION(void)
{
    fstream file;
    file.open("FEE.DAT", ios::in);
    if (!file.fail()) return;
    file.close();
    file.open("FEE.DAT", ios::app);
    for (int i=1; i<=12; i++) {
        Class = i;
        tuition = 0.0;
        ac = 0.0;
        science = 0.0;
        computer = 0.0;
        activity = 0.0;
        file.write((char *)this, sizeof(FEE));
    }
    file.close();
    MODIFY_RECORD(12, 450, 50, 60, 60, 50);
    MODIFY_RECORD(11, 450, 50, 60, 60, 50);
    MODIFY_RECORD(10, 350, 50, 30, 60, 50);
    MODIFY_RECORD(9, 350, 50, 20, 60, 50);
    MODIFY_RECORD(8, 300, 50, 20, 40, 50);
    MODIFY_RECORD(7, 300, 50, 20, 40, 50);
    MODIFY_RECORD(6, 300, 50, 20, 40, 50);
    MODIFY_RECORD(5, 250, 50, 0, 40, 40);
    MODIFY_RECORD(4, 250, 50, 0, 40, 40);
    MODIFY_RECORD(3, 250, 50, 0, 40, 40);
    MODIFY_RECORD(2, 250, 50, 0, 40, 40);
    MODIFY_RECORD(1, 250, 50, 0, 40, 40);
}

// 展示费用列表
void FEE::LIST()
{
    system("cls");
    DRAW d;
    d.BOX(1, 2, 80, 24, 218);
    gotoxy(27, 3);
    cout << "TOTAL FEES FOR THE CLASSES";
    d.LINE_HOR(2, 79, 4, 196);
    gotoxy(5, 5);
    cout << "CLASS          TOTAL FEES";
    d.LINE_HOR(2, 79, 6, 196);
    d.LINE_HOR(2, 79, 22, 196);
    float total;
    int row = 8;
    fstream file;
    file.open("FEE.DAT", ios::in);
    while (file.read((char *)this, sizeof(FEE))) {
        total = tuition + ac + science + computer + activity;
        gotoxy(6, row);
        cout << Class;
        gotoxy(23, row);
        cout << total;
        row++;
    }
    file.close();
    gotoxy(5, 23);
    cout << "Press any key to continue............";
    getch();
    mainmenu();
}

// 显示给定登记的记录
void FEE::DISPLAY(int tclass)
{
    fstream file;
    file.open("FEE.DAT", ios::in);
    while (file.read((char *)this, sizeof(FEE))) {
        if (Class == tclass) {
            gotoxy(5, 5);
            cout << "Class : " << Class;
            gotoxy(5, 7);
            cout << "~~~~~~~~~~~";
            gotoxy(5, 8);
            cout << "Tution Fee : " << tuition;
            gotoxy(5, 9);
            cout << "Annual charges Fee : " << ac;
            gotoxy(5, 10);
            cout << "Science Fee : " << science;
            gotoxy(5, 11);
            cout << "Computer Fee : " << computer;
            gotoxy(5, 12);
            cout << "Activity Fee : " << activity;
            break;
        }
    }
    file.close();
}

// 修改给定数据的费用记录
void FEE::MODIFY_RECORD(int tclass, float ttution, float tac, float tscience, float tcomputer, float tactivity)
{
    fstream file;
    file.open("FEE.DAT", ios::in);
    fstream temp;
    temp.open("temp.dat", ios::out);
    file.seekg(0, ios::beg);
    while (!file.eof()) {
        file.read((char *)this, sizeof(FEE));
        if (file.eof()) {
            break;
        }
        if (tclass = Class) {
            Class = tclass;
            tuition = ttution;
            ac = tac;
            science = tscience;
            computer = tcomputer;
            activity = tactivity;
            temp.write((char *)this, sizeof(FEE));
        } else {
            temp.write((char *)this, sizeof(FEE));
        }
    }
    file.close();
    temp.close();
    file.open("FEE.DAT", ios::out);
    temp.open("temp.dat", ios::in);
    temp.seekg(0, ios::beg);
    while (!temp.eof()) {
        temp.read((char *)this, sizeof(FEE));
        if (temp.eof()) {
            break;
        }
        file.write((char *)this, sizeof(FEE));
    }
    file.close();
    temp.close();
}

// 提供修改费用记录的数据
void FEE::MODIFICATION(void)
{
    system("cls");
    char ch, t1[10];
    int valid = 0, t = 0, tclass = 0;
    float t2 = 0;
    do {
        valid = 1;
        gotoxy(5, 25);
        cout << "Press <Enter> for EXIT";
        gotoxy(5, 5);
        cout << "Enter Class for the Modification of the Fee Structure : ";
        gets(t1);
        t = atoi(t1);
        if (strlen(t1) == 0) {
            return;
        }
        if (tclass < 1 || tclass > 12) {
            valid = 0;
            gotoxy(5, 25);
            cout << "Enter correctly";
            getch();
        }
    } while (!valid);
    system("cls");
    gotoxy(71, 1);
    cout << "<0>=Exit";
    DISPLAY(tclass);
    gotoxy(5, 25);
    do {
        gotoxy(5, 15);
        cout << "Do you want to modify the fee structure (y/n) : ";
        ch = getche();
        if (ch == '0') {
            return;
        }
        ch = toupper(ch);
    } while (ch != 'N' && ch != 'Y');
    if (ch == 'N') {
        mainmenu();
    }
    float ttution = 0.0, tac = 0.0, tscience = 0.0, tcomputer = 0.0, tactivity = 0.0;
    gotoxy(5, 13);
    gotoxy(5, 17);
    cout << "Tuition Fee : ";
    gotoxy(5, 18);
    cout << "Annual Charges Fwee : ";
    gotoxy(5, 19);
    cout << "Science Fee : ";
    gotoxy(5, 20);
    cout << "Computer Fee : ";
    gotoxy(5, 21);
    cout << "Activity Fee : ";
    int modified = 5;
    fstream file;
    file.open("FEE.DAT", ios::in);
    while (file.read((char *)this, sizeof(FEE))) {
        if (Class == tclass) break;
    }
    file.close();

    do {
        valid = 1;
        gotoxy(5, 27);
        cout << "Enter TUITION FEE or Press <ENTER> for no change";
        gotoxy(19, 17);
        gets(t1);
        t2 = atof(t1);
        ttution = t2;
        if (t1[0] == '0') return;
        if (strlen(t1) == 0) break;
        if (ttution > 1000) {
            valid = 0;
            gotoxy(5, 27);
            cout << "7Enter correctly";
            getch();
        }
    } while (!valid);

    if (strlen(t1) == 0) {
        modified--;
        ttution = tuition;
        gotoxy(20, 17);
        cout << ttution;
    }

    do {
        valid = 1;
        gotoxy(5, 27);
        cout << "Enter ANNUAL CHARGES fee or Press <ENTER> for no change";
        gotoxy(26, 18);
        gets(t1);
        t2 = atof(t1);
        tac = t2;
        if (t1[0] == '0') {
            return;
        }
        if (strlen(t1) == 0) {
            break;
        }
        if (tac > 1000) {
            valid = 0;
            gotoxy(5, 27);
            cout << "7Enter correctly";
            getch();
        }
    } while (!valid);
}

//*************************************************
// 主菜单函数
//*************************************************
void mainmenu()
{
    system("cls");

    for (li=30; li<=50; li++) {
        gotoxy(li, 14);
        Sleep(30);
        printf("*");
    }
    
    for (li=50; li>=30; li--) {
        gotoxy(li, 30);
        Sleep(30);
        printf("*");
    }

    for (lp=15; lp<30; lp++) {
        gotoxy(30, lp);
        Sleep(100);
        printf("|");
    }
    for (lp=29; lp>=15; lp--) {
        gotoxy(50, lp);
        Sleep(100);
        printf("|");
    }
    gotoxy(15, 10);

    printf("Press the corresponding Keys for the desired action");
    gotoxy(35, 16);

    printf("F: FEE SLIP");
    gotoxy(35, 19);

    printf("M: MODIFY");
    gotoxy(35, 22);

    printf("L: LIST");
    gotoxy(35, 25);

    printf("H: HELP");
    gotoxy(35, 28);

    printf("Q: QUIT");
    choice = getch();
    ch = toupper(choice);
    switch (ch)
    {
    case 'F':
        fee.FEE_SLIP();
        break;
    case 'M':
        fee.MODIFICATION();
        break;
    case 'L':
        fee.LIST();
        break;
    case 'H':
        fee.HELP();
        break;
    case 'Q':
        exit(0);
        break;
    default:
        gotoxy(33, 40);
        cout << "Illegal Choice Press any key to return to Main Menu";
        getch();
        mainmenu();
    }
}