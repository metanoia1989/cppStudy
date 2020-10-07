#include <cstdlib>

class Rect 
{
public:
    constexpr Rect(size_t width, size_t height)
        : mWidth(width), mHeight(height) {}
    constexpr size_t getArea() const { return mWidth * mHeight; }
private:
    size_t mWidth, mHeight;
};

int main(int argc, char const *argv[])
{
    constexpr Rect r(8, 2);
    int myArr[r.getArea()];
    return 0;
}
