#include <iostream>
#include <fstream>

using namespace std;

class Sales_data
{
private:
    /* data */
public:
    Sales_data(/* args */){};
    ~Sales_data(){};
};



int main(int argc, char const *argv[])
{
    ifstream input(argv[1]); // 打开销售记录文件
    fstream output(argv[2]); // 打开输出文件
    Sales_data trans; // 保存销售总额的变量
    if(read(input, total)) {
        while(read(input, tras)) { // 读取剩余记录
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            } else {
                print(output, total) << endl;
                total = trans;
            }
        }
        print(output, total) << endl;
    } else {
        cerr << "No data?!" << endl;
    }
    return 0;
}
