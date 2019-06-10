// 文件读取
#include <iostream>
#include <fstream> // 支持 file I/O
#include <cstdlib> // 支持 exit()

const int SIZE = 60;

int main()
{
    using namespace std;
    char filename[SIZE];
    ifstream inFile; // 文件读取对象
    cout << "Enter name of date file: ";
    cin.getline(filename, SIZE);
    inFile.open(filename);

    if(!inFile.is_open()) { // 文件打开失败
        cout << "Could not open the file " << filename << endl;
        cout << "Program terimnating." << endl;
        exit(EXIT_FAILURE);
    }

    double value;
    double sum = 0.0;
    int count = 0;
    inFile >> value; // 获取第一个值
    while (inFile.good()) // 没有读到文件末尾
    {
        ++count;
        sum += value;
        inFile >> value;
    }

    if (inFile.eof()) {
        cout << "End of file reached.\n";
    } else if (inFile.fail()) {
        cout << "Input ternimated by date mismatch\n";
    } else {
        cout << "Input ternimated for unknown reason.\n";
    }

    if (count == 0) {
        cout << "No data processed.\n";
    } else {
        cout << "Items read: " << count << endl;
        cout << "Sum: " << sum << endl;
        cout << "Average: " << sum / count << endl;
    }

    inFile.close();
    return 0;
}