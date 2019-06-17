#ifndef STONEWT_H_
#define STONEWT_H_

class Stonewt 
{
private:
    enum {Lbs_per_stn = 14}; // pounds per stone
    int stone; // 多少英石
    double pds_left; // 磅数
    double pounds; // 总重量的磅数
public:
    Stonewt(double lbs);
    Stonewt(int stn, double lbs);
    Stonewt(); 
    ~Stonewt(); 
    void show_libs() const; // 显示重量的磅数格式
    void show_stn() const; // 显示重量的英石格式
    // 类型转换函数
    operator int() const;
    operator double() const;
};

#endif