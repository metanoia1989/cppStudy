// 适量类 
#ifndef VECTOR_H_ 
#define VECTOR_H_ 
#include <iostream>

namespace VECTOR
{
    class Vector
    {
    public:
        // Rect rectangular 矩形 POL polar modes 极坐标
        enum Mode {RECT, POL};
    private:
        double x; // 水平坐标值
        double y; // 垂直坐标值
        double mag; // 矢量长度
        double ang;   // 矢量角度
        Mode mode;
        // 私有方法设置值
        void set_mag();
        void set_ang();
        void set_x();
        void set_y();
    public:
        Vector();
        Vector(double n1, double n2, Mode form = RECT);
        ~Vector();
        void reset(double n1, double n2, Mode form = RECT);
        double xval() const { return x; }
        double yval() const { return y; }
        double magval() const { return mag; }
        double angval() const { return ang; }
        void polar_mode(); // 设置 mode 为 POL
        void rect_mode(); // 设置 mode 为 RECT
        // 操作符重载
        Vector operator+(const Vector & b) const;
        Vector operator-(const Vector & b) const;
        Vector operator-() const;
        Vector operator*(double n) const;
        // 友元函数
        friend Vector operator*(double n, const Vector & a);
        friend std::ostream & 
            operator <<(std::ostream & os, const Vector & v);
    };
    
    
} // namespace VECTOR


#endif